//
// Created by Chau Ying on 09.05.2020.
//

#ifndef POO2_LABO4_BUFFY_MOVE_H
#define POO2_LABO4_BUFFY_MOVE_H

#include "Action.h"
#include "Direction.h"


class Move : public Action {

private:
    unsigned _stepRange;

    unsigned _toX;
    unsigned _toY;

public:


    Move(unsigned int _stepRange);

    void setMove(const Field& field);


    virtual void execute(const Field& field);

};


#endif //POO2_LABO4_BUFFY_MOVE_H
