/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : BuffyController.cpp
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */
#include <iostream>
#include <vector>
#include <iterator>
#include "BuffyController.h"

BuffyController::BuffyController()
: _simulating(false) {

}

void BuffyController::start(size_t width, size_t height, unsigned totalHumans, unsigned totalVampire) {

    // Create new field for the current simulation
    Field field(width, height);

    _simulating = true;

    std::string input;


    do {
        _displayer.display(field);
        std::cout << "[4] " << "q>uit s>tatistics n>ext: ";
        std::getline(std::cin, input);
        std::cout << "\b";
        if(input.length() != 1) {

        } else {
            switch (input[0]) {
                case 'n':

                    break;
                case 's':

                    break;
                default:

                    break;
            }
        }
    } while(input[0] != 'q');



}


