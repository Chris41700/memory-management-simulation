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
};

struct Partition {
	int id;
	bool inUsed;
	int processID;
};

enum Actions { stop, first, second, best, worst };

void firstFit(vector<int> partitionSize, int m, vector<int> processSize, int n);
void nextFit(vector<int> partitionSize, int m, vector<int> processSize, int n);
void bestFit(vector<int> partitionSize, int m, vector<int> processSize, int n);
void worstFit(vector<int> partitionSize, int m, vector<int> processSize, int n);

void firstFit(vector<int> partitionSize, int m, vector<int> processSize, int n) {

}

void nextFit(vector<int> partitionSize, int m, vector<int> processSize, int n) {

}

void bestFit(vector<int> partitionSize, int m, vector<int> processSize, int n) {

}

void worstFit(vector<int> partitionSize, int m, vector<int> processSize, int n) {

}

#endif