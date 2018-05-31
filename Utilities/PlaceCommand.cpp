#include "PlaceCommand.h"

PlaceCommand::PlaceCommand()
	:Command()
{

}

PlaceCommand::~PlaceCommand()
{

}

bool PlaceCommand::Execute(Robot* robot)
{
	if (robot)
	{
		return robot->Place(position);
	}

	return false;
}

void PlaceCommand::SetPosition(RobotPosition pos)
{
	position = pos;
}
