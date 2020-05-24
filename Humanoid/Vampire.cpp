//
// Created by Chau Ying on 10.05.2020.
//

#include <Utils.h>
#include "Vampire.h"

#include "../Action/Move.h"
#include "Field.h"

Vampire::Vampire(unsigned int _x, unsigned int _y) : Humanoid(new Move(1), _x, _y),
                                                     _bite(new Bite()),
                                                     _kill(new Kill()) {
    getMove()->setHumanoid(this);
}

void Vampire::setAction(const Field& field) {

    Humanoid* target = field.getCloset(this);


    if (target == nullptr) {
        getMove()->setRandomMove(field);
        setNextAction(getMove());
    } else if (abs(getX() - target->getX()) <= 1 &&
               abs(getY() - target->getY()) <= 1) {
        // if humain next to vampire Set target
        //*if (Utils::generateRandom(0, 2)) {
        //_bite->setTarget(target);
        //setNextAction(_bite);
        //} else {
            _kill->setTarget(target);
            setNextAction(_kill);
        //}
    } else {
        Direction moveDir = Direction::getDirection(getX(), getY(), target->getX(),
                                                    target->getY());

        getMove()->setNextPosition(moveDir);
        setNextAction(getMove());
    }
}

Vampire::Vampire(Human* human) : Humanoid(new Move(1), human->getX(), human->getY()),
                                 _bite(new Bite()),
                                 _kill(new Kill()) {
}

char Vampire::getSymbole() const {
    return 'v';
}

int Vampire::getDistance(const Human* h) const{
    return hypot(abs(getX() - h->getX()), abs(getY() -h->getY()));
}

int Vampire::getDistance(const Vampire* v)  const{
    return -1;
}



