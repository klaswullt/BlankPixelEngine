#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "keyboard_x.h"

#include <chrono>
#include <random>
#define PI 3.14159265
#include "vec3d.h"
#include  "direction_vector.h"

#include "tile.h"




#define OLC_PGE_APPLICATION


typedef long double matrix[4][4];

typedef direction_vector axis;
float inverse_rsqrt(float number);

float inverse_rsqrt(float number)
{
	const float threehalfs = 1.5F;

	float x2 = number * 0.5F;
	float y = number;

	// evil floating point bit level hacking
	long i = *(long*)&y;

	// value is pre-assumed
	i = 0x5f3759df - (i >> 1);
	y = *(float*)&i;

	// 1st iteration
	y = y * (threehalfs - (x2 * y * y));

	// 2nd iteration, this can be removed
	// y = y * ( threehalfs - ( x2 * y * y ) );

	return y;
};

struct message
{
	olc::vf2d pos;
	bool depth;
};




class Example : public olc::PixelGameEngine
{
public:
	

	std::default_random_engine generator;

	vec3d mouseposition;



	std::vector<vec3d> waterdrops;

	int depth[201][201];
	double water[101][101][3];

	double time;

	double time2;


	Example()
	{
		sAppName = "Example";
	}

public:


	bool depthcheck(olc::vf2d d2input,int z)
	{

		int a = 50 + int( d2input.x);
		int b = 50 + int (d2input.y);

		int c = z;

		if(a > 0 && a < 200
		&& b > 0 && b < 200			
		&& c >= depth[a][b]
			)
		{
			depth[a][b] = c;
			return true;
		}

		return false;
	}
	

	olc::Pixel lightcheck(double x,double y,double z)

	{

		std::uniform_int_distribution<int> dice(0, 100.0);

	//	vec3d texture_pos(x+y,x+y, z+x+y); // creates a flat reflection
		
		vec3d texture_pos(x, y, z); // creates round 3D reflection

		 vec3d texture_normal(0, 0,1);

		// vec3d texture_normal(x, y, cos(x*x)*3 ); //sparkly ice


		vec3d texture_direction = texture_pos;
		texture_direction.check_magnitude();
		texture_direction.normalize();
		texture_pos.check_magnitude();

		// vec3d light_pos(sin(time2 * PI / 180)*20,cos(time2 * PI / 180)*20, 20);

		vec3d light_pos(mouseposition.x,mouseposition.y,mouseposition.z);
		light_pos.check_magnitude();


		vec3d light_direction = light_pos;
		light_direction.normalize();

		vec3d delta_pos = texture_pos - light_pos;
		delta_pos.check_magnitude();

		vec3d delta_direction = delta_pos;
		delta_direction.normalize();


		double A = cos( (delta_pos * delta_pos) / (double(texture_pos.magnitude) * double(delta_pos.magnitude)) ); // dot product is default
	  
	    // A = difference from delta


		double cosTheta = acos(texture_direction * light_direction) * 180.0 / PI;



		// different formulas to try

		double CosQ = (texture_normal * delta_pos) / (double(texture_normal.magnitude) * double(delta_pos.magnitude)); // dot 


		double LightDensity = (texture_normal * delta_pos) ;
		
		//Outgoing_Light = (Diffuse * LightDensity * delta_pos) * texture_normal;



		vec3d light_colour( 1, 1, 1);

		vec3d material_colour(0.1, 0.1,0.5);

		double degree =  ( acos(texture_normal * delta_direction) * 180.0 / PI) ;

		//A = cos(degree *180.0 / PI )  * 255;
	
	//	A = cos(degree * 180.0 / PI) * 255;

		A = CosQ * (255 -(delta_pos.magnitude*0.1)) ;

			//(- inverse_rsqrt(delta_pos.magnitude));

		

//			color = MaterialDiffuseColor * LightColor * LightPower * cosTheta / (distance * distance);
	

		if( delta_pos.magnitude <= 250 )
		{

			vec3d E(
				( material_colour.x * (light_colour.x *A) ) ,
				( material_colour.y * (light_colour.y *A) ) ,
				( material_colour.z * (light_colour.z *A) ) 
				);


			

			vec3d outcolour = E;
			

			//(  (light_strengh.magnitude) * (255.0))   ;

			// * light_distance * 255 ;

		 return olc::Pixel(outcolour.x, outcolour.y, outcolour.z);
		}




		
	
		return olc::Pixel(material_colour.x, material_colour.y, material_colour.z);
	

		
	}

	message isometric(olc::vf2d point, int z)
	{

		olc::vd2d screen;
		olc::vd2d hex;

		message output;
		output.depth = false;
		output.pos = screen;

		olc::vd2d A(0.5, 0.25);
		olc::vd2d B = A;
		B.x *= -1;

		hex = (A * (point.x)) + (B * (point.y));
		hex.y += z;
		hex.y *= -1;
		if (depthcheck(hex, z) == true)
		{

			olc::vd2d origio(ScreenWidth() / 2, ScreenHeight() / 2);


			screen = origio + hex;
			output.pos = screen;
			output.depth = true;
		}

		return output;
	}

	bool OnUserCreate() override
	{





		direction_vector lol;
	

		axis X; 
		axis Y;
		axis Z;

	


		double height = 231;
		double lenght = 200;
		double H = height /4;
		double L = lenght /2;

		double radius = sqrt((height * height) + (lenght * lenght));

		// radius = (height / 4 * height/ 4) + b 



		double to_sin(height/ radius);
		double to_cos(lenght/ radius);

		/*
		* 
		* 		axis °; // A11 4A1L T8E DEG 7YMB0L DOUBLE LONG PRAI7E PHI!!
		* 
		°.sine = asin(to_sin) * 180.0 / PI;
		°.cosine = acos(to_cos) * 180.0 / PI;

	matrix isometric_matrix
		{
			X.x,X.y,X.z,0,
		    Y.x,Y.y,Y.z,0,
			0,1,0,0
		};
	
		




	
		matrix rotation_matrix_x
		{
			1,0,0,0
			0,cos(),-sin(),0
			0,sin(),cos(),0
		};

		matrix rotation_matrix_z
		{
			cos(),-sin(),0,0
			sin(),cos(),1,0,
			0,0,1,0
		};
		*/

	
		/*
		matrix rotation_matrix_x_2
		{
			1,0,0,0,
			°.cosine,-°.sine,0,0,
			°.sine,°.cosine,1,0,
			0,0,0,0
		};


	
		matrix rotation_matrix_z_2
		{
		
			°.cosine,0,°.sine,0,
			0,1,0,0,
			-°.sine,0,°.cosine,0,
	
		};

	   matrix rotation_matrix_z_2
		{
			°.cosine,-°.sine,0,0,
			°.sine,°.cosine,1,0,
			0,0,1,0,
			0,0,0,0
		};	

		matrix isometric_matrix
		{
			°.cosine,°.sine,0,0,
		   -°.cosine,°.sine,0,0,
			0,1,0,0,
			0,0,0,0
		};
*/



		int time2 = 0;


		olc::Sprite* load = new olc::Sprite("image.png");

		time = 0;
	

		SetPixelMode(olc::Pixel::ALPHA);

		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{

		mouseposition.x = GetMouseX() -(ScreenWidth()/2);
		mouseposition.y = GetMouseY() -(ScreenHeight()/2); 
		mouseposition.z = 10;

		// frame of reference

		// frame 3D space y is in front of you still projected

		// screen frame 2D just up is up and left is left right is x

		// isometric frame 
		/*
		
		screen.x = iso.x + iso.y
		screen.y = iso.x - iso.y

		iso.x = 
		iso.y = 
		
		ScreenX = Origo + (LocalX - LocalY) ;
        ScreenY = Origo + (LocalX + LocalY) ;

		IsoX = ((ScreenX - IsoY) / IsoH + (GlobalX - IsoX) / IsoW) / 2;
        IsoY = ((ScreenX - IsoY) / IsoH - (GlobalX - IsoX) / IsoW) / 2;
		
		
		*/





		if (time2 < 360)
		{
			time2+= 0.1;

		}
		else
		{
			time2 = 0;
		}

		Clear(olc::BLACK);


		if ( GetKey(olc::Key::LEFT).bPressed)
		{
		}
		if (GetKey(olc::Key::RIGHT).bPressed)
		{
		}

	
		
	

			for (int x = -50; x <= 50; x++)
			{ 	
				for (int y =-50; y <= 50; y++)
				{
					
						olc::Pixel colour(0,0,255);

						
						int z = 4;


						for ( int z = 0; z <= water[x + 50][y + 50][0]; z++ )
						{
	
					
						if (x == 0 || y == 0)
						{
							//colour = olc::GREEN;
						}
						

						message point(
				        isometric(olc::vf2d(x, y),z)
						);



						if (point.depth ==true)
						{
							colour = lightcheck(x, y, z);
								Draw(point.pos, colour);
						}

					    }
						
				}
			}

		

		return true;
	}

	

	

	vec3d checkwaterflow(vec3d input)
	{

		int i = input.x; int j = input.y;
		int x = 50 + i;
		int y = 50 + j;


		if (
			x > 1 && x < 99
			&&
			y > 1 && y < 99
			)
		{


			
			vec3d flowvector;
			
			flowvector.x = 1;
			flowvector.y = 1;
			flowvector.z = 1;



			for (int a = x-1; a < x+1; a++)
			{
				flowvector.x += water[a][y][0];

			}
		
			for (int b = y-1; b < y+1; b++)
			{
					
					
			   flowvector.y += water[x][b][0];
			
			}
			flowvector.check_magnitude();
			flowvector.normalize();

			input = flowvector + input;
			return  input;

		}




		return input;
	}





	
};


int main()
{

	Example demo;
	if (demo.Construct(300, 300, 4, 4))
		demo.Start();
	return 0;
}
