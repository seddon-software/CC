#include <iostream>
#include <string>
#include <wchar.h>
#include <locale.h>
#include <curses.h>
//#include <panel.h>
#include <cstdlib>

WINDOW *create_newwin(int height, int width, int starty, int startx)
{
  WINDOW *local_win = newwin(height, width, starty, startx);
  box(local_win, 0, 0);
  wrefresh(local_win);

  return (local_win);
}

int draw(int row, int col, const string& s)
{
    move(row++, col);
    addstr(s);
    return row;
}

int draw_box(int row, int col, const char* label)
{
    row = draw(row, col, "┌─────────┐");
    row = draw(row, col, "│         │");
    row = draw(row, col, "└─────────┘");
    refresh();
    return row -2;  // middle of box
}

int out(int row, int col, const char* text)
{
    move(row++, col);
    addstr(text);
    return row;
}

void print_program(int row, int col)
{ 
    move(row, col);
    addstr("int x\nint y;\ny = x + y;\n");
    refresh();
}

void read_file(const char* fileName)
{
    int row = 2;
    int col = 5;
    string text;
    FILE* fp = fopen(fileName, "r");
    // while(!feof(fp))
    // {
    //     fscanf(fp, "%[^\n]", text);
    //     printf("%s\n", text);
    // }
    while(fgets(text, 200, fp)){
        printf("%s\r", text);
        row = out(row, col, text);
    }
    fclose(fp);
    
}

int main(int argc, char** argv) 
{
    int row;
    // WINDOW *my_win;
    setlocale(LC_ALL, "");
    initscr();
    cbreak();
//    read_file(argv[1]);
//    read_file("myfile.txt");
    read_file("z.txt");
    getch();
    row = draw_box(2, 70, "x");
    getch();
    endwin();
}

