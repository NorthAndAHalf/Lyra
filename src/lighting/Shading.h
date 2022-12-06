#pragma once
#include "glm/vec3.hpp";
#include "Intersection.h"
#include "Light.h"

glm::vec3 phong_reflect(Intersection* intersection, Light* light, float ai, float smoothness);
