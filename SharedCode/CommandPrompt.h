#pragma once
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"


class CommandPrompt  {
public:
	CommandPrompt();
	void setFileFactory(AbstractFileFactory* f);
	void setFileSystem(AbstractFileSystem* s);
	int addCommand(string value, AbstractCommand* insert);
	int run();
private:
	map<string, AbstractCommand*> object;
	AbstractFileFactory* fileF;
	AbstractFileSystem* fileS;
protected:
	void listCommands();
	string prompt();
};




