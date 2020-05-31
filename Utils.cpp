/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : Utils.cpp
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */

#include "Utils.h"
#include <random>

Utils::Utils() {
}

unsigned Utils::generateRandom(unsigned min, unsigned max) {
    return (generator() % max) + min;
}

std::minstd_rand0 Utils::generator(
        std::chrono::system_clock::now().time_since_epoch().count());

bool Utils::isNextToTarget(Humanoid* source, std::weak_ptr<Humanoid> target) {
    return abs(source->getX() - target.lock()->getX()) <= 1 &&
           abs(source->getY() - target.lock()->getY()) <= 1;
}
