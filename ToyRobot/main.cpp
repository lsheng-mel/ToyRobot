#include<iostream>
#include<String>

#include "../Models/Robot.h"
#include "../Utilities/Command.h"
#include "../Utilities/CommandReader.h"

using namespace std;

int main(int argc, char *argv[])
{
	Robot robot;

	string command;
	do
	{
		// prompt user to input the next command
		cout << "Please type your command (exit to quit the program):\n";
		getline(cin, command);

		if (command.compare("exit") == 0)
			break;

		if (command != "")
		{
			CommandReader reader(command);

			Command* pCommand = reader.GetCommand();
			if (pCommand)
			{
				pCommand->Execute(&robot);
			}
		}
	} while (true);
}