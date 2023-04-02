//------------------------------------------------------------------------------
// Heliport.h : class declaration and definition
//------------------------------------------------------------------------------
#pragma once

#include "Helicopter.h"

#include <vector>
using std::vector;

class Heliport {
private:
    vector<Helicopter> vHelosPQ;

public:
    // constructors
    Heliport() { }

    Heliport(int nHelosExpected) {
        vHelosPQ.reserve(nHelosExpected);
    }

    //--------------------------------------------------------------------------
    // insert Helicopter into vector with fuel level in ascending order
    //--------------------------------------------------------------------------
    void insert(Helicopter h) {

        // don't loop when first helo or helo with most fuel
        if (vHelosPQ.empty() ||
            vHelosPQ.back().getFuelLeft() < h.getFuelLeft()) {

            vHelosPQ.push_back(h);
            return;
        }

        // insert helo between to others
        for (auto it = vHelosPQ.begin(); it != vHelosPQ.end(); ++it) {
            if (it->getFuelLeft() >= h.getFuelLeft()) {
                vHelosPQ.insert(it, h);
                return;
            }
        }
    }

    //--------------------------------------------------------------------------
    // - if vector not empty, fill reference param with Helicopter at index 0
    // - return true if vector is not empty, false otherwise
    //--------------------------------------------------------------------------
    bool front(Helicopter& returnHelo) {
        if (vHelosPQ.empty()) {
            return false;
        }

        returnHelo = vHelosPQ.at(0);
        return true;
    }

    //--------------------------------------------------------------------------
    // - if vector is not empty, remove Helicopter at index 0
    //--------------------------------------------------------------------------
    void pop_front() {
        if (!vHelosPQ.empty()) {
            vHelosPQ.erase(vHelosPQ.begin());
        }
    }
};

