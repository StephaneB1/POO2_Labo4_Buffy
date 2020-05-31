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

class Action;

class Move;

class Field;

class Human;

class Vampire;

class Buffy;

class Humanoid {

protected:
    Move* _move;

private:
    bool _isAlive;
    unsigned _x;
    unsigned _y;

    Action* _nextAction;

public:

    Humanoid(Move* _move, unsigned int _x, unsigned int _y);

    virtual ~Humanoid();

    void setAction(const Field& field);

    void executeAction(Field* field);

    virtual Humanoid* getTarget(const Field& field);

    // Humanoid actions
    virtual Action* getIdleAction(const Field& field);
    virtual Action* getAttackAction(const Field& field, Humanoid* target);
    virtual Action* getChaseAction(const Field& field, Humanoid* target);

    bool isAlive() const;

    unsigned int getX() const;

    void setX(unsigned int x);

    unsigned int getY() const;

    void setY(unsigned int y);

    void kill();

    bool standsHere(unsigned int x, unsigned int y);

    virtual char getSymbol() const = 0;

    /**
     * Get the distance between Buffy and this
     * @param b
     * @return if this is a Vampire return the distance otherwise -1
     */
    virtual int getDistance(const Buffy* b) const;

    /**
     * Get the distance between a vampire and this
     * @param v
     * @return if this is a Human return the distance otherwise -1
     */
    virtual int getDistance(const Vampire* v) const;
};


#endif //POO2_LABO4_BUFFY_HUMANOID_H
