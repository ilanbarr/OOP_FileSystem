#include "MacroCommand.h"
#include "AbstractFileSystem.h"
MacroCommand::MacroCommand(AbstractFileSystem* sys) {
	fSys = sys;
}
int MacroCommand::execute(string str) {
	vector<string> read = parStrat->parse(str);
	if (read.size() != command.size()) {
		return 46;
	}
	else {
		int j = 0;
		do {
			int check = command[j]->execute(read[j]);
			if (check != 0) return 43;
			j++;
		} while (j < command.size() && j < read.size());
	}
	return success;
}
void MacroCommand::addCommand(AbstractCommand* addC) {
	command.push_back(addC);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* pstrat) {
	parStrat = pstrat;
}

void MacroCommand::displayInfo() {
	int j = 0;
	do {
		command[j]->displayInfo();
		j++;
	} while (j < command.size());
}