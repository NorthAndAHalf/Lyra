#include "Shading.h"

#include <glm/geometric.hpp>
#include <algorithm>

// In the future, adapt this function to be able to work with emmisive objects as well as light objects, idk how emissive objects will work yet
// Future me problem :skull:

glm::vec3 phong_reflect(Intersection* i, Light* light, float ai, float smoothness)
{
    glm::vec3 lightDir = glm::normalize(i->intersectionPoint - light->colour);

    glm::vec3 ambient = ai * light->colour;
    glm::vec3 diffuse = light->intensity * light->colour * std::max(glm::dot(lightDir, i->normal), 0.0f);

    //Specular
    glm::vec3 viewDir = i->rayDir * -1.0f;
    glm::vec3 reflectDir = lightDir - 2 * glm::dot(lightDir, i->normal) * i->normal;
    glm::vec3 specular = light->intensity * light->colour * std::pow(std::max(glm::dot(viewDir, reflectDir), 0.0f), smoothness);

    return i->colour * (ambient + diffuse) + specular;
}