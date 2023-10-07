#include "Under_Bed_Monster.h"
using namespace std;

Under_Bed_Monster::Under_Bed_Monster() : Darkness_Monster() {
}

Under_Bed_Monster::Under_Bed_Monster(int noe) : Darkness_Monster(noe) {
}

// TODO: implement the scare method here
string Under_Bed_Monster::scare() {
    // Generate a random number to decide the scare message
    int random = rand() % 2;

    if (random == 0) { // if random is 0 we say it grabs you, otherwise it is watching you.
        return "*Grabs you*";
    } else {
        return "*" + std::to_string(number_of_eyes) + " eyes watching you*";
    }
}