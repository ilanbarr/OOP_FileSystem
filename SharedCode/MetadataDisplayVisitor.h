#pragma once
// declaration of MetadataDisplayVisitor here
#include "AbstractFileVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"

class MetadataDisplayVisitor : public AbstractFileVisitor {
	virtual void visit_TextFile(TextFile* p);
	virtual void visit_ImageFile(ImageFile* p);
};