#pragma once
#include <GL/freeglut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//The SIDE class will hold the four edges, and then handle drawing the two triangles for it.

class Side //aka, a polygon's coordinates
{
    private:
        float x[4], y[4], z[4];      
        float r, g, b;
    public:
        float X( int index );
        float Y( int index );        
        float Z( int index );        
        void SetX( int index, float val );        
        void SetY( int index, float val );        
        void SetZ( int index, float val );  
        float R() { return r; }
        float G() { return g; }
        float B() { return b; }
        void SetSides( float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4 );
        void SetColor( float new_r, float new_g, float new_b );
        void Draw();
        void Draw( float cX, float cY, float cZ );
        void Stats();
};
