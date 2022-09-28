#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "MetadataDisplayVisitor.h"

class LSCommand : public AbstractCommand {
private:
	AbstractFileSystem* fs;
public:
	 LSCommand(AbstractFileSystem* sys);
	virtual int execute(string s);
	virtual void displayInfo();
};

