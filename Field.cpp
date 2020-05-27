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
         it != _humanoids.end();)
        if (!(*it)->isAlive()) {
            std::cout << "kill!" << std::endl;
            delete *it; // destruction de l’humanoide référencé
            it = _humanoids.erase(it); // suppression de l’élément dans la liste
        } else
            ++it;
    return _turn++;
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

    for (Humanoid* h :_humanoids) {
        d = h->getDistance(v);

        if (d > 0 && min > d) {
            min = d;
            res = h;
        }
    }

    return res;
}

Humanoid* Field::getCloset(const Buffy* b) const {

    Humanoid* res = nullptr;
    int min = INT_MAX;
    int d;

    for (Humanoid* h :_humanoids) {
        d = h->getDistance(b);

        if (d >= 0 && min > d) {
            min = d;
            res = h;
        }
    }

    return res;
}

const std::list<Humanoid*>& Field::getHumanoids() const {
    return _humanoids;
}

void Field::replace(Human* oldPerson, Vampire* newPerson) {
    oldPerson->setIsAlive(false);
    _hCounter--;

    _humanoids.push_back(newPerson);
    _vCounter++;
}

void Field::reset() {
    _turn = 0;
    _humanoids.clear();
}

void Field::init() {

    _vCounter = _totalVampire;
    _hCounter = _totalHuman;
    unsigned x = Utils::generateRandom(0, _width);
    unsigned y = Utils::generateRandom(0, _height);
    _humanoids.push_back(new Buffy(x, y));

    for (int i = 0; i < _totalHuman; i++) {
        x = Utils::generateRandom(0, _width);
        y = Utils::generateRandom(0, _height);
        _humanoids.push_back(new Human(x, y));
    }

    for (int i = 0; i < _totalVampire; i++) {
        x = Utils::generateRandom(0, _width);
        y = Utils::generateRandom(0, _height);
        _humanoids.push_back(new Vampire(x, y));
    }
}

void Field::decVampire() {
    _vCounter--;
}

bool Field::isFreeOfVampires() const {
    return _vCounter == 0;
}

void Field::decHuman() {
    _hCounter--;
}

bool Field::isFreeOfHumans() const {
    return _hCounter == 0;
}

