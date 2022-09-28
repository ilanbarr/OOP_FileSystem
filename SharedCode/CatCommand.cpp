#include "CatCommand.h"
CatCommand::CatCommand(AbstractFileSystem* Sys) {
	fsys = Sys;
}
int CatCommand::execute(string str) {
	string numword;
	string name = str;
	AbstractFile* point = fsys->openFile(name);
	if (str.find(' ') == -1) {
		cout << "Enter the concatenation";
	}
	else {
		int space = str.find(' ');
		string cntnts;
		name = str.substr(0, space);
		point = fsys->openFile(name);
		numword = str.substr(space + 1);
		if (numword != "-a") {
			cout << "Invalid Argument" << endl;
			return CatCom_Inv_Arg;
		}
		else cout << "Enter the input for appending the file";

	}
	cout << "Enter :wq to save the file and exit, enter :q to exit without saving" << endl;
	if (numword == "-a") {
		if (point != nullptr) {
			vector<char> contents = point->read();
			string cntnts;
			for (int i = 0; i < contents.size(); i++) {
				cntnts += contents[i];
				cout << contents[i];
			}
		}
		else {
			cout << name << " does not exist" << endl;
			return Cat_Fl_DNE;
		}
	}
	vector<char> inputs;
	string UserIn;
	bool c = true;
	while (getline(cin, UserIn)) {
		if (UserIn != ":q" || UserIn != ":wq") {
			for (int i = 0; i < UserIn.length(); i++) {
				inputs.push_back(UserIn[i]);
			}cout << '\n';
		}
		else {

			if (UserIn == ":q") {
				this->fsys->closeFile(point);
				return success;
			}
			else if (UserIn == ":wq") {
				UserIn.pop_back();
				if (numword == "-a") {
					int check = point->append(inputs);
					if(check==success){
						this->fsys->closeFile(point);
						return success;
					}
					else return (check);
				} 
				/*else {
					
					return 90;
						
					return error;
				}*/
				int check = point->write(inputs);
				if (check != success) {
					return check;
				}
				else {
					this->fsys->closeFile(point);
					return success;
				}
			}
		}
	}
	return success;
}
	
void CatCommand::displayInfo() {
	cout << "cat <filename> [-a] writes to a file or appends a file using -a";
}