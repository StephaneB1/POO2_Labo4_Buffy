//
// Created by Chau Ying on 24.05.2020.
//

#include <cmath>
#include "Buffy.h"
#include "Vampire.h"

#include "../Action/Move.h"
#include "Field.h"

Buffy::Buffy(unsigned int _x, unsigned int _y) :
        Humanoid(new Move(2), _x, _y), _kill(new Kill) {
    getMove()->setHumanoid(this);
}

void Buffy::setAction(const Field& field) {

    Vampire* target = (Vampire*) field.getCloset(this);

    if (target == nullptr) {
        getMove()->setRandomMove(field);
        setNextAction(getMove());
    } else if (abs(getX() - target->getX()) <= 1 &&
               abs(getY() - target->getY()) <= 1) {

        _kill->setTarget(target);
        setNextAction(_kill);
    } else {
        Direction moveDir = Direction::getDirection(getX(), getY(),
                                                    target->getX(),
                                                    target->getY());

        getMove()->setNextPosition(moveDir);
        setNextAction(getMove());
    }
}

char Buffy::getSymbole() const {
    return 'b';
}

int Buffy::getDistance(const Buffy* h) const {
    return -1;
}

int Buffy::getDistance(const Vampire* v) const {
    return -1;
}
