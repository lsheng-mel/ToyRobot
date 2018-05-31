#pragma once
#include "Command.h"

class DllExport TurnCommand : public Command
{
public:
	TurnCommand(bool bTurnLeft);
	~TurnCommand();

public:
	virtual bool Execute(Robot* robot);

	bool IsTurnLeft() const { return bTurnLeft; }

private:
	bool bTurnLeft;
};
