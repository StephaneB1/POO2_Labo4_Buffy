/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : Vampire.cpp
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */


#include <iostream>
#include "../Utils.h"
#include "Vampire.h"

#include "../Action/Move.h"
#include "../Action/Kill.h"
#include "../Action/Bite.h"
#include "../Field.h"

Vampire::Vampire(int _x, int _y)
        : Humanoid(new Move(1, this), _x, _y),
          _kill(new Kill(false)),
          _bite(new Bite()) {
}

Vampire::Vampire(const std::shared_ptr<Human>& h) : Vampire(h->getX(), h->getY()) {
}

char Vampire::getSymbol() const {
    return 'v';
}

int Vampire::getDistanceTo(const std::shared_ptr<Buffy>& b) const {
    return Utils::getEuclideanDistance(getX(), getY(), b->getX(),
                                       b->getY());

}

std::shared_ptr<Humanoid> Vampire::getTarget(const Field& field) {
    return field.getClosest<Vampire>(shared_from_this());
}

Action*
Vampire::getAttackAction(const Field& field, const std::shared_ptr<Humanoid>& target) {
    // 50/50 between bite and kill human

    if (Utils::generateRandom(0, 2)) {
        _kill->setTarget(target);
        return _kill;
    } else {
        _bite->setTarget(target);
        return _bite;
    }
}

Action* Vampire::getIdleAction(const Field& field) {
    // Do nothing
    return nullptr;
}

Vampire::~Vampire() {
    delete _kill;
    delete _bite;
}
