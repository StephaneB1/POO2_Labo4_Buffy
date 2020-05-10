//
// Created by Chau Ying on 09.05.2020.
//

#include "Move.h"

Move::Move(unsigned int _stepRange) : _stepRange(_stepRange) {}

void Move::setDirection(Move::Direction direction) {
    _direction = direction;
}
