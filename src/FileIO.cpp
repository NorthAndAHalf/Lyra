#include "FileIO.h"

#include <iostream>
#include <fstream>

FileIO* FileIO::instance = 0;

FileIO* FileIO::getInstance()
{
	if (instance == 0)
	{
		instance = new FileIO();
	}

	return instance;
}

bool FileIO::outputPPM(Image* image, std::string path)
{
	std::ofstream fw(path, std::ofstream::out);

	if (fw.is_open())
	{
		fw << "P3" << "\n" << image->get_width() << " " << image->get_height() << "\n255\n";

		for (unsigned int y = 0; y < image->get_height(); y++)
		{
			for (unsigned int x = 0; x < image->get_width(); x++)
			{
				glm::vec3 pixel = image->get_pixel(x, y);
				fw << (int)(pixel.x * 255.0f) << " " << (int)(pixel.y * 255.0f) << " " << (int)(pixel.z * 255.0f) << "\n";
			}
		}
		fw.close();
		return true;
	}
	else
	{
		std::cout << "Couldn't open or create PPM file :(" << std::endl;
		return false;
	}
}

FileIO::FileIO()
{}