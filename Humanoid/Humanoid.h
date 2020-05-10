//
// Created by Chau Ying on 05.05.2020.
//

#ifndef POO2_LABO4_BUFFY_HUMANOID_H
#define POO2_LABO4_BUFFY_HUMANOID_H

#include <list>

class Action;
class Field;

class Humanoid {

private:
    bool _isAlive;
    unsigned _x;
    unsigned _y;
    unsigned _stepRange;

    std::list<Action*> _actionList;

    Action* _nextAction;

public:

    Humanoid(unsigned int _x, unsigned int _y, std::list<Action*> action);

    virtual void setAction(const Field& field) const = 0;

    void executeAction(const Field& field);

    bool isAlive() const;

    unsigned int getX() const;

    unsigned int getY() const;

    void setX(unsigned int _x);

    void setY(unsigned int _y);


};


#endif //POO2_LABO4_BUFFY_HUMANOID_H
