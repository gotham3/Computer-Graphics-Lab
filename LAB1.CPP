#include<iostream.h>
#include<conio.h>
#include<graphics.h>
void main()
{       clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"..\\bgi");
	circle(300,200,100);
	getch();
	closegraph();
}