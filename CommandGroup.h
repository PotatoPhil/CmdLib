#pragma once
#include "imports.h"
#include "Command.h"
class CommandGroup :
	public std::vector<Command>
{
	std::string _d;
	std::string _x; // Private variable, it can modify in this class directly    
public:
	
	CommandGroup() : name(_x),desc(_d) // Bind reference variable x to _x
	{
	}
	const std::string &desc;
	const std::string &name; // Constant variable
	CommandGroup(std::string name,std::string desc);
	~CommandGroup();
	CommandGroup Add(Command item);
	std::string toString();
	void execute(std::vector<std::string> list);
};

