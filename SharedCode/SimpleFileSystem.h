#pragma once
// declaration of SimpleFileSystem class goes here
#include "AbstractFileSystem.h"
#include "ImageFile.h"
#include "TextFile.h"




class SimpleFileSystem : public AbstractFileSystem {
private:
	map<string, AbstractFile*> files;
	set<AbstractFile*> openFiles;

public:
	virtual int addFile(string fName, AbstractFile* file);
	virtual int deleteFile(string fName);
	virtual AbstractFile* openFile(string fName);
	virtual int closeFile(AbstractFile* file);
	virtual set<string> getFileNames();
};
