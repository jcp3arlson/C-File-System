/*
TextFile.cpp

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Defintions of functions in textFile:
textfile() - default constructor for a textfile with variable Name(string)
getName() - returns textfiles name variable (string)
write() - accepts a vector of chars and and chages textFile variable contents(vector<char>) to be set to the new parameter vector of chars 
append() - accepts a vector of chars and appendsd it to textFile variable contents(vector<char>)
read() - returns textFile variable contents(vector<char>)
copy() - returns a deep copy of texfile as a new abstractFile*
*/

#include "TextFile.h"
#include "AbstractFileVisitor.h"
#include <iostream>

TextFile::TextFile(std::string Name) : name(Name) {};

unsigned int TextFile::getSize() {
	unsigned int a = contents.size();
	return a;
}

std::string TextFile::getName() {
	return name;
}

int TextFile::write(std::vector<char> newContents) {
	contents = newContents;
	return 0;
}

int TextFile::append(std::vector<char> add) {
	contents.insert(contents.end(), add.begin(), add.end());
	return 0;
}

std::vector<char> TextFile::read() {
	return contents;
}

void TextFile::accept(AbstractFileVisitor* visitor) {
	visitor->visit_TextFile(this);
}

AbstractFile* TextFile::copy(std::string name) {
	name = name.append(".txt");
	AbstractFile* text = new TextFile(name);
	text->write(this->contents);
	return text;
}