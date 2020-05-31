/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : Move.cpp
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */
#include "Action.h"
#include "../Utils.h"
#include "Move.h"

#include "../Field.h"

Move::Move(unsigned int _stepRange, Humanoid* humanoid)
        : _stepRange(_stepRange), _humanoid(humanoid), _toY(0), _toX(0) {
}

void Move::execute(Field* field) {
    getHumanoid()->setY(_toY);
    getHumanoid()->setX(_toX);
}

void Move::setRandomMove(const Field& field) {
    std::vector<Direction> possibleDirection = getPossibleDirections(field);

    Direction nextDirection = possibleDirection.at(
            Utils::generateRandom(0, possibleDirection.size()));

    setNextPosition(nextDirection, field);
}

void Move::setNextPosition(const Direction& nextDirection, const Field& field) {
    int newX = getHumanoid()->getX() + nextDirection.getX() * _stepRange;
    int newY = getHumanoid()->getY() + nextDirection.getY() * _stepRange;
    // without an explicit cast, the compiler cast into unsigned
    if (newX >= (int) field.getWidth()) {
        _toX = field.getWidth() - 1;
    } else if (newX < 0) {
        _toX = 0;
    } else {
        _toX = newX;
    }

    if (newY >= (int) field.getHeight()) {
        _toY = field.getHeight() - 1;
    } else if (newY < 0) {
        _toY = 0;
    } else {
        _toY = newY;
    }


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

    if (humX < field.getWidth() - _stepRange &&
        humY < field.getHeight() - _stepRange) {
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

Humanoid* Move::getHumanoid() const {
    return _humanoid;
}

unsigned int Move::get_stepRange() const {
    return _stepRange;
}

Move::~Move() {

}
