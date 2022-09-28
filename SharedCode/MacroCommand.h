#pragma once
#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include "AbstractFileSystem.h"
#include "AbstractFile.h"
class MacroCommand : public AbstractCommand {
private:
	vector<AbstractCommand*> command;
	AbstractParsingStrategy* parStrat;
	AbstractFileSystem* fSys;
public:
	MacroCommand(AbstractFileSystem* sys);
	int execute(string str);
	void displayInfo();
	void addCommand(AbstractCommand* point);
	void setParseStrategy(AbstractParsingStrategy* psPoint);
};