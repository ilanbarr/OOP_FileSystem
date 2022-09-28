#pragma once
#include "CopyCommand.h"

CopyCommand::CopyCommand(AbstractFileSystem* sys) {
	fsys = sys;
}

int CopyCommand::execute(string str) {
	int space = str.find(' ');
	istringstream wrap(str);
	string fName;
	string format;
	wrap >> fName;
	wrap >> format;
	AbstractFile* copy = fsys->openFile(fName);
	if (space == -1) {
		cout << "No name was provided for the copied file." << endl;
		return Copy_Com_INV_WORD;
	}
	if (copy == nullptr) {
		cout << fName << " does not exist" << endl;
		return 88;
	}
	fsys->closeFile(copy);
	//int space1 = space + 1;
	//format = str.substr(space1,str.length()-2);
	//fName = str.substr(1, space);
	//int dot = fName.find('.');
	//string ext = fName.substr(dot);
	//format.append(ext);
	format += ".";
	format += fName.substr(fName.length() - 3);
	AbstractFile* newF = fsys->openFile(fName);
	//int Copy = fsys->addFile(format, newF);

		AbstractFile* newe = newF->clone(format);
		fsys->closeFile(newF);
		if (newe == nullptr) {

			string message = format + " File Does not exist";
			cout << message << endl;
		
			return Copy_COM_F_DNE;

		}
		
		int checker = fsys->addFile(format, newe);
		if (checker == success) {
			return success;
		}else{

			cout << "Copied item was unsucesfully added" << endl;
			delete newe;
			return checker;
		}
}

void CopyCommand::displayInfo() {
	cout << "CopyCommand copies an existing file to a new file. The format is: cp <existingfilename> <newname_no_ext>" << endl;
}