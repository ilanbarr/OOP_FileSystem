#pragma once
#include "CommandPrompt.h"

CommandPrompt::CommandPrompt() {
	fileF = nullptr;
	fileS = nullptr;
}
void CommandPrompt::setFileFactory(AbstractFileFactory* f) {
	fileF = f;

}
void CommandPrompt::setFileSystem(AbstractFileSystem* s) {
	fileS = s;
}
int CommandPrompt::addCommand(string value, AbstractCommand* insert) {
	object.insert(pair<string, AbstractCommand*>(value, insert));
	if (object.find(value) != object.end()) {
		return 0;
	}
	else return 15;
}
int CommandPrompt::run() {
    bool condition = true;
    do {
        string comm = prompt();
        if (comm == "help") {
            listCommands();
        }
        else if (comm != "q") {
            if (comm.find(' ') != -1) {
                istringstream wrap(comm);
                string ext;
                wrap >> ext;
                if (ext != "help") {
                    string ed = comm.substr(comm.find(" ")+1);
                   // (comm.find(" ") + 1);
                    if (object.find(ext) != object.end()) {
                        object.find(ext)->second->execute(ed);
                    }
                }
                else {
                    string file;
                    wrap >> file;
                    if (object.find(file) != object.end()) {
                        object.find(file)->second->displayInfo();
                    }
                    else cout << "Command does not exist";
                }
           
            }
            else {
                istringstream wrap(comm);
                string ext;
                wrap >> ext;
                if (object.find(ext) != object.end()) {
                    string empty = "";
                    object.find(ext)->second->execute(empty);
                }
                else cout << "Command Failed";

                }
            }
        
        else {
            condition = false;
            return 52;
        }
    } while (condition);
}

void CommandPrompt::listCommands() {
	map<string, AbstractCommand*>::iterator it;
	for (it = object.begin(); it != object.end(); it++) {
		cout << it->first << endl;

	}

	

}

string CommandPrompt::prompt() {
	string user;
	cout << "Enter a command, q to quit, help for a list of commands, or help followed by a command name for help on that command" << endl;
	cout << "$   ";
    getline(cin, user);
	return user;
}