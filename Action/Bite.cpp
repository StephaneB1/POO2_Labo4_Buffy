/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : Bite.cpp
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */

#include <iostream>
#include "Bite.h"

#include "../Field.h"

void Bite::setTarget(Human* humanoid) {
    _target = humanoid;
}

void Bite::execute(Field* field) {
    //std::cout << "Biting : " << _target->getSymbol() << std::endl;
    field->replace(_target, _target->becomeAVampire());
}
