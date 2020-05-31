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

class Vampire : public Humanoid, public std::enable_shared_from_this<Vampire> {

    Kill* _kill;
    Bite* _bite;

public:
    Vampire(int _x, int _y);

    Vampire(std::weak_ptr<Human> h);

    std::weak_ptr<Humanoid> getTarget(const Field& field) override;

    Action* getAttackAction(const Field& field,
                            const std::weak_ptr<Humanoid>& target) override;

    Action* getIdleAction(const Field& field) override;

    char getSymbol() const override;

    int getDistanceTo(std::weak_ptr<Buffy> b) const override;

    virtual ~Vampire();

};


#endif //POO2_LABO4_BUFFY_VAMPIRE_H
