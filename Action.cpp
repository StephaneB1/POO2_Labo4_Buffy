//
// Created by Chau Ying on 05.05.2020.
//

#include "Action.h"

unsigned int Action::getStepRange() const {
    return _stepRange;
}

Action::Action(unsigned int _stepRange) : _stepRange(_stepRange) {}

void Action::move() {

}
