// definitions of basic display visitor here
#pragma once
#include "BasicDisplayVisitor.h"
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>

void BasicDisplayVisitor::visit_TextFile(TextFile* p) {
	if (p != nullptr) {
		for (int i = 0; i < p->getSize(); i++) {
			cout << p->read()[i];
	}

	}
}
void BasicDisplayVisitor::visit_ImageFile(ImageFile* p) {
	if (p != nullptr) {
	//	char temp = p->read()[p->getSize()-1];
		int size = p->getImgSize();
		int lineTracker = 0;
		int i = 0;
		//temp = temp - 48;
		unsigned int tt = p->getSize();
		while (i < tt) {
			cout << p->read()[i];// * size + tt];
			// for (int k = 0; k < size; ++k) {
			i++;
				 if (lineTracker == size - 1) {
					 lineTracker = 0;
					 cout << endl;
					 
				 }
				 else {
					 lineTracker++;
				 }
			

		}

		/*cout << endl;
		i++;*/

		//	}
	}
}


