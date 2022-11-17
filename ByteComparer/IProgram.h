#pragma once

class IProgram
{
public:
	virtual ~IProgram() {};
	virtual void run() = 0;
	virtual void compare() = 0;
	virtual void loadData() = 0;
	virtual void processResult() = 0;
	virtual bool wantToExit() = 0;
};