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

private:
    bool _isAlive;
    Move* _move;
    unsigned _x;
    unsigned _y;

    Action* _nextAction;

public:

    Humanoid(Move* _move, unsigned int _x, unsigned int _y);

    virtual ~Humanoid();

    virtual void setAction(const Field& field) = 0;

    void setNextAction(Action* nextAction);

    void executeAction(const Field& field);

    bool isAlive() const;

    unsigned int getX() const;

    void setX(unsigned int x);

    unsigned int getY() const;

    void setY(unsigned int y);

    Move* getMove() const;

    void setIsAlive(bool _isAlive);

    virtual char getSymbole() const = 0;

    /**
     * Get the distance between Buffy and this
     * @param b
     * @return if this is a Vampire return the distance otherwise -1
     */
    virtual int getDistance(const Buffy* b)const = 0;

    /**
     * Get the distance between a vampire and this
     * @param v
     * @return if this is a Human return the distance otherwise -1
     */
    virtual int getDistance(const Vampire* v)const = 0;
};


#endif //POO2_LABO4_BUFFY_HUMANOID_H
