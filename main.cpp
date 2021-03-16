#include <iostream>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "functions.h"

//int sumc(int a, int b);
//string CustomText(string input, colors Fcolor, colors Bcolor,  string options);
using namespace std;

#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <Windows.h>
#else
#include <sys/ioctl.h>
#endif

void get_terminal_size(int& width, int& height) {
#if defined(_WIN32)
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    width = (int)(csbi.srWindow.Right-csbi.srWindow.Left+1);
    height = (int)(csbi.srWindow.Bottom-csbi.srWindow.Top+1);
#else
    struct winsize w;
    ioctl(fileno(stdout), TIOCGWINSZ, &w);
    width = (int)(w.ws_col);
    height = (int)(w.ws_row);
#endif
}

#define GFX_WIDTH


char gfx[80*25];

void put_char(int x, int y, char c) {
    gfx[x+y*80] = c;
}

void clear_buffer() {
    for(int i = 0; i < 80*25; i += 1)
        gfx[i] = ' ';
}

void refresh_screen() {
    printf("\033[2J\033[1;1H");
    printf("%s", gfx);
}

int main() {
    int x = 5, y = 5;
    int width=0, height=0;
    get_terminal_size(width, height);

    /*while(1) {
        clear_buffer();
        put_char(x, y, 219);
        x += 1;
        y += 1;
        refresh_screen();
        gets(gfx);
    }*/

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    printf ("lines %d\n", w.ws_row);
    printf ("columns %d\n", w.ws_col);

    return 0;
}


/*int main() {
    cout << "Hello World!\n";
    cout << CustomText("red", red, black, "");
    return 0;
}*/
