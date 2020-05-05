//
// Created by Chau Ying on 05.05.2020.
//

#ifndef POO2_LABO4_BUFFY_ACTION_H
#define POO2_LABO4_BUFFY_ACTION_H


#include "Field.h"

class Action {
private:
    unsigned _stepRange;

public:
    Action(unsigned int _stepRange);

    virtual void excute(const Field& field);

    unsigned int getStepRange() const;

    void move();
};


#endif //POO2_LABO4_BUFFY_ACTION_H
