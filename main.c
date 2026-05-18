#include <ncurses.h>
#include <unistd.h>
#include <dirent.h>

void display_dir(char *dir_path, int start_y)
{
    DIR *directory = opendir(dir_path);
    struct dirent *next_file;

    move(start_y, 10);

    while((next_file = readdir(directory)) != NULL)
    {
        
    }

    getcurx(stdscr);
}


int main()
{
    initscr();
    int row, col;

    sleep(2);
    getmaxyx(stdscr, row, col);

    move(row / 2, col / 2);

    addstr("Hello world!");
    addch('9');

    refresh();

    sleep(3);

    endwin();

    sleep(2);
    puts("End of program");
    return 0;
}