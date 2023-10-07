#include "Darkness_Monster.h"


Darkness_Monster::Darkness_Monster() {
    number_of_eyes = rand() % (MAX_NUMBER_EYES - 1) + 2;
}

Darkness_Monster::Darkness_Monster(int noe) {
    set_number_of_eyes(noe);
}

int Darkness_Monster::get_number_of_eyes() const {
    return number_of_eyes;
}

void Darkness_Monster::force_number_of_eyes(int forcedEyes) {
    number_of_eyes = forcedEyes;
}

void Darkness_Monster::set_number_of_eyes(int noe) {
    if (noe < 2 || noe > MAX_NUMBER_EYES) {
        noe = MAX_NUMBER_EYES;
    }
    number_of_eyes = noe;
}

// TODO: Implement poke_eye method here
bool Darkness_Monster::poke_eye() {
    if (number_of_eyes > 0) {
        number_of_eyes--;
        return true;
    }
    else {
        number_of_eyes = rand() % (MAX_NUMBER_EYES - 4) + 5;
        return false;
    }

}
