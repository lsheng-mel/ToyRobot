#pragma once
#include <vector>
#include "../Models/RobotPosition.h"

class Command;

//! this is the factory that generates varies types of commands objects
class DllExport CommandFactory {
public:
	static Command* CreatePlaceCommand(RobotPosition position);
	static Command* CreateMoveCommand();
	static Command* CreateReportCommand();
	static Command* CreateTurnCommand(bool bTurnLeft);
};
