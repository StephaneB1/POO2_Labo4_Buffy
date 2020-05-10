//
// Created by Chau Ying on 09.05.2020.
//

#ifndef POO2_LABO4_BUFFY_MOVE_H
#define POO2_LABO4_BUFFY_MOVE_H

#include "Action.h"
#include "Direction.h"
#include <vector>


class Move : public Action {

private:
    unsigned _stepRange;

    unsigned _toX;
    unsigned _toY;

public:


    Move(unsigned int _stepRange);

    void setRandomMove(const Field& field);


    virtual void execute(const Field& field);

    std::vector<Direction> getListDirection(const Field& field) const;

    void setNextPosition(const Direction& nextDirection);
};


#endif //POO2_LABO4_BUFFY_MOVE_H
