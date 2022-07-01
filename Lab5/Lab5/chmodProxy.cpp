/*
chmodProxy.cpp

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Defintions of functions in chmodProxy:
chmodProxy() - creates a new chmodProxy object with variables File(abstractFile*) and password(string)
~chmodProxy() - deletes the abstractFile* and the chmodProxy object
getSize() - returns chmodProxy's file variable(abstractfile*) called with the getSize() function
getName() - returns chmodProxy's file variable(abstractfile*) called with the getName() function
write() - Attempts to write to the file, first checking whether or not the file is writable
append() - Attempts to append data to the file, first checking whether or not the file is writable
read() - Reads from the file as if it were any normal file
copy() - returns a deep copy of the file
*/


#include "chmodProxy.h"
#include <iostream>

chmodProxy::chmodProxy(AbstractFile* File, bool writeable) : isWriteable(writeable) {
	std::string nm = File->getName();
	nm = nm.substr(0,nm.find_first_of("."));
	file = File->copy(nm);
};

chmodProxy::~chmodProxy() {
	delete file;
}

unsigned int chmodProxy::getSize() {
	return file->getSize();
};

std::string chmodProxy::getName() {
	return file->getName();
};

int chmodProxy::write(std::vector<char> vec) {
	if (isWriteable) {
		return file->write(vec);
	}
	else {
		std::cout << "File is only readable\n";
		return fileOnlyReadable;
	}
};

int chmodProxy::append(std::vector<char> vec) {
	if (isWriteable) {
		return file->append(vec);
	}
	else {
		std::cout << "File is only readable\n";
		return fileOnlyReadable;
	}
};

std::vector<char> chmodProxy::read() {
	return file->read();
};

void chmodProxy::accept(AbstractFileVisitor* fileVis) {
		file->accept(fileVis);
};

AbstractFile* chmodProxy::copy(std::string name) {
	AbstractFile* filePtr = file->copy(name);
	return filePtr;
}