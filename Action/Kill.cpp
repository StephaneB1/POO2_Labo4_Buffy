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

Kill::Kill(bool targetIsVampire) : targetIsVampire(targetIsVampire) {}

void Kill::setTarget(Humanoid* target) {
    _target = target;
}

void Kill::execute(Field* field) {
    //std::cout << "kill!" << std::endl;
    _target->setIsAlive(false);
    if(targetIsVampire){
        field->decVampire();
    }else{
        field->decHuman();
    }
}


