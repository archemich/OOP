#pragma once
class ConsoleInterface
{
public:
	ConsoleInterface() {};
	void run();
	void printMenuText();
	int ReadInt();
	double ReadDouble();

	void prompt();
};

