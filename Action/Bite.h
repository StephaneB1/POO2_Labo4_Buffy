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
    std::weak_ptr<Humanoid> _target;
public:

    Bite();


    Bite(const std::weak_ptr<Human>& _target);

    virtual void execute(Field* field);

    void setTarget(std::weak_ptr<Humanoid> target);


    virtual ~Bite();
};


#endif //POO2_LABO4_BUFFY_BITE_H
