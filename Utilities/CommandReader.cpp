#include "CommandReader.h"
#include "CommandFactory.h"
#include "../Models/RobotPosition.h"

using namespace std;

CommandReader::CommandReader(string command)
	: pCommand(nullptr)
{
	ReadCommand(command);
}

CommandReader::~CommandReader()
{

}

bool CommandReader::ReadPosition(std::string strPosition, RobotPosition& position)
{
	const string delimiter = ",";

	vector<string> vecInfo;

	size_t pos = 0;
	string token;
	while ((pos = strPosition.find(delimiter)) != string::npos) {
		token = strPosition.substr(0, pos);
		vecInfo.push_back(token);
		strPosition.erase(0, pos + delimiter.length());
	}

	vecInfo.push_back(strPosition);

	if (vecInfo.size() == 3)
	{
		// TODO - validation against the tokens
		int x = stoi(vecInfo[0]);
		int y = stoi(vecInfo[1]);

		RobotPosition::Direction direction(RobotPosition::NORTH);

		string dir(vecInfo[2]);
		if (dir.compare("NORTH") == 0)
		{
			direction = RobotPosition::NORTH;
		}
		else if (dir.compare("SOUTH") == 0)
		{
			direction = RobotPosition::SOUTH;
		}
		else if (dir.compare("WEST") == 0)
		{
			direction = RobotPosition::WEST;
		}
		else if (dir.compare("EAST") == 0)
		{
			direction = RobotPosition::EAST;
		}
		else
		{
			return false;
		}

		position.SetX(x);
		position.SetY(y);
		position.SetDirection(direction);
		return true;
	}

	return false;
}

void CommandReader::ToUpperString(string& command)
{
	for (int i = 0; i < command.length(); ++i)
	{
		command[i] = toupper(command[i]);
	}
}

void CommandReader::ReadCommand(string& command)
{
	const string place("PLACE");
	const string move("MOVE");
	const string report("REPORT");
	const string left("LEFT");
	const string right("RIGHT");

	// make the command text capital
	ToUpperString(command);

	size_t idx(command.find(place));
	if (idx != string::npos)
	{
			string strPosition(command);
			strPosition.erase(idx, place.length());

			RobotPosition position;
			if (ReadPosition(strPosition, position))
			{
				pCommand = CommandFactory::CreatePlaceCommand(position);
			}
	}
	else if (command.compare(move) == 0)
	{
		pCommand = CommandFactory::CreateMoveCommand();
	}
	else if(command.compare(report) == 0)
	{
		pCommand = CommandFactory::CreateReportCommand();
	}
	else if (command.compare(left) == 0)
	{
		pCommand = CommandFactory::CreateTurnCommand(true);
	}
	else if (command.compare(right) == 0)
	{
		pCommand = CommandFactory::CreateTurnCommand(false);
	}
}