#include "Application.h"
#include <iostream>
#include "Image.h"
#include "FileIO.h"

Application::Application()
{
}

void Application::Run()
{
	std::string inputStr;
	std::cout << "Pleae enter the output directory and file name: ";
	std::cin >> inputStr;

	Image image = Image(255, 255);
	for (unsigned int y = 0; y < image.get_height(); y++)
	{
		for (unsigned int x = 0; x < image.get_width(); x++)
		{
			image.add_pixel(x, y, glm::vec3((x + y) / 2, (x + y) / 2, (x + y) / 2));
		}
	}

	FileIO::getInstance()->outputPPM(&image, inputStr);
}
