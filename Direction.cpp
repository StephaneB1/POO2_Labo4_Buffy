/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : Direction.cpp
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */

#include "Direction.h"

const Direction Direction::UP = Direction(0, -1);
const Direction Direction::UP_LEFT = Direction(-1, -1);
const Direction Direction::UP_RIGHT = Direction(1, -1);

const Direction Direction::DOWN = Direction(0, 1);
const Direction Direction::DOWN_LEFT = Direction(-1, 1);
const Direction Direction::DOWN_RIGHT = Direction(1, 1);

const Direction Direction::LEFT = Direction(-1, 0);
const Direction Direction::RIGHT = Direction(1, 0);


Direction Direction::getDirection(unsigned fromX, unsigned fromY, unsigned toX,
                                  unsigned toY) {
    int tempX = toX - fromX;
    int tempY = toY - fromY;

    if (tempX < 0) {
        if (tempY < 0) {
            return Direction::UP_LEFT;
        } else if (tempY == 0) {
            return Direction::LEFT;
        } else {
            return Direction::DOWN_RIGHT;
        }
    } else if (tempX == 0) {
        if (tempY < 0){
            return Direction::UP;
        } else {
            return Direction::DOWN;
        }
    } else {
        if (tempY < 0) {
            return Direction::UP_RIGHT;
        } else if (tempY == 0) {
            return Direction::RIGHT;
        } else {
            return Direction::DOWN_RIGHT;
        }
    }
}

int Direction::getX() const {
    return _x;
}

int Direction::getY() const {
    return _y;
}
