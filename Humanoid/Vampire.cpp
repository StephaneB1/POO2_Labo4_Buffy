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

char Vampire::getSymbol() const {
    return 'v';
}

int Vampire::getDistance(const Buffy* h) const {
    return (int) hypot(abs(getX() - h->getX()), abs(getY() - h->getY()));
}

Humanoid *Vampire::getTarget(const Field& field) {
    return (Human*) field.getClosest(this);
}

void Vampire::setIdleAction(const Field &field) {
    setNextAction(nullptr);
}

void Vampire::setAttackAction(const Field &field, Humanoid* target) {
    // 50/50 between bite and kill human
    setNextAction(Utils::generateRandom(0, 2) == 0 ?
                  (Action*) new Bite((Human*) target) :
                  (Action*) new Kill(target, false));
}