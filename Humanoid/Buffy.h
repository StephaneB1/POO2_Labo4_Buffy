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


class Buffy : public Humanoid, public std::enable_shared_from_this<Buffy>{

private:
    Kill* _kill;

    std::weak_ptr<Humanoid> getTarget(const Field &field) override;

    Action* getAttackAction(const Field& field,
                            const std::weak_ptr<Humanoid>& target) override;

public:

    Buffy(int _x, int _y);

    char getSymbol() const override;

    virtual ~Buffy();

};


#endif //POO2_LABO4_BUFFY_BUFFY_H
