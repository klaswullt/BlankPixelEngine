#include "tile.h"




void layer::update()
{	
	

	for (auto it = drops.cbegin(); it != drops.cend(); ++it)
	{

			int x = it->position.x;
			int y = it->position.y;
			int z = it->position.z;
		
			particle lol = *it;
			
			lol.update().flag;


		if (lol.update().flag == alive)
		{

			bottom[x+50][y+50]= z;
			drops.erase(drops.begin(), it );


		}

		
	}



	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 99; j++)
		{
	

	if ( total >= drops.size() )
	{


			bottom[i][j]= i;
			particle new_particle(i,j, bottom[i][j]);
			drops.push_back(new_particle);
			}

		}
	}



}

layer::layer()
{

	total = 400;
	
	for (int i = 1; i < 100; i++)
	{
		for (int j = 1; j < 100; j++)
		{
	
			bottom[i][j] = 0;
			top[i][j] = 0;
		}
	}	

}

layer::~layer()
{
}


void tile::update()
{

	/*
	add layers together save as a new layer
	*/

	water.update();



}

tile::tile()
{
}

tile::~tile()
{

}