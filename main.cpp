/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : main.cpp
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */


#include <cstdlib>
#include "Action/Move.h"
#include "Humanoid/Human.h"
#include "BuffyController.h"

using namespace std;

int main() {

    // Target stats : ~16%
    BuffyController controller;
    controller.start(50, 30, 20, 10);


/*
    Field f(10, 10);
    Human h(5, 5);
    cout << h.getX() << " " << h.getY() << endl;
    h.setAction(f);
    h.executeAction(f);
    cout << h.getX() << " " << h.getY() << endl;

    Vampire v(6,6);
    v.setAction(f);
    v.executeAction(f);*/

    return EXIT_SUCCESS;
}
