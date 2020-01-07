#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <iostream.h>

main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"..\\bgi");
	int a[]={100,100,150,150,200,100,250,250,150,300,100,100};
	//int a[]={100,100,200,150,200,300,125,200,100,100};
	drawpoly(6,a);
	int n,i,j,k,dx,dy,xi[10],x,y,temp;
	n=sizeof(a)/2;
	float slope[20];
	for(i=0;i<n;i+=2)
	{
		dy=a[(i+3)%n]-a[(i+1)%n];
		dx=a[(i+2)%n]-a[i%n];

		if(dy==0)
		{	slope[i]=1;     }
		if(dx==0)
		 {	slope[i]=0;        }
		if(dx!=0 && dy!=0)
		 {	slope[i]=(float)dx/dy;      }
	}
	for(y=0;y<480;y++)
	{
		k=0;
		for(i=0;i<n;i+=2)
		{
			if(((a[(i+1)%n]<=y) && (a[(i+3)%n]>y)) || ((a[(i+1)%n]>y) && (a[(i+3)%n]<=y)))
			{
				xi[k]=(int)(a[i]+slope[i]*(y-a[(i+1)%n]));
				k++;
			}
		}
		for(i=0;i<k-1;i++)
		{
			for(j=0;j<k-1;j++)
			{
				if(xi[j]>xi[j+1])
				{
					temp=xi[j];
					xi[j]=xi[j+1];
					xi[j+1]=temp;
				}
			}
		}
		setcolor(35);
		for(i=0;i<k;i+=2)
		{
		       line(xi[i%k],y,xi[(i+1)%k],y);
		}
	}
	getch();
	closegraph();
}