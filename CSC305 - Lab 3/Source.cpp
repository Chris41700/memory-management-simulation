#include <iostream>
#include <vector>
#include "Processes.h"

using namespace std;
;
int main() {
	int numProcesses;

	//Prompt the user for the number of processes
	cout << "Enter the number of processes: ";
	cin >> numProcesses;
	
	//Create a vector for each job
	vector<Processes> process;

	//Resize the vector to the user input
	process.resize(numProcesses);

	//Prompts the user to input the size for each job
	cout << "\nInput the size of each job:" << endl;
	for (int i = 0; i < numProcesses; i++) {
		int jobSize = 0;
		cin >> jobSize;
		process[0].size = jobSize;
	}
}