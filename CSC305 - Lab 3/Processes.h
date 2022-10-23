#pragma once
#ifndef PROCESSES_H
#define PROCESSES_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Processes {
	int id;
	string status;
	int partitionID;
	int size;
};

struct Partition {
	int id;
	bool status;
	int processID;
	int size;
	int waste;
};

enum Actions { stop, best, first, second, worst };

void bestFit(vector<Partition> partitionSize, int m, vector<Processes> processSize, int n);
void firstFit(vector<Partition> partitionSize, int m, vector<Processes> processSize, int n);
void nextFit(vector<Partition> partitionSize, int m, vector<Processes> processSize, int n);
void worstFit(vector<Partition> partitionSize, int m, vector<Processes> processSize, int n);

void bestFit(vector<Partition> partitionSize, int m, vector<Processes> processSize, int n) {
	//Create a allocation vector to store n size
	vector<int> allocation(n);

	//Stores block id of the block allocated to a process
	fill(allocation.begin(), allocation.end(), 0);

	int totalWaste = 0;

	//Select appropriate blocks for each process
	for (int i = 0; i < n; i++) {
		int bestIdx = -1;
		for (int j = 0; j < m; j++) {
			if (partitionSize[j].size >= processSize[i].size) {
				if (bestIdx == -1) {
					bestIdx = j;
					processSize[i].partitionID = j;
					processSize[i].status = "run";
					totalWaste += partitionSize[j].size - processSize[i].size;
					partitionSize[j].size -= processSize[i].size;
					partitionSize[j].processID = processSize[i].id;
					partitionSize[j].status = true;
				}
				else if (partitionSize[bestIdx].size > processSize[j].size) {
					bestIdx = j;
					processSize[i].partitionID = j;
					processSize[i].status = "run";
					totalWaste += partitionSize[j].size - processSize[i].size;
					partitionSize[j].size -= processSize[i].size;
					partitionSize[j].processID = processSize[i].id;
					partitionSize[j].status = true;
				}
			}
		}

		//Find a block for the current process
		if (bestIdx != -1) {
			allocation[i] = bestIdx;
			partitionSize[bestIdx].size -= processSize[i].size;
		}
	}

	cout << "Best Fit Algorithm" << endl;
	cout << "Job ID/Size\t\tPartition ID/Size\t\tWaste\t\tStatus" << endl;
	for (int i = 0; i < n; i++) {
		cout << processSize[i].id << " - " << processSize[i].size << "\t\t\t" << processSize[i].partitionID << " - " << partitionSize[i].size << "\t\t\t\t" << totalWaste << "\t\t" << processSize[i].status;
		if (allocation[i] != -1)
			cout << allocation[i] + 1;
		else
			cout << "Not Allocated";
		cout << endl;
	}
}

void firstFit(vector<Partition> partitionSize, int m, vector<Processes> processSize, int n) {
	//Create a allocation vector to store n size
	vector<int> allocation(n);

	//Stores block id of the block allocated to a process
	fill(allocation.begin(), allocation.end(), 0);

	//Sum of total waste from blocks
	int totalWaste = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (partitionSize[j].size >= processSize[i].size) {
				allocation[i] = j;
				processSize[i].partitionID = j;
				processSize[i].status = "run";
				totalWaste += partitionSize[j].size - processSize[i].size;
				partitionSize[j].size -= processSize[i].size;
				partitionSize[j].processID = processSize[i].id;
				partitionSize[j].status = true;
				break;
			}
		}
	}

	cout << "First Fit Algorithm" << endl;
	cout << "Job ID/Size\t\tPartition ID/Size\t\tWaste\t\tStatus" << endl;
	for (int i = 0; i < n; i++) {
		cout << processSize[i].id << " - " << processSize[i].size << "\t\t\t" << processSize[i].partitionID << " - " << partitionSize[i].size << "\t\t\t\t" << totalWaste << "\t\t" << processSize[i].status;
		if (allocation[i] != -1) {
			cout << allocation[i] + 1;
		}
		else {
			processSize[i].status = "wait";
			partitionSize[i].status = false;
		}
		cout << endl;
	}
}

void nextFit(vector<Partition> partitionSize, int m, vector<Processes> processSize, int n) {
	//Create a allocation vector to store n size
	vector<int> allocation(n);
	int j = 0;

	//Stores block id of the block allocated to a process
	fill(allocation.begin(), allocation.end(), 0);

	//Sum of total waste from blocks
	int totalWaste = 0;

	for (int i = 0; i < n; i++) {
		while (j < m) {
			allocation[i] = j;
			partitionSize[j].size -= processSize[i].size;
			break;
		}
		j = (j + 1) % m;
	}

	cout << "Next Fit Algorithm" << endl;
	cout << "Job ID/Size\t\tPartition ID/Size\t\tWaste\t\tStatus" << endl;
	for (int i = 0; i < n; i++) {
		cout << processSize[i].id << " - " << processSize[i].size << "\t\t\t" << processSize[i].partitionID << " - " << partitionSize[i].size << "\t\t\t\t" << totalWaste << "\t\t" << processSize[i].status;
		if (allocation[i] != -1) {
			cout << allocation[i] + 1;
		}
		else {
			processSize[i].status = "wait";
			partitionSize[i].status = false;
		}
		cout << endl;
	}
}

void worstFit(vector<Partition> partitionSize, int m, vector<Processes> processSize, int n) {

}

#endif