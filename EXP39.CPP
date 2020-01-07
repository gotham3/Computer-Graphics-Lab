#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

typedef struct coordinate
{
	int x,y;
	char code[4];
}PT;

PT setcode(PT p);
int visibility(PT p1,PT p2);
PT resetendpt(PT p1,PT p2);

void main()
{
	int gd=DETECT,v,gm;
	PT p1,p2,p3,p4,ptemp;
	p1.x=150;p1.y=170;
	p2.x=350;p2.y=370;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	rectangle(150,100,450,350);
	p1=setcode(p1);
	p2=setcode(p2);
	v=visibility(p1,p2);
	switch(v)
	{
	case 0:         line(p1.x,p1.y,p2.x,p2.y);
			break;
	case 1:		break;
	case 2:		p3=resetendpt(p1,p2);
			p4=resetendpt(p2,p1);
			line(p3.x,p3.y,p4.x,p4.y);
			break;
	}
	getch();
	closegraph();
}

PT setcode(PT p)	//for setting the 4 bit code
{
	PT ptemp;

	if(p.y<100)
		ptemp.code[0]='1';	//Top
	else
		ptemp.code[0]='0';

	if(p.y>350)
		ptemp.code[1]='1';	//Bottom
	else
		ptemp.code[1]='0';

	if(p.x>450)
		ptemp.code[2]='1';	//Right
	else
		ptemp.code[2]='0';

	if(p.x<150)
		ptemp.code[3]='1';	//Left
	else
		ptemp.code[3]='0';

	ptemp.x=p.x;
	ptemp.y=p.y;

	return(ptemp);
}

int visibility(PT p1,PT p2)
{
	int i,flag=0;

	for(i=0;i<4;i++)
	{
		if((p1.code[i]!='0') || (p2.code[i]!='0'))
			flag=1;
	}

	if(flag==0)
		return(0);

	for(i=0;i<4;i++)
	{
		if((p1.code[i]==p2.code[i]) && (p1.code[i]=='1'))
			flag=0;
	}

	if(flag==0)
		return(1);

	return(2);
}

PT resetendpt(PT p1,PT p2)
{
	PT temp;
	int x,y,i;
	float m,k;

	if(p1.code[3]=='1')
		x=150;

	if(p1.code[2]=='1')
		x=450;
	
	if((p1.code[3]=='1') || (p1.code[2]=='1'))
	{
		m=(float)(p2.y-p1.y)/(p2.x-p1.x);
		k=(p1.y+(m*(x-p1.x)));
		temp.y=k;
		temp.x=x;
		
		for(i=0;i<4;i++)
			temp.code[i]=p1.code[i];
		
		if(temp.y<=350 && temp.y>=100)
			return (temp);
	}
	
	if(p1.code[0]=='1')
		y=100;
	
	if(p1.code[1]=='1')
		y=350;
		
	if((p1.code[0]=='1') || (p1.code[1]=='1'))
	{
		m=(float)(p2.y-p1.y)/(p2.x-p1.x);
		k=(float)p1.x+(float)(y-p1.y)/m;
		temp.x=k;
		temp.y=y;
		
		for(i=0;i<4;i++)
			temp.code[i]=p1.code[i];
		
		return(temp);
	}
	else
		return(p1);
}