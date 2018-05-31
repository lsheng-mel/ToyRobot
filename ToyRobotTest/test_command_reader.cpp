#include "pch.h"
#include "../Utilities/PlaceCommand.h"
#include "../Utilities/MoveCommand.h"
#include "../Utilities/ReportCommand.h"
#include "../Utilities/TurnCommand.h"
#include "../Utilities/CommandReader.h"
#include "../Models/RobotPosition.h"
#include <string>

using namespace std;

void CheckValidPlaceCommand(string command, int x, int y, RobotPosition::Direction direction)
{
	CommandReader reader(command);

	PlaceCommand* pCommand = dynamic_cast<PlaceCommand*>(reader.GetCommand());
	EXPECT_TRUE(pCommand != nullptr);

	RobotPosition& position(pCommand->GetPosition());
	EXPECT_EQ(x, position.GetX());
	EXPECT_EQ(y, position.GetY());
	EXPECT_EQ(direction, position.GetDirection());
}

void CheckInvalidPlaceCommand(string command)
{
	CommandReader reader(command);

	//PlaceCommand* pCommand = dynamic_cast<PlaceCommand*>(reader.GetCommand());
	//EXPECT_TRUE(pCommand == nullptr);
}

// test if CommandReader interprets valid string into commands correctly
TEST(TestCommandReader, TestValidPlaceCommand)
{
	const string command1("PLACE 1,1,NORTH");
	const string command2("PLACE 2,2,SOUTH");
	const string command3("PLACE 3,3,WEST");
	const string command4("PLACE 4,4,EAST");

	const string command5("place 1,1,north");
	const string command6("place 2,2,south");
	const string command7("place 3,3,west");
	const string command8("place 4,4,east");

	CheckValidPlaceCommand(command1, 1, 1, RobotPosition::NORTH);
	CheckValidPlaceCommand(command2, 2, 2, RobotPosition::SOUTH);
	CheckValidPlaceCommand(command3, 3, 3, RobotPosition::WEST);
	CheckValidPlaceCommand(command4, 4, 4, RobotPosition::EAST);

	CheckValidPlaceCommand(command5, 1, 1, RobotPosition::NORTH);
	CheckValidPlaceCommand(command6, 2, 2, RobotPosition::SOUTH);
	CheckValidPlaceCommand(command7, 3, 3, RobotPosition::WEST);
	CheckValidPlaceCommand(command8, 4, 4, RobotPosition::EAST);
}

// test if CommandReader returns no command if the string is invalid
TEST(TestCommandReader, TestInvalidPlaceCommand)
{
	// typo for "PLACE"
	const string command1("PLAC 1,1,NORTH");
	// typo for direction "NORTH"
	const string command2("PLACE 1,1,NOTH");
	// typo for direction "SOUTH"
	const string command3("PLACE 1,1,SOUH");
	// typo for direction "WEST"
	const string command4("PLACE 1,1,WET");
	// typo for direction "EAST"
	const string command5("PLACE 1,1,EAT");

	// typo for "PLACE"
	const string command6("palc 1,1,NORTH");
	// typo for direction "NORTH"
	const string command7("place 1,1,noth");
	// typo for direction "SOUTH"
	const string command8("place 1,1,souh");
	// typo for direction "WEST"
	const string command9("place 1,1,wet");
	// typo for direction "EAST"
	const string command10("place 1,1,eat");

	CheckInvalidPlaceCommand(command1);
	CheckInvalidPlaceCommand(command2);
	CheckInvalidPlaceCommand(command3);
	CheckInvalidPlaceCommand(command4);
	CheckInvalidPlaceCommand(command5);

	CheckInvalidPlaceCommand(command6);
	CheckInvalidPlaceCommand(command7);
	CheckInvalidPlaceCommand(command8);
	CheckInvalidPlaceCommand(command9);
	CheckInvalidPlaceCommand(command10);
}

void CheckTurnCommand(string command, bool bLeft)
{
	CommandReader reader(command);
	TurnCommand* pCommand = dynamic_cast<TurnCommand*>(reader.GetCommand());

	EXPECT_TRUE(pCommand != nullptr);
	EXPECT_EQ(pCommand->IsTurnLeft(), bLeft);
}

// test if turn command can be interpreted correctly
TEST(TestCommandReader, TestTurnCommand)
{
	const string turnLeft1("LEFT");
	const string turnRight1("RIGHT");

	const string turnLeft2("left");
	const string turnRight2("right");

	// turn left
	CheckTurnCommand(turnLeft1, true);
	CheckTurnCommand(turnLeft2, true);

	// turn right
	CheckTurnCommand(turnRight1, false);
	CheckTurnCommand(turnRight2, false);
}

// test if move command can be interpreted correctly
TEST(TestCommandReader, TestMoveCommand)
{
	const string command1("MOVE");
	const string command2("move");

	// upper case
	CommandReader reader1(command1);
	MoveCommand* pCommand = dynamic_cast<MoveCommand*>(reader1.GetCommand());

	EXPECT_TRUE(pCommand != nullptr);

	// lower case
	CommandReader reader2(command2);
	pCommand = dynamic_cast<MoveCommand*>(reader2.GetCommand());

	EXPECT_TRUE(pCommand != nullptr);
}

// test if report command can be interpreted correctly
TEST(TestCommandReader, TestReportCommand)
{
	const string command1("REPORT");
	const string command2("report");

	// upper case
	CommandReader reader1(command1);
	ReportCommand* pCommand = dynamic_cast<ReportCommand*>(reader1.GetCommand());

	EXPECT_TRUE(pCommand != nullptr);

	// lower case
	CommandReader reader2(command2);
	pCommand = dynamic_cast<ReportCommand*>(reader2.GetCommand());

	EXPECT_TRUE(pCommand != nullptr);

}