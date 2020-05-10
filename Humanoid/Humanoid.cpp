//
// Created by Chau Ying on 05.05.2020.
//

#include "Humanoid.h"

#include "Action/Action.h"
#include "../Field.h"

Humanoid::Humanoid(unsigned int _x, unsigned int _y, std::list<Action*> action) : _x(_x),
                                                                             _y(_y),
                                                                                  _actionList(action),
                                                                             _isAlive(true) {}

bool Humanoid::isAlive() const {
    return _isAlive;
}

void Humanoid::executeAction(const Field& field) {
    _nextAction->execute(field);
}

unsigned int Humanoid::getX() const {
    return _x;
}

unsigned int Humanoid::getY() const {
    return _y;
}

void Humanoid::setX(unsigned int _x) {
    Humanoid::_x = _x;
}

void Humanoid::setY(unsigned int _y) {
    Humanoid::_y = _y;
}

