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
    unsigned _turn;

    // Field size
    const unsigned _width;
    const unsigned _height;

    // Field population
    const unsigned _totalHuman;
    const unsigned _totalVampire;
    std::list<std::shared_ptr<Humanoid>> _humanoids;

    // Counter for Vampires and Humans
    int _vCounter;
    int _hCounter;

    /**
     * Add a Humanoid in the list
     * @tparam T Type for the Humanoid to add (Buffy, Vampire, Human)
     * @param total : number of instances to add
     */
    template<typename T>
    void addToHumanoids(unsigned total);

public:
    Field(unsigned int _width, unsigned int _height, unsigned totalHuman,
          unsigned totalVampire);

    /**
     * Apply a single turn
     * @return the next turn's count
     */
    unsigned nextTurn();

    /**
     * @return width of the field in pixels
     */
    unsigned int getWidth() const;

    /**
     * @return height of the field in pixels
     */
    unsigned int getHeight() const;

    /**
     * @return turn's count
     */
    unsigned int getTurn() const;

    /**
     * Replace a target by a Vampire, the new Vampire has the same position
     * @param target : target to replace by a Vampire
     */
    void replaceByAVampire(const std::shared_ptr<Humanoid>& target);

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

    /**
     * Get the humanoids populating the field
     * @return list of humanoids
     */
    const std::list<std::shared_ptr<Humanoid>>& getHumanoids() const;

    /**
     * Resets the field
     */
    void reset();

    /**
     * Initialize the field
     */
    void init();

    /**
     * Indicates if the board contains any Vampire
     * @return true if all Vampires have been killed, false otherwise
     */
    bool isFreeOfVampires() const;

    /**
     * Indicates if the board contains any human
     * @return true if the field contains at least one human, false otherwise
     */
    bool hasHumans() const;

    /**
     * Kills a humanoid in the field
     * @param h : humanoid to kill
     * @param targetIsVampire : true if the target is a vampire
     */
    void kill(std::shared_ptr<Humanoid>& h, bool targetIsVampire);

};


#endif //POO2_LABO4_BUFFY_FIELD_H
