/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : Humanoid.cpp
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */

#include "Humanoid.h"

#include "../Action/Action.h"
#include "../Field.h"
#include "../Utils.h"
#include "../Direction.h"
#include "../Action/Move.h"

Humanoid::Humanoid(Move* _move, int _x, int _y) :
        _move(_move), _x(_x), _y(_y), _isAlive(true), _nextAction(nullptr) {}

Humanoid::~Humanoid() {

}

bool Humanoid::isAlive() const {
    return _isAlive;
}

void Humanoid::executeAction(Field* field) {
    if (_nextAction != nullptr) {
        _nextAction->execute(field);
    }
}

int Humanoid::getX() const {
    return _x;
}

int Humanoid::getY() const {
    return _y;
}

void Humanoid::kill() {
    _isAlive = false;
}

bool Humanoid::standsHere(unsigned int x, unsigned int y) {
    return _x + 1 == x && _y + 1 == y;
}

void Humanoid::setAction(const Field& field) {
    std::weak_ptr<Humanoid> target = getTarget(field);

    if (target.expired()) {
        // No target to chase or to kill
        _nextAction = getIdleAction(field);
    } else if (Utils::isNextToTarget(this, target)) {
        // Target is close enough for a kill
        _nextAction = getAttackAction(field, target);
    } else {
        // Target is too far : the chase has begun !
        _nextAction = getChaseAction(field, target);
    }
}

std::weak_ptr<Humanoid> Humanoid::getTarget(const Field& field) {
    // No target by default
    return std::weak_ptr<Humanoid>();
}

Action* Humanoid::getIdleAction(const Field& field) {
    // Random walking on the field by default
    _move->setRandomMove(field);
    return _move;
}

Action*
Humanoid::getAttackAction(const Field& field,const std::weak_ptr<Humanoid>& target) {
    // No attack by default
    return nullptr;
}

Action*
Humanoid::getChaseAction(const Field& field, const std::weak_ptr<Humanoid>& target){
    // Chase target by default
    Direction moveDir = Direction::getDirection(getX(), getY(),
                                                target.lock()->getX(),
                                                target.lock()->getY());

    _move->setNextPosition(moveDir, field);
    return _move;
}

int Humanoid::getDistanceTo(std::weak_ptr<Buffy> b) const {
    return -1;
}

int Humanoid::getDistanceTo(std::weak_ptr<Vampire> v) const {
    return -1;
}

void Humanoid::setPosition(int x, int y) {
    _x = x;
    _y = y;
}

