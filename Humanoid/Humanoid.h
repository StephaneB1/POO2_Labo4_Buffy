/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : Humanoid.h
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */

#ifndef POO2_LABO4_BUFFY_HUMANOID_H
#define POO2_LABO4_BUFFY_HUMANOID_H

#include <list>
#include <memory>

class Action;

class Move;

class Field;

class Human;

class Vampire;

class Buffy;

class Humanoid {

private:
    bool _isAlive;
    int _x;
    int _y;

    Move* _move;
    Action* _nextAction;

    // For debugging
    unsigned _id;
    static unsigned _counter;

    // Humanoid actions
    virtual Action* getIdleAction(const Field& field);
    virtual Action* getAttackAction(const Field& field,
            const std::shared_ptr<Humanoid>& target);
    virtual Action* getChaseAction(const Field& field,
            const std::shared_ptr<Humanoid>& target);

    /**
     * Get the closest target
     * @param field
     * @return A shared pointer to the closest target
   */
    virtual std::shared_ptr<Humanoid> getTarget(const Field& field);

public:

    Humanoid(Move* _move, int _x, int _y);

    virtual ~Humanoid();

    /**
     * Set the next action of the humanoid
     * @param field
     */
    void setAction(const Field& field);

    /**
     * Execute the humanoid's action
     * @param field
     */
    void executeAction(Field* field);

    /**
     * @return true if the humanoid is alive
     */
    bool isAlive() const;

    // Humanoid's position
    int getX() const;
    int getY() const;
    void setPosition(int x, int y);
    bool standsHere(unsigned int x, unsigned int y);

    /**
     * @return Humanoid's symbol as a character
     */
    virtual char getSymbol() const = 0;

    /**
     * Kills the humanoid
     */
    void kill();

    /**
     * Get the distance between Buffy and this humanoid(Euclidean distance)
     * @param b
     * @return if this is a Vampire return the distance otherwise -1
     */
    virtual int getDistanceTo(const std::shared_ptr<Buffy>& b) const;

    /**
     * Get the distance between a vampire and this humanoid(Euclidean distance)
     * @param v
     * @return if this is a Human return the distance otherwise -1
     */
    virtual int getDistanceTo(const std::shared_ptr<Vampire>& v) const;
};


#endif //POO2_LABO4_BUFFY_HUMANOID_H
