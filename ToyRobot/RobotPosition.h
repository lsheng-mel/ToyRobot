#pragma once
#include <string>

class RobotPosition
{
	// constructor & destructor
public:
	RobotPosition();
	~RobotPosition();

public:
	enum Direction
	{
		NORTH = 1,
		EAST = 2,
		SOUTH = 3,
		WEST = 4
	};

	// getters
public:
	bool IsValid();

	int GetX() const { return x; }
	int GetY() const { return y; }
	Direction GetDirection() const { return direction; }

	std::string GetDirectionStr();

	void SetX(int val) { x = val; }
	void SetY(int val) { y = val; }
	void SetDirection(Direction dir) { direction = dir; }

public:
	void TurnLeft();
	void TurnRight();

private:
	int x;
	int y;
	Direction direction;
};
