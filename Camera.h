#pragma once
#include <gl/gl.h>     
#include <GL/freeglut.h>
#include <math.h>
#include <iostream>
#define DEGTORAD	0.017453292519943295769236907684886
using namespace std;

/*
A primitive camera that will only move along the XZ plane,
and cannot pan up and down.
*/

enum Direction { FORWARD, BACKWARD, TURN_LEFT, TURN_RIGHT };

class Camera
{
    private:
        float x, y, z;
        float lookatX, lookatY, lookatZ;   //looking at
        float moveSpeed, turnSpeed;
        float angle;
        void FixAngle();
    public:
        float X() { return x; }
        float Y() { return y; }
        float Z() { return z; }
        float LookatX() { return lookatX; }
        float LookatY() { return lookatY; }
        float LookatZ() { return lookatZ; }
        float Angle() { return angle; }
        void Update();
        void Move( Direction dir );
        void InitCamera();
        void Point();
        Camera();
};
