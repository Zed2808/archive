#include <ncurses.h>

int main()
{
	int ch;

	initscr();			// Start curses mode
	raw();				// Disable line buffering
	keypad(stdscr, TRUE);		// Get function keys (F1, F2, etc.) and arrow keys
	noecho();			// Don't echo() when we getch()

	printw("Type any character to see it in bold\n");
	ch = getch();			// If raw() hadn't been called, we'd have to press enter

	if(ch == KEY_F(1))		// Would not be passed to program without raw(), and without noecho() escape chars would be printed
		printw("F1 key pressed");
	else
	{
		printw("The pressed key is ");
		attron(A_BOLD);
		printw("%c", ch);
		attroff(A_BOLD);
	}

	refresh();
	getch();
	endwin();

	return 0;
}
