#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <math.h>

int a[]={100,100,150,100,150,150,100,150,100,100};
int b[]={100,100,90,90,140,90,150,100};
int c[]={90,90,90,140,100,150};
int x=2,y=2,i;

void draw()
{
	drawpoly(5,a);
	drawpoly(4,b);
	drawpoly(3,c);
}

void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"..\\bgi");
	draw();
	for(i=0;2*i<sizeof(a);i+=2)
	{
		a[i]*=x;
		a[i+1]*=y;
	}
	for(i=0;2*i<sizeof(b);i+=2)
	{
		b[i]*=x;
		b[i+1]*=y;
	}
	for(i=0;2*i<sizeof(c);i+=2)
	{
		c[i]*=x;
		c[i+1]*=y;
	}
	draw();
	getch();
	closegraph();
}
