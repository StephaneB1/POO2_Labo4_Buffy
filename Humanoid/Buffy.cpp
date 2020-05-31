/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : Buffy.cpp
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */

#include "Buffy.h"
#include "Vampire.h"

#include "../Action/Move.h"
#include "../Field.h"

Buffy::Buffy(unsigned int _x, unsigned int _y) :
    Humanoid(new Move(2), _x, _y) {
    getMove()->setHumanoid(this);
}

void Buffy::setAction(const Field& field) {

    Vampire* target = (Vampire*) field.getClosest(this);

    if (target == nullptr) { // If Null (Zero Vampire in the board)
        getMove()->setRandomMove(field);
        setNextAction(getMove());
    } else if (abs(getX() - target->getX()) <= 1 &&
               abs(getY() - target->getY()) <= 1) { // If next to a Vampire
        setNextAction(new Kill(target, true));
    } else {

        Direction moveDir = Direction::getDirection(getX(), getY(),
                                                    target->getX(),
                                                    target->getY());

        getMove()->setNextPosition(moveDir, field);
        setNextAction(getMove());
    }
}

char Buffy::getSymbol() const {
    return 'b';
}

int Buffy::getDistance(const Buffy* b) const {
    return -1;
}

int Buffy::getDistance(const Vampire* v) const {
    return -1;
}
