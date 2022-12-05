#include "Sphere.h"
#include "glm/ext.hpp"
Sphere::Sphere(glm::vec3 centre, float radius, glm::vec3 colour)
    : m_Centre(centre), m_Radius(radius), m_Colour(colour)
{
}

Intersection Sphere::intersect(Ray* r)
{
    glm::vec3 oc = r->get_origin() - m_Centre;
    double b = glm::dot(oc, r->get_direction());
    double c = dot(oc, oc) - m_Radius * m_Radius;
    double h = b * b - c;
    if (h < 0.0) return Intersection(IntersectionType::NONE, 2000.0, glm::vec3(0.0), glm::vec3(0.0), glm::vec3(0.0), glm::vec3(0.0));
    h = sqrt(h);
    double t = -b - h;
    return Intersection(IntersectionType::PRIMITIVE, t, r->at(t), r->get_direction(), glm::normalize(m_Centre - r->at(t)), m_Colour);
}
