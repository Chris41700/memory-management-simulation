#include "Processes.h"

int main() {
	int numOfProcesses = 0;

	//Prompt the user for the number of processes
	cout << "Enter the number of processes: ";
	cin >> numOfProcesses;
	
	//Create a vector to store each process
	vector<Processes> process(numOfProcesses);

	//Create a vector to store process sizes
	vector<int> processSize;

	int jobSize = 0;
	//Prompts the user to input the size for each job
	cout << "\nInput the size of each job:" << endl;
	for (int i = 0; i < numOfProcesses; i++) {
		cin >> jobSize;
		processSize.push_back(jobSize);
		process[i].id = i + 1;
	}

	int numOfPartitions = 0;

	//Prompt the user for the number of partitions
	cout << "\nEnter the number of partitions: ";
	cin >> numOfPartitions;

	//Create a vector to store partitions objects
	vector<Partition> partition(numOfPartitions);

	//Create a vector to store partition sizes
	vector<int> partitionSize;

	int blockSize = 0;

	//Prompts the user to input the size for each partition;
	cout << "\nInput the size of each partition:" << endl;
	for (int i = 0; i < numOfPartitions; i++) {
		cin >> blockSize;
		partitionSize.push_back(blockSize);
		partition[i].id = i + 1;
	}

	int action;
	int m = partitionSize.size();
	int n = processSize.size();

	//User menu to choose an memory management algorithm
	do {
		cout << "\n----------Memory Management Algorithm Menu----------" << endl;
		cout << "0 - Stop" << endl;
		cout << "1 - Best Fit" << endl;
		cout << "2 - First Fit" << endl;
		cout << "3 - Next Fit" << endl;
		cout << "4 - Worst Fit" << endl;
		cout << "Enter a number to choose a memory management algorithm: ";
		cin >> action;
		cout << endl;

		switch (action) {
		case stop:
			exit(0);
			break;
		case best:
			bestFit(partitionSize, m, processSize, n);
			break;
		case first:
			firstFit(partitionSize, m, processSize, n);
			break;
		case second:
			nextFit(partitionSize, m, processSize, n);
			break;
		case worst:
			worstFit(partitionSize, m, processSize, n);
			break;
		}
	} while (action != stop);

	return 0;
}