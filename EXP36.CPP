//If we try for some other points, there might be an error.
//It would be beacuse line at that level has two pixels.
//at x,y and x+1,y.
#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

int a[]={100,100,150,140,300,100,250,250,100,150,100,100};

int check(int x, int y)
{
	int i,cnt=0,s=sizeof(a)/2;
	for(;x>=0;x--)
	{
		if(getpixel(x,y)==15)
		{
			cnt++;
			for(i=0;i<s;i+=2)
			{
				if(x==a[i] && y==a[i+1])
				{
					if(!(a[(i+3)%s]>y ^ a[(i-1+s)%s]>y))
					{
						cnt++;
					}
				}

			}
		}
	}
	return cnt;
}

void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"..\\bgi");
	drawpoly(6,a);
	int x=110,y=115,c;
	putpixel(x,y,15);
	c=check(x-1,y);
	if(c%2==0)
	{cout<<"Point is Outside"; }
	else
	{cout<<"Point is Inside"; }
	getch();
	closegraph();
}