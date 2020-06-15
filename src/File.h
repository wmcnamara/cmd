 #pragma once
#include <string>
#include <filesystem>
#include "SDL.h"

namespace fs = std::filesystem;

class File
{
public:
	//Returns true if file exists at path.
	static bool FileExists(std::string directory) { return fs::exists(directory); }

private:
};