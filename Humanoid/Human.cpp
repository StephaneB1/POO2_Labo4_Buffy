//
// Created by Chau Ying on 10.05.2020.
//

#include <Utils.h>
#include "Human.h"
#include "../Action/Move.h"

#include "../Field.h"


Human::Human(unsigned int _x, unsigned int _y) : Humanoid(new Move(1), _x, _y) {
    setNextAction(getMove());
    getMove()->setHumanoid(this);
}

void Human::setAction(const Field& field) {
    getMove()->setRandomMove(field);
}

char Human::getSymbole() const {
    return 'h';
}

int Human::getDistance(const Vampire* v) const {
    return hypot(abs(getX() - v->getX()), abs(getY() - v->getY()));
}

int Human::getDistance(const Buffy* h) const {
    return -1;
}

Vampire* Human::becomeAVampire() {
    return new Vampire(getX(), getY());
}
