
#pragma once
#include"olcPixelGameEngine.h"
#include <vector>
#include <string>



class keyboard_x
{

public:

	struct message
	{
		int keys[5];

	};

	std::string log;


	std::vector <int> inputs;

	std::vector <message> messages;

	void loop_keys(olc::PixelGameEngine* pge)
	{

	

		inputs.clear();
		std::string S;

			

		for (int i = 0; i < 255; i++)
		{

			if (pge->GetKey(olc::Key(i)).bHeld)
			{

				inputs.push_back(i);

				pge->DrawString(10, 10, std::to_string(i));

				char E = char(i);
			

				S += E;


				pge->DrawString(10, 30, S);



			}

		}
		// use and check inputs


	}



};

