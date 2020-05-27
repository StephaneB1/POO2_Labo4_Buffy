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

Humanoid::Humanoid(Move* _move, unsigned int _x, unsigned int _y) :
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


