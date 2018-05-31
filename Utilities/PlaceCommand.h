#pragma once
#include "Command.h"

class DllExport PlaceCommand : public Command
{
public:
	PlaceCommand();
	~PlaceCommand();

public:
	virtual bool Execute(Robot* robot);

	void SetPosition(RobotPosition pos);
	RobotPosition& GetPosition() { return position; }

private:
	RobotPosition position;
};
