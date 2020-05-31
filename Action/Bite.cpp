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
    field->replace(_target);
}

Bite::~Bite() {
}

Bite::Bite() {}

Bite::Bite(const std::weak_ptr<Human>& _target) : _target(_target) {}

void Bite::setTarget(std::weak_ptr<Humanoid> target) {
    _target = target;
}
