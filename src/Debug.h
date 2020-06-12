#pragma once
#include <iostream>
#include <string>
#include "SDL.h"

//Prefaces for a log message. Use the one according to the operation you are using.
enum LogType { LOG_MESSAGE, LOG_WARNING, LOG_ERROR, LOG_IO, LOG_INIT, LOG_CREATION };

class Debug
{
public:
	//Prints the latest error thrown by SDL. 
	static void LogSDLError();

	//Logs a string to the console with the LOG_MESSAGE preface.
	static void Log(std::ostream& stream, std::string msg, LogType T);

	//Logs a string to the console. Wrapper of std::cout.
	static void Log(std::ostream& stream, std::string msg)
	{
		stream << "Message: " << msg << std::endl;
	}
};