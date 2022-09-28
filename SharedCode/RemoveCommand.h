#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class RemoveCommand : public AbstractCommand {
public:
	RemoveCommand(AbstractFileSystem* sys);
	 int execute(string str);
	 void displayInfo();
private:
	AbstractFileSystem* sys;
};

