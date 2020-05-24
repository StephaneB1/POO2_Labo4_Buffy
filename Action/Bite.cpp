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

void Bite::setTarget(Human* humanoid) {
    _target = humanoid;
}

void Bite::execute(Field* field) {
    field->replace(_target, _target->becomeAVampire());
}
