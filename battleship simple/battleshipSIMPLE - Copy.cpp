/*1. Battleship Class

Recreate the battleship game shown earlier in the term (see weeks 4 & 5 in Modules) using a Ship class that creates five objects, one for each type of ship.
The class should have the following member variables:

shipName: Each object should be named to reflect the type of ship it is.
numHits: The number of hits the ship can take before sinking.
location: This should be an int array or vector and stores where on the 10 by 10 grid the ship is placed.
Think x,y coordinates like in graphing, only you need to store between 2 and 5 sets per ship.
Check the Reminder at the end for a way to make this easier.  Make sure none of the ships are placed overlapping each other!
hit: This should be an array of Boolean variables initialized as false, as the ship is hit in each location set the corresponding variable to true,
when the entire array is set to true, the ship is sunk.
The Ship class should also have the following functions:

Both a default and overloaded constructor.
Accessor (get) and Mutator (set) functions for each variable.
shipHit: This function should be called if a ship is hit, it should display the name of the ship,
how many times it has been hit or, if that was the final hit, that the ship has been sunk.
Your program needs to have the following function but it is NOT part of the Class:

displayShipInfo: when called this function should display the number of ships sunk,
the number of ships remaining, which ships have been sunk (by name), which ships are left (by name),
and which of the ships that have not been sunk have been hit and how many times they have been hit.


2. Battleship Game

Using the class and function you created above, complete the recreation of the battleship game. Y
es, you should look at my example files. No, you should not copy them directly.
You may need more functions and will likely need more variables than you have created already.
Create five objects from your class and either assign them random positions, have the user input the positions or hard code the positions yourself;
the choice is yours.

-If you have the user input the positions or assigned them randomly:
then have the computer attempt to sink your ships with random guesses.

-If you assigned the ship positions, have the user guess until all ships are sunk.



Regardless of how the game is played, display a message when all the ships have been sunk indicating the game is over.



Remember: The spaces on a battleship board can be numbered from 1-100 (0-99) starting in the upper left corner.
Don't allow guesses or random numbers outside this range.  I recommend placing the ships yourself (hard coded) and having the user guess. */

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath> 
#include <cstdlib>
#include <ctime>
using namespace std;

int findspace(string, int);

class Battleship
{
private:
	string shipName; // shipName: Each object should be named to reflect the type of ship it is.

	int pegs; // numHits: The number of hits the ship can take before sinking.
	int boatlocation[5]; // location: This should be an int array or vector and stores where on the 10 by 10 grid the ship is placed.
	int hit[];//hit array of Boolean variables initialized as false, as the ship is hit in each location set the corresponding variable to true,
	            //when the entire array is set to true, the ship is sunk.


public:
	// constructor
	
	void ship(string, int);

	//bool function to set with false values
	bool hits();

	// adds boat locations to an array
	int boats(int, int, int, int ,int);

	//search to see if ship has been hit
	int compare(int);

	//search to see if a shop has been sunk
    void sunk();
	//
	void displayhits();
		
	//display ship locations
	void displayShipInfo();



};

//constructor

void Battleship::ship(string s, int n)
{
	shipName = s;
	pegs = n;

}


int Battleship::boats(int a, int b, int c, int d, int e)
{
		
	for (int index = 0; index < pegs; index++)
	{
		if (index == 0)
		{
			boatlocation[index] = a;
		}
		else if (index == 1)
		{
			boatlocation[index] = b;
		}
		else if (index == 2)
		{
			boatlocation[index] = c;
		}
		else if (index == 3)
		{
			boatlocation[index] = d;
		}
		else if (index == 4)
		{
			boatlocation[index] = e;
		}
	}

	for (int arra = 0; arra < pegs; arra++)
	{
		return boatlocation[arra];
	}
}


//calls array for each ship
void Battleship::displayShipInfo()
{
	cout << this->shipName << " boat location: \n";
	for (int arra = 0; arra < pegs; arra++)
	{
		cout << this->boatlocation[arra] << endl;
	}

}

//set bool hits up with false values
bool Battleship::hits()
{
	for (int index = 0; index < pegs; index++)
	{
		hit[index] = false;
		return hit[index];
	}

}


//compare arrays to guess
int Battleship::compare(int place)
{
	
	int noHit = 0;
	
	for (int arra = 0; arra < pegs; arra++)
	{
		if (boatlocation[arra] == place)
		{
			cout << "You got a Hit!" << this->shipName << endl;;
			
			hit[arra] = true;
			noHit++;
			return hit[arra];
			
		}
		
	}
	
	
	if (noHit == 0)
	{
		cout << "You Missed " << this->shipName << endl;
	}

	
}

//it should display the name of the ship how many times it has been hit or , if that was the final hit, that the ship has been sunk.

void Battleship::displayhits()
{
	cout << this->shipName << endl;
	cout << "Total amount of hits it takes to destroy: " << this->pegs << endl;
	int numHits = 0;
	for (int arra = 0; arra < pegs; arra++)
	{
		if (hit[arra] == true)
		{
			numHits++;
		}
	}
	cout << "Total amount of hits: " << numHits << endl;
	if (numHits == pegs)
	{
		cout << this->shipName << " has sunk.\n";
	}
}


//add to it to bool array 
void Battleship::sunk()
{
	int sunk = 0;
	for (int index = 0; index < pegs; index++)
	{
		if (hit[index] == true)
		{
			sunk++;
		}
	}
	if (sunk == pegs)
	{
		cout << this->shipName << " ship has sunk!!" << endl;
	}
}


int main()
{
	//random number start
	srand(time(0));

	cout << "Hello World!\n";

	int filler = 0;

	//pt boat 2 pegs
	Battleship PT;
	string ptboat = "PT Boat";
	//hardcode name and ship.
	int ptpegs = 2;
	PT.ship(ptboat, ptpegs);
	PT.hits();

	//add pegs one random one by design
	int ptrandom = 0;
	int addpegpt = 0;
	ptrandom = 1 + (rand() % 100);

	addpegpt = ptrandom + 1;
	if (addpegpt > 100)
	{
		ptrandom = 1 + (rand() % 100);

	}
	//add pegs to array
	PT.boats(ptrandom, addpegpt, filler, filler, filler);


	//frigate boat 3 pegs
	Battleship frigate;
	string frigat = "frigate";
	int fripegs = 3;
	//hardcode name and ship.
	frigate.ship(frigat, fripegs);
	frigate.hits();

	//add pegs one random one by design
	int ptrandom1 = 0;
	int addpegpt1 = 0;
	int addanother = 0;

	//run a random; make sure none of the answers are the same as PT boat
	do 
	{
		ptrandom1 = 1 + (rand() % 100);
		
		addpegpt1 = ptrandom1 + 10;
		if (addpegpt1 == ptrandom || addpegpt1 == addpegpt)
		{
			ptrandom1 = ptrandom;
			break;
		}
		addanother = addpegpt1 + 10;
		if (addanother == ptrandom || addanother == addpegpt)
		{
			ptrandom1 = ptrandom;
			break;
		}
		if (addpegpt1 > 100 || addanother > 100)
		{
			ptrandom1 = ptrandom;
			break;
		}
	
				
	} while (ptrandom1 == ptrandom);

	frigate.boats(ptrandom1, addpegpt1, addanother, filler, filler);


	//submarine boat 3 pegs
	Battleship submarine;
	string submarines = "submarine";
	int subpegs = 3;
	//hardcode name and ship.
	submarine.ship(submarines, subpegs);
	submarine.hits();

	//add pegs one random one by design
	int sub1 = 0;
	int sub2 = 0;
	int sub3 = 0;

	//run a random; make sure none of the answers are the same as PT boat
	do
	{
		sub1 = 1 + (rand() % 100);

		while (sub1 == ptrandom || sub1 == addpegpt || sub1 == ptrandom1 || sub1 == addpegpt1 || sub1 == addanother)
		{
			sub1 = 1 + (rand() % 100);
		}

		sub2 = sub1 + 1;
		if (sub2 == ptrandom || sub2 == addpegpt || sub2 == ptrandom1 || sub2 == addpegpt1 || sub2 == addanother)
		{
		
			sub1 = ptrandom;
			break;
		}
		sub3 = sub2 + 1;
		if (sub3 == ptrandom || sub3 == addpegpt || sub3 == ptrandom1 || sub3 == addpegpt1 || sub3 == addanother)
		{
			sub1 = ptrandom;
			break;
		}
		if (sub2 > 100 || sub3 > 100 )
		{
			sub1 = ptrandom;
			break;
		}


	} while (sub1 == ptrandom);

	submarine.boats(sub1, sub2, sub3, filler, filler);


	//battleship boat 4 pegs
	Battleship battleship;
	string battleshipS = "battleship";
	int battleshipps = 4;
	//hardcode name and ship.
	battleship.ship(battleshipS, battleshipps);
	battleship.hits();

	//add pegs one random one by design
	int battle1 = 0;
	int battle2 = 0;
	int battle3 = 0;
	int battle4 = 0;

	//run a random; make sure none of the answers are the same as PT boat
	do
	{
		battle1 = 1 + (rand() % 100);

		while (battle1 == ptrandom || battle1 == addpegpt || battle1 == ptrandom1 || battle1 == addpegpt1 || battle1 == addanother
			|| battle1  == sub1 || battle1 == sub2 || battle1 == sub3 )
		{
			battle1 = 1 + (rand() % 100);
		}

		battle2 = battle1 + 10;
		if (battle2 == ptrandom || battle2 == addpegpt || battle2 == ptrandom1 || battle2 == addpegpt1 || battle2 == addanother
			|| battle2 == sub1 || battle2 == sub2 || battle2 == sub3)
		{

			battle1 = ptrandom;
			break;
		}
		battle3 = battle2 + 10;
		if (battle3 == ptrandom || battle3 == addpegpt || battle3 == ptrandom1 || battle3 == addpegpt1 || battle3 == addanother
			|| battle3 == sub1 || battle3 == sub2 || battle3 == sub3)
		{
			battle1 = ptrandom;
			break;
		}
		battle4 = battle3 + 10;
		if (battle4 == ptrandom || battle4 == addpegpt || battle4 == ptrandom1 || battle4 == addpegpt1 || battle4 == addanother
			|| battle4 == sub1 || battle4 == sub2 || battle4 == sub3)
		{
			battle1 = ptrandom;
			break;
		}

		if (battle2 > 100 || battle3 > 100 || battle4 > 100)
		{
			battle1 = ptrandom;
			break;
		}

	} while (sub1 == ptrandom);

	battleship.boats(battle1, battle2, battle3, battle4, filler);


	//aircraft carrier boat 5 pegs
	Battleship aircraft;
	string aircrafts = "aircraft";
	int aircraftc = 5;
	//hardcode name and ship.
	aircraft.ship(aircrafts, aircraftc);
	aircraft.hits();

	//add pegs one random one by design
	int air1 = 0;
	int air2 = 0;
	int air3 = 0;
	int air4 = 0;
	int air5 = 0;

	//run a random; make sure none of the answers are the same as PT boat
	do
	{
		air1 = 1 + (rand() % 100);

		while (air1 == ptrandom || air1 == addpegpt || air1 == ptrandom1 || air1 == addpegpt1 || air1 == addanother
			|| air1 == sub1 || air1 == sub2 || air1 == sub3
			|| air1 == battle1 || air1 == battle2 || air1 == battle3 || air1 == battle4)
		{
			air1 = 1 + (rand() % 100);
		}

		air2 = air1 + 1;
		if (air2 == ptrandom || air2 == addpegpt || air2 == ptrandom1 || air2 == addpegpt1 || air2 == addanother
			|| air2 == sub1 || air2 == sub2 || air2 == sub3
			|| air2 == battle1 || air2 == battle2 || air2 == battle3 || air2 == battle4)
		{

			battle1 = ptrandom;
			break;
		}
		air3 = air2 + 1;
		if (air3 == ptrandom || air3 == addpegpt || air3 == ptrandom1 || air3 == addpegpt1 || air3 == addanother
			|| air3 == sub1 || air3 == sub2 || air3 == sub3
			|| air3 == battle1 || air3 == battle2 || air3 == battle3 || air3 == battle4)
		{
			battle1 = ptrandom;
			break;
		}
		air4 = air3 + 1;
		if (air4 == ptrandom || air4 == addpegpt || air4 == ptrandom1 || air4 == addpegpt1 || air4 == addanother
			|| air4 == sub1 || air4 == sub2 || air4 == sub3
			|| air4 == battle1 || air4 == battle2 || air4 == battle3 || air4 == battle4)
		{
			battle1 = ptrandom;
			break;
		}
		air5 = air4 + 1;
		if (air5 == ptrandom || air5 == addpegpt || air5 == ptrandom1 || air5 == addpegpt1 || air5 == addanother
			|| air5 == sub1 || air5 == sub2 || air5 == sub3
			|| air5 == battle1 || air5 == battle2 || air5 == battle3 || air5 == battle4)
		{
			battle1 = ptrandom;
			break;
		}

		if (air2 > 100 || air3 > 100 || air4 > 100 || air5 > 100)
		{
			battle1 = ptrandom;
			break;
		}


	} while (sub1 == ptrandom);

	//add pegs to array
	aircraft.boats(air1, air2, air3, air4, air5);
	//int frigateboat[3] = { ptrandom, addpegpt, addanother };
	//display
	frigate.displayShipInfo();
	PT.displayShipInfo();
	submarine.displayShipInfo();
	battleship.displayShipInfo();
	aircraft.displayShipInfo();

	//play game
	cout << "Let's play Battleship! Guess where the computer's ships are: \n";

	const int CONTINUE = 1,
		QUIT_CHOICE = 4,
		SUNK_SHIP = 2,
		DISPLAY_SHIPINFO = 3;
	int choice;

	//game instructions
	cout << "Guess again?\n1 guess\n2 which ships have sunk\n3 amount of hits on each ship\n4 quit game\n";
	cin >> choice;
	
	do {
		//validation
		while (choice < CONTINUE || choice > QUIT_CHOICE)
		{
			cout << "Please enter a valid choice: ";
			cin >> choice;
		} //if the program is not 2 continue
		
		if (choice != QUIT_CHOICE)
		{//switch for choice
			switch (choice)
			{
				//case 1 is to enter values
				case 1:
				{

					while (choice == 1)
					{
						cout << "Column:  ";
						string col;
						cin >> col;


						cout << "Row:  ";
						int row;
						cin >> row;


						//to find numbered guess in array
						int place = findspace(col, row);
						cout << "guess: " << place << endl;
						

						//compare guess to boat arrays. 
						PT.compare(place);

						frigate.compare(place);

						submarine.compare(place);

						battleship.compare(place);

						aircraft.compare(place);


						cout << "Guess again?\n1 guess\n2 which ships have sunk\n3 amount of hits on each ship\n4 quit game\n";
						cin >> choice;
						cout << endl;
					}
					break;
					
				}//list of ships sunk
				case 2:
				{
					PT.sunk();
					frigate.sunk();
					submarine.sunk();
					battleship.sunk();
					aircraft.sunk();

					cout << "Guess again?\n1 guess\n2 which ships have sunk\n3 amount of hits on each ship\n4 quit game\n";
					cin >> choice;
					cout << endl;
					break;

				}//display of hits
				case 3:
				{
					PT.displayhits();
					frigate.displayhits();
					submarine.displayhits();
					battleship.displayhits();
					aircraft.displayhits();

					cout << "Guess again?\n1 guess\n2 which ships have sunk\n3 amount of hits on each ship\n4 quit game\n";
					cin >> choice;
					cout << endl;
					break;
				}
			}
		}
	} while (choice != QUIT_CHOICE);



}
//convert letter to a number and ind the place on a 100 integer array.
int findspace(string col, int row)
{

	string validation = col;
	string val[10] = { "A","B","C","D","E","F","G","H","I","J" };

	int start = 0;
	int aThroughJ = 0;
	//validate for loop

	do {
		for (start = 0; start < 10; start++)
		{

			// if col is not A then add to athroughj
			if (validation != val[start])
			{
				aThroughJ++;
			}
			else
			{
				break;
			}

		}
		if (aThroughJ == 10)
		{
			cout << "Enter a letter A through J:  ";
			cin >> validation;
			cout << endl;
			aThroughJ = 0;
		}
		else
		{
			break;
		}
	} while (aThroughJ == 0);

	int index = 0;
	int keepTrack = 0;
	for (index = 0; index < 10; index++)
	{


		if (validation != val[index]) {
			keepTrack++;
		}
		else
		{
			keepTrack++;
			break;
		}

	}

	int place = 0;
	int columnnumber = keepTrack;
	place = ((row * 10) - 10) + columnnumber;
	return place;
	

	//reset
	start = 0;
	aThroughJ = 0;
	index = 0;
	keepTrack = 0;

}
