#pragma once

//  Define the TextFile class here


#include "TextFile.h"

TextFile::TextFile(string s) {
	name = s;
}


 unsigned int TextFile::getSize() {
	int c = contents.size();
	return c;

}

string TextFile::getName() {
	return name;
}
int TextFile::write(vector<char> c) {
	contents = c;
	if (contents == c) {
		return 0;
	}
}

int TextFile::append(vector <char> c) {
	for (int i = 0; i < c.size(); i++) {
		contents.push_back(c[i]);
	}

	return 0;
}

vector<char> TextFile::read() {
	//for (int i = 0; i < getSize(); i++) {
	//	cout << contents[i];
//	}
	return contents;
}


void TextFile::accept(AbstractFileVisitor* c) {
	if (c != nullptr) {
		c->visit_TextFile(this);
	}
}

AbstractFile* TextFile::clone(string str) {
	AbstractFile* newClone = new TextFile(str);
	newClone->write(contents);
	return newClone;
 }