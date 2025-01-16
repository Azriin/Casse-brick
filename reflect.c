#include <math.h>

// normer2D
float normer2D(float *vIn, float *vOut) { 
	float lg = sqrt(vIn[0]*vIn[0]+vIn[1]*vIn[1]);
	if (lg) {
		vOut[0] = vIn[0]/lg;
		vOut[1] = vIn[1]/lg;
	}
	return(lg);
} // normer2D  

// prodScal2D
float prodScal2D(float *v1, float *v2) {
	return v1[0]*v2[0]+v1[1]*v2[1];
} // prodScal2D

// compute2DReflectedVector
// Orientation and direction are normed vectors
void compute2DReflectedVector(float *orientation, float *direction, float *reflected) {
	float modifiedCos = -2.0 * prodScal2D(direction, orientation);
	reflected[0] = modifiedCos * orientation[0] + direction[0];
	reflected[1] = modifiedCos * orientation[1] + direction[1];
} // compute2DReflectedVector

// compute2DReflectedVectorRaw
// Orientation and direction are normed vectors
void compute2DReflectedVectorRaw(float *orientation, float *direction, float *reflected) {
	float normedOr[2], normedDir[2];
		
	normer2D(orientation, normedOr);
	normer2D(direction, normedDir);
	
	compute2DReflectedVector(normedOr, normedDir, reflected);
} // compute2DReflectedVectorRaw

// simple2DReflect
// orientation = vector wall, direction = vector input, reflected = vector output
void simple2DReflect(float *orientation, float *direction, float *reflected){
	if (orientation[0] != 0) {
		reflected[0] = fabs(direction[0]) * orientation[0];
	} else {reflected[0] = direction[0];}
	if (orientation[1] != 0) {
		reflected[1] = fabs(direction[1]) * orientation[1];
	} else {reflected[1] = direction[1];}
} // simple2DReflect