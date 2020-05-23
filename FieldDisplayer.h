/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : FieldDisplayer.h
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */
#ifndef POO2_LABO4_BUFFY_FIELDDISPLAYER_H
#define POO2_LABO4_BUFFY_FIELDDISPLAYER_H


#include "Field.h"

class FieldDisplayer {

public:

    FieldDisplayer() {};

    void display(const Field& field) const;

};


#endif //POO2_LABO4_BUFFY_FIELDDISPLAYER_H