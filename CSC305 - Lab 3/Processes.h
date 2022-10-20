#pragma once
#ifndef PROCESSES_H
#define PROCESSES_H

#include <iostream>

struct Processes {
	int id;
	int size;
};

struct Partition {
	int size;
	int waste;
	bool status;
};

#endif