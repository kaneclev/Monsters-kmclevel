#include "Closet_Monster.h"
#include "Under_Bed_Monster.h"
#include <ctime>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

int get_int_input(string prompt, string invalid, int low, int high) {
    cout << prompt;
    int choice = 0;
    string junk;
    while (!(cin >> choice) || choice < low || choice > high) {
        cout << invalid;
        cin.clear();
        getline(cin, junk);
    }
    return choice;
}
int main() {
    /*
     * TODO: Create a vector of Darkness Monster unique pointers and push a variety of ten Closet Monsters and Under Bed Monsters to it.
     * TODO: Tell the user that there are monster eyes staring at them from the darkness!
     * TODO: Repeatedly give the user the option to poke the eyes or run away.
     *     - If they choose to poke the eyes, loop through the vector and call the poke_eye and scare method on each monster. Output the scare method return values to the console.
     *         - Note: the calls to poke_eye are NOT polymorphism.
     *         - Note: the calls to scare are polymorphism.
     *     - If they choose to run away, the program ends.
     */

    std::vector<std::unique_ptr<Darkness_Monster>> monsters; // Create the vector of pointers to monster objects
    // Create a variety of ten monsters and add them to the vector.
    monsters.push_back(std::make_unique<Closet_Monster>(5));
    monsters.push_back(std::make_unique<Closet_Monster>(4));
    monsters.push_back(std::make_unique<Closet_Monster>(1));
    monsters.push_back(std::make_unique<Closet_Monster>(10));
    monsters.push_back(std::make_unique<Closet_Monster>(12));
    monsters.push_back(std::make_unique<Under_Bed_Monster>(33));
    monsters.push_back(std::make_unique<Under_Bed_Monster>(67));
    monsters.push_back(std::make_unique<Under_Bed_Monster>(88));
    monsters.push_back(std::make_unique<Under_Bed_Monster>(45));
    monsters.push_back(std::make_unique<Under_Bed_Monster>(3));

    std::cout << "There are monster eyes staring at you from the darkness!" << std::endl;

    bool hasRanAway = false;
    int choice;
    while(!hasRanAway) {
        std::cout << "You may either (1) poke the eyes of the monster or (2) run away." << endl;
        choice = get_int_input("What will your choice be?: ",
                               "Invalid input. Pick either 1 or 2. ",
                               1,
                               2);

         if(choice == 1) {
             for(int i = 0; i < 10; i++) {
                 monsters[i]->poke_eye();
                 cout << monsters[i]->scare() << endl;

             }
         }
         else {
             hasRanAway = true;
         }
    }

    return 0;
}


