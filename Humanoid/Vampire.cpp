/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : Vampire.cpp
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */


#include "../Utils.h"
#include "Vampire.h"

#include "../Action/Move.h"
#include "../Field.h"

Vampire::Vampire(unsigned int _x, unsigned int _y) : Humanoid(new Move(1), _x, _y) {
    getMove()->setHumanoid(this);
}

Vampire::Vampire(Human* h) : Vampire(h->getX(), h->getY()) {

}

/*void Vampire::setAction(const Field& field) {

    Human* target = (Human*) field.getClosest(this);


    if (target == nullptr) {
        setNextAction(nullptr);
        return;
    } else if (Utils::isNextToTarget(this, target)) {
        // Attack (50/50) : bite or kill for the next action
        setNextAction(Utils::generateRandom(0, 2) == 0 ?
                      (Action*) new Bite(target) :
                      (Action*) new Kill(target, false));
    } else {
        Direction moveDir = Direction::getDirection(getX(), getY(), target->getX(),
                                                    target->getY());

        getMove()->setNextPosition(moveDir, field);
        setNextAction(getMove());
    }
}*/

char Vampire::getSymbol() const {
    return 'v';
}

int Vampire::getDistance(const Buffy* h) const {
    return (int) hypot(abs(getX() - h->getX()), abs(getY() - h->getY()));
}

int Vampire::getDistance(const Vampire* v) const {
    return -1;
}

Humanoid *Vampire::getTarget(const Field& field) {
    return (Human*) field.getClosest(this);
}

void Vampire::setIdleAction(const Field &field) {
    setNextAction(nullptr);
}

void Vampire::setAttackAction(const Field &field, Humanoid* target) {
    setNextAction(Utils::generateRandom(0, 2) == 0 ?
                  (Action*) new Bite((Human*) target) :
                  (Action*) new Kill(target, false));
}

void Vampire::setDefaultAction(const Field &field, Humanoid* target) {
    Direction moveDir = Direction::getDirection(getX(), getY(), target->getX(),
                                                target->getY());

    getMove()->setNextPosition(moveDir, field);
    setNextAction(getMove());
}

