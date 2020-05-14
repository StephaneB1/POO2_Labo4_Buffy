//
// Created by Stephane on 14.05.2020.
//

#include "BuffyController.h"

BuffyController::BuffyController() : _field(Field(10, 10)) {

    _displayer.display(_field);

}

void BuffyController::start(size_t width, size_t height, unsigned totalHumans,
                            unsigned totalVampire) {

}
