/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : BuffyController.h
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */

#ifndef POO2_LABO4_BUFFY_BUFFYCONTROLLER_H
#define POO2_LABO4_BUFFY_BUFFYCONTROLLER_H

#include <cstdlib>
#include "Field.h"
#include "FieldDisplayer.h"

class Field;
class FieldDisplayer;

class BuffyController {

private:
    /**
     * Displays an error message
     * @param msg : message to display in the console
     */
    void displayErrorMsg(const std::string& msg);

public:
    BuffyController();

    /**
     * Starts a simulation
     * @param width        : width of the field
     * @param height       : height of the field
     * @param totalHumans  : total number of Humans
     * @param totalVampire : total number of Vampires
     */
    void start(size_t width, size_t height, unsigned totalHumans, unsigned totalVampire);

    /**
     * Displays the stats out of TOTAL_SIMULATION iterations
     * @param width        : width of the field
     * @param height       : height of the field
     * @param totalHumans  : total number of Humans
     * @param totalVampire : total number of Vampires
     */
    void displayStats(size_t width, size_t height, unsigned totalHumans, unsigned totalVampire);

private:
    const unsigned TOTAL_SIMULATION = 10000;

    FieldDisplayer _displayer;
    bool _simulating;

};


#endif //POO2_LABO4_BUFFY_BUFFYCONTROLLER_H
