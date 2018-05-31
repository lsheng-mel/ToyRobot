#include "CommandFactory.h"
#include "PlaceCommand.h"
#include "MoveCommand.h"
#include "ReportCommand.h"
#include "TurnCommand.h"

Command* CommandFactory::CreatePlaceCommand(RobotPosition position)
{
	PlaceCommand* command = new PlaceCommand();
	command->SetPosition(position);
	return command;
}

Command* CommandFactory::CreateMoveCommand()
{
	MoveCommand* command = new MoveCommand();
	return command;
}

Command* CommandFactory::CreateReportCommand()
{
	ReportCommand* command = new ReportCommand();
	return command;
}

Command* CommandFactory::CreateTurnCommand(bool bTurnLeft)
{
	TurnCommand* command = new TurnCommand(bTurnLeft);
	return command;
}