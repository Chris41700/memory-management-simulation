#pragma once
#ifndef PROCESSES_H
#define PROCESSES_H

#include <iostream>
#include <numeric>
#include <vector>
#include <string>

using namespace std;

struct Processes {
	int id;
	string status;
	int partitionID;
};

struct Partition {
	int id;
	bool inUsed;
	int processID;
};

//Enum for switch menu choices
enum Actions { stop, first, second, best, worst };

//Function Prototypes
void firstFit(vector<int> partitionSize, int m, vector<int> processSize, int n, vector<Partition> partition, vector<Processes> process);
void nextFit(vector<int> partitionSize, int m, vector<int> processSize, int n, vector<Partition> partition, vector<Processes> process);
void bestFit(vector<int> partitionSize, int m, vector<int> processSize, int n, vector<Partition> partition, vector<Processes> process);
void worstFit(vector<int> partitionSize, int m, vector<int> processSize, int n, vector<Partition> partition, vector<Processes> process);

void firstFit(vector<int> partitionSize, int m, vector<int> processSize, int n, vector<Partition> partition, vector<Processes> process) {
	//Create vector to store waste from partitions
	vector<int> waste(n);
	
	for (int i = 0; i < n; i++) {
		process[i].status = "wait";
		for (int j = 0; j < m; j++) {
			if (partitionSize[j] >= processSize[i] && partition[j].inUsed != true) {
				process[i].partitionID = partition[j].id;
				process[i].status = "run";
				partition[j].inUsed = true;
				partition[j].processID = process[i].id;
				waste[i] = partitionSize[j] - processSize[i];
				partitionSize[j] -= processSize[i];
				break;
			}
		}
	}

	cout << "===============================First Fit Algorithm===============================" << endl;
	cout << "Job ID\t\tPartition ID\t\tWaste\t\t\tStatus" << endl;
	for (int i = 0; i < n; i++) {
		cout << process[i].id << "\t\t" << process[i].partitionID << "\t\t\t";

		if (i >= waste.size()) {
			cout << "0" << "\t\t\t" << process[i].status << endl;;
		}
		else {
			cout << waste.at(i) << "\t\t\t" << process[i].status << endl;
		}
	}
	cout << "Total Waste: " << accumulate(waste.begin(), waste.end(), 0) << endl;
	cout << "=================================================================================" << endl;
}

void nextFit(vector<int> partitionSize, int m, vector<int> processSize, int n, vector<Partition> partition, vector<Processes> process) {
	//Create vector to store waste from partitions
	vector<int> waste(n);
	int j = 0;

	for (int i = 0; i < n; i++) {
		int count = 0;
		process[i].status = "wait";
		while (count < m) {
			if (partitionSize[j] >= processSize[i] && partition[j].inUsed != true) {
				process[i].partitionID = partition[j].id;
				process[i].status = "run";
				partition[j].inUsed = true;
				partition[j].processID = process[i].id;
				waste[i] = partitionSize[j] - processSize[i];
				partitionSize[j] -= processSize[i];
				break;
			}
			j = (j + 1) % m;
			count += 1;
		}
	}

	cout << "===============================Next Fit Algorithm================================" << endl;
	cout << "Job ID\t\tPartition ID\t\tWaste\t\t\tStatus" << endl;
	for (int i = 0; i < n; i++) {
		cout << process[i].id << "\t\t" << process[i].partitionID << "\t\t\t";

		if (i < waste.size()) {
			cout << waste.at(i) << "\t\t\t" << process[i].status << endl;
		}
		else {
			cout << "0" << "\t\t\t" << process[i].status << endl;;
		}
	}
	cout << "Total Waste: " << accumulate(waste.begin(), waste.end(), 0) << endl;
	cout << "=================================================================================" << endl;
}

void bestFit(vector<int> partitionSize, int m, vector<int> processSize, int n, vector<Partition> partition, vector<Processes> process) {
	//Create vector to store waste from partitions
	vector<int> waste(n);

	for (int i = 0; i < n; i++) {
		int bestIndex = -1;
		process[i].status = "wait";
		for (int j = 0; j < m; j++) {
			if (partitionSize[j] >= processSize[i] && partition[j].inUsed != true) {
				if (bestIndex == -1) {
					bestIndex = j;
				}
				else if (partitionSize[bestIndex] > partitionSize[j]) {
					bestIndex = j;
				} 
			}
		}
		
		if (bestIndex != -1) {
			process[i].partitionID = bestIndex + 1;
			process[i].status = "run";
			partition[bestIndex].inUsed = true;
			partition[bestIndex].processID = process[i].id;
			waste[i] = partitionSize[bestIndex] - processSize[i];
			partitionSize[bestIndex] -= processSize[i];
		}
	}

	cout << "==============================Best Fit Algorithm===============================" << endl;
	cout << "Job ID\t\tPartition ID\t\tWaste\t\t\tStatus" << endl;
	for (int i = 0; i < n; i++) {
		cout << process[i].id << "\t\t" << process[i].partitionID << "\t\t\t";

		if (i < waste.size()) {
			cout << waste.at(i) << "\t\t\t" << process[i].status << endl;
		}
		else {
			cout << "0" << "\t\t\t" << process[i].status << endl;;
		}
	}
	cout << "Total Waste: " << accumulate(waste.begin(), waste.end(), 0) << endl;
	cout << "===============================================================================" << endl;
}

void worstFit(vector<int> partitionSize, int m, vector<int> processSize, int n, vector<Partition> partition, vector<Processes> process) {
	//Create vector to store waste from partitions
	vector<int> waste(n);

	for (int i = 0; i < n; i++) {
		int worstIndex = -1;
		process[i].status = "wait";
		for (int j = 0; j < m; j++) {
			if (partitionSize[j] >= processSize[i] && partition[j].inUsed != true) {
				if (worstIndex == -1) {
					worstIndex = j;
				}
				else if (partitionSize[worstIndex] < partitionSize[j]) {
					worstIndex = j;
				}
			}
		}

		if (worstIndex != -1) {
			process[i].partitionID = worstIndex + 1;
			process[i].status = "run";
			partition[worstIndex].inUsed = true;
			partition[worstIndex].processID = process[i].id;
			waste[i] = partitionSize[worstIndex] - processSize[i];
			partitionSize[worstIndex] -= processSize[i];
		}
	}

	cout << "===============================Worst Fit Algorithm================================" << endl;
	cout << "Job ID\t\tPartition ID\t\tWaste\t\t\tStatus" << endl;
	for (int i = 0; i < n; i++) {
		cout << process[i].id << "\t\t" << process[i].partitionID << "\t\t\t";

		if (i < waste.size()) {
			cout << waste.at(i) << "\t\t\t" << process[i].status << endl;
		}
		else {
			cout << "0" << "\t\t\t" << process[i].status << endl;;
		}
	}
	cout << "Total Waste: " << accumulate(waste.begin(), waste.end(), 0) << endl;
	cout << "=================================================================================" << endl;
}

#endif