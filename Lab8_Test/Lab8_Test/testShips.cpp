// Mikhail Nesterenko
// tests battleShip functions implementation
// 10/13/2013

#include "battleship.h"
#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() {

	srand(time(nullptr)); // random seed
	// srand(1); // fixed seed    

			  //
			  // checking Location functions
			  // 

			  // create Location
	Location mySpot;
	mySpot.x = 5;
	mySpot.y = 'e';

	// print Location 
	cout << "mySpot.x = " << mySpot.x << " mySpot.y = " << mySpot.y << endl;

	mySpot = pick(); // assign randomly generated Location to mySpot
	cout << "mySpot.x = " << mySpot.x << " mySpot.y = " << mySpot.y << endl;

	mySpot = fire(); // assign user input Location to mySpot
	cout << "mySpot.x = " << mySpot.x << " mySpot.y = " << mySpot.y << endl;


	//
	// checking Ship functions
	//

	
	Ship myShip;

	myShip.loc = pick(); // assign random Location to myShip
	myShip.sunk = false;  // myShip is not sunk
	printShip(myShip); // print myShip information

	if(match(myShip,mySpot))
	cout << "myShip is at mySpot Location\n";
	else
	cout << "myShip is not at mySpot Location\n";

	sink(myShip); // sinking myShip
	printShip(myShip); // print sunk ship
	

	//
	// checking fleet functions
	// 

	
	Ship myFleet[fleetSize];

	initialize(myFleet); //assigning -1 to all ship's Locations in myFleet
	printFleet(myFleet);

	deploy(myFleet); // deploying ships at random Locations
	printFleet(myFleet);

	if(check(myFleet,mySpot) != -1)
	cout << "myFleet has a ship at mySpot\n";
	else
	cout << "myFleet does not have a ship at mySpot\n";

	if(operational(myFleet))
	cout << "at least one ship is not sunk\n";
	else
	cout << "all ships are sunk\n";
	
}