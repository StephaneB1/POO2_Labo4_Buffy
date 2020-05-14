//
// Created by Stephane on 14.05.2020.
//

#ifndef POO2_LABO4_BUFFY_BUFFYCONTROLLER_H
#define POO2_LABO4_BUFFY_BUFFYCONTROLLER_H

#include <cstdlib>
#include "Field.h"
#include "FieldDisplayer.h"

class Field;
class FieldDisplayer;

class BuffyController {

public:
    BuffyController();

    void start(size_t width, size_t height, unsigned totalHumans, unsigned totalVampire);
    void getStats();
    void quit();

private:
    Field _field;
    FieldDisplayer _displayer;

};


#endif //POO2_LABO4_BUFFY_BUFFYCONTROLLER_H
