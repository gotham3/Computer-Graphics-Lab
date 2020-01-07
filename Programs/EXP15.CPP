#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"..\\bgi");
	double x,y;
	int angle=0,xm,ym;
	xm=getmaxx();
	ym=getmaxy();
	line(0,ym/2,xm,ym/2);
	for(x=0;x<xm;x+=2)
	{
		y=100*sin(angle*3.141592/180);
		y=ym/2-y;
		putpixel(x,y,7);
		angle+=2;
	}
	getch();
	closegraph();
	return 0;
}
