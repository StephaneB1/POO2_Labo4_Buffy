//
// Created by Chau Ying on 10.05.2020.
//

#ifndef POO2_LABO4_BUFFY_HUMAIN_H
#define POO2_LABO4_BUFFY_HUMAIN_H


#include "Humanoid.h"

class Field;

class Humain: public Humanoid {

public:

    Humain(unsigned int _x, unsigned int _y, const Move& move);

    virtual void setAction(const Field& field);

};


#endif //POO2_LABO4_BUFFY_HUMAIN_H
