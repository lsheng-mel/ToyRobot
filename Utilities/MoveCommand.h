#pragma once
#include "Command.h"

class DllExport MoveCommand : public Command
{
public:
	MoveCommand();
	~MoveCommand();

public:
	virtual bool Execute(Robot* robot);
};
