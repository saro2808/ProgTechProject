#include <ncurses.h>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include "player.h"
#include "opponents.h"
using namespace std;

/*
enum { NS_PER_SECOND = 1000000000 };

void sub_timespec(struct timespec t1, struct timespec t2, struct timespec *td) {
    td->tv_nsec = t2.tv_nsec - t1.tv_nsec;
    td->tv_sec  = t2.tv_sec - t1.tv_sec;
    if (td->tv_sec > 0 && td->tv_nsec < 0) {
        td->tv_nsec += NS_PER_SECOND;
        td->tv_sec--;
    }
    else if (td->tv_sec < 0 && td->tv_nsec > 0) {
        td->tv_nsec -= NS_PER_SECOND;
        td->tv_sec++;
    }
}
*/

int main() {
	initscr();
	noecho();
	cbreak();

	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	Player* p = new Player(yMax/2, 1, '@');
	Opponents op;
	op.total = 0;
	for(int i = 0; i < yMax; i++) {
		op.wonline[i] = 0;
	}
	int iter = 0;

	for (int i = 0; i < 10; ++i) {
		op.gentarg();
	}

	//struct timespec start, now, delta;
	//clock_gettime(CLOCK_REALTIME, &start);
	time_t start, now, delta;
	time(&start);
	do {
		//clock_gettime(CLOCK_REALTIME, &now);
		//sub_timespec(start, now, &delta);
		time(&now);
		delta = now - start;
		if (delta/*.tv_sec*/ > 1) {
			op.gentarg();
			//clock_gettime(CLOCK_REALTIME, &start);
			time(&start);
		}
		
		p->display();
		refresh();

		if (p->justshot) {
			op.vanish(p->gety());
			p->justshot = false;
		}

		if (op.total == 0 && iter > 0) {
			mvprintw(yMax/2 - 1, xMax/2 - 3, "YOU WON!!!");
			getch();
			endwin();
			return 0;
		}
		++iter;
	} while (p->getmv() != 'q');

	endwin();

	return 0;
}
