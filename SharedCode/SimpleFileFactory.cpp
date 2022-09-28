// studio 18 - simple file factory definitions
#include "SimpleFileFactory.h"
#include "TextFile.h"
#include "ImageFile.h"

AbstractFile* SimpleFileFactory::createFile(string name) {
	
			int a = name.find(".");
			string ext = "";
			for (int i = a + 1; i < name.length(); i++) {
				ext += name[i];

			}
			if (ext == "txt") {
				AbstractFile* newText = new TextFile(name);
				return newText;
			}
			if (ext == "img") {
				AbstractFile* newImg = new ImageFile(name);
				return newImg;
			}
			else return nullptr;
}

