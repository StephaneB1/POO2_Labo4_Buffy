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

/*Kill::Kill(Humanoid *target, bool targetIsVampire)
        : _target(target), _targetIsVampire(targetIsVampire) {
}*/

void Kill::execute(Field* field) {
    // Replace the target by nothing (= kill)
    _target.lock()->kill();
}


Kill::~Kill() {

}

Kill::Kill(bool targetIsVampire) : _targetIsVampire(targetIsVampire){

}

void Kill::setTarget(std::weak_ptr<Humanoid> target) {
    _target = target;
}


