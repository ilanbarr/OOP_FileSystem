#pragma once
#include <set>
#include <iostream>
#include "H:\Lab5\SharedCode\AbstractCommand.h"
#include "H:\Lab5\SharedCode\AbstractFileSystem.h"

class editDisplay : public AbstractCommand {
public: 
	editDisplay(AbstractFileSystem* pointer);
	int execute(string str);
	void displayInfo();
private:
	AbstractFileSystem* fSys;
};