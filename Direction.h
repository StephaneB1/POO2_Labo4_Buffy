/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : Direction.h
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */

#ifndef POO2_LABO4_BUFFY_DIRECTION_H
#define POO2_LABO4_BUFFY_DIRECTION_H

class Direction {

private:
    int _x;
    int _y;
private:
    Direction(int _x, int _y) : _x(_x), _y(_y){}

public:

    static const Direction UP;
    static const Direction UP_LEFT;
    static const Direction LEFT;
    static const Direction DOWN_LEFT;
    static const Direction DOWN;
    static const Direction DOWN_RIGHT;
    static const Direction RIGHT;
    static const Direction UP_RIGHT;

    /**
     * Give the direction to move given the starting point and the target position
     * @param fromX
     * @param fromY
     * @param toX
     * @param toY
     * @return
     */
    static Direction getDirection(unsigned fromX, unsigned fromY, unsigned toX,
                                  unsigned toY);

    int getX() const;

    int getY() const;

};


#endif //POO2_LABO4_BUFFY_DIRECTION_H
