#include<graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <iostream.h>

void fill(int x,int y, int n, int o,int b)
{
	if(getpixel(x,y)!=b && getpixel(x,y)!=n)
	{
		putpixel(x,y,n);
		fill(x-1,y,n,o,b);
		fill(x,y+1,n,o,b);
		fill(x+1,y,n,o,b);
		fill(x,y-1,n,o,b);
	}
}

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"..\\bgi");
	int a[]={100,100,130,130,200,115,150,150,120,140,100,100};
	drawpoly(6,a);
	int o=0,n=12,b=15;
	fill(115,116,n,o,b);
	getch();
	closegraph();
	return (0);
}