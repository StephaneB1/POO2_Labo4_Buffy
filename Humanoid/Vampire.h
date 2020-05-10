//
// Created by Chau Ying on 10.05.2020.
//

#ifndef POO2_LABO4_BUFFY_VAMPIRE_H
#define POO2_LABO4_BUFFY_VAMPIRE_H


#include <Action/Kill.h>
#include <Action/Bite.h>
#include "Humanoid.h"
#include "Human.h"

class Vampire : public Humanoid{

    Bite* _bite;
    Kill* _kill;

public:
    Vampire(unsigned int _x, unsigned int _y);

    Vampire(Human* human);

    void setAction(const Field& field) ;

};


#endif //POO2_LABO4_BUFFY_VAMPIRE_H
