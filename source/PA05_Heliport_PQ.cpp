//------------------------------------------------------------------------------
// PA05_Heliport_PQ.cpp : app code for Helicopter priority queue
//------------------------------------------------------------------------------

#include "Heliport.h"

// turn off assertions 
//#define NDEBUG
// must #define NDEBUG before #including assert.h or cassert
#include <cassert>

#include <cstdlib>
#include <iostream>

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::cin;
using std::cout;
using std::string;

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr int NUM_HELOS = 4;

//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------
namespace heli {
    Heliport port(NUM_HELOS);

    string names[] = { 
        "Apache 7",
        "Huey Looey",
        "Black Hawk",
        "Marine 1",
    };
}

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
void initIncoming();
void displayLandings();

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    initIncoming();
    displayLandings();

    return 0;
}

//------------------------------------------------------------------------------
// sets up incoming flights
//------------------------------------------------------------------------------
void initIncoming() {

    // make sure the number of names matches the number of Helicopters
    assert((sizeof(heli::names) / sizeof(string)) == NUM_HELOS);

    Helicopter h;
    h.setThrottle(SPEED_SLOW);

    for (int i = 0; i < NUM_HELOS; ++i) {

        // set random amount of fuel
        h.setFuelLeft(rand() % 70 + 30);

        h.setName(heli::names[i]);

        // call by value generates copy
        // to prevent dangling reference and keep names unique
        heli::port.insert(h);
    }
}

//------------------------------------------------------------------------------
// displays helicopter landings with fuel levels in ascending order
//------------------------------------------------------------------------------
void displayLandings() {

    cout << "\nWelcome to the CS 281 Heliport!\n\n";

    Helicopter h;
    int i = 1;

    cout << "Landings in ascending order of remaining fuel\n";
    while (heli::port.front(h)) {
        cout << i++ << ": " << h << '\n';

        heli::port.pop_front();
    }
    cout << '\n';
}
