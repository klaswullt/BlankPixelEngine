#include "vec3d.h"

vec3d::vec3d()
{


	double x = 0;
	double y = 0;
	double z = 0;
	int magnitude = 0;



}


vec3d::~vec3d()
{

}




vec3d::vec3d(double a,double b, double c)
{
	x = a;
	y = b;
	z = c;

	magnitude = int(sqrt(double((x * x) + (y * y) + (z * z))));
}

