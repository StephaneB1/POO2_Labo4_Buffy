/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : Kill.cpp
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */

#include "Kill.h"
#include "../Field.h"

void Kill::setTarget(Humanoid* target) {
    _target = target;
}

void Kill::execute(Field* field) {
    _target->setIsAlive(false);
}


