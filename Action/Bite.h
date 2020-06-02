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
    std::shared_ptr<Humanoid> _target;
public:

    Bite();

    virtual void execute(Field* field);

    /**
     * Set which humanoid to execute the action
     * @param target
     */
    void setTarget(const std::shared_ptr<Humanoid>& target);

    virtual ~Bite();
};


#endif //POO2_LABO4_BUFFY_BITE_H
