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
#include <Humanoid/Buffy.h>
#include <memory>

#include "Humanoid/Humanoid.h"

class Field {

private:
    unsigned _width;
    unsigned _height;

    unsigned turn;

    std::list<Humanoid*> humanoids;

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

    Humanoid* getCloset(const Vampire* v) const;

    Humanoid* getCloset(const Buffy* v) const;


    const std::list<Humanoid*>& getHumanoids() const;

private:


};


#endif //POO2_LABO4_BUFFY_FIELD_H
