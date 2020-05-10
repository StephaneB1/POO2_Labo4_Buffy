//
// Created by Chau Ying on 05.05.2020.
//

#include "Action.h"

#include "../Field.h"




void Action::setHumanoid(Humanoid* _humanoid) {
    Action::_humanoid = _humanoid;
}

Humanoid* Action::getHumanoid() const {
    return _humanoid;
}

Action::~Action() {

}
