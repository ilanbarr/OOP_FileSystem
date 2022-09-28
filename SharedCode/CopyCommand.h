#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class CopyCommand : public AbstractCommand {
private:
	AbstractFileSystem* fsys;

public:
	CopyCommand(AbstractFileSystem* sys);
	int execute(string str);
	void displayInfo();
};

