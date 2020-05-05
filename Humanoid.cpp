//
// Created by Chau Ying on 05.05.2020.
//

#include "Humanoid.h"

bool Humanoid::isAlive() const {
    return _isAlive;
}

Humanoid::Humanoid(unsigned int _x, unsigned int _y, const Action& action) : _x(_x),
                                                                             _y(_y),
                                                                             _action(action),
                                                                             _isAlive(true) {}
