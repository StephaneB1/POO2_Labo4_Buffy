/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : Vampire.h
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */

#ifndef POO2_LABO4_BUFFY_VAMPIRE_H
#define POO2_LABO4_BUFFY_VAMPIRE_H


#include "../Action/Kill.h"
#include "../Action/Bite.h"
#include "Humanoid.h"
#include "Human.h"

class Vampire : public Humanoid{

public:
    Vampire(unsigned int _x, unsigned int _y);

    Vampire(Human* h);

    Humanoid *getTarget(const Field& field) override;

    void setIdleAction(const Field &field) override;

    void setAttackAction(const Field &field, Humanoid* target) override;

    //void setChaseAction(const Field &field, Humanoid* target) override;

    char getSymbol()const override;

    int getDistance(const Buffy* h) const override;

    int getDistance(const Vampire* v) const override;

};


#endif //POO2_LABO4_BUFFY_VAMPIRE_H
