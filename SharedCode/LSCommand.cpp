#pragma once
#include "LSCommand.h"

LSCommand::LSCommand(AbstractFileSystem* sys){
	fs = sys;
}

int LSCommand::execute(string s) {
	set<string> names = fs->getFileNames();
	set<string>::iterator its = names.begin();

	if (names.size() == 0) {
		cout << "no files" << endl;
		return 55;
	}
	if (s != "" && s != "-m") {
		cout << "Invalid Argument. " << s.substr(1) << " is not a valid input for ls. " << endl;
		return 77;

	}

	if (s == "-m") {
		AbstractFileVisitor* meta = new MetadataDisplayVisitor();
	
		for (its; its != names.end(); its++){
			AbstractFile* file = fs->openFile(*its);
			file->accept(meta);
			fs->closeFile(file);
		}
		//delete meta;
		return success;
	}
	else if (s == "") {
		bool secondDone = false;
		for (its = names.begin(); its != names.end(); its++) {
			int size = its->length();
			cout << *its;

			if (secondDone) {
				cout << endl;
				secondDone = false;
			}
			else {
				int spaces = 26 - size;
				for (int i = 0; i < spaces; i++) {
					cout << " ";
				}
				secondDone = true;
			}
		}
		cout << endl;
		return success;
	}
}


void LSCommand::displayInfo() {
	cout << "ls lists all available files in the file system" << endl;
	cout << "type 'ls' to list all files" << endl;
	cout << "type '-m' to display all metadata for files" << endl;
}


