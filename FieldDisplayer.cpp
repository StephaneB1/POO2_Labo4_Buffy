/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : FieldDisplayer.cpp
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */
#include "FieldDisplayer.h"
#include <iostream>

void FieldDisplayer::display(const Field& field) const {

/*
    std::cout << field.getWidth() << "/" << field.getHeight() << std::endl;

    for (std::shared_ptr<Humanoid> h :field.getHumanoids()) {
            std::cout << h->getSymbole() << " : " << h->getX() << " , " <<h->getY
            () <<std::endl;
    }
*/

    for (size_t y = 0; y < field.getHeight() + 2; ++y) {
        for (size_t x = 0; x < field.getWidth() + 2; ++x) {
            if (y == 0 || y == field.getHeight() + 1) {
                if (x == 0) {
                    std::cout << "+";
                } else if (x == field.getWidth() + 1) {
                    std::cout << "+" << std::endl;
                } else {
                    std::cout << "-";
                }
            } else {
                if (x == 0) {
                    std::cout << "|";
                } else if (x == field.getWidth() + 1) {
                    std::cout << "|" << std::endl;
                } else {
                    // Display Humanoids here
                    bool printed = false;
                    for (std::shared_ptr<Humanoid> h :field.getHumanoids()) {
                        if (h->getX() == x-1 && h->getY() == y-1) {
                            std::cout << h->getSymbole();
                            printed = true;
                            break;
                        }
                    }

                    if (!printed)
                        std::cout << " ";

                }
            }
        }
    }

}
