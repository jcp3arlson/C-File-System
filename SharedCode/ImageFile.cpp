/*
ImageFile.cpp

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Definitions of functions in ImageFile:
getSize() - returns the size of the image file
getName() - returns the name of the image file
write() - accepts a vector of chars and and chages image file variable contents(vector<char>) to be set to the new parameter vector of chars
append() - returns an error, image files cannot be appended
read() - returns image file variable contents(vector<char>) to be printed out
copy() - returns a deep copy of imagefile as a new abstractFile*
*/

#include "ImageFile.h"
#include "AbstractFileVisitor.h"
#include <iostream>
#include <cmath>

ImageFile::ImageFile(std::string Name) : name(Name) {};

unsigned int ImageFile::getSize() {
	unsigned int a = contents.size();
	return a;
}

std::string ImageFile::getName() {
	return name;
}

int ImageFile::write(std::vector<char> newContents) {
	size = newContents.back() - '0';
	newContents.pop_back();
	if (newContents.size() != size * size) {
		size = 0;
		contents.clear();
		return wrongSize;
	}
	for (char c : newContents) {
		if (!(c == 'X' || c == ' ')) {
			size = 0;
			contents.clear();
			return badChar;
		}
		
	}
	contents = newContents;
	return successs;
}

int ImageFile::append(std::vector<char> add) {
	return illegalProccess;
}

std::vector<char> ImageFile::read() {
	return contents;
}

void ImageFile::accept(AbstractFileVisitor* visitor) {
	visitor->visit_ImageFile(this);
}

AbstractFile* ImageFile::copy(std::string name) {
	name = name.append(".img");
	ImageFile* img = new ImageFile(name);
	std::vector<char> newContents;
	for (char c : this->contents) {
		newContents.push_back(c);
	}
	char size = sqrt(this->getSize()) + '0';
	newContents.push_back(size);
	img->write(newContents);
	return img;
}