//
// Created by Chau Ying on 05.05.2020.
//

#ifndef POO2_LABO4_BUFFY_ACTION_H
#define POO2_LABO4_BUFFY_ACTION_H

class Field;

class Action {

public:

    virtual void execute(const Field& field) = 0;
};


#endif //POO2_LABO4_BUFFY_ACTION_H
