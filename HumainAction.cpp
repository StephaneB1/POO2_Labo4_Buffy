//
// Created by Chau Ying on 05.05.2020.
//

#include "HumainAction.h"

void HumainAction::excute(const Field& field) {
    Action::move();
}

HumainAction::HumainAction(unsigned int _stepRange) : Action(_stepRange) {}
