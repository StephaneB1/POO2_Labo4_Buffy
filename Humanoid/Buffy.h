/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : Buffy.h
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */

#ifndef POO2_LABO4_BUFFY_BUFFY_H
#define POO2_LABO4_BUFFY_BUFFY_H


#include "Humanoid.h"
#include "Vampire.h"
#include "../Action/Kill.h"
#include "../Action/Bite.h"


class Buffy : public Humanoid{

private:
    Kill* _kill;

public:
    Buffy(unsigned int _x, unsigned int _y);

    virtual void setAction(const Field& field) ;

    virtual char getSymbol()const;

    virtual int getDistance(const Buffy* h) const;

    virtual int getDistance(const Vampire* v)  const;
};


#endif //POO2_LABO4_BUFFY_BUFFY_H
