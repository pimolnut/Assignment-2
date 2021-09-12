#define _CRT_SECURE_NU_WARNINGS 1
#include<stdio.h>
#include<conio.h>
#include<windows.h>

void gotoxy(int x, int y)
{
    COORD c = { x, y };
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void setcolor(int fg, int bg)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void setcursor(bool visible)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console, &lpCursor);
}
void draw_ship(int x, int y)
{
    setcolor(2, 4);
    gotoxy(x, y);
    printf(" <-0-> ");
}
void draw_blship(int x, int y)
{
    setcolor(2, 0); //ÊÕà¢ÕÂÇbg´Ó
    gotoxy(x, y);
    printf("^");
}
void erase_ship(int x, int y)
{
    gotoxy(x, y);
    printf("       ");
}
void erase_blship(int x, int y)
{
    setcolor(0, 0);
    gotoxy(x, y);
    printf("       ");
}
void erase_background(int x, int y)
{
    gotoxy(x, y);
    setcolor(0, 0); //black
    printf("       ");
}
struct bullet
{
    int a = 0;
    int x = 0, y = 0;
};
int main()
{
    bullet bulletship[5];
    char ch = ' ';
    int x = 38, y = 20;
    draw_ship(x, y);
    do {
        if (_kbhit())
        {
            ch = _getch();
            if (ch == 'a' && x > 0)
            {
                erase_ship(x, y);
                erase_background(x, y);
                draw_ship(--x, y);
            }
            if (ch == 'd' && x < 80)
            {
                erase_ship(x, y);
                erase_background(x, y);
                draw_ship(++x, y);
            }
            if (ch == 's' && y < 30)
            {
                erase_ship(x, y);
                erase_background(x, y);
                draw_ship(x, y);
            }
            if (ch == ' ') {
                for (int i = 0; i < 5; i++) {
                    if (bulletship[i].a == 0) {
                        bulletship[i].a = 1;
                        bulletship[i].x = x + 3;
                        bulletship[i].y = y;
                        break;
                    }
                }
            }
            fflush(stdin);
        }
        for (int i = 0; i < 5; i++) {
            if (bulletship[i].a == 1) {
                erase_blship(bulletship[i].x, bulletship[i].y);
                if (bulletship[i].y > 0) {
                    draw_blship(bulletship[i].x, --bulletship[i].y);
                }
                else {
                    bulletship[i].a = 0;
                }
            }

        }
        Sleep(100);
    } while (ch != 'x');
    return 0;
}