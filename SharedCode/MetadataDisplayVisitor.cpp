// definitions of metadata visitor here
#include "MetadataDisplayVisitor.h"

void MetadataDisplayVisitor::visit_TextFile(TextFile* p) {
	string fName = p->getName();

	unsigned int fSize = p->getSize();
	cout << fName  ;
	cout << " text " ;
	cout << fSize <<endl;
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* p) {
	string fName = p->getName();
	unsigned int fSize = p->getSize();
	cout  << fName  ;
	cout << " image "  ;
	cout  << fSize << endl;
	

}