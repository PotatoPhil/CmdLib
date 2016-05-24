#pragma once
#include "imports.h"
#include "CommandGroup.h"
class Parser
{
public:
	Parser();
	~Parser();
	bool debug;
	static std::vector<CommandGroup> CommandList;
	static std::vector<EnvironmentVariables> ENV_VAR;
	static void start();
private:
	void parseAndExecute();
	void execute(ParseResult parse);
	ParseResult parse(std::string input);

};

