#include "particle.h"



particle::particle(double x,double y, double z)
{
	energy = 10;
	acceleration = 2;
	collide = 0 ;
	std::uniform_int_distribution<int> distribution(1, 10);

	int a = distribution(generator);

	int b = distribution(generator);

	int c = distribution(generator);

	vec3d new_bounce(0, 0, 0);
	Opposite_Force = new_bounce;

	position.x = x;
	position.y = y;
	position.z = z;

	Force.x = a;
	Force.y = b;
	Force.z = c;
	Force.check_magnitude();
	Force.normalize();
}

particle_message particle::update()
{
	collide = false;

	particle_message M;


	M.flag = alive;

	if (collide == true)
	{

	Force = Force + Opposite_Force;
	
	}

	if (x >= 48)
	{
		collide = true;
		Velocity.x = -10;

	}
	if (x <= -48)
		collide = true;
	{
		Velocity.x = 10;
	}
	if (y >= 48 )
	{
		collide = true;
		Velocity.y = -10;
	}
	if (y <= -48)
	{
		collide = true;
		Velocity.y = 10;
	}
	if (z >= 100)
	{
		collide = true;
		Velocity.z = -10;
	}
	if (z <= 1 )
	{
		collide = true;
		Velocity.z = 10;
	}

	if (energy <= 0)
	{
		collide = true;
		position.z = 0;

		//M.flag = dead;

	}




	
	
	Velocity.check_magnitude();
	Velocity.normalize();

	position = position + Velocity;



	energy--;


	return M;
}