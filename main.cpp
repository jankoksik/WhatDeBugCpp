#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include "functions.h"

#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <Windows.h>
#else
#include <sys/ioctl.h>
#endif

using namespace std;

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

class GfxBuffer {
public:
  unsigned int width, height;

  GfxBuffer(unsigned int w, unsigned int h) {
    width = w;
    height = h;
    gfx = new char[width*height];
  }

  void put_char(int x, int y, char c) {
      gfx[x+y*width] = c;
  }

  void clear_buffer() {
      for(int i = 0; i < width*height; i += 1)
          gfx[i] = ' ';
  }

  void refresh_screen() {
      printf("\033[2J\033[1;1H");
      printf("%s", gfx);
  }

private:
  char* gfx;
};

int main() {
    int x = 5, y = 5;
    int width=0, height=0;
    get_terminal_size(width, height);
    char* sss = "x";

    GfxBuffer gfx(width, height);

    while(1) {
        gfx.clear_buffer();
        gfx.put_char(x, y, 's');
        x += 1;
        y += 1;
        gfx.refresh_screen();
        gets(sss);
    }

    printf ("lines %d\n", width);
    printf ("columns %d\n", height);

    return 0;
}

/*int main() {
    cout << "Hello World!\n";
    cout << CustomText("red", red, black, "");
    return 0;
}*/
