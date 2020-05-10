//
// Created by Chau Ying on 05.05.2020.
//

#include "Humanoid.h"

#include "Action/Action.h"
#include "../Field.h"

Humanoid::Humanoid(Move* _move, unsigned int _x, unsigned int _y) : _move(_move),
                                                                    _x(_x), _y(_y) {}

bool Humanoid::isAlive() const {
    return _isAlive;
}

void Humanoid::executeAction(const Field& field) {
    _nextAction->execute(field);
}

void Humanoid::setNextAction(Action* nextAction) {
    _nextAction = nextAction;
}


Action* Humanoid::getNextAction() const {
    return _nextAction;
}

unsigned int Humanoid::getX() const {
    return _x;
}

void Humanoid::setX(unsigned int x) {
    Humanoid::_x = x;
}

unsigned int Humanoid::getY() const {
    return _y;
}

void Humanoid::setY(unsigned int y) {
    Humanoid::_y = y;
}

Move* Humanoid::getMove() const {
    return _move;
}

