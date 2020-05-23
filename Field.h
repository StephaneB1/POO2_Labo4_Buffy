/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : Field.h
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */


#ifndef POO2_LABO4_BUFFY_FIELD_H
#define POO2_LABO4_BUFFY_FIELD_H


#include <list>
#include <Humanoid/Vampire.h>
#include <Humanoid/Human.h>
#include <memory>

#include "Humanoid/Humanoid.h"

class Field {

private:
    unsigned _width;
    unsigned _height;

    unsigned turn;

    std::list<std::weak_ptr<Human>> humans;
    std::list<std::weak_ptr<Vampire>> vampires;
    std::list<std::shared_ptr<Humanoid>> humanoids;


public:
    Field(unsigned int _width, unsigned int _height, unsigned totalHuman,
          unsigned totalVampire);

    /**
     * Apply a single turn
     * @return retunn next turn count
     */
    int nextTurn();

    /**
     * Find the closest Humanoid from h
     * @param h
     * @return return the closest humainoid from h
     */
    //Humanoid* getCloset(const Humanoid& h) const;

    unsigned int getWidth() const;

    unsigned int getHeight() const;

    void replace(Human* oldPerson, Vampire* newPerson);

    std::shared_ptr<Humanoid> getCloset(const Vampire* v) const;

    const std::list<std::shared_ptr<Humanoid>>& getHumanoids() const;

private:


};


#endif //POO2_LABO4_BUFFY_FIELD_H
