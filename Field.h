/*
-----------------------------------------------------------------------------------
Laboratoire : 04
Fichier     : Field.h
Auteur(s)   : Stéphane Bottin & Chau Ying Kot
Date        : 14.05.2020
-----------------------------------------------------------------------------------
 */
#ifndef POO2_LABO4_BUFFY_FIELD_H
#define POO2_LABO4_BUFFY_FIELD_H


class Field {
private:
    unsigned _width;
    unsigned _height;
    unsigned turn;

public:
    Field(unsigned int _width, unsigned int _height);
    /**
     * Apply a single turn
     * @return retunn next turn count
     */
    int nextTurn();
    /**
     * Find the closest Humanoid from h
     * @param h
     * @return return the closest humainoid from h
     */
    unsigned int getWidth() const;

    unsigned int getHeight() const;
};

#endif //POO2_LABO4_BUFFY_FIELD_H
