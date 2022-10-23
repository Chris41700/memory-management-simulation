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

enum Actions { stop, first, second, best, worst };

void firstFit(vector<int> partitionSize, int m, vector<int> processSize, int n, vector<Partition> partition, vector<Processes> process);
void nextFit(vector<int> partitionSize, int m, vector<int> processSize, int n, vector<Partition> partition, vector<Processes> process);
void bestFit(vector<int> partitionSize, int m, vector<int> processSize, int n, vector<Partition> partition, vector<Processes> process);
void worstFit(vector<int> partitionSize, int m, vector<int> processSize, int n, vector<Partition> partition, vector<Processes> process);

void firstFit(vector<int> partitionSize, int m, vector<int> processSize, int n, vector<Partition> partition, vector<Processes> process) {
	vector<int> waste(m);
	
	for (int i = 0; i < n; i++) {
		process[i].status = "wait";
		for (int j = 0; j < m; j++) {
			partition[j].inUsed = false;
			if (partitionSize[j] >= processSize[i] && partition[j].inUsed != true) {
				process[i].partitionID = partition[j].id;
				process[i].status = "run";
				partition[j].inUsed = true;
				partition[j].processID = process[i].id;
				partitionSize[j] -= processSize[i];
				waste.push_back(partitionSize[j]);
				break;
			}
		}
		
	}

	cout << "===============================First Fit Algorithm==============================="<< endl;
	cout << "Job ID\t\tPartition ID\t\tWaste\t\t\tStatus" << endl;
	for (int i = 0; i < n; i++) {
		cout << process[i].id << "\t\t" << process[i].partitionID << "\t\t\t" << waste[i] << "\t\t\t" << process[i].status << endl;
	}
	cout << "Total Waste: " << accumulate(waste.begin(), waste.end(), 0) << endl;
	cout << "=================================================================================" << endl;
}

void nextFit(vector<int> partitionSize, int m, vector<int> processSize, int n, vector<Partition> partition, vector<Processes> process) {

}

void bestFit(vector<int> partitionSize, int m, vector<int> processSize, int n, vector<Partition> partition, vector<Processes> process) {

}

void worstFit(vector<int> partitionSize, int m, vector<int> processSize, int n, vector<Partition> partition, vector<Processes> process) {

}

#endif