#include "Processes.h"

int main() {
	int numOfProcesses = 0;

	//Prompt the user for the number of processes
	cout << "Enter the number of processes: ";
	cin >> numOfProcesses;
	
	//Create a vector for each job
	vector<Processes> process(numOfProcesses);

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
	vector<Partition> partition(numOfPartitions);

	//Prompts the user to input the size for each partition;
	cout << "\nInput the size of each partition:" << endl;
	for (int i = 0; i < numOfPartitions; i++) {
		int partitionSize = 0;
		cin >> partitionSize;
		partition[i].size = partitionSize;
	}

	int action;
    int m = sizeof(process) / sizeof(process[0]);
    int n = sizeof(partition) / sizeof(partition[0]);

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
			bestFit(process, m, partition, n);
			break;
		}
	} while (action != stop);
}