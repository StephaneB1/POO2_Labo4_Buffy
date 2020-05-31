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

Bite::Bite(Human* target) : _target(target) {
}

void Bite::execute(Field* field) {
    field->replace(_target, new Vampire(_target), false);
}

Bite::~Bite() {
}
