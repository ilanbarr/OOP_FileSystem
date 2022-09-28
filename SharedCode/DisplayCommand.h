#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFile.h"

class DisplayCommand : public AbstractCommand {
public:
	DisplayCommand(AbstractFileSystem* sys);
	int execute(string str);
	void displayInfo();
private:
	AbstractFileSystem* fSys;
};