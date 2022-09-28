#pragma once
//#include "ImageFile.h"
//#include "TextFile.h"
// declaration of the file visitor interface here
class ImageFile;
class TextFile;

class AbstractFileVisitor {
public:
	virtual void visit_ImageFile(ImageFile* I) = 0;
	virtual void visit_TextFile(TextFile* T) = 0;
};