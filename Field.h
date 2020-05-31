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
#include "Humanoid/Vampire.h"
#include "Humanoid/Human.h"
#include "Humanoid/Buffy.h"
#include <memory>

#include "Humanoid/Humanoid.h"

class Field {

private:
    unsigned _width;
    unsigned _height;

    unsigned _turn;

    unsigned _totalHuman;
    unsigned _totalVampire;

    int _vCounter;
    int _hCounter;

    std::list<Humanoid*> _humanoids;

public:
    Field(unsigned int _width, unsigned int _height, unsigned totalHuman,
          unsigned totalVampire);

    /**
     * Apply a single turn
     * @return retunn next turn count
     */
    unsigned nextTurn();

    unsigned int getWidth() const;

    unsigned int getHeight() const;

    unsigned int getTurn() const;

    void replace(Humanoid* target, Vampire* replacement, bool targetIsVampire);

    /**
    * Find the closest Humain to the vampire v
    * @param v
    * @return
    */
    Humanoid* getClosest(const Vampire* v) const;

    /**
     * -> Refactor into getClosest(Humanoid*) ?
     * Find the closest Vampire to the Buffy
     * @param b
     * @return
     */
    Humanoid* getClosest(const Buffy* b) const;

    template<typename F>
    Humanoid* getClosest(const Humanoid* source, F lambda) const;

    const std::list<Humanoid*>& getHumanoids() const;

    void reset();

    void init();

    template <typename T>
    void addToHumanoids(unsigned total);

    bool isFreeOfVampires() const;

    bool hasHumans() const;
};


#endif //POO2_LABO4_BUFFY_FIELD_H
