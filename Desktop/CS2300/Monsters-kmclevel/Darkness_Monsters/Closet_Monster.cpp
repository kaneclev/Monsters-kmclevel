#include "Closet_Monster.h"
using namespace std;

// FIXME: this has two constructors to allow creation of monsters that have or do not have eyes
Closet_Monster::Closet_Monster() : Darkness_Monster(), door_is_open(false) {
}

Closet_Monster::Closet_Monster(int noe) : Darkness_Monster(noe), door_is_open(false) {
}

bool Closet_Monster::open_door() {
    if (door_is_open) {
        return false;
    }
    door_is_open = true;
    return true;
}

bool Closet_Monster::is_open() const {
    return door_is_open;
}

// TODO: Implement the scare method here
string Closet_Monster::scare() {
    return "BOO!!!!!!!!!!!!";
}
