/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : Move.cpp
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
---------
 --------------------------------------------------------------------------
 */
#include "Action.h"
#include "../Utils.h"
#include <iostream>
#include "Move.h"

#include "../Field.h"

Move::Move(unsigned int _stepRange) : _stepRange(_stepRange), _toY(0), _toX(0) {}

void Move::execute(Field* field) {
    getHumanoid()->setY(_toY);
    getHumanoid()->setX(_toX);
}

void Move::setRandomMove(const Field& field) {
    std::vector<Direction> possibleDirection = getPossibleDirections(field);

    Direction nextDirection = possibleDirection.at(
            Utils::generateRandom(0, possibleDirection.size()));

    setNextPosition(nextDirection);
}

void Move::setNextPosition(const Direction& nextDirection) {
    _toX = getHumanoid()->getX() + nextDirection.getX() * _stepRange;
    _toY = getHumanoid()->getY() + nextDirection.getY() * _stepRange;
}

std::vector<Direction> Move::getPossibleDirections(const Field& field) const {
    std::vector<Direction> possibleDirection;

    unsigned int humX = _humanoid->getX();
    unsigned int humY = _humanoid->getY();

    if (humX >= _stepRange) {
        possibleDirection.push_back(Direction::LEFT);
    }

    if (humX >= _stepRange && humY >= _stepRange) {
        possibleDirection.push_back(Direction::UP_LEFT);
    }

    if (humX >= _stepRange && humY < field.getHeight() - _stepRange) {
        possibleDirection.push_back(Direction::DOWN_LEFT);
    }

    if (humX < field.getWidth() - _stepRange) {
        possibleDirection.push_back(Direction::RIGHT);
    }

    if (humX < field.getWidth() - _stepRange && humY >= _stepRange) {
        possibleDirection.push_back(Direction::UP_RIGHT);
    }

    if (humX < field.getWidth() - _stepRange && humY < field.getHeight() - _stepRange) {
        possibleDirection.push_back(Direction::DOWN_RIGHT);
    }

    if (humY >= _stepRange) {
        possibleDirection.push_back(Direction::UP);
    }

    if (humY < field.getHeight() - _stepRange) {
        possibleDirection.push_back(Direction::DOWN);
    }

    return possibleDirection;
}


void Move::setHumanoid(Humanoid* _humanoid) {
    Move::_humanoid = _humanoid;
}

Humanoid* Move::getHumanoid() const {
    return _humanoid;
}