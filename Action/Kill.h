/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : Kill.h
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */

#ifndef POO2_LABO4_BUFFY_KILL_H
#define POO2_LABO4_BUFFY_KILL_H

#include "Action.h"

class Kill : public Action {

private:
    Humanoid* _target;

    const bool _targetIsVampire;

public:

    Kill(Humanoid* target, bool targetIsVampire);

    Kill(bool targetIsVampire);

    void setTarget(Humanoid* target);

    virtual void execute(Field* field);


    virtual ~Kill();

};


#endif //POO2_LABO4_BUFFY_KILL_H
