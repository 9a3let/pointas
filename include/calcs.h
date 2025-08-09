#ifndef CALCS_H
#define CALCS_H

#include "vec3.h"
#include "types.h"

#define E0 8.8541878e-12
#define PI 3.1415927

/* returns Point3f centroid of the given Charge array */
Point3f charge_cntr(Charge*, int);

/* returns the Vec3f coulomb force vector between two point-Charges */
Vec3f charge_coulomb_force(Charge, Charge, float Er);

/* returns the electric field Vec3f between a point-charge and a Point3f point */
Vec3f charge_efield(Charge, Point3f, float Er);

/* returns the net electric field Vec3f vector in a specified Point3f point */
Vec3f net_efield(Charge*, int, Point3f, float Er);

#endif
