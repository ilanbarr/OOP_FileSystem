#pragma once
#include "TouchCommand.h"

TouchCommand::TouchCommand(AbstractFileSystem* system, AbstractFileFactory* factory) {
	fac = factory;
	sys = system;
}
int TouchCommand::execute(string str) {

	
	if (str == "") {
		cout << "no info" << endl;
	}
	else {
		istringstream wrap(str);
		string ext;
		string secondW;
		wrap >> ext;
		wrap >> secondW;
		AbstractFile* point = fac->createFile(ext);
		if (point != nullptr) {
			//if (sys->addFile(ext, point) == 0) {
				if (secondW == "-p") {
					string pass="";
					do {
						pass = "";
						cout << "enter password" << endl;
						cin >> pass;
					} while (pass == "");
					AbstractFile* passProx = new PasswordProxy(point, pass);
					return sys->addFile(ext, passProx);
				}
				if (sys->openFile(ext)) {
					sys->closeFile(point);
					return success;
				}
				else {
					sys->deleteFile(ext);
					return 45;
				}
				return 19;
			
			

		}return 17;
	}
}

void TouchCommand::displayInfo() {
	cout << "touch <file name> creates a file with the inputted name and is password protected by writing touch <file name> -p " << endl;

}