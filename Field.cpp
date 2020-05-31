/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : Field.cpp
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */

#include <iostream>
#include <algorithm>
#include <climits>
#include "Field.h"
#include "Utils.h"

class Utils;

Field::Field(unsigned int _width, unsigned int _height, unsigned totalHuman,
             unsigned totalVampire) : _width(_width),
                                      _height(_height),
                                      _turn(0),
                                      _totalHuman(totalHuman),
                                      _totalVampire(totalVampire) {
    init();
}

unsigned Field::nextTurn() {

    // Déterminer les prochaines actions
    for (std::list<Humanoid*>::iterator it = _humanoids.begin();
         it != _humanoids.end(); it++)
        (*it)->setAction(*this);
    // Executer les actions
    for (std::list<Humanoid*>::iterator it = _humanoids.begin();
         it != _humanoids.end(); it++)
        (*it)->executeAction(this);
    // Enlever les humanoides tués
    for (std::list<Humanoid*>::iterator it = _humanoids.begin();
         it != _humanoids.end();) {
        if (!(*it)->isAlive()) {
            delete *it; // destruction de l’humanoide référencé
            it = _humanoids.erase(it); // suppression de l’élément dans la liste
        } else
            ++it;
    }

    return _turn++;
}

unsigned int Field::getWidth() const {
    return _width;
}

unsigned int Field::getHeight() const {
    return _height;
}

template<typename F>
Humanoid* Field::getClosest(const Humanoid* source, F distFunc) const {
    Humanoid* res = nullptr;
    int min = INT_MAX;
    int d;

    for (Humanoid* h :_humanoids) {
        d = distFunc(h, source);

        if (d >= 0 && min > d) {
            min = d;
            res = h;
        }
    }

    return res;
}

Humanoid* Field::getClosest(const Vampire* v) const {
    return getClosest(v, [](const Humanoid* h1, const Humanoid* h2) {
        return h1->getDistance((Vampire*) h2);
    });
}

Humanoid* Field::getClosest(const Buffy* b) const {
    return getClosest(b, [](const Humanoid* h1, const Humanoid* h2) {
        return h1->getDistance((Buffy*) h2);
    });
}

const std::list<Humanoid*>& Field::getHumanoids() const {
    return _humanoids;
}

void Field::replace(Humanoid* target, Vampire* replacement, bool targetIsVampire) {
    // Killing the humanoid (human or vampire)
    if(target != nullptr) {
        target->kill();
        if(targetIsVampire) _vCounter--;
        else                _hCounter--;
    }

    // replacing the dead human by a vampire
    if(!targetIsVampire && replacement != nullptr) {
        _humanoids.push_back(replacement);
        _vCounter++;
    }
}

void Field::reset() {
    _turn = 0;
    _humanoids.clear();
}

void Field::init() {

    _vCounter = (int) _totalVampire;
    _hCounter = (int) _totalHuman;

    addToHumanoids<Buffy>(1);
    addToHumanoids<Human>(_totalHuman);
    addToHumanoids<Vampire>(_totalVampire);
}

template <typename T>
void Field::addToHumanoids(unsigned total) {
    unsigned x, y;
    for (int i = 0; i < total; i++) {
        x = Utils::generateRandom(0, _width);
        y = Utils::generateRandom(0, _height);
        _humanoids.push_back(new T(x, y));
    }
}

bool Field::isFreeOfVampires() const {
    return _vCounter <= 0;
}

bool Field::hasHumans() const {
    return _hCounter > 0;
}

unsigned int Field::getTurn() const {
    return _turn;
}

