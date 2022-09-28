#pragma once
#include "AbstractFile.h"

class PasswordProxy : public AbstractFile {
private:
	AbstractFile* target;
	 string password;

public:
 PasswordProxy(AbstractFile* tgt, string pword);
 ~PasswordProxy();
 virtual vector<char> read();
 virtual AbstractFile* clone(string str);
 virtual int write(vector<char> c);
 virtual int append(vector<char> c);
 virtual unsigned int getSize();
 virtual string getName();
 virtual void accept(AbstractFileVisitor* A);

protected:
	string passwordPrompt();
	int match(string pass);
};