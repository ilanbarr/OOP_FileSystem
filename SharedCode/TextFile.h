#pragma once
// TextFile declaration goes here

#include "AbstractFile.h"

class TextFile : public AbstractFile {
public: 
	TextFile(string s);
	virtual vector<char> read();
	virtual int write(vector<char> c);
	virtual int append(vector<char> c);
	virtual unsigned int getSize();
	virtual string getName();
	virtual void accept(AbstractFileVisitor* A);
	virtual AbstractFile* clone(string str);

private:
	vector<char> contents;
		string name;
};