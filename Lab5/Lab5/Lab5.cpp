/*
Lab5.cpp

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

This file contains the Main function that will create a run a file 
system then clean up all data to avoid memory leakas of any kind.
*/
#include "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/TouchCommand.h"
#include "../../SharedCode/CommandPrompt.h"
#include "../../SharedCode/AbstractCommand.h"
#include "../../SharedCode/LSCommand.h"
#include "../../SharedCode/RemoveCommand.h"
#include "../../SharedCode/DisplayCommand.h"
#include "../../SharedCode/CatCommand.h"
#include "../../SharedCode/CopyCommand.h"
#include "../../SharedCode/RenameParsingStrategy.h"
#include "../../SharedCode/MacroCommand.h"
#include "TouchCatParsingStrategy.h"
#include "chmodCommand.h"
#include <iostream>

int main()
{
	SimpleFileSystem* system = new SimpleFileSystem();
	SimpleFileFactory* factory = new SimpleFileFactory();
	AbstractCommand* touch = new TouchCommand(system, factory);
	AbstractCommand* ls = new LSCommand(system);
	AbstractCommand* rm = new RemoveCommand(system);
	AbstractCommand* ds = new DisplayCommand(system);
	AbstractCommand* cat = new CatCommand(system);
	AbstractCommand* cp = new CopyCommand(system);
	MacroCommand* rn = new MacroCommand();
	rn->addCommand(cp);
	rn->addCommand(rm);
	RenameParsingStrategy* rps = new RenameParsingStrategy();
	rn->setParseStrategy(rps);
	MacroCommand* tc = new MacroCommand();
	tc->addCommand(touch);
	tc->addCommand(cat);
	TouchCatParsingStrategy* tcps = new TouchCatParsingStrategy();
	tc->setParseStrategy(tcps);
	AbstractCommand* chmod = new chmodCommand(system);
	CommandPrompt prompt = CommandPrompt();
	prompt.setFileFactory(factory);
	prompt.setFileSystem(system);
	prompt.addCommand("touch", touch);
	prompt.addCommand("ls", ls);
	prompt.addCommand("rm", rm);
	prompt.addCommand("ds", ds);
	prompt.addCommand("cat", cat);
	prompt.addCommand("cp", cp);
	prompt.addCommand("rn", rn);
	prompt.addCommand("tc", tc);
	prompt.addCommand("chmod", chmod);
	prompt.run();
	std::set<std::string> files = system->getFileNames();
	for (std::string fileName : files) {
		system->deleteFile(fileName);
	}
	delete system;
	delete factory;
	delete touch;
	delete ls;
	delete rm;
	delete ds;
	delete cat;
	delete cp;
	delete rn;
	delete rps;
	delete tc;
	delete tcps;
	delete chmod;
	return 0;
}


