#include <iostream>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "functions.h"

//int sumc(int a, int b);
//string CustomText(string input, colors Fcolor, colors Bcolor,  string options);
using namespace std;

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
