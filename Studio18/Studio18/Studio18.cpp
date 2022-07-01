// Studio18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/SimpleFileSystem.h"


using namespace std;

int main()
{
	AbstractFileSystem* fs = new SimpleFileSystem();
	AbstractFileFactory* cf = new SimpleFileFactory();

	fs->addFile("text.txt", cf->createFile("text.txt"));

	AbstractFile* tf = fs->openFile("text.txt");
	vector<char> vc;
	vc.push_back('h');
	tf->write(vc);
	tf->read();

	return 0;
}
