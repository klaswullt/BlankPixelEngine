#pragma once
#include"olcPixelGameEngine.h"


class Ball
{
public:
    Ball()
    {

    }

    void DrawSelf(olc::PixelGameEngine* pge)
    {
        pge->FillCircle(position, 3); // to define a 3px radius
    }

public:
    olc::vf2d position = { 0, 0 };
};
