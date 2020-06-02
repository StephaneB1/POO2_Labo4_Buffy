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
#include "Humanoid/Humanoid.h"

class Utils {

private:
    static std::minstd_rand0 generator;

public:

    Utils();

    /**
     * Generate a random value in the given range with a Linear congruential
     * random number engine
     * @param min
     * @param max
     * @return A random unsigned between min and max
     */
    static unsigned generateRandom(unsigned min, unsigned max);

    /**
     * Indicate if the nearby his target (one case distance)
     * @param source
     * @param target
     * @return true is the source is one case distance to the source
     */
    static bool isNextToTarget(Humanoid* source,
                               const std::weak_ptr<Humanoid>& target);

    /**
     * Return the euclidean distance between from and to
     * @param fromX
     * @param fromY
     * @param toX
     * @param toY
     * @return euclidean distance casted into int
     */
    static int getEuclideanDistance(int fromX, int fromY, int toX, int toY);

};


#endif //POO2_LABO4_BUFFY_UTILS_H
