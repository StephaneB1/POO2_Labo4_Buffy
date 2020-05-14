//
// Created by Stephane on 14.05.2020.
//

#include "FieldDisplayer.h"
#include <iostream>
#include <iomanip>


void FieldDisplayer::display(const Field& field) const {

    std::cout << "+" << std::left << std::setfill('-') << std::setw(field.getWidth()) << std::endl;
    for(size_t i = 0; i < field.getHeight() - 2; ++i) {
        std::cout << "|" << std::setfill(' ') << std::setw(field.getWidth()) << "|" << std::endl;
    }

}
