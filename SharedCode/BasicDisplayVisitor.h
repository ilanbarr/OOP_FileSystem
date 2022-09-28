#pragma once
// declaration of BasicDisplayVisitor here
#include "AbstractFileVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"

class BasicDisplayVisitor : public AbstractFileVisitor {
	virtual void visit_TextFile(TextFile* p);
	virtual void visit_ImageFile(ImageFile* p);
};

