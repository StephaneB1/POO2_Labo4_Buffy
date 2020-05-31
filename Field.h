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

    // Counter for Vampires and Humans
    int _vCounter;
    int _hCounter;

    std::list<std::shared_ptr<Humanoid>> _humanoids;

    /**
     * Find the humanoid according th lambda function
     * @tparam F
     * @param lambda
     * @return
     */
    template<typename F>
    std::weak_ptr<Humanoid> getClosest(F lambda) const;

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

    /**
     * Replace a the target by a Vampire, the new Vampire has the same position
     * @param target
     */
    void replaceByAVampire(std::weak_ptr<Humanoid> target);

    /**
    * Find the closest Human to the vampire v
    * @param v the vampire we want to know his closest human
    * @return a weak_ptr to the closest human
    */
    std::weak_ptr<Humanoid> getClosest(std::weak_ptr<Vampire> v) const;

    /**
     * Find the closest Vampire to the Buffy
     * @param b Buffy
     * @return a weak_ptr to the closest Vampire to Buffy
     */
    std::weak_ptr<Humanoid> getClosest(std::weak_ptr<Buffy> b) const;

    const std::list<std::shared_ptr<Humanoid>>& getHumanoids() const;

    /**
     * reset the board
     */
    void reset();

    /**
     * Init the board
     */
    void init();

    /**
     * Add a Humanoid in the list
     * @tparam T Type for the Humanoid to add (Buddy, Vampire, Human)
     * @param total How many to add
     */
    template<typename T>
    void addToHumanoids(unsigned total);

    /**
     * Indicate if the board containing any vampires
     * @return true if the board containing none vampire, otherwise false
     */
    bool isFreeOfVampires() const;

    /**
     * Indicate if the board containing any human
     * @return true if the board containing none human, otherwise false
     */
    bool hasHumans() const;

    /**
     * Kill the Humanoid h, we set isAlive at false and decrement the
     * corresponding counter
     * @param h the humanoid killed
     * @param targetIsVampire indicate which counter to decrement
     */
    void kill(std::weak_ptr<Humanoid>& h, bool targetIsVampire);

    int get_vCounter() const;

    int get_hCounter() const;

};


#endif //POO2_LABO4_BUFFY_FIELD_H
