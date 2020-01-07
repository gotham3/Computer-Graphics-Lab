#include<graphics.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"..\\bgi");
	int xm,ym,i;
	xm=getmaxx();
	ym=getmaxy();
	line(0,ym/2,xm,ym/2);
	line(xm/2,0,xm/2,ym);
	int a[]={100,75,100,175,200,175,200,75,100,75};
	int b[]={200,75,225,100,225,200,200,175};
	int c[]={225,200,125,200,100,175};
	drawpoly(5,a);
	drawpoly(4,b);
	drawpoly(3,c);
	for(i=0;2*i<sizeof(a);i+=2)
	{
		a[i]=xm-a[i];
	}
	for(i=0;2*i<sizeof(b);i+=2)
	{
		b[i]=xm-b[i];
	}
	for(i=0;2*i<sizeof(c);i+=2)
	{
		c[i]=xm-c[i];
	}
	drawpoly(5,a);
	drawpoly(4,b);
	drawpoly(3,c);
	for(i=0;2*i<sizeof(a);i+=2)
	{
		a[i+1]=ym-a[i+1];
	}
	for(i=0;2*i<sizeof(b);i+=2)
	{
		b[i+1]=ym-b[i+1];
	}
	for(i=0;2*i<sizeof(c);i+=2)
	{
		c[i+1]=ym-c[i+1];
	}
	drawpoly(5,a);
	drawpoly(4,b);
	drawpoly(3,c);
	getch();
	closegraph();
	return 0;
}