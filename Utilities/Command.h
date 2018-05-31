#pragma once
#include "../Models/RobotPosition.h"
#include "../Models/Robot.h"

class DllExport Command
{
public:
	Command() {}
	~Command() {}

public:
	virtual bool Execute(Robot* robot)
	{
		// by default, any command needs to check if the robot's position has been placed yet
		if (robot)
		{
			return robot->IsPositionPlaced();
		}

		return false;
	}
};