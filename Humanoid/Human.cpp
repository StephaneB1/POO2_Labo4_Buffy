//
// Created by Chau Ying on 10.05.2020.
//

#include <Utils.h>
#include "Humain.h"
#include "../Action/Move.h"

#include "../Field.h"

Humain::Humain(unsigned int _x, unsigned int _y, const Move& move)
        : Humanoid(_x, _y, move) {
}

void Humain::setAction(const Field& field) {
}
