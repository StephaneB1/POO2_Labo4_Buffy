/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : Action.h
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */

#ifndef POO2_LABO4_BUFFY_ACTION_H
#define POO2_LABO4_BUFFY_ACTION_H

#include "../Humanoid/Humanoid.h"

class Field;

class Action {

public:
    Action() {};

    virtual ~Action();

    /**
     * Execute the corresponding action
     * @param field
     */
    virtual void execute(Field* field) = 0;

};


#endif //POO2_LABO4_BUFFY_ACTION_H
