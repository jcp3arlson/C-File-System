// Studio17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\AbstractFile.h"
#include "..\..\\SharedCode\TextFile.h"
#include "..\..\\SharedCode\ImageFile.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include <iostream>


using namespace std;


int main()
{

	AbstractFile& img = ImageFile("image01");
	vector<char> v;
	v.push_back('X');
	v.push_back('X');
	v.push_back(' ');
	v.push_back('X');
	v.push_back('2');
	img.write(v);
	img.read();

	SimpleFileSystem fileSystem;
	fileSystem.addFile("image01.img", &img);
	fileSystem.createFile("file.txt");

	return 0;


}

