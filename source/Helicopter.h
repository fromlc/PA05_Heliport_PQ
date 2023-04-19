//------------------------------------------------------------------------------
// Helicopter.h : class declaration
//------------------------------------------------------------------------------
#ifndef HELICOPTER_H
#define HELICOPTER_H

#include "Throttle.h"
#include "FuelGauge.h"
#include "Speedometer.h"

#include <ostream>
#include <string>
using std::ostream;
using std::string;

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr int HELO_HARDLANDING_LIMIT = -3;

//------------------------------------------------------------------------------
// enum for helicopter status
//------------------------------------------------------------------------------
enum HeloStatus { HELO_ONGROUND, HELO_INAIR, HELO_HARDLANDING, HELO_CRASHED };

//------------------------------------------------------------------------------
// Helicopter
//------------------------------------------------------------------------------
class Helicopter {
private:
	string name;
	int altitude;
	int distance;
	HeloStatus status;
	Throttle stick;
	FuelGauge fg;
	Speedometer speedo;

public:
	// constructor
	Helicopter();

	// returns current altitude
	int getAltitude() const;
	// returns distance flown so far
	int getDistance() const;
	// puts altitude and distance in reference params
	HeloStatus getPosition(int&, int&);

	// increases altitude by absolute passed value, returns current altitude
	int goUp(int);
	// decreases altitude by absolute passed value, returns current altitude
	int goDown(int);
	// increases distance by absolute passed value, returns distance flown so far
	int goForward(int);

	// resets altitude to 0
	void goLand();

	// control enumerated speed
	int setThrottle(speedSelect);
	// get cruising speed in mph
	int getMph() const;
	// get remaining fuel units
	int getFuelLeft() const;
	// force fuel tank level
	void setFuelLeft(int);

	// get enumerated flight status
	HeloStatus getStatus() const;

	// aircraft name
	void setName(const string&);
	string getName() const;

	// overload stream insertion operator <<
	friend static ostream& operator<<(std::ostream&, Helicopter&);

private:
	int _setThrottle(speedSelect);
};

//------------------------------------------------------------------------------
// overload stream insertion operator <<
//------------------------------------------------------------------------------
static ostream& operator<<(std::ostream& os, Helicopter& h) {

	os << h.name << " has "
		<< h.fg.getFuelAmount() << " gallons of fuel";

	return os;
}

#endif // HELICOPTER_H
