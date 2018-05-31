#pragma once
#include<iostream>
#include "RobotPosition.h"

class DllExport Robot
{
	// constructor & destructor
public:
	Robot();
	~Robot();

	// operations
public:
	// place the robot to the given position if it is a valid position
	bool Place(RobotPosition pos);

	// set the position property
	void SetPosition(RobotPosition pos);

	// check if the initial position has been placed
	bool IsPositionPlaced() const { return bPositionPlaced; }

	// move towards the currect direction by one unit while sitll remains within the tabletop
	bool Move();

	// turn the direction to the left
	void TurnLeft();

	// turn the direction to the right
	void TurnRight();

	// return reference to its position
	const RobotPosition& GetPosition() const { return position; }

private:
	RobotPosition position;

	bool bPositionPlaced;
};
