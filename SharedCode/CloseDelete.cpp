#include "CloseDelete.h"

CloseDelete::CloseDelete(AbstractFileSystem* pointer) {
	fSys = pointer;
}

int CloseDelete::execute(string str) {
	AbstractFile* pointer = fSys->openFile(str);
	if (pointer != nullptr) {
		fSys->closeFile(pointer);
		fSys->deleteFile(str);
		return success;
	}
	else return CloseDeleteError;
}

void CloseDelete::displayInfo() {
	cout << " EditDisplay " << endl;
}