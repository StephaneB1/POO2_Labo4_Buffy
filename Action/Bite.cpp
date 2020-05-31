/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : Bite.cpp
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */

#include "Bite.h"

#include "../Field.h"

void Bite::execute(Field* field) {
    if(_target.lock()->isAlive()) {
        field->kill(_target, false);
        field->replaceByAVampire(_target);
    }
}

Bite::~Bite() {
}

Bite::Bite() {}


void Bite::setTarget(std::weak_ptr<Humanoid> target) {
    _target = target;
}
