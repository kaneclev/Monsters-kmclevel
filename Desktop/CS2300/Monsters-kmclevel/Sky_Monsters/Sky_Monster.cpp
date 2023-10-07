//
// Created by Kane Cleveland on 10/7/23.
//

#include "Sky_Monster.h"
// Default constructor for Sky_Monster
Sky_Monster::Sky_Monster() : number_of_wings(2) {
}

// Non-default constructor for Sky_Monster
Sky_Monster::Sky_Monster(int now) : number_of_wings(now) {
    if (now < 2 || now % 2 == 1) {
        number_of_wings = MAX_NUMBER_WINGS;
    }

}

// Getter for the number of wings
int Sky_Monster::get_number_of_wings() const {
    return number_of_wings;
}

// Default implementation of the scare method for Sky_Monster
std::string Sky_Monster::scare() {
    return "You feel a chilling wind as the sky monster approaches!";
}

void Sky_Monster::set_number_of_wings(int now) {
    if (now < 2 || now > MAX_NUMBER_WINGS || now % 2 != 0) {
        now = MAX_NUMBER_WINGS;
    }
    if (now % 2 != 0) {
        now++;
    }
    number_of_wings = now;
}

int Sky_Monster::growth_spurt() {
    set_number_of_wings(number_of_wings+2);

    return 0;
}
