#pragma once
#include <string>
#include "Command.h"

//! this class takes a string as the input and interprets it into a command if can be recognised
class DllExport CommandReader
{
public:
	CommandReader(std::string command);
	~CommandReader();

public:
	Command* GetCommand() { return pCommand; }

private:
	// transform the given string to upper case
	void ToUpperString(std::string& command);

	// read the text and interpret the command
	void ReadCommand(std::string& command);

	// read the text and interpret the position represented by it
	bool ReadPosition(std::string strPosition, RobotPosition& position);

public:
	Command * pCommand;
};
