#pragma once
#include<iostream>
#include "RobotPosition.h"

class Robot
{
	// constructor & destructor
public:
	Robot();
	~Robot();

	// operations
public:
	bool Place(RobotPosition pos);

	// move towards the currect direction by one unit while sitll remains within the tabletop
	bool Move();

	// turn the direction to the left
	void TurnLeft();

	// turn the direction to the right
	void TurnRight();

	// report the robot's current position
	void Report();

private:
	RobotPosition position;
};
