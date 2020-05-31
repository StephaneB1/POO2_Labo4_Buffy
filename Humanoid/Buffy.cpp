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
    Humanoid(new Move(2, this), _x, _y), _kill(new Kill(true)) {
}

char Buffy::getSymbol() const {
    return 'b';
}

std::weak_ptr<Humanoid> Buffy::getTarget(const Field &field) {
    return field.getClosest(weak_from_this());
}

Action* Buffy::getAttackAction(const Field &field, std::weak_ptr<Humanoid>target) {
    _kill->setTarget(target);
    return _kill;
}

Buffy::~Buffy() {
}

std::shared_ptr<Buffy> Buffy::getBuffy() {
    return  shared_from_this();
}

