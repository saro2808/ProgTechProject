#include <iostream>
using namespace std;

class Marines {
protected:
	bool left_is_alive;
	bool right_is_alive;
public:
	int number;
	Marines(int _number) {
		number = _number;
		left_is_alive = true;
		right_is_alive = true;
	}
	Marines() {
		left_is_alive = true;
		right_is_alive = true;
	}
};
class Oarsmen: public Marines {
public:
	Oarsmen(int x) : Marines(x) {}
	Oarsmen() {}
};
class Artillerymen: public Marines {
public:
	Artillerymen(int x) : Marines(x) {}
	Artillerymen() {}
};
class Attackers: public Marines {
public:
	Attackers(int x) : Marines(x) {}
	Attackers() {}
};

struct Location {
	int x;
	int y;
};

class Boat {
public:
	int no;		// the number of the boat
	Oarsmen oarers;
	Attackers atckers;
	int oar_num;
	int atck_num;
	int speed;
	int angle;	// the angle between the x axis and the boat's direction
	Location loc;
	Boat(int _oar_num, int _atck_num) {
		Oarsmen _oarers(_oar_num);
		Attackers _atckers(_atck_num);
	}
	Boat() {
		oarers.number = 0;
		atckers.number = 0;
	}
};

class Ship: public Boat {
public:
	Boat boat;
	Artillerymen artillers;
	int art_num;
	Ship(int _oar_num, int _atck_num, int _art_num) {
		Oarsmen _oarers(_oar_num);
		Attackers _atckers(_atck_num);
		Artillerymen _artillers(_art_num);
	}
	Ship() {}
};

const Ship SHIP(10, 5, 2);

class Player {
public:
	Ship ship[3];
	Player() {
		ship[0] = SHIP;
		ship[1] = SHIP;
		ship[2] = SHIP;
	}
};


////////////////////////////////////////////////////////////////////////

int main() {
	cout << "Welcome to ArmadaFight" << endl;
	cout << "Press 'q' to quit or any other key to start" << endl;
	char c;
	cin >> c;
	if (c == 'q') {
		return 0;
	}

	Player user();
	Player computer();

	return 0;
}
