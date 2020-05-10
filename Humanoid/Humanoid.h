//
// Created by Chau Ying on 05.05.2020.
//

#ifndef POO2_LABO4_BUFFY_HUMANOID_H
#define POO2_LABO4_BUFFY_HUMANOID_H

#include <list>

class Action;
class Move;
class Field;

class Humanoid {

private:
    bool _isAlive;
    Move* _move;
    unsigned _x;
    unsigned _y;

    Action* _nextAction;

public:

    Humanoid(Move* _move, unsigned int _x, unsigned int _y);

    virtual void setAction(const Field& field) = 0;

    void setNextAction(Action* nextAction);

    void executeAction(const Field& field);

    bool isAlive() const;

    Action* getNextAction() const;

    unsigned int getX() const;

    void setX(unsigned int x);

    unsigned int getY() const;

    void setY(unsigned int y);

    Move* getMove() const;
};


#endif //POO2_LABO4_BUFFY_HUMANOID_H
