/*
BasicDisplayVisitor.cpp

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Definitions of functions in BasicDisplayVisitor:
visit_TextFile() - prints the contents of the text file
visit_ImageFile() - prints the contents of the image file formatted as an image (not raw data)
*/

#include "BasicDisplayVisitor.h"

void BasicDisplayVisitor::visit_TextFile(TextFile* tFile) {
	std::vector<char> cont = tFile->read();
	for (char c : cont) {
		std::cout << c;
	}
	std::cout << std::endl;
}

void BasicDisplayVisitor::visit_ImageFile(ImageFile* file) {

	std::vector<char> contents = file->read();
    unsigned int size = sqrt(file->getSize());
    
	for (int y = size-1; y >= 0; --y) {
		for (int x = 0; x < size; ++x) {
			std::cout << contents[y*size + x];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
