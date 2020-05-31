/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : Kill.cpp
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */

#include <iostream>
#include "Kill.h"
#include "../Field.h"

Kill::Kill(bool targetIsVampire) : Kill(nullptr, targetIsVampire) {}

void Kill::setTarget(Humanoid* target) {
    _target = target;
}

void Kill::execute(Field* field) {
    _target->setIsAlive(false);
    if(_targetIsVampire){
        field->decVampire();
    }else{
        field->decHuman();
    }
}

Kill::Kill(Human *target, bool targetIsVampire) : _target(target),
                                                  _targetIsVampire(targetIsVampire) {

}


