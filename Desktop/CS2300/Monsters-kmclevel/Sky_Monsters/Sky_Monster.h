//
// Created by Kane Cleveland on 10/7/23.
//

#ifndef MONSTERS_SKY_MONSTER_H
#define MONSTERS_SKY_MONSTER_H
#include <iostream>
#include <string>
#include <memory>
#include <vector>

class Sky_Monster {
public:
    /**
     * Requires: nothing
     * Modifies: number_of_wings
     * Effects: default constructor, sets number_of_wings to 2
     */
    Sky_Monster();

    /**
     * Requires: nothing
     * Modifies: number_of_wings
     * Effects: non-default constructor, sets number_of_wings to the specified value
     */
    explicit Sky_Monster(int now);

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns the number of wings
     */
    int get_number_of_wings() const;

    /**
     * Requires: nothing
     * Modifies: number of wings
     * Effects: returns new number of wings
     */
    int growth_spurt();

    /**
     * Requires: integer number of wings
     * Modifies: the number of wings
     * Effects: nothing; void
     */


    void set_number_of_wings(int now);
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: virtual method, returns a generic scare message
     */
    virtual std::string scare();
    static const int MAX_NUMBER_WINGS = 100;
protected:
    int number_of_wings;

};



#endif //MONSTERS_SKY_MONSTER_H
