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
    _toX = getHumanoid()->getX() + nextDirection.getX() * _stepRange;
    _toY = getHumanoid()->getY() + nextDirection.getY() * _stepRange;
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
    }

    if (getHumanoid()->getX() != field.getWidth() - 1) {
        possibleDirection.push_back(Direction::RIGHT);
        if (getHumanoid()->getY() != 0) {
            possibleDirection.push_back(Direction::UP);
            possibleDirection.push_back(Direction::UP_RIGHT);
        }
        if (getHumanoid()->getY() != field.getHeight() - 1) {
            possibleDirection.push_back(Direction::DOWN);
            possibleDirection.push_back(Direction::DOWN_RIGHT);
        }
    }
    return possibleDirection;
}


