#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFile.h"

class CatCommand : public AbstractCommand {
public:
	CatCommand(AbstractFileSystem* sys);
	int execute(string str);
	void displayInfo();
private:
	AbstractFileSystem* fsys;
};