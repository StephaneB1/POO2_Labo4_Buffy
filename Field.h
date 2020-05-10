//
// Created by Chau Ying on 05.05.2020.
//

#ifndef POO2_LABO4_BUFFY_FIELD_H
#define POO2_LABO4_BUFFY_FIELD_H



#include <list>
#include <Humanoid/Vampire.h>
#include <Humanoid/Human.h>

#include "Humanoid/Humanoid.h"

class Field {

private:
    unsigned _width;
    unsigned _height;

    unsigned turn;

    std::list<Humanoid*> humanoids;

public:
    Field(unsigned int _width, unsigned int _height);

    /**
     * Apply a single turn
     * @return retunn next turn count
     */
    int nexTurn();

    /**
     * Find the closest Humanoid from h
     * @param h
     * @return return the closest humainoid from h
     */
    Humanoid* getCloset(const Humanoid& h) const;

    unsigned int getWidth() const;

    unsigned int getHeight() const;

    void replace(Human oldPerson, Vampire newPerson);


};


#endif //POO2_LABO4_BUFFY_FIELD_H
