// Studio21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/TouchCommand.h"
#include "../../SharedCode/CommandPrompt.h"
#include "../../SharedCode/AbstractCommand.h"
#include <iostream>

int main()
{
	SimpleFileSystem* system = new SimpleFileSystem();
	SimpleFileFactory* factory = new SimpleFileFactory();
	AbstractCommand* touch = new TouchCommand(system, factory);
	CommandPrompt prompt = CommandPrompt();
	prompt.setFileFactory(factory);
	prompt.setFileSystem(system);
	prompt.addCommand("touch", touch);
	prompt.run();

	AbstractFile* file = system->openFile("something.txt");
	if (file) {
		std::cout << "success" << std::endl;
	}
	else {
		std::cout << "fail" << std::endl;
	}

	return 0;
}

