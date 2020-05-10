//
// Created by Chau Ying on 09.05.2020.
//

#include <Utils.h>
#include "Move.h"

#include "../Field.h"

Move::Move(unsigned int _stepRange) : _stepRange(_stepRange), _toY(0), _toX(0) {}

void Move::execute(Field field) {
    getHumanoid()->setY(_toY);
    getHumanoid()->setX(_toX);
}

void Move::setRandomMove(const Field& field) {

    std::vector<Direction> possibleDirection = getListDirection(field);

    Direction nextDirection = possibleDirection.at(Utils::generateRandom(0,
                                                                         possibleDirection.size()));

    setNextPosition(nextDirection);

}

void Move::setNextPosition(const Direction& nextDirection) {
    switch (nextDirection) {
        case Direction::UP :
            _toX = getHumanoid()->getX() - _stepRange;
            _toY = getHumanoid()->getY();
            break;

        case Direction::LEFT :
            _toX = getHumanoid()->getX();
            _toY = getHumanoid()->getY() + _stepRange;
            break;

        case Direction::DOWN :
            _toX = getHumanoid()->getX() + _stepRange;
            _toY = getHumanoid()->getY();
            break;

        case Direction::RIGHT :
            _toX = getHumanoid()->getX();
            _toY = getHumanoid()->getY() - _stepRange;
            break;

        case Direction::UP_LEFT:
            _toX = getHumanoid()->getX() - _stepRange;
            _toY = getHumanoid()->getY() + _stepRange;
            break;

        case Direction::DOWN_LEFT:
            _toX = getHumanoid()->getX() + _stepRange;
            _toY = getHumanoid()->getY() + _stepRange;
            break;

        case Direction::DOWN_RIGHT:
            _toX = getHumanoid()->getX() + _stepRange;
            _toY = getHumanoid()->getY() - _stepRange;
            break;

        case Direction::UP_RIGHT:
            _toX = getHumanoid()->getX() - _stepRange;
            _toY = getHumanoid()->getY() - _stepRange;
            break;
    }
}

std::vector<Direction> Move::getListDirection(const Field& field) const {
    std::vector<Direction> possibleDirection;

    if (getHumanoid()->getX() != 0) {
        possibleDirection.push_back(Direction::LEFT);
        if (getHumanoid()->getY() != 0) {
            possibleDirection.push_back(Direction::UP);
            possibleDirection.push_back(Direction::UP_LEFT);
        }
        if (getHumanoid()->getY() != field.getHeight() - 1) {
            possibleDirection.push_back(Direction::DOWN);
            possibleDirection.push_back(Direction::DOWN_LEFT);
        }
    } else if (getHumanoid()->getX() != field.getWidth() - 1) {
        possibleDirection.push_back(Direction::LEFT);
        if (getHumanoid()->getY() != 0) {
            possibleDirection.push_back(Direction::UP);
            possibleDirection.push_back(Direction::UP_LEFT);
        }
        if (getHumanoid()->getY() != field.getHeight() - 1) {
            possibleDirection.push_back(Direction::DOWN);
            possibleDirection.push_back(Direction::DOWN_LEFT);
        }
    }
    return possibleDirection;
}