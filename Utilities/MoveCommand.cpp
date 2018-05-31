#include "MoveCommand.h"

MoveCommand::MoveCommand()
	:Command()
{

}

MoveCommand::~MoveCommand()
{

}

bool MoveCommand::Execute(Robot* robot)
{
	// call the funciton inherited from the parent class to make sure its position has been placed
	if (!__super::Execute(robot))
		return false;

	if (robot)
	{
		// move step forward
		return robot->Move();
	}

	return false;
}