//
// Created by Chau Ying on 09.05.2020.
//

#include <Utils.h>
#include "Move.h"

Move::Move(unsigned int _stepRange) : _stepRange(_stepRange) {}

void Move::setDirection(Move::Direction direction) {
    _direction = direction;
}

Move::Direction Move::getRandomDirection() const {
    return Direction(Utils::generateRandom(0, 7));
}

void Move::execute(const Field& field) {

}
