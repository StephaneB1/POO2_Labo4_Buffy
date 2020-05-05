//
// Created by Chau Ying on 05.05.2020.
//

#ifndef POO2_LABO4_BUFFY_HUMAINACTION_H
#define POO2_LABO4_BUFFY_HUMAINACTION_H


#include "Action.h"

class HumainAction : public Action{

public:
    HumainAction(unsigned int _stepRange);

    void excute(const Field& field);
};


#endif //POO2_LABO4_BUFFY_HUMAINACTION_H
