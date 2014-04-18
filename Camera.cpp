#include "Camera.h"

void Camera::FixAngle()
{
    /*
    Might as well keep the angles simple & clean.  
    Even though sin ( 1440 ) will give you the same as sin ( 0 ),
    we should probably stick with 0 to 360. :)
    */
    if ( angle < 0 )
        angle += 360;
    else if ( angle > 360 )
        angle -= 360;
}

void Camera::Update()
{
    //Would be more complex if I had more complex movement
    FixAngle();
}

void Camera::Move( Direction dir )
{
    Point();
    FixAngle();
    switch( dir )
    {
        case FORWARD:
            x += lookatX * moveSpeed;
            z += lookatZ * moveSpeed;
            break;
        case BACKWARD:
            x -= lookatX * moveSpeed;
            z -= lookatZ * moveSpeed;
            break;
        case TURN_LEFT:
            angle -= turnSpeed;
            break;
        case TURN_RIGHT:
            angle += turnSpeed;
            break;
    }
}

void Camera::InitCamera()
{
    moveSpeed = 1.0;
    turnSpeed = 5.0;
    angle = 0.0;
    Update();
    Point();
    x = -15;
    z = 15;
}

void Camera::Point()
{
    lookatX = -sin( angle * DEGTORAD );
    lookatY = 0;
    lookatZ = -cos( angle * DEGTORAD );
    
	glLoadIdentity();
	Update();
}

Camera::Camera()
{
    InitCamera();
}













