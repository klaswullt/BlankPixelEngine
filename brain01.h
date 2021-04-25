#pragma once
class brain01
{
	struct node
	{

		int x;
		int y;

		struct weight
		{
			double positive;
			double negative;
			double neutral;
			node* muh_node_pointer;
		};

		weight positives[2];
		weight negatives[2];
		weight neutrals[2];

		int onoff;

		weight bias;
	};

	node bias;
	node brain[23][23];

	int grid_h;
	int grid_W;

	brain01()
	{


		grid_h = 10;
		grid_W = 10;




		for (int x = 0; x < grid_W; x++)
		{
			for (int y = 0; y < grid_h; y++)
			{

				brain[x][y].x = x;
				brain[x][y].y = y;


				brain[x][y].bias.positive = 0.5;
				brain[x][y].bias.neutral = 0.5;
				brain[x][y].bias.negative = 0.5;


				brain[x][y].positives[0].positive = 0.5;
				brain[x][y].positives[0].neutral = 0.5;
				brain[x][y].positives[0].negative = 0.5;

				brain[x][y].positives[1].positive = 0.5;
				brain[x][y].positives[1].neutral = 0.5;
				brain[x][y].positives[1].negative = 0.5;

				brain[x][y].negatives[0].positive = 0.5;
				brain[x][y].negatives[0].neutral = 0.5;
				brain[x][y].negatives[0].negative = 0.5;

				brain[x][y].negatives[1].positive = 0.5;
				brain[x][y].negatives[1].neutral = 0.5;
				brain[x][y].negatives[1].negative = 0.5;
/*

				int pos1 = rand() % 4;
				int pos2 = rand() % 4;
				int neg1 = rand() % 4;
				int neg2 = rand() % 4;

				brain[x][y].onoff = 0;

				brain[x][y].positives[0].muh_node_pointer = &brain[x][y + 1];
				brain[x][y].positives[1].muh_node_pointer = &brain[x + 1][y + 1];
				brain[x][y].negatives[0].muh_node_pointer = &brain[neg1][y + 1];
				brain[x][y].negatives[1].muh_node_pointer = &brain[neg2][y + 1];*/
			}
		}


		for (int x = 0; x < grid_W; x++)
		{
			int y = grid_h;

			brain[x][y].x = x;
			brain[x][y].y = y;


			brain[x][y].bias.positive = 0.5;
			brain[x][y].bias.neutral = 0.5;
			brain[x][y].bias.negative = 0.5;


			brain[x][y].positives[0].positive = 0.5;
			brain[x][y].positives[0].neutral = 0.5;
			brain[x][y].positives[0].negative = 0.5;

			brain[x][y].positives[1].positive = 0.5;
			brain[x][y].positives[1].neutral = 0.5;
			brain[x][y].positives[1].negative = 0.5;

			brain[x][y].negatives[0].positive = 0.5;
			brain[x][y].negatives[0].neutral = 0.5;
			brain[x][y].negatives[0].negative = 0.5;

			brain[x][y].negatives[1].positive = 0.5;
			brain[x][y].negatives[1].neutral = 0.5;
			brain[x][y].negatives[1].negative = 0.5;

			//int pos1 = rand() % 4;
			//int pos2 = rand() % 4;
		//	int neg1 = rand() % 4;
		//	int neg2 = rand() % 4;
			/*

			brain[x][y].positives[0].muh_node_pointer = &brain[x][1];
			brain[x][y].positives[1].muh_node_pointer = &brain[x + 1][1];
			brain[x][y].negatives[0].muh_node_pointer = &brain[neg1][5];
			brain[x][y].negatives[1].muh_node_pointer = &brain[neg2][5];
			*/
		}

	}

	void update()
	{
	

				/*
		for (int x = 0; x < grid_W; x++)
		{
			for (int y = 0; y < grid_h; y++)
			{

				brain[x][y].x = x;
				brain[x][y].y = y;
				brain[x][y].onoff = 0;

			}
		}
	
		for (int y = 0; y < grid_h; y++)
		{

			for (int x = 0; x < grid_W; x++)
			{


				if (brain[x][y].onoff == 1)
				{


					brain[x][y].positives[0].muh_node_pointer->onoff = 1;
					brain[x][y].positives[1].muh_node_pointer->onoff = 1;

				}

			}

		}

		for (int y = grid_h - 1; y > 0; y--)
		{

			for (int x = grid_W; x > 0; x--)
			{

				brain[x][y].positives[0].positive *= 0.9;
				brain[x][y].positives[0].neutral *= 0.9;
				brain[x][y].positives[0].negative *= 0.9;

				brain[x][y].positives[1].positive *= 0.9;
				brain[x][y].positives[1].neutral *= 0.9;
				brain[x][y].positives[1].negative *= 0.9;

				brain[x][y].negatives[0].positive *= 0.9;
				brain[x][y].negatives[0].neutral *= 0.9;
				brain[x][y].negatives[0].negative *= 0.9;

				brain[x][y].negatives[1].positive *= 0.9;
				brain[x][y].negatives[1].neutral *= 0.9;
				brain[x][y].negatives[1].negative *= 0.9;


			

				if (
					brain[y][x].positives[0].muh_node_pointer != NULL
					&&
					brain[y][x].positives[0].muh_node_pointer->onoff == 1
					)
				{


					if (brain[x][y].onoff == 1)
					{
						brain[x][y].positives[0].positive += 0.1;

					}
					else
					{
						brain[x][y].positives[1].positive -= 0.1;
					}

				}

	

				if (
					brain[y][x].positives[1].muh_node_pointer != NULL
					&&
					brain[y][x].positives[1].muh_node_pointer->onoff == 1)
				{


					if (brain[x][y].onoff == 1)
					{
						brain[x][y].positives[1].positive += 0.1;

					}
					else
					{
						brain[x][y].positives[1].positive += 0.1;
					}

				}

				if (
					brain[y][x].positives[0].muh_node_pointer != NULL
					&&
					brain[y][x].positives[1].muh_node_pointer != NULL
					)
				{

					brain[y][x].positives[0].muh_node_pointer->bias.positive =
						brain[x][y].bias.positive * brain[x][y].positives[0].positive;

					brain[y][x].positives[1].muh_node_pointer->bias.positive =
						brain[x][y].bias.positive * brain[x][y].positives[1].positive;

				}



			}
*/


		}

		for (int y = grid_h - 1; y > 0; y--)
		{

			for (int x = grid_W; x > 0; x--)
			{

				if (brain[x][y].positives[0].positive > brain[x][y].positives[1].positive)
				{

				//	int pos1 = rand() % grid_W - 1;
				//	&brain[pos1][y + 1];

				}
				if (brain[x][y].positives[0].positive < brain[x][y].positives[1].positive)
				{

				//	int pos1 = rand() % grid_W - 1;
				//	&brain[pos1][y + 1];

				}


			}
		}








	

	
	
	
	}

};

