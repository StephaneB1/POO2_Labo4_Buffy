//
// Created by Chau Ying on 05.05.2020.
//

#include "Action.h"

#include "../Field.h"

Action::Action(Humanoid* humanoid) : _humanoid(humanoid){

}

Humanoid* Action::getHumanoid() const {
    return _humanoid;
}
