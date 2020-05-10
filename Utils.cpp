//
// Created by Chau Ying on 10.05.2020.
//


#include "Utils.h"
#include <random>

Utils::Utils() {
}

unsigned Utils::generateRandom(unsigned min, unsigned max) {
    return (generator() * max) + min;
}

std::minstd_rand0 Utils::generator(
        std::chrono::system_clock::now().time_since_epoch().count());

