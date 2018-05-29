#include "pch.h"
#include "../Models/RobotPosition.h"
#include "../Models/Robot.h"

TEST(TestRobotPosition, TestPositionTurn) {
  // test a robot position shall be initialised to the north direction
  RobotPosition position;
  EXPECT_EQ(position.GetDirection(), RobotPosition::NORTH);

  // test turn left from north shall end up facing the west
  position.TurnLeft();
  EXPECT_EQ(position.GetDirection(), RobotPosition::WEST);

  // test turn left from west shall end up facing the south
  position.TurnLeft();
  EXPECT_EQ(position.GetDirection(), RobotPosition::SOUTH);

  // test turn left from south shall end up facing the east
  position.TurnLeft();
  EXPECT_EQ(position.GetDirection(), RobotPosition::EAST);

  // test turn left from east shall end up facing the north
  position.TurnLeft();
  EXPECT_EQ(position.GetDirection(), RobotPosition::NORTH);
}

TEST(TestRobot, TestRobotInitialPosition)
{
	Robot robot;

	const RobotPosition& position = robot.GetPosition();

	// test that a robot shall be initially put in to the position of (0, 0) and facing north
	EXPECT_EQ(position.GetX(), 0);
	EXPECT_EQ(position.GetY(), 0);
	EXPECT_EQ(position.GetDirection(), RobotPosition::NORTH);
}

void TestInvalidRobotPlace(Robot& robot, RobotPosition& newPosition, int x, int y)
{
	// record the orginal position of the robot
	RobotPosition orgPosition(robot.GetPosition());

	// set up the proposed new position
	newPosition.SetX(x);
	newPosition.SetY(y);

	// this shall be unsuccessful
	EXPECT_EQ(false, robot.Place(newPosition));

	// the robot's position shall stay the same
	EXPECT_EQ(orgPosition.GetX(), robot.GetPosition().GetX());
	EXPECT_EQ(orgPosition.GetY(), robot.GetPosition().GetY());
}

void TestValidRobotPlace(Robot& robot, RobotPosition& newPosition, int x, int y)
{
	// set up the proposed new position
	newPosition.SetX(x);
	newPosition.SetY(y);

	// this shall be unsuccessful
	EXPECT_EQ(true, robot.Place(newPosition));

	// the robot's position shall stay the same
	EXPECT_EQ(x, robot.GetPosition().GetX());
	EXPECT_EQ(y, robot.GetPosition().GetY());
}

TEST(TestRobot, TestRobotPlaceInvalid)
{
	// a robot
	Robot robot;

	// the position the robot is to be moved to
	RobotPosition position;

	//////////////////////////////
	// invalid positions

	// invalid x coordinate
	int x = -1;
	for (int y = 0; y <= 5; ++y)
	{
		TestInvalidRobotPlace(robot, position, x, y);
	}

	x = 6;
	for (int y = 0; y <= 5; ++y)
	{
		TestInvalidRobotPlace(robot, position, x, y);
	}
	
	// invalid y coordinate
	int y = -1;
	for (int x = 0; x <= 5; ++x)
	{
		TestInvalidRobotPlace(robot, position, x, y);
	}

	y = 6;
	for (int x = 0; x <= 5; ++x)
	{
		TestInvalidRobotPlace(robot, position, x, y);
	}

	// x & y coordinates both invalid
	TestInvalidRobotPlace(robot, position, -1, -1);
	TestInvalidRobotPlace(robot, position, 6, 6);
}

TEST(TestRobot, TestRobotPlaceValid)
{
	// a robot
	Robot robot;

	// the position the robot is to be moved to
	RobotPosition position;

	//////////////////////////////
	// valid positions
	for (int x = 0; x <= 5; ++x)
	{
		for (int y = 0; y <= 5; ++y)
		{
			TestValidRobotPlace(robot, position, x, y);
		}
	}
}