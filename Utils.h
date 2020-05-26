/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : Utils.h
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */
#ifndef POO2_LABO4_BUFFY_UTILS_H
#define POO2_LABO4_BUFFY_UTILS_H

#include <chrono>
#include <random>

class Utils {


    static std::minstd_rand0 generator;

public:

    Utils();

    /**
     * Generate a random value in the given range with a Linear congruential
     * random number engine
     * @param min
     * @param max
     * @return
     */
    static unsigned generateRandom(unsigned min, unsigned max);

};


#endif //POO2_LABO4_BUFFY_UTILS_H
