//
// Created by Chau Ying on 10.05.2020.
//

#include <Utils.h>
#include "Vampire.h"

#include "../Action/Move.h"
#include "Field.h"

Vampire::Vampire(unsigned int _x, unsigned int _y) : Humanoid(new Move(1), _x, _y),
                                                     _bite(new Bite()),
                                                     _kill(new Kill()) {}

void Vampire::setAction(const Field& field) {

    if (false) {// if humain next to vampire
        // Set target
        if (Utils::generateRandom(0, 2)) {
            setNextAction(_bite);
        } else {
            setNextAction(_kill);
        }
    } else {
        Humanoid* target = field.getCloset(this);
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



