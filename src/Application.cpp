#include "Application.h"
#include <iostream>
#include "Image.h"
#include "FileIO.h"
#include <Windows.h>
#include "Camera.h"
#include "Scene.h"
#include "hittables/Sphere.h"

Application::Application()
{
}

void Application::Run()
{
	std::string inputStr;
	std::cout << "Please enter the output directory and file name: ";
	std::cin >> inputStr;

	Camera camera = Camera(1.0, glm::vec3(0.0), glm::vec3(0.0, 0.0, -1.0));
	Scene scene = Scene(&camera);
	Sphere* sphere = new Sphere(glm::vec3(0.0, 0.0, -2.0), 0.5, glm::vec3(0.7, 0.0, 1.0));
	scene.add_hittable(sphere);
	Image image = scene.Render(1000, 1000);
	delete sphere;

	bool output = FileIO::getInstance()->outputPPM(&image, inputStr);

	// Opens the image file in the system default viewer if the write was successful
	if (output)
	{
		std::wstring stemp = std::wstring(inputStr.begin(), inputStr.end()); // ShellExecute needs some weird type of string idk I got this from stack overflow
		ShellExecute(0, 0, stemp.c_str(), 0, 0, SW_SHOW);
	}
}
