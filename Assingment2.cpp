#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>

using namespace std;

class Coordinate
{
	public:
		int x, y;
		char code[5]; 
};

class Lineclip
{
	public:
		Coordinate PT;
		void drawwindow();
		void drawline(Coordinate p1, Coordinate p2);
		Coordinate setcode(Coordinate p);
		int visibility(Coordinate p1, Coordinate p2);
		Coordinate resetendpt(Coordinate p1, Coordinate p2);		
};

int main()
{
	Lineclip lc;
	int gd = DETECT, v, gm;
	Coordinate p1, p2, p3, p4;
	cout << "\n Enter x1 and y1\n";
	cin >> p1.x >> p1.y;
	cout << "\n Enter x2 and y2\n";
	cin >> p2.x >> p2.y;

	initgraph(&gd, &gm, NULL);
	lc.drawwindow();
	delay(3000);

	lc.drawline(p1, p2);
	delay(3000);
	cleardevice();

	delay(3000);
	p1 = lc.setcode(p1);
	p2 = lc.setcode(p2);
	v = lc.visibility(p1, p2);
	delay(3000);

	switch(v)
	{
		case 0: lc.drawwindow();
                            delay(3000);
				lc.drawline(p1, p2);
				break;
	       case 1: lc.drawwindow();
                     delay(3000);
                     break;
	       case 2: p3 = lc.resetendpt(p1, p2);
                     p4 = lc.resetendpt(p2, p1);
                     lc.drawwindow();
                     delay(3000);
                     lc.drawline(p3, p4);
                     break;
       }
       delay(3000);
       closegraph();
}

void Lineclip::drawwindow()
{
       line(160, 110, 460, 110);
       line(460, 110, 460, 360);
       line(460, 360, 160, 360);
       line(160, 360, 160, 110);
}

void Lineclip::drawline(Coordinate p1, Coordinate p2)
{
 	line(p1.x, p1.y, p2.x, p2.y);
}

Coordinate Lineclip::setcode(Coordinate p)
{
	Coordinate ptemp;

	ptemp.code[0] = (p.y < 110) ? '1' : '0';
	ptemp.code[1] = (p.y > 360) ? '1' : '0';
	ptemp.code[2] = (p.x > 460) ? '1' : '0';
	ptemp.code[3] = (p.x < 160) ? '1' : '0';
	ptemp.code[4] = '\0'; 
	ptemp.x = p.x;
	ptemp.y = p.y;

	return ptemp;
}

int Lineclip::visibility(Coordinate p1, Coordinate p2)
{
	int i, flag = 0;
	for(i = 0; i < 4; i++)
	{
		if(p1.code[i] != '0' || p2.code[i] != '0')
			flag = 1;
	}

	if(flag == 0)
		return 0;
	flag = 1;
	for(i = 0; i < 4; i++)
	{
		if(p1.code[i] == p2.code[i] && p1.code[i] == '1')
flag = 0;
	}

	if(flag == 0)
		return 1;

	return 2;	
}

Coordinate Lineclip::resetendpt(Coordinate p1, Coordinate p2)
{
	Coordinate temp;
	int x, y, i;
	float m, k;

	if(p1.code[3] == '1')
		x = 160;
	else if(p1.code[2] == '1')
		x = 460;

	if(p1.code[3] == '1' || p1.code[2] == '1')
	{
		m = (float)(p2.y - p1.y) / (p2.x - p1.x);
		k = p1.y + m * (x - p1.x);
		temp.y = k;
		temp.x = x;

		for(i = 0; i < 4; i++)
			temp.code[i] = p1.code[i];

		if(temp.y <= 360 && temp.y >= 110)
			return temp;
	}

	if(p1.code[0] == '1')
		y = 110;
	else if(p1.code[1] == '1')
		y = 360;

	if(p1.code[0] == '1' || p1.code[1] == '1')
	{
		m = (float)(p2.y - p1.y) / (p2.x - p1.x);
		k = p1.x + (y - p1.y) / m;
		temp.x = k;
		temp.y = y;

		for(i = 0; i < 4; i++)
			temp.code[i] = p1.code[i];

		return temp;
	}

	return p1;
}

