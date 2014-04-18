#include "RachObject.h"

void RachObject::Setup( int sideAmt )
{
    if ( sideAmt <= 0 )
        sideAmt = 1;
    if ( side != NULL )
        delete [] side;
    side = new Side [sideAmt];
}

RachObject::RachObject()
{
    Setup( 0 );
    scale = 1.0;
    rotation = 0.0;
}

RachObject::RachObject( int sideAmt )
{
    Setup( sideAmt );
}

RachObject::~RachObject()
{
    delete [] side;
}

void RachObject::DrawObject()
{
    for ( int i=0; i<sideAmt; i++ )
    {
        side[i].Draw( cX, cY, cZ );
    }
}

void RachObject::SetCoordinates( float x, float y, float z )
{
    cX = x;
    cY = y;
    cZ = z;
}

void RachObject::SetupObject( ObjectType type )
{
    switch( type )
    {
        case TREE:
            /*
            The tree has four rectangles for it's trunk, and four triangles
            for the tree part, with one square at the base of the triangles.
            */
            scale = 1.0;
            rotation = 0;
            sideAmt = 9;
            cX = 20;
            cY = 0;
            cZ = -15;
            side = new Side[ sideAmt ];
            
            //---TRUNK--//
            //"front" surface
            side[0].SetColor( 0.8f, 0.2f, 0.0f );
            side[0].SetSides(   -0.5, 4.0, 0.5,
                                -0.5, 0.0, 0.5,
                                0.5, 0.0, 0.5,
                                0.5, 4.0, 0.5 );
            //"back" surface
            side[1].SetColor( 0.7f, 0.1f, 0.0f );
            side[1].SetSides(   -0.5, 4.0, -0.5,
                                -0.5, 0.0, -0.5,
                                0.5, 0.0, -0.5,
                                0.5, 4.0, -0.5 );
            //"left" surface
            side[2].SetColor( 0.6f, 0.0f, 0.0f );
            side[2].SetSides(   -0.5, 4.0, -0.5,
                                -0.5, 0.0, -0.5,
                                -0.5, 0.0, 0.5,
                                -0.5, 4.0, 0.5 );       
            //"right" surface
            side[3].SetColor( 0.6f, 0.0f, 0.0f );
            side[3].SetSides(   0.5, 4.0, -0.5,
                                0.5, 0.0, -0.5,
                                0.5, 0.0, 0.5,
                                0.5, 4.0, 0.5 );   
            //--TREENESS--//
            //Side 1 
            side[4].SetColor( 0.2f, 0.8f, 0.0f );
            side[4].SetSides(   0.0, 18.0, 0.0,
                                3.0, 4.0, 0.0,
                                0.0, 4.0, 3.0,
                                0.0, 18.0, 0.0 );  
            //Side 2 
            side[5].SetColor( 0.3f, 0.8f, 0.0f );
            side[5].SetSides(   0.0, 18.0, 0.0,
                                -3.0, 4.0, 0.0,
                                0.0, 4.0, -3.0,
                                0.0, 18.0, 0.0 );   
            //Side 3
            side[6].SetColor( 0.4f, 1.0f, 0.0f );
            side[6].SetSides(   0.0, 18.0, 0.0,
                                3.0, 4.0, 0.0,
                                0.0, 4.0, -3.0,
                                0.0, 18.0, 0.0 );   
            //Side 4 
            side[7].SetColor( 0.3f, 1.0f, 0.0f );
            side[7].SetSides(   0.0, 18.0, 0.0,
                                -3.0, 4.0, 0.0,
                                0.0, 4.0, 3.0,
                                0.0, 18.0, 0.0 );                                                                                      
            break;
        case BED:
            /*
            The bed is made up of four rectangles for the pillow, and
            four rectangles for the sheets. (Not drawing side facing floor,
            or side facing pillow).
            */
            scale = 0.7;
            rotation = 0;
            sideAmt = 8;
            cX = -15;
            cY = 0;
            cZ = 18;
            side = new Side[ sideAmt ];
            //---PILLOW---//
            //Top surface
            side[0].SetColor( 1.0f, 1.0f, 1.0f );
            side[0].SetSides(   -6.0, 1.0, 3.0,
                                -3.0, 1.0, 3.0,
                                -3.0, 1.0, -3.0,
                                -6.0, 1.0, -3.0 );
            //"front" surface
            side[1].SetColor( 0.8f, 0.8f, 0.8f );
            side[1].SetSides(   -6.0, 1.0, 3.0,
                                -6.0, 0.0, 3.0,
                                -3.0, 0.0, 3.0,
                                -3.0, 1.0, 3.0 );
            //"back" surface
            side[2].SetColor( 0.7f, 0.7f, 0.7f );
            side[2].SetSides(   -6.0, 1.0, -3.0,
                                -6.0, 0.0, -3.0,
                                -3.0, 0.0, -3.0,
                                -3.0, 1.0, -3.0 );
            //"left" surface
            side[3].SetColor( 0.6f, 0.6f, 0.6f );
            side[3].SetSides(   -6.0, 1.0, -3.0,
                                -6.0, 0.0, -3.0,
                                -6.0, 0.0, 3.0,
                                -6.0, 1.0, 3.0 );                                  
            //---BED---//                    
            //Top surface
            side[4].SetColor( 0.5f, 0.2f, 0.2f );
            side[4].SetSides(   -3.0, 1.0, 3.0,
                                6.0, 1.0, 3.0,
                                6.0, 1.0, -3.0,
                                -3.0, 1.0, -3.0 );
            //"front" surface
            side[5].SetColor( 0.4f, 0.1f, 0.1f );
            side[5].SetSides(   -3.0, 1.0, 3.0,
                                -3.0, 0.0, 3.0,
                                6.0, 0.0, 3.0,
                                6.0, 1.0, 3.0 );
            //"back" surface
            side[6].SetColor( 0.4f, 0.1f, 0.1f );
            side[6].SetSides(   -3.0, 1.0, -3.0,
                                -3.0, 0.0, -3.0,
                                6.0, 0.0, -3.0,
                                6.0, 1.0, -3.0 );
            //"right" surface
            side[7].SetColor( 0.3f, 0.0f, 0.0f );
            side[7].SetSides(   6.0, 1.0, -3.0,
                                6.0, 0.0, -3.0,
                                6.0, 0.0, 3.0,
                                6.0, 1.0, 3.0 ); 
            break;
        case TABLE:
            /*
            The table has six rectangles for the main table body, and each
            leg has another four rectangles. (We aren't counting the bottom and top
            surface of the legs)
            6 + 4(4) = 22
            */
            scale = 0.7;
            rotation = 0;
            sideAmt = 22;
            cX = -18;
            cY = 0;
            cZ = -18;
            side = new Side[ sideAmt ];
            //---TABLETOP---//
            //Top surface
            side[0].SetColor( 1.0f, 0.4f, 0.0f );
            side[0].SetSides(   -3.0, 4.0, -4.5, 
                                -3.0, 4.0, 4.5,
                                3.0, 4.0, 4.5,
                                3.0, 4.0, -4.5 );
            //Bottom surface
            side[1].SetColor( 0.6f, 0.0f, 0.0f );
            side[1].SetSides(   -3.0, 3.5, -4.5, 
                                -3.0, 3.5, 4.5,
                                3.0, 3.5, 4.5,
                                3.0, 3.5, -4.5 );
            //"Forward" surface            
            side[2].SetColor( 0.8f, 0.2f, 0.0f );                    
            side[2].SetSides(   -3.0, 4.0, 4.5,
                                -3.0, 3.5, 4.5,
                                3.0, 3.5, 4.5,
                                3.0, 4.0, 4.5 );
            //"Back" surface                     
            side[3].SetColor( 0.6f, 0.2f, 0.0f );           
            side[3].SetSides(   3.0, 4.0, -4.5,
                                3.0, 3.5, -4.5,
                                -3.0, 3.5, -4.5,
                                -3.0, 4.0, -4.5 );
            //"Left" surface                     
            side[4].SetColor( 1.0f, 0.2f, 0.0f );       
            side[4].SetSides(   -3.0, 4.0, -4.5, 
                                -3.0, 3.5, -4.5, 
                                -3.0, 3.5, 4.5,
                                -3.0, 4.0, 4.5 );
            //"Right" surface                    
            side[5].SetColor( 0.9f, 0.2f, 0.0f );        
            side[5].SetSides(   3.0, 4.0, -4.5,
                                3.0, 3.5, -4.5,
                                3.0, 3.5, 4.5,
                                3.0, 4.0, 4.5 );
            //---LEG 1---//
            //"Forward" surface            
            side[6].SetColor( 0.8f, 0.2f, 0.0f );                    
            side[6].SetSides(   -3.0, 3.5, 4.5,
                                -3.0, 0.0, 4.5,
                                -2.5, 0.0, 4.5,
                                -2.5, 3.5, 4.5 );
            //"Back" surface                     
            side[7].SetColor( 0.6f, 0.2f, 0.0f );           
            side[7].SetSides(   -3.0, 3.5, 4.0,
                                -3.0, 0.0, 4.0,
                                -2.5, 0.0, 4.0,
                                -2.5, 3.5, 4.0 );
            //"Left" surface                     
            side[8].SetColor( 1.0f, 0.2f, 0.0f );       
            side[8].SetSides(   -3.0, 3.5, 4.0,
                                -3.0, 0.0, 4.0,
                                -3.0, 0.0, 4.5,
                                -3.0, 3.5, 4.5 );
            //"Right" surface                    
            side[9].SetColor( 0.9f, 0.2f, 0.0f );        
            side[9].SetSides(   -2.5, 4.0, 4.0,
                                -2.5, 0.0, 4.0,
                                -2.5, 0.0, 4.5,
                                -2.5, 4.0, 4.5 );  
            //---LEG 2---//
            //"Forward" surface            
            side[10].SetColor( 0.8f, 0.2f, 0.0f );                    
            side[10].SetSides(   3.0, 3.5, 4.5,
                                3.0, 0.0, 4.5,
                                2.5, 0.0, 4.5,
                                2.5, 3.5, 4.5 );
            //"Back" surface                     
            side[11].SetColor( 0.6f, 0.2f, 0.0f );           
            side[11].SetSides(  3.0, 3.5, 4.0,
                                3.0, 0.0, 4.0,
                                2.5, 0.0, 4.0,
                                2.5, 3.5, 4.0 );
            //"Left" surface                     
            side[12].SetColor( 1.0f, 0.2f, 0.0f );       
            side[12].SetSides(  3.0, 3.5, 4.0,
                                3.0, 0.0, 4.0,
                                3.0, 0.0, 4.5,
                                3.0, 3.5, 4.5 );
            //"Right" surface                    
            side[13].SetColor( 0.9f, 0.2f, 0.0f );        
            side[13].SetSides(  2.5, 4.0, 4.0,
                                2.5, 0.0, 4.0,
                                2.5, 0.0, 4.5,
                                2.5, 4.0, 4.5 );      
            //---LEG 3---//
            //"Forward" surface            
            side[14].SetColor( 0.8f, 0.2f, 0.0f );                    
            side[14].SetSides(   -3.0, 3.5, -4.5,
                                -3.0, 0.0, -4.5,
                                -2.5, 0.0, -4.5,
                                -2.5, 3.5, -4.5 );
            //"Back" surface                     
            side[15].SetColor( 0.6f, 0.2f, 0.0f );           
            side[15].SetSides(   -3.0, 3.5, -4.0,
                                -3.0, 0.0, -4.0,
                                -2.5, 0.0, -4.0,
                                -2.5, 3.5, -4.0 );
            //"Left" surface                     
            side[16].SetColor( 1.0f, 0.2f, 0.0f );       
            side[16].SetSides(   -3.0, 3.5, -4.0,
                                -3.0, 0.0, -4.0,
                                -3.0, 0.0, -4.5,
                                -3.0, 3.5, -4.5 );
            //"Right" surface                    
            side[17].SetColor( 0.9f, 0.2f, 0.0f );        
            side[17].SetSides(   -2.5, 4.0, -4.0,
                                -2.5, 0.0, -4.0,
                                -2.5, 0.0, -4.5,
                                -2.5, 4.0, -4.5 );  
            //---LEG 4---//
            //"Forward" surface            
            side[18].SetColor( 0.8f, 0.2f, 0.0f );                    
            side[18].SetSides(  3.0, 3.5, -4.5,
                                3.0, 0.0, -4.5,
                                2.5, 0.0, -4.5,
                                2.5, 3.5, -4.5 );
            //"Back" surface                     
            side[19].SetColor( 0.6f, 0.2f, 0.0f );           
            side[19].SetSides(  3.0, 3.5, -4.0,
                                3.0, 0.0, -4.0,
                                2.5, 0.0, -4.0,
                                2.5, 3.5, -4.0 );
            //"Left" surface                     
            side[20].SetColor( 1.0f, 0.2f, 0.0f );       
            side[20].SetSides(  3.0, 3.5, -4.0,
                                3.0, 0.0, -4.0,
                                3.0, 0.0, -4.5,
                                3.0, 3.5, -4.5 );
            //"Right" surface                    
            side[21].SetColor( 0.9f, 0.2f, 0.0f );        
            side[21].SetSides(  2.5, 4.0, -4.0,
                                2.5, 0.0, -4.0,
                                2.5, 0.0, -4.5,
                                2.5, 4.0, -4.5 );                          
            break;
        case CHAIR:
            /*
            The chair has five rectangles. for the back, six for the seat,
            and each leg consists of four rectangles.
            */
            scale = 0.5;
            rotation = 0;
            sideAmt = 27;
            cX = -20;
            cY = 0;
            cZ = -9;
            side = new Side[ sideAmt ];
            
            //---SEAT---//
            side[0].SetColor( 1.0f, 0.4f, 0.0f );
            side[0].SetSides(   -1.0, 2.5, -1.0, 
                                -1.0, 2.5, 1.0,
                                 1.0, 2.5, 1.0,
                                 1.0, 2.5, -1.0 );
            //Bottom surface
            side[1].SetColor( 0.6f, 0.0f, 0.0f );
            side[1].SetSides(   -1.0, 3.5, -1.0, 
                                -1.0, 3.5, 1.0,
                                 1.0, 3.5, 1.0,
                                 1.0, 3.5, -1.0 );
            //"Forward" surface            
            side[2].SetColor( 0.8f, 0.2f, 0.0f );                    
            side[2].SetSides(   -1.0, 2.5, 1.0,
                                -1.0, 3.5, 1.0,
                                 1.0, 3.5, 1.0,
                                 1.0, 2.5, 1.0 );
            //"Back" surface                     
            side[3].SetColor( 0.6f, 0.2f, 0.0f );           
            side[3].SetSides(    1.0, 2.5, -1.0,
                                 1.0, 3.5, -1.0,
                                -1.0, 3.5, -1.0,
                                -1.0, 2.5, -1.0 );
            //"Left" surface                     
            side[4].SetColor( 1.0f, 0.2f, 0.0f );       
            side[4].SetSides(   -1.0, 2.5, -1.0, 
                                -1.0, 3.5, -1.0, 
                                -1.0, 3.5, 1.0,
                                -1.0, 2.5, 1.0 );
            //"Right" surface                    
            side[5].SetColor( 0.9f, 0.2f, 0.0f );        
            side[5].SetSides(   1.0, 2.5, -1.0,
                                1.0, 3.5, -1.0,
                                1.0, 3.5, 1.0,
                                1.0, 2.5, 1.0 );
            //---LEG 1---//
            //"Forward" surface            
            side[6].SetColor( 0.8f, 0.2f, 0.0f );                    
            side[6].SetSides(   -1.0, 3.5, 1.0,
                                -1.0, 0.0, 1.0,
                                -0.5, 0.0, 1.0,
                                -0.5, 3.5, 1.0 );
            //"Back" surface                     
            side[7].SetColor( 0.6f, 0.2f, 0.0f );           
            side[7].SetSides(   -1.0, 3.5, 0.5,
                                -1.0, 0.0, 0.5,
                                -0.5, 0.0, 0.5,
                                -0.5, 3.5, 0.5 );
            //"Left" surface                     
            side[8].SetColor( 1.0f, 0.2f, 0.0f );       
            side[8].SetSides(   -1.0, 3.5, 0.5,
                                -1.0, 0.0, 0.5,
                                -1.0, 0.0, 1.0,
                                -1.0, 3.5, 1.0 );
            //"Right" surface                    
            side[9].SetColor( 0.9f, 0.2f, 0.0f );        
            side[9].SetSides(   -0.5, 2.5, 0.5,
                                -0.5, 0.0, 0.5,
                                -0.5, 0.0, 1.0,
                                -0.5, 2.5, 1.0 );  
            //---LEG 2---//
            //"Forward" surface            
            side[10].SetColor( 0.8f, 0.2f, 0.0f );                    
            side[10].SetSides(  1.0, 3.5, 1.0,
                                1.0, 0.0, 1.0,
                                0.5, 0.0, 1.0,
                                0.5, 3.5, 1.0 );
            //"Back" surface                     
            side[11].SetColor( 0.6f, 0.2f, 0.0f );           
            side[11].SetSides(  1.0, 3.5, 0.5,
                                1.0, 0.0, 0.5,
                                0.5, 0.0, 0.5,
                                0.5, 3.5, 0.5 );
            //"Left" surface                     
            side[12].SetColor( 1.0f, 0.2f, 0.0f );       
            side[12].SetSides(  1.0, 3.5, 0.5,
                                1.0, 0.0, 0.5,
                                1.0, 0.0, 1.0,
                                1.0, 3.5, 1.0 );
            //"Right" surface                    
            side[13].SetColor( 0.9f, 0.2f, 0.0f );        
            side[13].SetSides(  0.5, 2.5, 0.5,
                                0.5, 0.0, 0.5,
                                0.5, 0.0, 1.0,
                                0.5, 2.5, 1.0 );      
            //---LEG 3---//
            //"Forward" surface            
            side[14].SetColor( 0.8f, 0.2f, 0.0f );                    
            side[14].SetSides(  -1.0, 3.5, -1.0,
                                -1.0, 0.0, -1.0,
                                -0.5, 0.0, -1.0,
                                -0.5, 3.5, -1.0 );
            //"Back" surface                     
            side[15].SetColor( 0.6f, 0.2f, 0.0f );           
            side[15].SetSides(  -1.0, 3.5, -0.5,
                                -1.0, 0.0, -0.5,
                                -0.5, 0.0, -0.5,
                                -0.5, 3.5, -0.5 );
            //"Left" surface                     
            side[16].SetColor( 1.0f, 0.2f, 0.0f );       
            side[16].SetSides(  -1.0, 3.5, -0.5,
                                -1.0, 0.0, -0.5,
                                -1.0, 0.0, -1.0,
                                -1.0, 3.5, -1.0 );
            //"Right" surface                    
            side[17].SetColor( 0.9f, 0.2f, 0.0f );        
            side[17].SetSides(  -0.5, 2.5, -0.5,
                                -0.5, 0.0, -0.5,
                                -0.5, 0.0, -1.0,
                                -0.5, 2.5, -1.0 );  
            //---LEG 4---//
            //"Forward" surface            
            side[18].SetColor( 0.8f, 0.2f, 0.0f );                    
            side[18].SetSides(  1.0, 3.5, -1.0,
                                1.0, 0.0, -1.0,
                                0.5, 0.0, -1.0,
                                0.5, 3.5, -1.0 );
            //"Back" surface                     
            side[19].SetColor( 0.6f, 0.2f, 0.0f );           
            side[19].SetSides(  1.0, 3.5, -0.5,
                                1.0, 0.0, -0.5,
                                0.5, 0.0, -0.5,
                                0.5, 3.5, -0.5 );
            //"Left" surface                     
            side[20].SetColor( 1.0f, 0.2f, 0.0f );       
            side[20].SetSides(  1.0, 3.5, -0.5,
                                1.0, 0.0, -0.5,
                                1.0, 0.0, -1.0,
                                1.0, 3.5, -1.0 );
            //"Right" surface                    
            side[21].SetColor( 0.9f, 0.2f, 0.0f );        
            side[21].SetSides(  0.5, 2.5, -0.5,
                                0.5, 0.0, -0.5,
                                0.5, 0.0, -1.0,
                                0.5, 2.5, -1.0 );
                                
            //---BACK---//
            //"left" surface
            side[22].SetColor( 1.0f, 0.4f, 0.0f );
            side[22].SetSides(  -1, 3.5,    -1,
                                -1, 3.5,    -0.5,
                                -1, 8,      -0.5,
                                -1, 8,      -1 );
            //"right" surface            
            side[23].SetColor( 0.8f, 0.2f, 0.0f );                    
            side[23].SetSides(  1,  3.5,    -1,
                                1,  3.5,    -0.5,
                                1,  8,      -0.5,
                                1,  8,      -1 );
            //"front" surface                     
            side[24].SetColor( 1.0f, 0.2f, 0.0f );           
            side[24].SetSides(  -1.0,   8,      -0.5,
                                -1.0,   3.5,    -0.5,
                                 1,     3.5,    -0.5,
                                 1,     8,      -0.5 );
            //"back" surface                     
            side[25].SetColor( 0.6f, 0.2f, 0.0f );       
            side[25].SetSides(  -1.0,   8,      -1,
                                -1.0,   3.5,    -1,
                                 1,     3.5,    -1,
                                 1,     8,      -1 );
            //"top" surface                    
            side[26].SetColor( 1.0f, 0.4f, 0.0f );        
            side[26].SetSides(  -1.0, 8, -1,
                                -1.0, 8, -0.5,
                                 1.0, 8, -0.5,
                                 1.0, 8, -1 );                
            break;
        case YARD:
            /*
            The yard is made up of the fence on three sides, the grassy
            portion, and the patio portion... a total of five quads.
            */
            sideAmt = 5;
            side = new Side[ sideAmt ];
            
            //Ground
            side[0].SetColor( 0.0f, 1.0f, 0.3f );
            side[0].SetSides(   9.0, 0.0, -24,
                                9.0, 0.0, 24,
                                24, 0.0, 24,
                                24, 0.0, -24 );
            //Fence 1
            side[1].SetColor( 0.8f, 0.2f, 0.3f );
            side[1].SetSides(   0.0, 6.0, -24,
                                0.0, 0.0, -24,
                                24, 0.0, -24,
                                24, 6.0, -24 );
            //Fence 2
            side[2].SetColor( 0.8f, 0.2f, 0.3f );
            side[2].SetSides(   0.0, 6.0, 24,
                                0.0, 0.0, 24,
                                24, 0.0, 24,
                                24, 6.0, 24 );
            //Fence 3
            side[3].SetColor( 1.0f, 0.2f, 0.3f );
            side[3].SetSides(   24, 0.0, -24,
                                24, 6.0, -24,
                                24, 6.0, 24,
                                24, 0.0, 24 );
            //Patio
            side[4].SetColor( 0.6f, 0.6f, 0.6f );
            side[4].SetSides(   0.0, 0.0, -24,
                                0.0, 0.0, 24,
                                9, 0.0, 24,
                                9, 0.0, -24 );
            break;
        case HOUSE:
            /*
            House has three walls for the perimeter, the floor, 
            and one wall inside the house, and then the fourth perimeter
            wall is actually different pieces, to make up the windows
            and door holes.
            */ 
            sideAmt = 19;
            side = new Side[ sideAmt ];
            //Ground
            side[0].SetColor( 0.6f, 0.5f, 1.0f );
            side[0].SetSides(   0.0, 0.0, -24,
                                0.0, 0.0, 24,
                                -24, 0.0, 24,
                                -24, 0.0, -24 );
            //Wall 1
            side[1].SetColor( 0.0f, 0.8f, 1.0f );
            side[1].SetSides(   0.0, 18.0, -24,
                                0.0, 0.0, -24,
                                -24, 0.0, -24,
                                -24, 18.0, -24 );
            //Wall 2
            side[2].SetColor( 0.0f, 0.8f, 1.0f );
            side[2].SetSides(   0.0, 18.0, 24,
                                0.0, 0.0, 24,
                                -24, 0.0, 24,
                                -24, 18.0, 24 );
            //Wall 3
            side[3].SetColor( 0.0f, 0.6f, 1.0f );
            side[3].SetSides(   -24, 0.0, -24,
                                -24, 18.0, -24,
                                -24, 18.0, 24,
                                -24, 0.0, 24 );
            //Wall 4
            side[4].SetColor( 0.0f, 0.8f, 1.0f );
            side[4].SetSides(   -9, 18.0, 6,
                                -9, 0.0,  6,
                                -24, 0.0,  6,
                                -24, 18.0, 6 );
            //Wall 5
            side[5].SetColor( 0.0f, 0.6f, 1.0f );
            side[5].SetSides(   0, 0.0, 18,
                                0, 18.0, 18,
                                0, 18.0, 24,
                                0, 0.0, 24 );
            side[6].SetColor( 0.0f, 0.6f, 1.0f );
            side[6].SetSides(   0, 0.0, -9,
                                0, 18.0, -9,
                                0, 18.0, 15,
                                0, 0.0, 15 );
            side[7].SetColor( 0.0f, 0.6f, 1.0f );
            side[7].SetSides(   0, 0.0, -15,
                                0, 18.0, -15,
                                0, 18.0, -12,
                                0, 0.0, -12 );
            side[8].SetColor( 0.0f, 0.6f, 1.0f );
            side[8].SetSides(   0, 0.0, -24,
                                0, 18.0, -24,
                                0, 18.0, -21,
                                0, 0.0, -21 );
            side[9].SetColor( 0.0f, 0.6f, 1.0f );
            side[9].SetSides(   0, 0.0, -15,
                                0, 3.0, -15,
                                0, 3.0, 24,
                                0, 0.0, 24 );
            side[10].SetColor( 0.0f, 0.6f, 1.0f );
            side[10].SetSides(   0, 9.0, -15,
                                0, 18.0, -15,
                                0, 18.0, 24,
                                0, 9.0, 24 );
            side[11].SetColor( 0.0f, 0.6f, 1.0f );
            side[11].SetSides(   0, 9.0, -15,
                                0, 18.0, -15,
                                0, 18.0, -24,
                                0, 9.0, -24 );
            //Wall 5 (outer side is diff color)
            side[12].SetColor( 0.7f, 0.6f, 0.4f );
            side[12].SetSides(  0.1, 0.0, 18,
                                0.1, 18.0, 18,
                                0.1, 18.0, 24,
                                0.1, 0.0, 24 );
            side[13].SetColor( 0.7f, 0.6f, 0.4f );
            side[13].SetSides(  0.1, 0.0, -9,
                                0.1, 18.0, -9,
                                0.1, 18.0, 15,
                                0.1, 0.0, 15 );
            side[14].SetColor( 0.7f, 0.6f, 0.4f );
            side[14].SetSides(  0.1, 0.0, -15,
                                0.1, 18.0, -15,
                                0.1, 18.0, -12,
                                0.1, 0.0, -12 );
            side[15].SetColor( 0.7f, 0.6f, 0.4f );
            side[15].SetSides(  0.1, 0.0, -24,
                                0.1, 18.0, -24,
                                0.1, 18.0, -21,
                                0.1, 0.0, -21 );
            side[16].SetColor( 0.7f, 0.6f, 0.4f );
            side[16].SetSides(  0.1, 0.0, -15,
                                0.1, 3.0, -15,
                                0.1, 3.0, 24,
                                0.1, 0.0, 24 );
            side[17].SetColor( 0.7f, 0.6f, 0.4f );
            side[17].SetSides(  0.1, 9.0, -15,
                                0.1, 18.0, -15,
                                0.1, 18.0, 24,
                                0.1, 9.0, 24 );
            side[18].SetColor( 0.7f, 0.6f, 0.4f );
            side[18].SetSides(  0.1, 9.0, -15,
                                0.1, 18.0, -15,
                                0.1, 18.0, -24,
                                0.1, 9.0, -24 );
                                
            break;
    }
}
