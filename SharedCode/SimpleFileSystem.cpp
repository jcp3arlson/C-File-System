/*
SimpleFileSystem.cpp

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Definitions of functions in SimpleFileSystem:
addFile() - Adds a file to this file system
deleteFile() - Removes a file from this file sytem
openFile() - opens the file for operations to be done
closeFile() - closes the file for file protection
getFileNames() - returns a list of the file names in this file system
*/

#include "SimpleFileSystem.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <iostream>

int SimpleFileSystem::addFile(std::string fileName, AbstractFile* file) {
	if (files.find(fileName)!=files.end()) {
		return fileExists;
	}
	if (file==nullptr) {
		return nullFile;
	}
	files.insert(std::pair<std::string, AbstractFile*> (fileName, file) );
	return successs;
}

int SimpleFileSystem::deleteFile(std::string fileName) {
	if (files.find(fileName) == files.end()) {
		return fileDoesNotExist;
	}
	if (openFiles.find(files[fileName]) != openFiles.end()) {
		return fileOpen;
	}
	delete files[fileName];
	files.erase(fileName);
	return 0;

}

AbstractFile* SimpleFileSystem::openFile(std::string fileName) {
	if (files.find(fileName) == files.end()) {
		return nullptr;
	}
	AbstractFile* file = files[fileName];
	if (openFiles.count(file)) {
		return nullptr;
	}
	openFiles.insert(file);
	return file;
}

int SimpleFileSystem::closeFile(AbstractFile* file) {
	if (openFiles.find(file) == openFiles.end()) {
		return fileNotOpen;
	}
	else {
		openFiles.erase(file);
		return 0;
	}
}

std::set<std::string> SimpleFileSystem::getFileNames() {
	std::set<std::string> s;
	for (auto it = files.begin(); it != files.end(); ++it) {
		s.insert(it->first);
	}
	return s;
}
