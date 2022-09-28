#pragma once
#include "PasswordProxy.h"

PasswordProxy::PasswordProxy(AbstractFile* tgt, string pword) {
	target = tgt;
	password = pword;
}

PasswordProxy::~PasswordProxy(){
	delete target;
}


string PasswordProxy::passwordPrompt() {
	string input;
	cout << "Please input password";
	cin >> input;
	return input;
}


int PasswordProxy::match(string pass) {
	if (password == pass) {
		return success;
	}
	else return 12;
}

vector<char> PasswordProxy::read() {
	string user = passwordPrompt();
	if (match(user) != success) return vector<char>();
	else return target->read();
}
int  PasswordProxy::write(vector<char> c) {
	string user = passwordPrompt();
	if (match(user) != success) return 13;
	else return target->write(c);
 }
 int  PasswordProxy::append(vector<char> c) {
	 string user = passwordPrompt();
	 if (match(user) != success) return 13;
	 else return target->append(c);
}
 unsigned int  PasswordProxy::getSize() {
	 return target->getSize();
}
 string  PasswordProxy::getName() {
	 return target->getName();
}
 void PasswordProxy::accept(AbstractFileVisitor* A) {
	/* string user = passwordPrompt();
	 if (match(user) == success) {
		 target->accept(A);
	*/
	 string x = passwordPrompt();
	 cout << endl;
	 if (x == password){
		 target->accept(A);
	 }

}


 AbstractFile* PasswordProxy::clone(string str) {
	 AbstractFile* save = target->clone(str);
	 AbstractFile* newSave = new PasswordProxy(save, password);
	 return newSave;
 }