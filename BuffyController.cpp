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

BuffyController::BuffyController(size_t width, size_t height)
: _field(Field(width, height)), _simulating(false) {

}

void BuffyController::start(unsigned totalHumans, unsigned totalVampire) {

    _simulating = true;

    std::string input;
    std::vector<std::string> cmd;

    std::istringstream iss;
    do {

        // User input
        do {
            // TODO : Add real turn value
            std::cout << "[0"  << "]";
            std::getline(std::cin, input);
            iss = std::istringstream(input);
            cmd = std::vector<std::string>(
                    (std::istream_iterator<std::string>(iss)),
                    std::istream_iterator<std::string>());
        } while ((cmd.size() > 2 || cmd.empty() || cmd.front().size() != 1) &&
                 /*displayErrorMsg("Commande non valide")*/);

        // Commands operations
        switch (cmd.at(0).at(0)) {
            case 'n':

                break;
            case 's':

                break;
            default:
                //displayErrorMsg("Commande inconnue");
                break;
        }

        /*if (hasWon()) {
            std::cout << "Bravo! Vous avez gagne en "
                      << turn << " tour!" << std::endl;
            break;
        }*/

        fflush(stdin);
    } while (cmd.at(0).at(0) != 'q');


}


