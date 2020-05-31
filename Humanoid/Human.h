/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : Human.cpp
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */


#ifndef POO2_LABO4_BUFFY_HUMAIN_H
#define POO2_LABO4_BUFFY_HUMAIN_H


#include "Humanoid.h"

class Field;

class Human: public Humanoid {

public:

    Human(unsigned int _x, unsigned int _y);

    char getSymbol() const override;

    int getDistance(const Vampire* v) const override;
};


#endif //POO2_LABO4_BUFFY_HUMAIN_H
