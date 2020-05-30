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

Vampire::Vampire(unsigned int _x, unsigned int _y) : Humanoid(new Move(1), _x, _y),
                                                     _bite(new Bite()),
                                                     _kill(new Kill(false)) {
    getMove()->setHumanoid(this);
}

Vampire::Vampire(Human* h) : Vampire(h->getX(), h->getY()) {

}

void Vampire::setAction(const Field& field) {

    Human* target = (Human*) field.getClosest(this);


    if (target == nullptr) {
        setNextAction(nullptr);
        return;
    } else if (abs(getX() - target->getX()) <= 1 &&
               abs(getY() - target->getY()) <= 1) {
        if (Utils::generateRandom(0, 2)) {
            _bite->setTarget(target);
            setNextAction(_bite);
        } else {
            _kill->setTarget(target);
            setNextAction(_kill);
        }
    } else {
        Direction moveDir = Direction::getDirection(getX(), getY(), target->getX(),
                                                    target->getY());

        getMove()->setNextPosition(moveDir, field);
        setNextAction(getMove());
    }
}

char Vampire::getSymbol() const {
    return 'v';
}

int Vampire::getDistance(const Buffy* h) const {
    return (int) hypot(abs(getX() - h->getX()), abs(getY() - h->getY()));
}

int Vampire::getDistance(const Vampire* v) const {
    return -1;
}



