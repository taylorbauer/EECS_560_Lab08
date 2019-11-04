//
//  Author: Taylor Bauer
//  Date:   11.3.2019
//          EECS 560
//          Lab 08
//

#ifndef MENU_H
#define MENU_H
#include "MinLeftistHeap.h"


//  The class that handles all user interaction and manages the heap
class Menu {
public:

    // Constructor that requires a pre-existing heap
    Menu(MinLeftistHeap heap);

    //  Run the menu.  This is where all user interaction takes place.
    void run();
private:

    MinLeftistHeap h;

};

#endif