#pragma once 
// definition of ImageFile class here
#include "ImageFile.h"
using namespace std;

ImageFile::ImageFile(string s) {
	name = s;
	size = '0';
}
//create helper getter method that returns size

unsigned int ImageFile::getSize() {
	unsigned int x = contents.size();
	return x;
}

string ImageFile::getName() {
	return name;
}

int ImageFile::write(vector<char> c) {
	contents.clear();
	char l = c[c.size() - 1];
	size = l - 48;

	if (c.size() -1 == (int)size * (int)size) {
		for (int j = 0; j < c.size() - 1; j++) {
			if (c[j] != 'X' && c[j] != ' ') {
				contents.clear();
				size = 0;
				return 1;
			}
			else {
				contents.push_back(c[j]);
			}
		}
		return 0;
	}
	else return 6;
}

int ImageFile::getImgSize() {
	return this->size;
}

int ImageFile::append(vector<char> c) {
	return 2;
}

vector<char> ImageFile::read() {
	/*if (contents.size() == size * size) {
		int temp = size - 1;
		
		while (temp >= 0) {
			for (int k = 0; k < size; ++k) {
				cout << contents[(k)*size + temp];

			}
			cout << endl;
			temp--;
		}

	} */
	return contents;
}

void ImageFile::accept(AbstractFileVisitor* A) {
	if (A != nullptr)
		A->visit_ImageFile(this);
	
}
AbstractFile* ImageFile::clone(string str) {
	AbstractFile* newClone = new ImageFile(str);
	newClone->write(contents);
	return newClone;
}