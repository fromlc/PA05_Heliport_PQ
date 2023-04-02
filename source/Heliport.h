//------------------------------------------------------------------------------
// Heliport.h : class declaration and definition
// 
// std::priority_queue references:
//  1) member functions
// https://cplusplus.com/reference/queue/priority_queue/
//  2) example code with custom comparison
// https://cplusplus.com/reference/queue/priority_queue/priority_queue/
//------------------------------------------------------------------------------
#pragma once

#include "Helicopter.h"

#include <queue>          // std::priority_queue
#include <vector>         // for custom comparison

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::priority_queue;
using std::vector;

//------------------------------------------------------------------------------
// CompareFuelLevels : compare Helicopters based on fuel level
//------------------------------------------------------------------------------
class CompareFuelLevels {
private:
    bool reverse;

public:
    // constructor with hooks for descending sort order
    CompareFuelLevels(const bool& revparam = false) {
        reverse = revparam;
    }

    // comparison operator used by std::priority_queue
    bool operator() (const Helicopter& lhs, const Helicopter& rhs) const {
        if (reverse) {
            return (rhs.getFuelLeft() > lhs.getFuelLeft());
        }
        return (rhs.getFuelLeft() < lhs.getFuelLeft());
    }
};

//------------------------------------------------------------------------------
// Heliport
//------------------------------------------------------------------------------
class Heliport {
private:
    // use custom comparison operator
    priority_queue<Helicopter, vector<Helicopter>, CompareFuelLevels> pqHelos;

public:
    // constructors
    Heliport() { }

    //--------------------------------------------------------------------------
    // insert Helicopter with fuel levels in ascending order
    //--------------------------------------------------------------------------
    void insert(Helicopter h) { pqHelos.push(h); }

    //--------------------------------------------------------------------------
    // - if priority queue not empty, fill reference param with top element
    // - return true if priority queue is not empty, false otherwise
    //--------------------------------------------------------------------------
    bool front(Helicopter& returnHelo) {

        if (pqHelos.empty()) {
            return false;
        }

        returnHelo = pqHelos.top();
        return true;
    }

    //--------------------------------------------------------------------------
    // - if priority queue is not empty, remove top element
    //--------------------------------------------------------------------------
    void pop_front() {

        if (!pqHelos.empty()) {
            pqHelos.pop();
        }
    }
};

