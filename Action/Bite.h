/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : Bite.h
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */

#ifndef POO2_LABO4_BUFFY_BITE_H
#define POO2_LABO4_BUFFY_BITE_H

#include "../Humanoid/Human.h"
#include "Action.h"

class Bite : public Action{

    Human* _target;

public:

    void setTarget(Human* humanoid);

    virtual void execute(Field* field);
};


#endif //POO2_LABO4_BUFFY_BITE_H
