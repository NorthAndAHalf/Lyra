#pragma once

#include <string>
#include "Image.h"

class FileIO
{
public:
	static FileIO* getInstance();

	bool outputPPM(Image* image, std::string path);

private:
	static FileIO* instance;
	FileIO();
};