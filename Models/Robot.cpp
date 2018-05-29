#include "Robot.h"

Robot::Robot()
{
}

Robot::~Robot()
{

}

bool Robot::Place(RobotPosition pos)
{
	// validate the new position before moving
	if (pos.IsValid())
	{
		position = pos;
		return true;
	}

	return false;
}

bool Robot::Move()
{
	// move from the current position
	RobotPosition newPosition(position);

	// work out the movement based on the direction
	switch (position.GetDirection())
	{
	case RobotPosition::NORTH:
		newPosition.SetY(newPosition.GetY() + 1);
		break;
	case RobotPosition::SOUTH:
		newPosition.SetY(newPosition.GetY() - 1);
		break;
	case RobotPosition::WEST:
		newPosition.SetX(newPosition.GetX() - 1);
		break;
	case RobotPosition::EAST:
		newPosition.SetX(newPosition.GetX() + 1);
		break;
	default:
		break;
	}

	// update the position
	if (newPosition.IsValid())
	{
		position = newPosition;
		return true;
	}
		
	return false;
}

void Robot::TurnLeft()
{
	position.TurnLeft();
}

void Robot::TurnRight()
{
	position.TurnRight();
}

void Robot::Report()
{
	std::cout << position.GetX() << "," << position.GetY() << "," << position.GetDirectionStr();
}