/*
PasswordProxy.cpp

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Defintions of functions in PasswordProxy:
PasswordProxy() - creates a new PasswordProxy object with variables File(abstractFile*) and password(string)
~PasswordProxy() - deletes the abstractFile* and the PasswordProxy object
getSize() - returns passwordProxy's file variable(abstractfile*) called with the getSize() function
getName() - returns passwordProxy's file variable(abstractfile*) called with the getName() function
write() - calls password prompt and if the user enters the correct password, writes to passwordProxy's file variable(abstractfile*) or returns a fail code if the password is incorrect
append() - calls password prompt and if the user enters the correct password, appends to passwordProxy's file variable(abstractfile*) or returns a fail code if the password is incorrect
read() - calls password prompt and if the user enters the correct password, reads passwordProxy's file variable(abstractfile*) and returns its contents(vector<char>)or returns a fail code if the password is incorrect
accept() - calls password prompt and if the user enters the correct password, calles accept with passwordProxy's file variable(abstractfile*) else returns an incorrect password fail
passwordPrompt() - prompts the user to enter a password and reutrns the input of the user as a string
copy() - copys a passwordProxy to a new passwordProxy with the same password variable
*/


#include "PasswordProxy.h"
#include <iostream>

PasswordProxy::PasswordProxy(AbstractFile* File, std::string Password) : file(File), password(Password) {};

PasswordProxy::~PasswordProxy() {
	delete file;
}

unsigned int PasswordProxy::getSize() {
	return file->getSize();
};

std::string PasswordProxy::getName() {
	return file->getName();
};

int PasswordProxy::write(std::vector<char> vec) {
	if (passwordPrompt() == password) {
		return file->write(vec);
	}
	else {
		return passwordFail;
	}
	
	
};

int PasswordProxy::append(std::vector<char> vec) {
	if (passwordPrompt() == password) {
		return file->append(vec);
	}
	else {
		return passwordFail;
	}
};

std::vector<char> PasswordProxy::read() {
	if (passwordPrompt() == password) {
		return file->read();
	}
	else {
		std::vector<char> vec;
		return vec;
	}
};

void PasswordProxy::accept(AbstractFileVisitor* fileVis) {
	if (passwordPrompt() == password) {
		file->accept(fileVis);
	}
};

std::string PasswordProxy::passwordPrompt() {
	std::string str;
	std::cout << "You must enter a password to access or alter " << file->getName() << ": ";
	std::getline(std::cin, str);
	return str;

};

AbstractFile* PasswordProxy::copy(std::string name) {
		AbstractFile* filePtr = file->copy(name);
		return new PasswordProxy(filePtr, this->password);
}