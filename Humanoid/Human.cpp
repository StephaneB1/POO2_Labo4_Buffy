/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : Human.cpp
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */

#include "../Utils.h"
#include "Human.h"
#include "../Action/Move.h"

#include "../Field.h"


Human::Human(unsigned int _x, unsigned int _y)
: Humanoid(new Move(1, this), _x, _y) {
}

char Human::getSymbol() const {
    return 'h';
}

int Human::getDistance(const Vampire* v) const {
    return Humanoid::getDistance((Humanoid*) v);
}

Human::~Human() {

}
