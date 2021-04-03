const int xMax = 80;
const int yMax = 24;

class Opponents {
	public:
		void gentarg();		// generate target
		void vanish(int y);	// clear line y

		int total;
		int wonline[yMax];	// walls on line xMax
};

void Opponents::gentarg() {
	int y = abs(int(rand())) % (yMax - 2) + 1;
	int x = abs(int(rand())) % (xMax/2) + xMax/2;
	mvaddch(y, x, '|');
	total++;
	wonline[y]++;
}

void Opponents::vanish(int y) {
	total -= wonline[y];
	wonline[y] = 0;
}
