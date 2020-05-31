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

int Human::getDistanceTo(std::weak_ptr<Vampire> v) const {
    return (int) hypot(abs((int) getX() - v.lock()->getX()),
                       abs((int) getY() - v.lock()->getY()));
}

Human::~Human() {

}
