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

    for (size_t y = 0; y < field.getHeight() + 2; ++y) {
        for (size_t x = 0; x < field.getWidth() + 2; ++x) {
            // top / bottom limits
            if (y == 0 || y == field.getHeight() + 1) {
                // top left corner
                if (x == 0) {
                    std::cout << "+";
                }
                // top right corner
                else if (x == field.getWidth() + 1) {
                    std::cout << "+" << std::endl;
                }
                // top / bottom line
                else {
                    std::cout << "-";
                }
            }
            // left / right limits
            else {
                // left line
                if (x == 0) {
                    std::cout << "|";
                }
                // right line
                else if (x == field.getWidth() + 1) {
                    std::cout << "|" << std::endl;
                }
                // field display
                else {
                    bool printed = false;
                    for (std::weak_ptr<Humanoid> h : field.getHumanoids()) {
                        // If there is a humanoid we display it
                        if (h.lock()->standsHere(x, y)) {
                            std::cout << h.lock()->getSymbol();
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
