#include "tile.h"

#pragma once

class Isometry 
{

public:

	tile watersimulator;






};



/*

this creates a very nice silverly colour if the light moves

olc::Pixel lightcheck(double x, double y, double z)
{

	std::uniform_int_distribution<int> dice(0, 100.0);

	vec3d texture_pos(x + y, x + y, z + x + y);

	vec3d light_pos(sin(time2 * PI / 180) * 20, cos(time2 * PI / 180) * 20, 20);
	light_pos.check_magnitude();


	vec3d light_direction = light_pos;
	light_direction.normalize();

	vec3d texture_direction = texture_pos;
	texture_direction.normalize();

	vec3d delta_pos = texture_pos - light_pos;
	delta_pos.check_magnitude();

	vec3d delta_direction = delta_pos;
	delta_direction.normalize();


	double A = cos((delta_pos * delta_pos) / (double(texture_pos.magnitude) * double(delta_pos.magnitude))); // dot product is default

	// A = difference from delta



	double cosTheta = acos(texture_direction * light_direction);



	vec3d light_colour(255, 0, 0);

	vec3d material_colour(150, 150, 150);



	//

//			color = MaterialDiffuseColor * LightColor * LightPower * cosTheta / (distance * distance);

	vec3d E(
		(material_colour.x * light_colour.x * (0.255) * delta_pos.check_magnitude()) - z,
		(material_colour.y * light_colour.y * (0.255) * delta_pos.check_magnitude()) - z,
		(material_colour.z * light_colour.z * (0.255) * delta_pos.check_magnitude()) - z
	);



	vec3d outcolour = E * cosTheta;


	//(  (light_strengh.magnitude) * (255.0))   ;


	// * light_distance * 255 ; 
	return olc::Pixel(outcolour.x, outcolour.y, outcolour.z);








	return olc::Pixel(20, 20, 20);



}


*/