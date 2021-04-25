#include <math.h>

#pragma once

using namespace::std;

class vec3d
{

protected:

public:
	

    double x;
	double y;
	double z;
	int magnitude;

	vec3d(double a, double b, double c);



	vec3d();
   ~vec3d();


	// prefix increment
	void operator++()
	{
		x++;
		y++;
		z++;
		return;
	}
	void operator--()
	{
		x--;
		y--;
		z--;
		return;
	}
	void operator+=(const vec3d& B)
	{   
		x += B.x;
		y += B.y;
		z += B.z;
		return;
	}
	void operator-=(const vec3d& B)
	{

		x -= B.x;
		y -= B.y;
		z -= B.z;

		return;
	}

	vec3d operator-(vec3d& B)
	{
		vec3d C;
		C.x = this->x + B.x;
		C.y = this->y + B.y;
		C.z = this->z + B.z;

		return C;
	}

	vec3d operator+(vec3d& B)
	{
		vec3d C;
		C.x = this->x + B.x;
		C.y = this->y + B.y;
		C.z = this->z + B.z;

		return C;
	}
	
	double operator*(vec3d& B)
	{
		double C;
         	C = (this->x * B.x)
			+ (this->y * B.y)
			+ (this->z * B.z);

		return C;
	}

	vec3d operator*(double B)
	{
	
		vec3d C;
		C.x = this->x * B;
		C.y = this->y * B;
		C.z = this->z * B;
		magnitude = int(sqrt(double((x * x) + (y * y) + (z * z))));

		return C;
	}

	double check_magnitude()
	{
	return	magnitude = int( sqrt( double( (x * x) + (y * y) + (z * z)) ));

	}

	void normalize()
	{
		x /= magnitude;
		y /= magnitude;
		z /= magnitude;

		magnitude = 1;
		return;
	}


};


