#include "TurnCommand.h"

TurnCommand::TurnCommand(bool bTurnLeft)
	: Command(),
	bTurnLeft(bTurnLeft)
{

}

TurnCommand::~TurnCommand()
{

}

bool TurnCommand::Execute(Robot* robot)
{
	// call the funciton inherited from the parent class to make sure its position has been placed
	if (!__super::Execute(robot))
		return false;

	if (robot)
	{
		if (bTurnLeft)
			robot->TurnLeft();
		else
			robot->TurnRight();

		return true;
	}

	return false;
}