#include "Shading.h"

#include <glm/geometric.hpp>
#include <algorithm>

// In the future, adapt this function to be able to work with emmisive objects as well as light objects, idk how emissive objects will work yet
// Future me problem :skull:
// Update: Actually nvm probably since phong reflections are just a first step and I'll be going with actual reflections from now on
// Still need to figure out how emissive objects will work there though

// Specular is fucked I think
glm::vec3 phong_reflect(const Intersection* i, const std::vector<Light*>* lights, float ai, float smoothness)
{
    glm::vec3 finalCol = glm::vec3(0.0);

    for (const Light* l : *lights)
    {
        glm::vec3 lightDir = glm::normalize(i->intersectionPoint - l->colour);

        glm::vec3 ambient = ai * l->colour;
        glm::vec3 diffuse = l->intensity * l->colour * std::max(glm::dot(lightDir, i->normal), 0.0f);

        //Specular
        glm::vec3 viewDir = i->rayDir * -1.0f;
        glm::vec3 reflectDir = lightDir - 2 * glm::dot(lightDir, i->normal) * i->normal;
        glm::vec3 specular = l->intensity * l->colour * std::pow(std::max(glm::dot(viewDir, reflectDir), 0.0f), smoothness) * 5.0f;

        finalCol += (ambient + diffuse) + specular;
    }

    return i->colour * finalCol;
}

glm::vec3 flat_colour(const Intersection& intersection)
{
    return intersection.colour;
}