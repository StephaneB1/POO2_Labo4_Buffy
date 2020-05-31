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

template<typename F>
std::weak_ptr<Humanoid>
Field::getClosest(std::weak_ptr<Humanoid> source, F distFunc) const {
    std::weak_ptr<Humanoid> res;
    int min = INT_MAX;
    int d;

    for (std::weak_ptr<Humanoid> h :_humanoids) {
        d = distFunc(h);

        if (d >= 0 && min > d) {
            min = d;
            res = h;
        }
    }

    return res;
}

std::weak_ptr<Humanoid> Field::getClosest(std::weak_ptr<Vampire> v) const {
    return getClosest(v, [&](std::weak_ptr<Humanoid> h1) {
        return h1.lock()->getDistance(v);
    });
}

std::weak_ptr<Humanoid> Field::getClosest(std::weak_ptr<Buffy> b) const {
    return getClosest(b, [&](std::weak_ptr<Humanoid> h1) {
        return h1.lock()->getDistance(b);
    });
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
Field::replace(std::weak_ptr<Humanoid> target) {
    _vCounter++;
    _hCounter--;

    _humanoids.push_back(std::make_shared<Vampire>(target.lock()->getX(), target
            .lock()->getY()));
    target.lock()->kill();
}

