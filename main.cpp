#include <gl/gl.h>     
#include <gl/freeglut.h> 
#include "RachObject.h"
#include "Camera.h"
#include "ObjectManager.h"
#include <iostream>
using namespace std;

/*********************************************
Name:           Rachel J. Morris
Course:         CS 475
Program:        Assignment 2
Due Date:       2/16/09
Description:    Take the floor plans from Assignment 1 and
                Make a rudimentary 3D version of it in OpenGL.
Inputs:         W, A, S, and D to move, R to enable/disable drawing of the
                house and yard (was for debugging).  Esc to quit.
Outputs:        Outputs many quads to the screen in such a way that it
                resembles a house, yard, tree, weird chairs, a table, and a bed.
Algorithm:      Initialize OpenGL and GLUT
                Init objects (colors and vertices)
                While in main loop
                    Look for and handle keypresses
                    Render objects to screen
                Clean up program and quit
Miscellaneous:  Written/compiled in DevC++, shouldn't have any
                problems under Visual Studio.
                
                http://www.moosader.com
*********************************************/


void RenderScene();
void HandleKeypress( unsigned char key, int x, int y );
void InitProgram( int argc, char *argv[] );
void HandleResize( int width, int height );

// I DISLIKE GLUT BECAUSE THESE KIND OF HAVE TO BE
// GLOBAL!  GRR!  VIVA LA SDL!
Camera player;
ObjectManager objManager;

int main ( int argc, char *argv[] )   
{
    InitProgram( argc, argv );
    glutMainLoop();          
    return 0;
}

void InitProgram( int argc, char *argv[] )
{
     //Init Glut
     glutInit( &argc, argv ); 
     glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
     glutInitWindowSize( 1024, 768 );
     glutCreateWindow( "Ass2" );    
     //Init OpenGL
     glClearColor(0.2f, 0.5f, 1.0f, 0.5f);			
     glClearDepth(1.0f);									
     glEnable(GL_DEPTH_TEST);						
     glDepthFunc(GL_LEQUAL);							
     glEnable ( GL_COLOR_MATERIAL );
     glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
     //Misc
     glutDisplayFunc( RenderScene );  
     glutReshapeFunc( HandleResize );
     glutKeyboardFunc( HandleKeypress );
     glutIdleFunc( RenderScene );
}

void HandleKeypress ( unsigned char key, int x, int y )
{
    if ( key == 27 )            //esc
     exit( 0 );
    if ( key == 'a' || key == 'A' )           //left
    {   
        player.Move( TURN_LEFT );
    }
    else if ( key == 'd' || key == 'D' )      //right
    {
        player.Move( TURN_RIGHT );
    }
    if ( key == 'w' || key == 'D' )           //up
    {
        player.Move( FORWARD );
    }
    else if ( key == 's' || key == 'S' )      //down
    {
        player.Move( BACKWARD );
    }
    
    if ( key == 'r' )           //display room (or don't)
    {
        if ( objManager.DisplayRoom() == true )
            objManager.DisplayRoom( false );
        else
            objManager.DisplayRoom( true );
    }
}

//Copied HandleResize from Nehe tutorial
void HandleResize ( int width , int height )   
{
  if (height==0)	   //no division by zero plzthx.								
	{
		height=1;										
	}

	glViewport(0,0,width,height);					

	glMatrixMode(GL_PROJECTION);					
	glLoadIdentity();									

	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

	glMatrixMode(GL_MODELVIEW);							
	glLoadIdentity();									
}

void RenderScene()   // Create The Display Function
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
    glLoadIdentity();									// Reset The Current Modelview Matrix
    glPushMatrix();
    glScalef( 1.0f, 1.0f, 1.0f );
    //glTranslatef( -1.5f, -5.0f, -20.0f );	
    glRotatef( player.Angle(), 0.0f, 1.0f, 0.0f);					
    glTranslatef( player.X(), -5.0, -player.Z() );

    //Draw
    objManager.DrawObjects();
    //End Draw
    
    glPopMatrix();    
    glutSwapBuffers();
}
