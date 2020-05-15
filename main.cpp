#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <time.h>
#include "player.h"
#include "/home/saro/myfolder/getrandom_int.h"
#include "opponents.h"
using namespace std;

int main() {
	initscr();
	noecho();
	cbreak();

	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	mvaddch(yMax/3, xMax/2, '|');
	mvaddch(yMax/1.5 + 1, xMax/2, '|');
	refresh();

	Player* p = new Player(yMax/2, 1, '@');
	Opponents op;
	op.total = 0;
	for(int i = 0; i < yMax; i++) {
		op.wonline[i] = 0;
	}
	int iter = 0;
	time_t start, now;
	time(&start);
	do {
		time(&now);
		if(now - start > 1) {
			op.gentarg();
			time(&start);
		}
		
		p->display();
		refresh();

		if(p->justshot) {
			op.vanish(p->gety());
			p->justshot = false;
		}

		if(op.total == 0 && iter > 0) {
			mvprintw(yMax/2 - 1, xMax/2 - 3, "YOU WON!!!");
			getch();
			endwin();
			return 0;
		}
		iter++;
	} while(p->getmv() != 'q');

	endwin();

	return 0;
}
