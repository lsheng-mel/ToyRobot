#include "RobotPosition.h"

RobotPosition::RobotPosition()
{
	x = 0;
	y = 0;
	direction = NORTH;
}

RobotPosition::~RobotPosition() 
{
}

bool RobotPosition::IsValid()
{
	const int min(0);
	const int max(5);

	if (x < min || x > max || y < min || y > max)
		return false;

	return true;
}

void RobotPosition::TurnLeft()
{
	int nDirection = static_cast<int>(direction);
	nDirection--;

	if (nDirection < NORTH)
	{
		direction = WEST;
	}
	else
	{
		direction = static_cast<Direction>(nDirection);
	}
}

void RobotPosition::TurnRight() 
{
	int nDirection = static_cast<int>(direction);
	nDirection++;

	if (nDirection > WEST)
	{
		direction = NORTH;
	}
	else
	{
		direction = static_cast<Direction>(nDirection);
	}
}

std::string RobotPosition::GetDirectionStr()
{
	std::string strDirection("");

	switch (direction)
	{
	case RobotPosition::NORTH:
		strDirection = "NORTH";
		break;
	case RobotPosition::EAST:
		strDirection = "EAST";
		break;
	case RobotPosition::SOUTH:
		strDirection = "SOUTH";
		break;
	case RobotPosition::WEST:
		strDirection = "WEST";
		break;
	default:
		break;
	}

	return strDirection;
}