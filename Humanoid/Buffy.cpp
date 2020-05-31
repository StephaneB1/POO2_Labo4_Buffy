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
#include "../Utils.h"

Buffy::Buffy(unsigned int _x, unsigned int _y) :
    Humanoid(new Move(2), _x, _y) {
    getMove()->setHumanoid(this);
}

/*void Buffy::setAction(const Field& field) {

    Vampire* target = (Vampire*) field.getClosest(this);

    // If Null (Zero Vampire in the board)
    if (target == nullptr) {
        getMove()->setRandomMove(field);
        setNextAction(getMove());
    }
    // If next to a Vampire : attack
    else if (Utils::isNextToTarget(this, target)) {
        setNextAction(new Kill(target, true));
    }
    // Else Buffy will chase the Vampire
    else {
        Direction moveDir = Direction::getDirection(getX(), getY(),
                                                    target->getX(),
                                                    target->getY());

        getMove()->setNextPosition(moveDir, field);
        setNextAction(getMove());
    }
}*/

char Buffy::getSymbol() const {
    return 'b';
}

int Buffy::getDistance(const Buffy* b) const {
    return -1;
}

int Buffy::getDistance(const Vampire* v) const {
    return -1;
}

Humanoid *Buffy::getTarget(const Field &field) {
    return (Vampire*) field.getClosest(this);
}

void Buffy::setIdleAction(const Field &field) {
    getMove()->setRandomMove(field);
    setNextAction(getMove());
}

void Buffy::setAttackAction(const Field &field, Humanoid *target) {
    setNextAction(new Kill(target, true));
}

/*void Buffy::setChaseAction(const Field &field, Humanoid *target) {
    Direction moveDir = Direction::getDirection(getX(), getY(),
                                                target->getX(),
                                                target->getY());

    getMove()->setNextPosition(moveDir, field);
    setNextAction(getMove());
}*/
