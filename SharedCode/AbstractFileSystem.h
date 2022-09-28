#pragma once
// declaration of the interface all file systems provide goes here

#include "AbstractFile.h"
#include <set>
#include <map>

class AbstractFileSystem {
public:
	virtual int addFile(string fName, AbstractFile* file) = 0;
	virtual int deleteFile(string fName) = 0;
	virtual AbstractFile* openFile(string fName) = 0;
	virtual int closeFile(AbstractFile* file) = 0;
	virtual set<string> getFileNames() = 0;

};


