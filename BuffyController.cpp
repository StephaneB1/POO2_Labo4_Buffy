/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : BuffyController.cpp
Auteur(s)   : St�phane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */
#include "BuffyController.h"

BuffyController::BuffyController() : _field(Field(50, 50)) {

    _displayer.display(_field);

}

void BuffyController::start(size_t width, size_t height, unsigned totalHumans,
                            unsigned totalVampire) {

}