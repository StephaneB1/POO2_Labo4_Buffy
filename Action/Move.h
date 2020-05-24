//
// Created by Chau Ying on 09.05.2020.
//

#ifndef POO2_LABO4_BUFFY_MOVE_H
#define POO2_LABO4_BUFFY_MOVE_H

#include "Action.h"
#include "Direction.h"
#include <vector>
#include <Humanoid/Humanoid.h>


class Move : public Action {

private:
    Humanoid* _humanoid;
    unsigned _stepRange;

    unsigned _toX;
    unsigned _toY;

public:


    Move(unsigned int _stepRange);

    void setRandomMove(const Field& field);


    virtual void execute(Field field);

    std::vector<Direction> getListDirection(const Field& field) const;

    void setNextPosition(const Direction& nextDirection);

    void setHumanoid(Humanoid* _humanoid);

    Humanoid* getHumanoid() const;
};


#endif //POO2_LABO4_BUFFY_MOVE_H
