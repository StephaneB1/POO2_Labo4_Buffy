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
#include "../Direction.h"
#include "../Humanoid/Humanoid.h"

#include <vector>

class Move : public Action {

private:

    // Which Humanoid own this move
    Humanoid* _humanoid;
    const unsigned _stepRange;

    int _toX;
    int _toY;

public:

    Move(unsigned int _stepRange, Humanoid* humanoid);

    virtual ~Move();

    void execute(Field* field) override;

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
    std::vector<Direction> getPossibleDirections(const Field& field) const;

    /**
     * Set the position for the next turn
     * @param nextDirection
     */
    void setNextPosition(const Direction& nextDirection, const Field& field);

    Humanoid* getHumanoid() const;

};


#endif //POO2_LABO4_BUFFY_MOVE_H
