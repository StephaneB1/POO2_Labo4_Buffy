/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : BuffyController.cpp
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */
#include <iostream>
#include "BuffyController.h"

BuffyController::BuffyController()
        : _simulating(false) {

}

void BuffyController::start(size_t width, size_t height, unsigned totalHumans,
                            unsigned totalVampire) {

    // Create new field for the current simulation
    Field field(width, height, totalHumans, totalVampire);
    _simulating = true;

    std::string input;

    bool quitting = false;

    std::cout << "\nWelcome to the Buffy simulator !\n"
              << "   >> PRESS \'n\' TO START <<   \n\n";

    do {
        std::cout << "[" << field.getTurn() << "] " << "q>uit s>tatistics n>ext: ";
        std::getline(std::cin, input);
        std::cout << "\b";
        if (input.length() != 1) {
            displayErrorMsg(
                    "Invalid input length.\n\t-> Must be one character only.");
        } else {
            switch (input[0]) {
                case 'n':
                    field.nextTurn();
                    _displayer.display(field);
                    break;
                case 's':
                    displayStats(width, height, totalHumans, totalVampire);
                    break;
                case 'q':
                    quitting = true;
                    break;
                default:
                    displayErrorMsg("Unknown command. Please try again.");
                    break;
            }
        }
    } while (!quitting);
}

void BuffyController::displayErrorMsg(const std::string& msg) {
    std::cout << "/!\\ Error : " << msg << std::endl;
}

void BuffyController::displayStats(size_t width, size_t height,
        unsigned totalHumans, unsigned totalVampire) {

    double success = 0;
    Field field(width, height, totalHumans, totalVampire);

    std::cout << "Simulating [";

    for(int i = 0; i < TOTAL_SIMULATION; ++i) {
        field.reset();
        field.init();

        do {
            field.nextTurn();
        } while (!field.isFreeOfVampires());

        if(field.hasHumans())
            success++;

        // Loading animation
        if((i % (TOTAL_SIMULATION / 30)) == 0)
            std::cout << ".";
    }

    std::cout << "]" << std::endl;

    std::cout << "Buffy success rate for " << TOTAL_SIMULATION
              << " simulations : "
              << (success / TOTAL_SIMULATION) * 100 << "%" <<
              std::endl;
}

