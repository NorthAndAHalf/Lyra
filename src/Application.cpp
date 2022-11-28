#include "Application.h"
#include <iostream>
#include "Image.h"

Application::Application()
{
}

void Application::Run()
{
	Image image = Image(5, 5);
	image.add_pixel(1, 1, glm::vec3(5, 2, 5));
	image.add_pixel(2, 3, glm::vec3(6, 2, 6));
	while (true)
	{
		std::cout << image.get_pixel(2, 3).x << image.get_pixel(2, 3).y << image.get_pixel(2, 3).z << std::endl;
		std::cout << image.get_pixel(2, 3).x << image.get_pixel(2, 3).y << image.get_pixel(2, 3).z << std::endl;
		std::cout << image.get_pixel(1, 1).x << image.get_pixel(1, 1).y << image.get_pixel(1, 1).z << std::endl;
	}
}
