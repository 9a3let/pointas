#ifndef VEC3_H
#define VEC3_H

#define VEC3F_NULL (Vec3f) {0, 0, 0}

typedef struct 
{
    float x, y, z;
} Point3f;

typedef struct 
{
    float x, y, z;
} Vec3f;


/* returns distance between two Point3f points */
float point3f_dist(Point3f, Point3f);

/* returns Point3f centroid of the given Point3f array */
Point3f point3f_cntr(Point3f*, int);

/* returns a Vec3f formed from the first Point3f to the second Point3f */
Vec3f vec3f_form(Point3f, Point3f);

/* returns the lenght of a Vec3f vector */
float vec3f_lenght(Vec3f);

/* adds two Vec3f vectors */
Vec3f vec3f_add(Vec3f, Vec3f);

/* returns a scaled Vec3f vector */
Vec3f vec3f_scale(Vec3f, float);

#endif
