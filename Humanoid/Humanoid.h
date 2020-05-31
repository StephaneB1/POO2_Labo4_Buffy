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

    unsigned _id;
    static unsigned _counter;

public:

    Humanoid(Move* _move, int _x, int _y);

    virtual ~Humanoid();

    void setAction(const Field& field);

    void executeAction(Field* field);

    virtual std::weak_ptr<Humanoid> getTarget(const Field& field);

    // Humanoid actions
    virtual Action* getIdleAction(const Field& field);

    virtual Action*
    getAttackAction(const Field& field,const std::weak_ptr<Humanoid>& target);

    virtual Action*
    getChaseAction(const Field& field,const std::weak_ptr<Humanoid>& target);

    bool isAlive() const;

    int getX() const;

    int getY() const;

    void setPosition(int x, int y);

    void kill();

    bool standsHere(unsigned int x, unsigned int y);

    virtual char getSymbol() const = 0;

    /**
     * Get the distance between Buffy and this
     * @param b
     * @return if this is a Vampire return the distance otherwise -1
     */
    virtual int getDistanceTo(std::weak_ptr<Buffy> b) const ;

    /**
     * Get the distance between a vampire and this
     * @param v
     * @return if this is a Human return the distance otherwise -1
     */
    virtual int getDistanceTo(std::weak_ptr<Vampire> v) const;

    unsigned int get_id() const;



};


#endif //POO2_LABO4_BUFFY_HUMANOID_H
