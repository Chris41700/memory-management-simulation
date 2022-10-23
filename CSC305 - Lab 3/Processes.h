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
};

enum Actions { stop, best, first, next, worst };

void bestFit(vector<Processes> processSize, int m, vector<Partition> partitionSize, int n);
void firstFit(vector<Processes> processSize, int m, vector<Partition> partitionSize, int n);
void nextFit(vector<Processes> processSize, int m, vector<Partition> partitionSize, int n);
void worstFit(vector<Processes> processSize, int m, vector<Partition> partitionSize, int n);

void bestFit(vector<Processes> processSize, int m, vector<Partition> partitionSize, int n) {
	//Create a allocation vector to store n size
	vector<int> allocation(n);

	//Stores block id of the block allocated to a process
	fill(allocation.begin(), allocation.end(), 0);

	//Select appropriate blocks for each process
	for (int i = 0; i < n; i++) {
		int bestIdx = -1;
		for (int j = 0; j < m; j++) {
			if (processSize[j] >= partitionSize[i]) {
				if (bestIdx == -1) {
					bestIdx = j;
				}
				else if (processSize[bestIdx] > processSize[j]) {
					bestIdx = j;
				}
			}
		}

		//Find a block for the current process
		if (bestIdx != -1) {
			allocation[i] = bestIdx;
			processSize[bestIdx] -= partitionSize[i];
		}
	}

	cout << "\nProcess No.\tProcess Size\tBlock no.\n";
	for (int i = 0; i < n; i++) {
		cout << "   " << i + 1 << "\t\t" << processSize[i] << "\t\t";
		if (allocation[i] != -1)
			cout << allocation[i] + 1;
		else
			cout << "Not Allocated";
		cout << endl;
	}
}

#endif