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
    getHumanoid()->setPosition(_toX, _toY);
}

void Move::setRandomMove(const Field& field) {
    std::vector<Direction> possibleDirection = getPossibleDirections(field);

    // Choose a random direction in the possible list
    Direction nextDirection = possibleDirection.at(
            Utils::generateRandom(0, possibleDirection.size()));

    setNextPosition(nextDirection, field);
}

void Move::setNextPosition(const Direction& nextDirection, const Field& field) {

    // if the new position is outside the board, we replace inside the board
    _toX = getTargetCoordinate(
            getHumanoid()->getX() + nextDirection.getX() * _stepRange,
            field.getWidth());
    _toY = getTargetCoordinate(
            getHumanoid()->getY() + nextDirection.getY() * _stepRange,
            field.getHeight());
}

int Move::getTargetCoordinate(int newCoord, int limit) {
    int toCoord;
    if (newCoord >= limit) {
        toCoord = limit - 1;
    } else if (newCoord < 0) {
        toCoord = 0;
    } else {
        toCoord = newCoord;
    }
    return toCoord;
}

std::vector<Direction> Move::getPossibleDirections(const Field& field) const {
    std::vector<Direction> possibleDirection;

    int humX = _humanoid->getX();
    int humY = _humanoid->getY();

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

Move::~Move() {

}
