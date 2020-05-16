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

    bool quitting = false;

    do {
        _displayer.display(field);
        std::cout << "[4] " << "q>uit s>tatistics n>ext: ";
        std::getline(std::cin, input);
        std::cout << "\b";
        if(input.length() != 1) {
            displayErrorMsg("Input too long. \n    -> Must be one character only.");
        } else {
            switch (input[0]) {
                case 'n':

                    break;
                case 's':

                    break;
                case 'q':
                    quitting = true;
                    break;
                default:
                    displayErrorMsg("Unknown command. Please try again.");
                    break;
            }
        }
    } while(!quitting);
}

void BuffyController::displayErrorMsg(const std::string &msg) {
    std::cout << "/!\\ Error : " << msg << std::endl;
}

