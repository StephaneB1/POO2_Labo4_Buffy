//
// Created by Chau Ying on 10.05.2020.
//

#ifndef POO2_LABO4_BUFFY_UTILS_H
#define POO2_LABO4_BUFFY_UTILS_H

#include <chrono>
#include <random>

class Utils {


    static std::minstd_rand0 generator;

public:

    Utils();

    static unsigned generateRandom(unsigned min, unsigned max);

};



#endif //POO2_LABO4_BUFFY_UTILS_H
