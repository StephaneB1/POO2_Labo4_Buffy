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
    std::weak_ptr<Humanoid> _target;

    // Indicate if the humanoid target is a Vampire
    const bool _targetIsVampire;

public:

    Kill(bool targetIsVampire);

    virtual ~Kill();

    /**
     * Set which humanoid to execute the action
     * @param target
     */
    void setTarget(const std::weak_ptr<Humanoid>& target);

    virtual void execute(Field* field);

};


#endif //POO2_LABO4_BUFFY_KILL_H
