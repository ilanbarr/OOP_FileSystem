#pragma once
#include <set>
#include <iostream>
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "SimpleFileSystem.h"

class CloseDelete : public AbstractCommand {
public:
	CloseDelete(AbstractFileSystem* pointer);
	int execute(string str);
	void displayInfo();
private:
	AbstractFileSystem* fSys;
};