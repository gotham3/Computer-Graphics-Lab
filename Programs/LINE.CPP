#include<graphics.h>
#include <stdio.h>
#include <conio.h>

int main()
{
clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGT")      ;
line(200,200,400,200);
getch();
closegraph();
return (0);
}