//
// Created by Chau Ying on 09.05.2020.
//

#include "Kill.h"
#include "../Field.h"

void Kill::setTarget(Humanoid* target) {
    _target = target;
}

void Kill::execute(Field field) {
    _target->set_isAlive(false);
}


