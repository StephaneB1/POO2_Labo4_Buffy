//
// Created by Chau Ying on 05.05.2020.
//

#ifndef POO2_LABO4_BUFFY_HUMANOID_H
#define POO2_LABO4_BUFFY_HUMANOID_H


#include "Action.h"

class Humanoid {

private:
    bool _isAlive;
    unsigned _x;
    unsigned _y;

    Action _action;

public:

    Humanoid(unsigned int _x, unsigned int _y, const Action& action);

    void setAction(const Field& field) const;

    void executeAction(const Field& field);

    bool isAlive() const;

};


#endif //POO2_LABO4_BUFFY_HUMANOID_H
