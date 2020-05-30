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

    BuffyController controller;
    controller.start(50, 20, 10, 5);

    return EXIT_SUCCESS;
}
