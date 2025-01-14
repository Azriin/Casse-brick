#ifndef REFLECT_H
#define REFLECT_H

float normer2D(float *vIn, float *vOut);
float prodScal2D(float *v1, float *v2);
void compute2DReflectedVector(float *orientation, float *direction, float *reflected);
void compute2DReflectedVectorRaw(float *orientation, float *direction, float *reflected);

#endif //REFLECT_H