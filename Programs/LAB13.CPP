#include<iostream.h>
#include<conio.h>
#include<graphics.h>
void main()
{
       int gd=DETECT,gm;
       initgraph(&gd,&gm,"..\\BGI");
	circle(250,250,100);
	getch();
	closegraph();
}
