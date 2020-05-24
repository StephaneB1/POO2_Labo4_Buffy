//
// Created by Chau Ying on 09.05.2020.
//

#ifndef POO2_LABO4_BUFFY_KILL_H
#define POO2_LABO4_BUFFY_KILL_H

#include "Action.h"

class Kill : public Action{

private:
    Humanoid* _target;

public:

    void setTarget(Humanoid* target);

    virtual void execute(Field field);

};


#endif //POO2_LABO4_BUFFY_KILL_H
