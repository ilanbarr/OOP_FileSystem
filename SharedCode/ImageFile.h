#pragma once
// Image file class declaration here

#include "AbstractFile.h"



class ImageFile : public AbstractFile {

private:
	string name;
	vector<char> contents;
	char size;


public:
	ImageFile(string s);
	virtual unsigned int getSize();
	virtual string getName();
	virtual int write(vector<char> c);
	virtual int append(vector<char> c);
	virtual vector<char> read();
	virtual void accept(AbstractFileVisitor* A);
	virtual AbstractFile* clone(string str);
	int getImgSize();

};
