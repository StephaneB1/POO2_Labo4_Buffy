/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : Field.cpp
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */

#include <iostream>
#include "Field.h"
#include "Utils.h"

Field::Field(unsigned int _width, unsigned int _height, unsigned totalHuman,
             unsigned totalVampire) : _width(_width), _height(_height),
                                      _turn(0), _totalHuman(totalHuman),
                                      _totalVampire(totalVampire) {
    init();
}

unsigned Field::nextTurn() {

    // Déterminer les prochaines actions
    for (std::list<std::shared_ptr<Humanoid>>::iterator it = _humanoids.begin();
         it != _humanoids.end(); it++)
        (*it)->setAction(*this);
    // Executer les actions
    for (std::list<std::shared_ptr<Humanoid>>::iterator it = _humanoids.begin();
         it != _humanoids.end(); it++)
        (*it)->executeAction(this);
    // Enlever les humanoides tués
    for (std::list<std::shared_ptr<Humanoid>>::iterator it = _humanoids.begin();
         it != _humanoids.end();) {
        if (!(*it)->isAlive()) {
            //delete *it; // destruction de l’humanoide référencé
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

template<typename T>
void Field::addToHumanoids(unsigned total) {
    unsigned x, y;
    for (int i = 0; i < total; i++) {
        x = Utils::generateRandom(0, _width);
        y = Utils::generateRandom(0, _height);
        _humanoids.push_back(std::make_shared<T>(x, y));
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

const std::list<std::shared_ptr<Humanoid>>& Field::getHumanoids() const {
    return _humanoids;
}

void
Field::replaceByAVampire(const std::shared_ptr<Humanoid>& target) {
    _vCounter++;
    _humanoids.push_back(std::make_shared<Vampire>(target->getX(),
                                                   target->getY()));
}


void Field::kill(std::shared_ptr<Humanoid>& h, bool targetIsVampire) {
    h->kill();

    // Update the right counter
    if (targetIsVampire) {
        _vCounter--;
    } else {
        _hCounter--;
    }
}

