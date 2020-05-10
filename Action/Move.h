//
// Created by Chau Ying on 09.05.2020.
//

#include "Action.h"

#ifndef POO2_LABO4_BUFFY_MOVE_H
#define POO2_LABO4_BUFFY_MOVE_H


class Move : public Action {
private:
    unsigned _stepRange;

    enum class Direction{
        UP,
        UP_LEFT,
        LEFT,
        DOWN_LEFT,
        DOWN,
        DOWN_RIGHT,
        RIGHT,
        UP_RIGHT
    };

    Direction getRandomDirection() const;

    Direction _direction;


public:
    Move(unsigned int _stepRange);

    void setDirection(Direction direction);

    virtual void execute(const Field& field);

};


#endif //POO2_LABO4_BUFFY_MOVE_H
