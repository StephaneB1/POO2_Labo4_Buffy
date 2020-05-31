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

char Buffy::getSymbol() const {
    return 'b';
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