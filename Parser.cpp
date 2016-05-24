#include "Parser.h"
static struct ParseResult
{
	std::vector<std::string> args;
	std::string name;
	bool success;
};
static struct EnvironmentVariables
{
	std::string name;
	std::string value;
};
Parser::Parser()
{
}


Parser::~Parser()
{
}
void Parser::execute(ParseResult parse) 
{
	for each (CommandGroup var in CommandList)
	{
		//if(var.name == parse.name){
		//var.execute(parse.args);
		//}
	}
}
ParseResult Parser::parse(std::string input)
{
	ParseResult result = ParseResult();
	std::vector<std::string> parts = split(input);
	if (parts.size == 0) {
		result.success = false;
		return result;
	}
	std::vector<std::string> args = range(parts, 1, parts.size - 1);
	for (int i = 0; i < args.size; i++) {
		for each (EnvironmentVariables var in ENV_VAR)
		{
			replace(args[i], "%" + var.name + "%", var.value);
		}
	}
	result.name = parts[0];
	result.args = args;
}
bool replace(std::string& str, const std::string& from, const std::string& to) {
	size_t start_pos = str.find(from);
	if (start_pos == std::string::npos)
		return false;
	str.replace(start_pos, from.length(), to);
	return true;
}
std::vector<std::string> range(std::vector<std::string> input,int begin, int end) {
	using namespace std;
	vector<string> rangeF;
	for (int i = begin; i < end; i++) {
		rangeF.push_back(input[i]);
	}
}
std::vector<std::string> split(std::string input)
{
	using namespace std;
	bool inQ;
	vector<string> splitStr;
	string currPce = "";
	for (int i = 0; i < input.length; i++) {
		if (input.data[i] == '"')
		{
			inQ = !inQ;
		}
		if (inQ) continue;
		if (input.data[i] == ' ') {
			splitStr.push_back(currPce);
			currPce = "";
		}
	}
	return splitStr;
}
