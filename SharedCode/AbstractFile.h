#pragma once
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary

#include <vector>
#include <iostream>
#include <string>
#include "AbstractFileVisitor.h"
#include "Enum.h"
using namespace std;

class AbstractFile {
public:
	
	virtual vector<char> read()=0;
	virtual int write(vector<char> c) = 0;
	virtual int append(vector<char> c) = 0;
	virtual unsigned int getSize()=0;
	virtual string getName() = 0;
	virtual ~AbstractFile() = default;
	virtual void accept(AbstractFileVisitor* A) = 0;
	virtual AbstractFile* clone(string str) = 0;
};

