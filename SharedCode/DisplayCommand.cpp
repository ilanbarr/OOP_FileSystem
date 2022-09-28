#include "DisplayCommand.h"
#include "BasicDisplayVisitor.h"
DisplayCommand::DisplayCommand(AbstractFileSystem* sys) {
	fSys = sys;
}

int DisplayCommand::execute(string str) {
	int space = str.find(' ');
	istringstream wrap(str);
	string name;
	wrap >> name;
	string strs;
	wrap >> strs;
	AbstractFile* fac = fSys->openFile(name);
	if (str == "") {
		cout << "no info" << endl;
		return 74;
	}
	else {
		/*istringstream wrap(str);
		string ext;
		string secondW;
		wrap >> ext;
		wrap >> secondW; */
		if (fac != nullptr) {
		//	if (fSys->addFile(str, fac) == 0) {
				if (strs == "-d") {
					vector<char> iterator = fac->read();
					int j = 0;
					do {
						cout << iterator[j];
						++j;
					} while (j < iterator.size() );
				}
				else {
					AbstractFileVisitor* basicVisitor = new BasicDisplayVisitor;
					fac->accept(basicVisitor);
				}
				cout << endl;
				fSys->closeFile(fac);
				return success;
			}
			
		else {
			return 92;
		}
	}
}

void DisplayCommand::displayInfo(){
	cout << "ds <filename> [-d] will display a file where -d is for displaying data only" << endl;
}
