#include "RemoveCommand.h"
RemoveCommand::RemoveCommand(AbstractFileSystem* syspoint) {
	sys = syspoint;
}
int RemoveCommand::execute(string name) {
	if (name == "") {
		cout << "empty";
		return 18;
	}
	return this->sys->deleteFile(name);
}

void RemoveCommand::displayInfo() {
	cout << "if the file exists, you can call rm <filename> to delete";
}