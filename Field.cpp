/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : Field.h
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */

#include <iostream>
#include "Field.h"
#include "Utils.h"

Field::Field(unsigned int _width, unsigned int _height, unsigned totalHuman,
             unsigned totalVampire) : _width(_width),
                                      _height(_height),
                                      turn(0) {
    unsigned x;
    unsigned y;
    for (int i = 0; i < totalHuman; i++) {
        x = Utils::generateRandom(0, _width);
        y = Utils::generateRandom(0, _height);
        humanoids.push_back(new Human(x, y));
    }

    for (int i = 0; i < totalVampire; i++) {
        x = Utils::generateRandom(0, _width);
        y = Utils::generateRandom(0, _height);
        humanoids.push_back(new Vampire(x, y));
    }

    x = Utils::generateRandom(0, _width);
    y = Utils::generateRandom(0, _height);
    //Buffy singleton
    //humanoids.push_back(new Buffy(x,y))
}

int Field::nextTurn() {

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
            //delete *it; // destruction de l’humanoide référencé
        } else
            ++it;
    return turn++;
}

unsigned int Field::getWidth() const {
    return _width;
}

unsigned int Field::getHeight() const {
    return _height;
}

Humanoid* Field::getCloset(const Vampire* v) const {

    Humanoid* res = nullptr;
    int min = INT_MAX;
    int d;

    for (Humanoid* h :humanoids) {
        d = h->getDistance(v);

        if (d > 0 && min > d) {
            min = d;
            res = h;
        }
    }

    return res;
}

const std::list<Humanoid*>& Field::getHumanoids() const {
    return humanoids;
}
