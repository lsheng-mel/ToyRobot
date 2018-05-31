#include "ReportCommand.h"

ReportCommand::ReportCommand()
	:Command()
{

}

ReportCommand::~ReportCommand()
{

}

bool ReportCommand::Execute(Robot* robot)
{
	// call the funciton inherited from the parent class to make sure its position has been placed
	if (!__super::Execute(robot))
		return false;

	if (robot)
	{
		const RobotPosition& position(robot->GetPosition());

		// report the current position
		std::cout << position.GetX() << "," << position.GetY() << "," << position.GetDirectionStr() << "\n";
		return true;
	}

	return false;
}