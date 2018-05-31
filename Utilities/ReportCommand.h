#pragma once
#include "Command.h"

class DllExport ReportCommand :public Command
{
public:
	ReportCommand();
	~ReportCommand();

public:
	virtual bool Execute(Robot* robot);
};
