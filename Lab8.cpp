#include<stdio.h>
#include <windows.h>
#include <time.h>
#define screen_x 80
#define screen_y 25
#define scount 80
int X,Y,i,x_ship,y_ship;
HANDLE wHnd;
COORD star[scount];
CHAR_INFO consoleBuffer[screen_x * screen_y];
COORD bufferSize = { screen_x,screen_y };
COORD characterPos = { 0,0 };
SMALL_RECT windowSize = { 0,0,screen_x-1,screen_y-1 };
HANDLE rHnd;
DWORD fdwMode;
DWORD numEvents = 0;
DWORD numEventsRead = 0;
int color=7;
int life=10;
bool player=true;
void setcursor(bool visible){
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console,&lpCursor);
}
int setMode(){
    rHnd = GetStdHandle(STD_INPUT_HANDLE);
    fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT |ENABLE_MOUSE_INPUT;
    SetConsoleMode(rHnd, fdwMode);
return 0;
}
int setConsole(int x, int y){
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	return 0;
}
void spwanstar(){
	for(i=0;i<80;i++)
    {
        Y=(rand()%25);
        X=(rand()%80);
        consoleBuffer[X + screen_x * Y].Char.AsciiChar = '*';
        consoleBuffer[X + screen_x * Y].Attributes = 7;
        star[i]={X,Y};
    }
}
void clear_buffer(){
		for (int y = 0; y < screen_y; ++y) {
		for (int x = 0; x < screen_x; ++x) {
		consoleBuffer[x + screen_x * y].Char.AsciiChar = 0 ;
		consoleBuffer[x + screen_x * y].Attributes = 7;
		}
		}
}
void fill_buffer_to_console(){
		WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos,&windowSize);
}
void starfall(){
    for(int i=0;i<scount;i++)
        {
            if(star[i].Y>=screen_y-1)
                {
                    star[i].Y=0;
                    star[i].X=(rand()%80);
                }
            else if(star[i].Y==y_ship&&star[i].X<=x_ship+2&&star[i].X>=x_ship-2)
            {
                star[i].Y=0;
                star[i].X=(rand()%80);
                life--;
                Beep(5000,10);
            }
            else
                star[i].Y++;
            consoleBuffer[star[i].X + screen_x * star[i].Y].Char.AsciiChar = '*';
            consoleBuffer[star[i].X + screen_x * star[i].Y].Attributes = 7;
        }
}
void drawship(int x,int y){
    consoleBuffer[x_ship - 2 + screen_x * y_ship].Char.AsciiChar = '<';
    consoleBuffer[x_ship - 2 + screen_x * y_ship].Attributes = color;
    consoleBuffer[x_ship - 1 + screen_x * y_ship].Char.AsciiChar = '-';
    consoleBuffer[x_ship - 1 + screen_x * y_ship].Attributes = color;
    consoleBuffer[x_ship + screen_x * y_ship].Char.AsciiChar = '0';
    consoleBuffer[x_ship + screen_x * y_ship].Attributes = color;
    consoleBuffer[x_ship + 1 + screen_x * y_ship].Char.AsciiChar = '-';
    consoleBuffer[x_ship + 1 + screen_x * y_ship].Attributes = color;
    consoleBuffer[x_ship + 2 + screen_x * y_ship].Char.AsciiChar = '>';
    consoleBuffer[x_ship + 2 + screen_x * y_ship].Attributes = color;
}
void find_xy_ship(){
    if (numEvents != 0)
        {
            INPUT_RECORD* eventBuffer = new INPUT_RECORD[numEvents];
            ReadConsoleInput(rHnd, eventBuffer, numEvents, &numEventsRead);
            for (DWORD i = 0; i < numEventsRead; ++i)
            {
                if(eventBuffer[i].Event.KeyEvent.wVirtualKeyCode==VK_ESCAPE)
                    player=false;
                else if(eventBuffer[i].Event.KeyEvent.uChar.AsciiChar=='c'||eventBuffer[i].Event.KeyEvent.uChar.AsciiChar=='C')
                    color=rand()%15+1;
                else
                {
                    if(eventBuffer[i].Event.MouseEvent.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED)
                       color=rand()%15+1;
                    x_ship=eventBuffer[i].Event.MouseEvent.dwMousePosition.X;
                    y_ship=eventBuffer[i].Event.MouseEvent.dwMousePosition.Y;
                    if(x_ship<2)
                        x_ship=2;
                    if(x_ship>77)
                        x_ship=77;
                }
            }
        }
}
int main()
{
	setConsole(screen_x, screen_y);
	setMode();
	srand( time( NULL ) );
	spwanstar();
    setcursor(0);
	while(player)
    {
        GetNumberOfConsoleInputEvents(rHnd, &numEvents);
        clear_buffer();
        starfall();
        find_xy_ship();
        drawship(x_ship,y_ship);
        fill_buffer_to_console();
        if(life<=0)
            player=false;
        Sleep(100);
    }
	return 0;
}
