//
// Created by Stephane on 14.05.2020.
//

#include "Field.h"

Field::Field(unsigned int width, unsigned int height) : _width(width), _height(height)  {

}

unsigned int Field::getWidth() const {
    return _width;
}

unsigned int Field::getHeight() const {
    return _height;
}
