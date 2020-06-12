#include "Debug.h"

void Debug::LogSDLError()
{
	std::cout << "SDL Error: " << SDL_GetError() << std::endl;
}

void Debug::Log(std::ostream & stream, std::string msg, LogType T)
{
	switch (T)
	{
		case LOG_MESSAGE:
			stream << "Message: " << msg << std::endl;
			break;
		case LOG_WARNING:
			stream << "Warning: " << msg << std::endl;
			break;
		case LOG_ERROR:
			stream << "Error: " << msg << std::endl;
			break;
		case LOG_IO:
			stream << "File IO: " << msg << std::endl;
			break;
		case LOG_INIT:
			stream << "Init: " << msg << std::endl;
			break;
		case LOG_CREATION:
			stream << "Creation: " << msg << std::endl;
			break;
	}
}
