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
    Humanoid(new Move(2, this), _x, _y) {
}

char Buffy::getSymbol() const {
    return 'b';
}

Humanoid *Buffy::getTarget(const Field &field) {
    return (Vampire*) field.getClosest(this);
}

Action* Buffy::getIdleAction(const Field &field) {
    getMove()->setRandomMove(field);
    return getMove();
}

Action* Buffy::getAttackAction(const Field &field, Humanoid *target) {
    return new Kill(target, true);
}