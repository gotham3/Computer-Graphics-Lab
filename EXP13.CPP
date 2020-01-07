#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <graphics.h>

void draw(float xc, float yc, float x, float y)
{
	putpixel(xc+x,yc-y,7);
	putpixel(xc+x,yc+y,7);
	putpixel(xc-x,yc-y,7);
	putpixel(xc-x,yc+y,7);
}

int main()
{
	float xc=250,yc=150,rx=200,ry=100,p1,p2;
	float x=0,y=ry;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"..\\bgi");
	p1=ry*ry+rx*rx*ry+rx*rx/4;
	draw(xc,yc,x,y);
	while((ry*ry*x)<=(rx*rx*y))
	{
		if(p1<0)
		{
			x++;
			draw(xc,yc,x,y);
			p1=p1+2*ry*ry*x+ry*ry;
		}
		else
		{
			x++;
			y--;
			draw(xc,yc,x,y);
			p1=p1+2*ry*ry*x+ry*ry-2*rx*rx*y;
		}
	}
	p2=ry*ry*(x+0.5)*(x+0.5)+rx*rx*(y-1)*(y-1)-rx*rx*ry*ry;
	while(y>0)
	{
		if(p2>0)
		{
			y--;
			draw(xc,yc,x,y);
			p2=p2-2*rx*rx*y+rx*rx;
		}
		else
		{
			x++;
			y--;
			draw(xc,yc,x,y);
			p2=p2-2*rx*rx*y+rx*rx+2*ry*ry*x;
		}
	}
	getch();
	closegraph();
}