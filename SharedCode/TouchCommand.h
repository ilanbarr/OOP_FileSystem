#pragma once
#include "CommandPrompt.h"
#include "AbstractFileSystem.h"
#include "PasswordProxy.h"
#include "AbstractFileFactory.h"
#include "AbstractCommand.h"




class TouchCommand : public AbstractCommand {
private:
	AbstractFileSystem* sys;
	AbstractFileFactory* fac;

public:
	TouchCommand(AbstractFileSystem* system, AbstractFileFactory* factory);
	virtual int execute(string str);
	virtual void displayInfo();
	
};
