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

    std::list<std::shared_ptr<Humanoid>> _humanoids;

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

    void replaceByAVampire(std::weak_ptr<Humanoid> target);
    /**
    * Find the closest Humain to the vampire v
    * @param v
    * @return
    */
    std::weak_ptr<Humanoid> getClosest(std::weak_ptr<Vampire> v) const;

    /**
     * Find the closest Vampire to the Buffy
     * @param b
     * @return
     */
    std::weak_ptr<Humanoid> getClosest(std::weak_ptr<Buffy> b) const;

    template<typename F>
    std::weak_ptr<Humanoid>
    getClosest(F lambda) const;

    const std::list<std::shared_ptr<Humanoid>>& getHumanoids() const;

    void reset();

    void init();

    template<typename T>
    void addToHumanoids(unsigned total);

    bool isFreeOfVampires() const;

    bool hasHumans() const;

    void kill(std::weak_ptr<Humanoid>& h, bool targetIsVampire);

    int get_vCounter() const;

    int get_hCounter() const;

};


#endif //POO2_LABO4_BUFFY_FIELD_H
