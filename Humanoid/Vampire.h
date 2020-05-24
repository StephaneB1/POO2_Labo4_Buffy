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


#include <Action/Kill.h>
#include <Action/Bite.h>
#include "Humanoid.h"
#include "Human.h"

class Vampire : public Humanoid{

    Bite* _bite;
    Kill* _kill;

public:
    Vampire(unsigned int _x, unsigned int _y);

    virtual void setAction(const Field& field) ;

    virtual char getSymbole()const;

    virtual int getDistance(const Buffy* h) const;

    virtual int getDistance(const Vampire* v)  const;

};


#endif //POO2_LABO4_BUFFY_VAMPIRE_H
