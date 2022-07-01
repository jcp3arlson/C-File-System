// Studio20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\SharedCode\PasswordProxy.h"
#include "..\..\SharedCode\AbstractFile.h"
#include "..\..\SharedCode\TextFile.h"
#include <iostream>

using namespace std;

int main()
{
	AbstractFile* f = new TextFile("txtfile");
	AbstractFile* proxy = new PasswordProxy(f, "1234");
	cout << proxy->getName() << endl;
	vector<char> vec;
	vec.push_back('h');
	vec.push_back('e');
	vec.push_back('l');
	vec.push_back('l');
	vec.push_back('o');
	vec.push_back(' ');
	vec.push_back('w');
	
	proxy->write(vec);

	vec = proxy->read();
	for (char c: vec) {
		cout << c;
	}
	

	return 0;
}

