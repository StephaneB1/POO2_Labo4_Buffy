//
// Created by Stephane on 14.05.2020.
//

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
    int nexTurn();
    /**
     * Find the closest Humanoid from h
     * @param h
     * @return return the closest humainoid from h
     */
    unsigned int getWidth() const;
    unsigned int getHeight() const;
};

#endif //POO2_LABO4_BUFFY_FIELD_H
