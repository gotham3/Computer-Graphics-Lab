#include<iostream.h>
#include<conio.h>
#include<graphics.h>

void main()
{       clrscr();
       int gd=DETECT,gm;
       initgraph(&gd,&gm,"..\\BGI");
	clrscr();
	for(int i=0;i<=10;i++)
	{
	cout<<"*\n";
       }
	line(100,170,100,5);

	getch();
	clrscr();
	closegraph();
}
