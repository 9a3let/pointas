#include "calcs.h"

#include <math.h>

Point3f 
charge_cntr(Charge *q, int n)
{
    int i;
    Point3f center = {0, 0, 0};
    
    for(i=0; i<n; i++)
    {
        center.x += q[i].point.x;
        center.y += q[i].point.y;
        center.z += q[i].point.z;
    }
    center.x /= n;
    center.y /= n;
    center.z /= n;

    return center;
}

Vec3f 
charge_coulomb_force(Charge q1, Charge q2, float Er)
{
    Vec3f force;
    float r, m;

    force = vec3f_form(q1.point, q2.point);

    r = point3f_dist(q1.point, q2.point);
    m = q1.value*q2.value / (4 * PI * E0 * Er * pow(r, 3));
    force = vec3f_scale(force, m);

    return force;
}

Vec3f 
charge_efield(Charge q, Point3f p, float Er)
{
    Vec3f efield;
    float r, m;

    efield = vec3f_form(q.point, p);

    r = point3f_dist(q.point, p);
    if(!r) 
        return VEC3F_NULL;

    m = q.value / (4 * PI * E0 * Er * pow(r, 3));
    efield = vec3f_scale(efield, m);

    return efield;
}

Vec3f 
net_efield(Charge *qs, int n, Point3f p, float Er)
{
    int i;
    Vec3f net_efield = VEC3F_NULL;

    for(i=0; i<n; i++)
        net_efield = vec3f_add(net_efield, charge_efield(qs[i], p, Er));

    return net_efield;
}
