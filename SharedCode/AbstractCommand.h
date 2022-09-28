#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <sstream> 
#include <set>

using namespace std;

class AbstractCommand {
public:
	virtual ~AbstractCommand() = default;
	virtual int execute(string str) = 0;
	virtual void displayInfo() = 0;
};

