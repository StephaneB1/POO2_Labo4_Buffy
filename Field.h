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
#include <algorithm>
#include <climits>
#include "Humanoid/Vampire.h"
#include "Humanoid/Human.h"
#include "Humanoid/Buffy.h"
#include <memory>

#include "Humanoid/Humanoid.h"

class Field {

private:
    const unsigned _width;
    const unsigned _height;

    unsigned _turn;

    const unsigned _totalHuman;
    const unsigned _totalVampire;

    // Counter for Vampires and Humans
    int _vCounter;
    int _hCounter;

    std::list<std::shared_ptr<Humanoid>> _humanoids;



    /**
     * Add a Humanoid in the list
     * @tparam T Type for the Humanoid to add (Buddy, Vampire, Human)
     * @param total How many to add
     */
    template<typename T>
    void addToHumanoids(unsigned total);

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
    void replaceByAVampire(std::shared_ptr<Humanoid> target);

    /**
     * Finds the closest humanoid of type T from a target
     * @tparam T     : type of humanoid
     * @param target : get closest from this instance
     * @return closest humanoid of type T from target
     */
    template<typename T>
    std::shared_ptr<Humanoid> getClosest(const std::shared_ptr<T>& target) const {
        std::shared_ptr<Humanoid> res;
        int min = INT_MAX;
        int d;

        for (std::shared_ptr<Humanoid> h :_humanoids) {
            d = h->getDistanceTo(target);

            if (d >= 0 && min > d) {
                min = d;
                res = h;
            }
        }

        return res;
    };


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
    void kill(std::shared_ptr<Humanoid>& h, bool targetIsVampire);

    int get_vCounter() const;

    int get_hCounter() const;

};


#endif //POO2_LABO4_BUFFY_FIELD_H
