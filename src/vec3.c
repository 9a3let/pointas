#include "vec3.h"

#include <math.h>

float
point3f_dist(Point3f p1, Point3f p2)
{
    float distance;
    distance = pow(p1.x - p2.x, 2);
    distance += pow(p1.y - p2.y, 2);
    distance += pow(p1.z - p2.z, 2);
    distance = sqrt(distance);

    return distance;
}

Point3f
point3f_cntr(Point3f *p, int n)
{
    int i;
    Point3f center = {0, 0, 0};
    
    for(i=0; i<n; i++)
    {
        center.x += p[i].x;
        center.y += p[i].y;
        center.z += p[i].z;
    }
    center.x /= n;
    center.y /= n;
    center.z /= n;

    return center;
}

Vec3f
vec3f_form(Point3f p1, Point3f p2)
{
    Vec3f vector;
    vector.x = p2.x - p1.x;
    vector.y = p2.y - p1.y;
    vector.z = p2.z - p1.z;

    return vector;
}

float
vec3f_lenght(Vec3f v)
{
    float lenght;
    lenght = pow(v.x, 2);
    lenght += pow(v.y, 2);
    lenght += pow(v.z, 2);
    lenght = sqrt(lenght);

    return lenght;
}

Vec3f
vec3f_add(Vec3f v1, Vec3f v2)
{
    Vec3f result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    result.z = v1.z + v2.z;

    return result;
}

Vec3f
vec3f_scale(Vec3f v, float s)
{
    v.x *= s;
    v.y *= s;
    v.z *= s;

    return v;
}
