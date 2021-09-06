#include<stdio.h>
#include<windows.h>
#include<conio.h>
bool bullet[5];
int  bullet_x[5],bullet_y[5];
void setcolor(int fg,int bg)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, bg*16+fg);
}
void gotoxy(int x, int y)
{
    COORD c = { x, y };
    SetConsoleCursorPosition(
    GetStdHandle(STD_OUTPUT_HANDLE) , c);
}
void draw_ship(int x,int y)
{
    gotoxy(x,y);
    setcolor(2,4);
    printf("<-0->");
}
void erase_ship(int x,int y)
{
    gotoxy(x,y);
    setcolor(0,0);
    printf("     ");
}
void setcursor(bool visible)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console,&lpCursor);
}
void draw_bullet(int x,int y)
{
    gotoxy(x,y);
    setcolor(5,7);
    printf("*");
}
void erase_bullet(int x,int y)
{
    gotoxy(x,y);
    setcolor(0,0);
    printf(" ");
}
void shot(int n)
{
    erase_bullet(bullet_x[n],bullet_y[n]);
    if(bullet_y[n]>1)
    {
        draw_bullet(bullet_x[n],--bullet_y[n]);
    }
    else
    {
        bullet[n]=false;
    }
}

int main()
{
    int temp_x=0;
    setcursor(0);
    char ch;
    int x=38,y=20;
    draw_ship(x,y);
    do {
        setcursor(0);

        if (_kbhit())//กด keyboard
        {
            ch=_getch();
            if(ch==' ')
                for(int i=0;i<5;i++)
                    if(!bullet[i])
                    {
                        bullet[i]=true;
                        bullet_x[i]=x+2;
                        bullet_y[i]=y-1;
                        break;
                    }
            if(ch=='a'&&x>1)  temp_x=-1;
            if(ch=='d'&&x<92) temp_x=1;
            if(ch=='s'&&x<92) temp_x=0;
            fflush(stdin);

        }
        //up data ship
        erase_ship(x,y);
        if(x+temp_x>0&&x+temp_x<80) x+=temp_x;
        draw_ship(x,y);
        //up data bullet
        for(int i=0;i<5;i++)
        {
            if(bullet[i])
            {
                shot(i);
            }
        }
        Sleep(100);
    } while (ch!='x');
    return 0;
}
