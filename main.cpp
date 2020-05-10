
#include <cstdlib>
#include <iostream>
#include "Action/Move.h"
#include "Humanoid/Human.h"
#include "Field.h"

using namespace std;

int main() {


    Field f(10, 10);
    Move* move = new Move(1);
    Human h(move, 5, 5);
    move->setHumanoid(&h);
    cout << h.getX() << " " << h.getY() << endl;
    h.setAction(f);
    h.executeAction(f);
    cout << h.getX() << " " << h.getY() << endl;

    return EXIT_SUCCESS;
}
