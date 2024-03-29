#pragma once
#include "RachObject.h"

class ObjectManager
{
    private:
        RachObject tabl; 
        RachObject yard;
        RachObject house;
        RachObject chair;
        RachObject chair2;
        RachObject bed;
        RachObject tree;
        bool displayRoom;
    public:
        ObjectManager();
        void InitObjects();
        void DisplayRoom( bool displayRoom ) { this->displayRoom = displayRoom; }
        bool DisplayRoom() { return displayRoom; }
        void DrawObjects();
};


