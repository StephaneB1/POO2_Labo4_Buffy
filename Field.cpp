//
// Created by Chau Ying on 05.05.2020.
//

#include "Field.h"

Field::Field(unsigned int _width, unsigned int _height) : _width(_width),
                                                          _height(_height),
                                                          turn(0) {}

int Field::nexTurn() {

    // Déterminer les prochaines actions
    for (std::list<Humanoid*>::iterator it = humanoids.begin();
         it != humanoids.end(); it++)
        (*it)->setAction(*this);
    // Executer les actions
    for (std::list<Humanoid*>::iterator it = humanoids.begin();
         it != humanoids.end(); it++)
        (*it)->executeAction(*this);
    // Enlever les humanoides tués
    for (std::list<Humanoid*>::iterator it = humanoids.begin();
         it != humanoids.end();)
        if (!(*it)->isAlive()) {
            it = humanoids.erase(it); // suppression de l’élément dans la liste
            delete *it; // destruction de l’humanoide référencé
        } else
            ++it;
    return turn++;
}
