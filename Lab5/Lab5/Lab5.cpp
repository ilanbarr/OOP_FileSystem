// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "H:\332Work\STUD16\SharedCode\Inlcusions.h"
//#include "H:\Lab5\SharedCode\Inlcusions.h"

int main()
{
	AbstractFileSystem* theSystem = new SimpleFileSystem;
	AbstractFileFactory* theFac = new SimpleFileFactory;
	AbstractCommand* theCom = new TouchCommand(theSystem,theFac);
	AbstractCommand* disp = new DisplayCommand(theSystem);
	AbstractCommand* remove = new RemoveCommand(theSystem);
	AbstractCommand* LS = new LSCommand(theSystem);
	AbstractCommand* cop = new CopyCommand(theSystem);
	AbstractCommand* catt = new CatCommand(theSystem);
	AbstractCommand* cldel = new CatCommand(theSystem);


	MacroCommand* mac = new MacroCommand(theSystem);
	MacroCommand* mactual = new MacroCommand(theSystem);
	mac->addCommand(cop);
	mac->addCommand(cldel);
	mactual->addCommand(theCom);
	mac->addCommand(remove);
	mactual->addCommand(catt);
	mactual->setParseStrategy(new RenameParsingStrategy());
	mac->setParseStrategy(new RenameParsingStrategy());
	AbstractCommand* real = mac;
	AbstractCommand* real2 = mactual;
	CommandPrompt nowCom;
	nowCom.setFileSystem(theSystem);
	nowCom.setFileFactory(theFac);
	nowCom.addCommand("theCom", theCom);
	nowCom.addCommand("disp", disp);
	nowCom.addCommand("remove", remove);
	nowCom.addCommand("cop", cop);
	nowCom.addCommand("catt", catt);
	nowCom.addCommand("cldel", cldel);
	nowCom.run();

	return 0;
}


