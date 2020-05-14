//
// Created by Chau Ying on 09.05.2020.
//

#include "Bite.h"

#include "../Field.h"

void Bite::setTarget(Human* humanoid) {
    _target = humanoid;
}

void Bite::execute(Field field) {
    //field.replace(_target, new Vampire(_target));
}
