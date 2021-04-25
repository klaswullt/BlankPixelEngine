#pragma once


#include "particle.h"
#include <vector>




class layer 
{
public:


    int total;

    std::vector<particle> drops;

    int bottom[101][101];
    int top[101][101];



    /*
    3d prints a image voxel by voxel
    save it as reduced quality image
    with some depth buffer data
    and shadow data
    
    */

    void update();

    layer();
    ~layer();

};

/*

tile class sends image to tilecreator
and tilecreator sends image back in a loop

*/

class tile 
{
public:

    layer wall;

    layer floor;

    layer water; // one image 
    layer fire; // one image
    layer ice; // one image

    void update();

    tile();
    ~tile();



};

