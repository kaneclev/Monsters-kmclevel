#include "Closet_Monster.h"
#include "Under_Bed_Monster.h"
#include <ctime>
#include <iostream>
using namespace std;

bool test_Darkness_Monster();
bool test_Closet_Monster();
bool test_Under_Bed_Monster();

int main() {
    srand(time(NULL));
    if (test_Darkness_Monster()) {
        cout << "Passed all Darkness Monster test cases" << endl;
    }
    if (test_Closet_Monster()) {
        cout << "Passed all Closet Monster test cases" << endl;
    }
    if (test_Under_Bed_Monster()) {
        cout << "Passed all Under Bed Monster test cases" << endl;
    }
    return 0;
}

bool test_Darkness_Monster() {
    bool passed = true;
    // Darkness Monster is abstract so we can only access it through the child classes
    Closet_Monster cm;
    if (cm.get_number_of_eyes() < 2 || cm.get_number_of_eyes() > Darkness_Monster::MAX_NUMBER_EYES) {
        passed = false;
        cout << "FAILED default constructor test case" << endl;
    }
    Closet_Monster cm2(1);
    if (cm2.get_number_of_eyes() != Darkness_Monster::MAX_NUMBER_EYES) {
        passed = false;
        cout << "FAILED 1 test case" << endl;
    }
    cm2.set_number_of_eyes(50);
    if (cm2.get_number_of_eyes() != 50) {
        passed = false;
        cout << "FAILED 50 test case" << endl;
    }
    cm2.set_number_of_eyes(101);
    if (cm2.get_number_of_eyes() != Darkness_Monster::MAX_NUMBER_EYES) {
        passed = false;
        cout << "FAILED 101 test case" << endl;
    }
    cm2.set_number_of_eyes(50);
    cm2.set_number_of_eyes(-7);
    if (cm2.get_number_of_eyes() != Darkness_Monster::MAX_NUMBER_EYES) {
        passed = false;
        cout << "FAILED negative test case" << endl;
    }
    // TODO: Test poke_eye method
    // test one
    cm2.set_number_of_eyes(15); // use a number of eyes to make sure we are properly checking/decrementing
    cm2.poke_eye();
    if (cm2.get_number_of_eyes() != 14) { // if we didn't in fact decrement
        passed = false;
        cout << "FAILED eye poking test case" << endl; // return in a fashion like all other test cases
    }
    cout << cm2.poke_eye() << endl;
    // Test two; lets make sure the other branch of our conditional in the poke_eye function works.
    cm2.set_number_of_eyes(0); // In this case, we should reset the number of eyes.
    cm2.poke_eye();
    if (cm2.get_number_of_eyes() == 0) { // Check that we reach the else statement and reset the number of eyes.
        passed = false;
        cout << "FAILED: eye poking does not reset number of eyes." << endl;
    }

    // Test three; make sure that we do in fact return false if there are no eyes left to poke.
    cm2.set_number_of_eyes(0); // In this case, we should return false, because there are no eyes to poke.
    // created my own method to force the number of eyes to be zero so that we can test the return value
    cm2.force_number_of_eyes(0);
    if (cm2.poke_eye()) { // if it is true then we have failed the test.
        cout << cm2.get_number_of_eyes() << endl;
        passed = false;
        cout << "FAILED: We did not return false when num_eyes equals zero." << endl;
    }

    return passed;
}

bool test_Closet_Monster() {
    bool passed = true;
    Closet_Monster cm(4);
    if (cm.is_open()) {
        passed = false;
        cout << "FAILED non-default constructor test case" << endl;
    }
    cm.open_door();
    if (!cm.is_open()) {
        passed = false;
        cout << "FAILED open door test case" << endl;
    }
    Closet_Monster cm2;
    if (cm2.is_open()) {
        passed = false;
        cout << "FAILED default constructor test case" << endl;
    }
    // TODO: test scare method
    // First check teh case in which the door is open.
    cm.open_door();
    cm.scare();
    if (cm.is_open()) {
        passed = false;
        cout << "FAILED scare test case; door shouldnt be open" << endl;
    }

    // Test two: in the case that the door is closed.
    cm.scare();
    if(cm.is_open()) {
        passed = false;
        cout << "FAILED scare test case; door shouldnt be open" << endl;
    }
    return passed;
}

bool test_Under_Bed_Monster() {
    bool passed = true;
    Under_Bed_Monster ubm(78);
    if (ubm.get_number_of_eyes() != 78) {
        passed = false;
        cout << "FAILED non-default constructor test case" << endl;
    }
    Under_Bed_Monster ubm2;
    if (ubm2.get_number_of_eyes() < 2 || ubm2.get_number_of_eyes() > Darkness_Monster::MAX_NUMBER_EYES) {
        passed = false;
        cout << "FAILED default constructor test case" << endl;
    }
    // TODO: test scare method
    // Test case 1:
    for (int i = 0; i < 5; i++) { // check and make sure that calling it doesnt return nothing.
        std::string scareMessage = ubm2.scare(); // grab the string that scare() returns
        std::cout << "Scare #" << i+1 << ": " << scareMessage << std::endl; //
        if(scareMessage.empty()) {
            cout << "FAILED scare method by empty string" << endl;
            passed = false;
        }
    }
    // Test Case 2: Check and make sure it is actually random
    int repeatCount = 0;
    for (int i = 0; i < 100; i++) { // Loop through and repeatedly generate 'random' responses.
        std::string scareMessage = ubm2.scare();
        std::string newMessage = ubm2.scare();
        if(scareMessage == newMessage) { // If they are equal, increment repeatcount.
            repeatCount++;
        }
        if (repeatCount == 100) { // Too many repeats to just be naturally random.
            passed = false;
        }
        std::cout << "Scare #" << i+1 << ": " << scareMessage << std::endl; // Visual output.
        std::cout << "Scare #" << i+1 << ": " << newMessage << std::endl;
        std::cout << repeatCount << endl;
    }

    return passed;
}