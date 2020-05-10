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

