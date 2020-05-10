//
// Created by Chau Ying on 10.05.2020.
//

#include <Utils.h>
#include "Human.h"
#include "../Action/Move.h"

#include "../Field.h"




Human::Human(Move* _move, unsigned int _x, unsigned int _y) : Humanoid(_move,
                                                                             _x,
                                                                             _y) {
    setNextAction(_move);
}

void Human::setAction(const Field& field) {
    getMove()->setMove(field);
}
