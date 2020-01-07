#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <math.h>

int a[]={250,100,250,200,350,200,350,100,250,100};
int b[]={250,100,225,75,325,75,350,100};
int c[]={225,75,225,175,250,200};

void draw()
{
	drawpoly(5,a);
	drawpoly(4,b);
	drawpoly(3,c);
}
void main()
{
	int i;
	float n=30*3.141592/180;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"..\\bgi");
	draw();
	for(i=0;2*i<sizeof(a);i+=2)
		a[i]=a[i]+a[i+1]*tan(n)-250;
	for(i=0;2*i<sizeof(b);i+=2)
		b[i]=b[i]+b[i+1]*tan(n)-250;
	for(i=0;2*i<sizeof(c);i+=2)
		c[i]=c[i]+c[i+1]*tan(n)-250;
	draw();
	getch();
	closegraph();
}
