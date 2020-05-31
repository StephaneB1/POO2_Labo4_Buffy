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

Humanoid::Humanoid(Move* _move, unsigned int _x, unsigned int _y) :
        _move(_move), _x(_x), _y(_y), _isAlive(true), _nextAction(nullptr) {}

Humanoid::~Humanoid() {
    delete _move;
    delete _nextAction;
}

bool Humanoid::isAlive() const {
    return _isAlive;
}

void Humanoid::executeAction(Field* field) {
    if (_nextAction != nullptr) {
        _nextAction->execute(field);
    }
}

void Humanoid::setNextAction(Action* nextAction) {
    _nextAction = nextAction;
}

unsigned int Humanoid::getX() const {
    return _x;
}

void Humanoid::setX(unsigned int x) {
    _x = x;
}

unsigned int Humanoid::getY() const {
    return _y;
}

void Humanoid::setY(unsigned int y) {
    _y = y;
}

Move* Humanoid::getMove() const {
    return _move;
}

void Humanoid::setIsAlive(bool isAlive) {
    _isAlive = isAlive;
}

bool Humanoid::standsHere(unsigned int x, unsigned int y) {
    return _x + 1 == x && _y + 1 == y;
}

void Humanoid::setAction(const Field &field) {
    Humanoid* target = getTarget(field);

    if (target == nullptr) {
        _nextAction = getIdleAction(field);
    } else if (Utils::isNextToTarget(this, target)) {
        _nextAction = getAttackAction(field, target);
    } else {
        _nextAction = getChaseAction(field, target);
    }
}

Humanoid *Humanoid::getTarget(const Field &field) {
    // No target by default
    return nullptr;
}

Action *Humanoid::getIdleAction(const Field &field) {
    // no idle action by default
    return nullptr;
}

Action* Humanoid::getAttackAction(const Field &field, Humanoid *target) {
    // No attack by default
    return nullptr;
}

Action* Humanoid::getChaseAction(const Field &field, Humanoid *target) {
    // Chase target by default
    Direction moveDir = Direction::getDirection(getX(), getY(),
            target->getX(), target->getY());

    _move->setNextPosition(moveDir, field);
    return _move;
}

int Humanoid::getDistance(const Buffy *b) const {
    return -1;
}

int Humanoid::getDistance(const Vampire *v) const {
    return -1;
}
