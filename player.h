class Player {
	public:
		Player(int y, int x, char c);

		void placecrs(int ydo, int xdo);
		void clearcrs();
		void mvup();
		void mvdown();
		void mvleft();
		void mvright();
		void shoot();
		int getmv();
		void display();
		bool justshot;
		int gety();

	private:
		int xLoc, yLoc, xMax, yMax;
		char character;
};

Player::Player(int y, int x, char c) {
	yLoc = y;
	xLoc = x;
	getmaxyx(stdscr, yMax, xMax);
	keypad(stdscr, true);
	character = c;
}

// ydo, xdo in {-1, 0, 1}
void Player::placecrs(int ydo, int xdo) {
	mvaddch(yLoc + ydo - 1, xLoc + xdo, '\\');
	mvaddch(yLoc + ydo + 1, xLoc + xdo, '/');
	mvaddch(yLoc + ydo, xLoc + xdo, '|');
}

void Player::clearcrs() {
	mvaddch(yLoc - 1, xLoc, ' ');
	mvaddch(yLoc + 1, xLoc, ' ');
	mvaddch(yLoc, xLoc, ' ');
}

void Player::mvup() {
	if(yLoc > 1) {
		clearcrs();
		placecrs(-1, 0);
		yLoc--;
	}
}

void Player::mvdown() {
	if(yLoc < yMax - 2) {
		clearcrs();
		placecrs(1, 0);
		yLoc++;
	}
}

void Player::mvleft() {
	if(xLoc > 0) {
		clearcrs();
		placecrs(0, -1);
		xLoc--;
	}
}

void Player::mvright() {
	if(xLoc < xMax - 1) {
		clearcrs();
		placecrs(0, 1);
		xLoc++;
	}
}

void Player::shoot() {
	justshot = true;
	mvhline(yLoc, xLoc, '.', 10);
	refresh();
	const int step = 10;
	int j;
	for (j = 0; xLoc + (j - 1) * step < xMax; j++) {
		int i = 0;
		while(i < 10000000) {
			i++;
		}
		mvhline(yLoc, xLoc, ' ', step * j);
		refresh();
		mvhline(yLoc, xLoc + step * j, '.', step);
		refresh();
	}
}

int Player::getmv() {
	int choice = getch();
	switch(choice) {
		case KEY_UP:
			mvup();
			break;
		case KEY_DOWN:
			mvdown();
			break;
		case KEY_LEFT:
			mvleft();
			break;
		case KEY_RIGHT:
			mvright();
			break;
		case 'd':
			shoot();
			break;
		default:
			break;
	}
	return choice;
}

void Player::display() {
	mvaddch(yLoc, xLoc, character);
}

int Player::gety() {
	return yLoc;
}
