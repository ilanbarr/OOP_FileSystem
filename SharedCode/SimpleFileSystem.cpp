// define methods of SimpleFileSystem class here
#include "SimpleFileSystem.h"

int SimpleFileSystem::addFile(string fName, AbstractFile* file) {
	if (file == nullptr) {
		return 4;
	}
	if (files.find(fName) != files.end()) {
		return 7;
	}
	else {
		files.insert(pair<string, AbstractFile*>(fName, file));

		return 0;
	}
}

/*
int SimpleFileSystem::createFile(string fName) {
	if (files.find(fName) != files.end()) {
		return 7;
	}
	else {
		int a = fName.find(".");
		string ext = "";
			for (int i = a+1; i < fName.length(); i++) {
				ext += fName[i];

		}
		if (ext == "txt") {
			TextFile newText(fName);
			AbstractFile* newPoint = &newText;
			files.insert(pair<string, AbstractFile*>(fName, newPoint));
			return 0;
		}
			if (ext == "img") {
				ImageFile newImage(fName);
				AbstractFile* newPoint = &newImage;
				files.insert(pair<string, AbstractFile*>(fName, newPoint));
			return 0;
			}
	}
}
*/

int SimpleFileSystem::deleteFile(string fName) {
	if (files.find(fName) != files.end()) {
		AbstractFile* name = files[fName];
		if (openFiles.find(name) != openFiles.end()) {
			return 5;
		}
		else {
			files.erase(fName);
			delete name;
			return 0;
		}


	}
	else return 3;

}
AbstractFile* SimpleFileSystem::openFile(string fName) {
	if (files.find(fName) != files.end()) {
		AbstractFile* open = files[fName];
		if (openFiles.find(open) != openFiles.end()) {
			return nullptr;
		}
		else {
			openFiles.insert(open);
			return open;
		}
	}
	else return nullptr;
}


int SimpleFileSystem::closeFile(AbstractFile* file) {
	if (openFiles.find(file) != openFiles.end()) {
		openFiles.erase(file);
		return 0;
	}
	else return 5;
}

set<string> SimpleFileSystem::getFileNames() {
	set<string> names;
	map<string, AbstractFile*>::iterator its;
	for (its = this->files.begin(); its != this->files.end(); its++){
	names.insert(its->first);
}
return names;

}