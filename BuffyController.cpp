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

    std::cout << "\nWelcome to the Buffy simulator !\n"
              << "   >> PRESS \'n\' TO START <<   \n\n";

    do {
        std::cout << "[" << field.nextTurn() << "] " << "q>uit s>tatistics n>ext: ";
        std::getline(std::cin, input);
        std::cout << "\b";
        if(input.length() != 1) {
            displayErrorMsg("Invalid input length.\n    -> Must be one character only.");
        } else {
            switch (input[0]) {
                case 'n':
                    _displayer.display(field);

                    break;
                case 's':
                    /*for(int i = 0; i < TOTAL_SIMULATION; ++i) {
                        PSEUDO CODE
                        (1) Resetting the positions of the humanoids randomly on the field
                        field.resetPositions()

                        (2) Simulate the field actions until there's no vampires left
                        do {

                        } while (field.isFreeOfVampires())

                        (3) update information on display (buffy success)
                        buffyAttempts++;
                        if(!field.isFreeOfHumans()) buffySuccess++;

                    }
                    std::cout << "Buffy success rate : "
                              << buffyAttempts / buffySucess * 100 << std::endl*/
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

