/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : Move.h
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */

#ifndef POO2_LABO4_BUFFY_MOVE_H
#define POO2_LABO4_BUFFY_MOVE_H

#include "Action.h"
#include "Direction.h"
#include <vector>
#include <Humanoid/Humanoid.h>


class Move : public Action {

private:
    Humanoid* _humanoid;
    unsigned _stepRange;

    unsigned _toX;
    unsigned _toY;

public:


    Move(unsigned int _stepRange);

    virtual void execute(Field* field);

    /**
     * Set the move to be a random direction
     * @param field
     */
    void setRandomMove(const Field& field);

    /**
     * Return a list of the possible direction for the Humanoid
     * @param field
     * @return
     */
    std::vector<Direction> getListDirection(const Field& field) const;

    /**
     * Set the position for the next turn
     * @param nextDirection
     */
    void setNextPosition(const Direction& nextDirection);

    /**
     * Set the humanoid that own this move
     * @param _humanoid
     */
    void setHumanoid(Humanoid* _humanoid);


    Humanoid* getHumanoid() const;
};


#endif //POO2_LABO4_BUFFY_MOVE_H
