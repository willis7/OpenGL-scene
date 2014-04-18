#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
    InitObjects();
}

void ObjectManager::InitObjects()
{
    displayRoom = true;
    table.SetupObject( TABLE );
    yard.SetupObject( YARD );
    house.SetupObject( HOUSE );
    chair.SetupObject( CHAIR );
    chair2.SetupObject( CHAIR );
    chair2.SetCoordinates( -10, 0, -12 );
    bed.SetupObject( BED );
    tree.SetupObject( TREE );
}

void ObjectManager::DrawObjects()
{
    if ( displayRoom )
    {
        yard.DrawObject();
        house.DrawObject();
    }
    table.DrawObject();
    bed.DrawObject();
    tree.DrawObject();
    chair.DrawObject();
    chair2.DrawObject();
}
