#include <iostream>
#include <vector>
#include "Processes.h"

using namespace std;
;
int main() {
	int numOfProcesses = 0;

	//Prompt the user for the number of processes
	cout << "Enter the number of processes: ";
	cin >> numOfProcesses;
	
	//Create a vector for each job
	vector<Processes> process;

	//Resize the vector to the user input
	process.resize(numOfProcesses);

	//Prompts the user to input the size for each job
	cout << "\nInput the size of each job:" << endl;
	for (int i = 0; i < numOfProcesses; i++) {
		int jobSize = 0;
		cin >> jobSize;
		process[i].size = jobSize;
		process[i].id = i;
	}

	int numOfPartitions = 0;

	//Prompt the user for the number of partitions
	cout << "\nEnter the number of partitions: ";
	cin >> numOfPartitions;

	//Create a vector to store partitions objects
	vector<Partition> partition;

	//Resize the vector to the user input
	partition.resize(numOfPartitions);

	//Prompts the user to input the size for each partition;
	cout << "\nInput the size of each partition:" << endl;
	for (int i = 0; i < numOfPartitions; i++) {
		int partitionSize = 0;
		cin >> partitionSize;
		partition[i].size = partitionSize;
	}


}