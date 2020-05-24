//
// Created by Chau Ying on 10.05.2020.
//

#ifndef POO2_LABO4_BUFFY_HUMAIN_H
#define POO2_LABO4_BUFFY_HUMAIN_H


#include "Humanoid.h"

class Field;

class Human: public Humanoid {

public:

    Human(unsigned int _x, unsigned int _y);


    virtual void setAction(const Field& field);

    virtual char getSymbole()const;

    virtual int getDistance(const Human* h) const;

    virtual int getDistance(const Vampire* v) const;

    Vampire* becomeAVampire();
};


#endif //POO2_LABO4_BUFFY_HUMAIN_H
