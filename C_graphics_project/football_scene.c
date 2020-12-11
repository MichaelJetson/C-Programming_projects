#include<conio.h>
#include<stdio.h>
#include<graphics.h>

void free(int xmid,int ymid)
{   int i,j;
    settextstyle(GOTHIC_FONT, HORIZ_DIR,4 );
    for(i=50;i<600;i=i+200)
    {
    for(j=50;j<600;j=j+200)
    {
     outtextxy(j,i, "FREEKICK");
    }
    }

}


void head(int xmid,int ymid)
{       setcolor(4);
	settextstyle(GOTHIC_FONT, HORIZ_DIR,4 );
	outtextxy(xmid+140, 30, "FREEKICK");
	outtextxy(xmid+140, ymid+100, "BLACK");
	outtextxy(xmid+140, ymid+130, "  VS  ");
	outtextxy(xmid+140, ymid+160, "WHITE");
	setcolor(15);
	outtextxy(xmid+155, ymid-50, "3");
	outtextxy(xmid+245, ymid-50, "3");
	outtextxy(xmid+190, ymid-50, " : ");
	rectangle(xmid+140,ymid-50,xmid+180,ymid);
	rectangle(xmid+230,ymid-50,xmid+270,ymid);
}
void scene1(int xmax,int ymax,int xmid,int  ymid,int l1)
{
       int i,j,x;
	x=l1/2;
	rectangle(0,0,xmax,ymax);  //mainframe
	line(xmid+110,0,xmid+110,ymax);       //detail line

	circle(xmid-110,ymid+3*l1,10+x);                      //Centre Circle

	line(0,ymid+3*l1,xmid+110,ymid+3*l1);       //midliine
	setfillstyle(SOLID_FILL,LIGHTGREEN);   //fillground
	floodfill(xmid+110-1,1,15);
	floodfill(xmid+110-1,ymax-1,15);
	floodfill(1,ymax-1,15);

	arc(xmid-110, ymax-100+3*l1, 0, 180, 50);                //goalkeeper's D
	arc(xmid-110, 100+l1, 180, 360, 50+l1);

	setfillstyle(HATCH_FILL,15);                            //GOAL POST
	rectangle(xmid-230-l1,0,xmid+10+l1,100+l1);
	rectangle(xmid-180-l1,0,xmid-40+l1,30+x);
	floodfill(xmid-41,1+x,15);

	rectangle(xmid-230,ymax+3*l1,xmid+10,ymax-100+3*l1);
	rectangle(xmid-180,ymax+3*l1,xmid-40,ymax-30+3*l1);
	floodfill(xmid-41,ymax-1+l1,15);



	 setcolor(0);
	circle(xmid-110,30+x,5);     //Black Goalkeeper
	line(xmid-110,35+x,xmid-110,55+x);
	line(xmid-110,50+x,xmid-115,60+x);
	line(xmid-110,50+x,xmid-105,60+x);
	setcolor(15);



}

void scene2(int xmax,int ymax,int xmid,int ymid,int l2,int l1)
{



	circle(xmid-110,ymax-l2,5);     //Player1
	line(xmid-110,ymax+5-l2,xmid-110,ymax+25-l2);
	line(xmid-110,ymax+20-l2,xmid-115,ymax+30-l2);
	line(xmid-110,ymax+20-l2,xmid-105,ymax+30-l2);

	circle(xmid,ymax-l2,5);     //Player2
	line(xmid,ymax+5-l2,xmid,ymax+25-l2);
	line(xmid,ymax+20-l2,xmid-5,ymax+30-l2);
	line(xmid,ymax+20-l2,xmid+5,ymax+30-l2);

	circle(xmid-150,ymax-l2,5);     //Player3
	line(xmid-150,ymax+5-l2,xmid-150,ymax+25-l2);
	line(xmid-150,ymax+20-l2,xmid-155,ymax+30-l2);
	line(xmid-150,ymax+20-l2,xmid-145,ymax+30-l2);

	circle(xmid-100,ymax+20-l2,5);    //Ball
	line(xmid-95,ymax+20-l2,xmid-105,ymax+20-l2);
	line(xmid-100,ymax+15-l2,xmid-100,ymax+25-l2);
	scene1( xmax, ymax,xmid,ymid,l1);
}

void scene3(int xmax,int ymax,int xmid,int ymid,int i)
{
	int j,k,z=i/4;
	setbkcolor(LIGHTCYAN);
	setfillstyle(SOLID_FILL,LIGHTGREEN);
	setcolor(LIGHTGREEN);
	rectangle(0,ymid,xmid,ymax);
	floodfill(xmid-200,ymax-50,LIGHTGREEN);

	setfillstyle(SOLID_FILL,GREEN);
	setcolor(GREEN);
	rectangle(xmid,ymid,xmax,ymax);
	floodfill(xmid+i,ymax-50,GREEN);

	setfillstyle(SOLID_FILL,GREEN);
	setcolor(GREEN);
	line(0,ymid,100-i,ymid);
	line(100-i,ymid,0,ymid+100);
	line(0,ymid,0,ymid+100);
	floodfill(1,ymid+1,GREEN);

	setfillstyle(SOLID_FILL,LIGHTGREEN);
	setcolor(LIGHTGREEN);
	line(xmid+200+i,ymid,xmax,ymid);
	line(xmax,ymid,xmax,ymid+100);
	line(xmid+200+i,ymid,xmax,ymid+100);
	floodfill(xmax-55,ymid+10,LIGHTGREEN);

	for(k=0;k<10;k++)
	{
	setfillstyle(HATCH_FILL,15);
	setcolor(15);
	rectangle(xmid-150,ymid-150+z,xmid+150,ymid+20+z);
	line(xmid-150,ymid-150+z,xmid-170,ymid+40+z);
	line(xmid+150,ymid-150+z,xmid+170,ymid+40+z);
	line(xmid+150,ymid+20+z,xmid+170,ymid+40+z);
	line(xmid-150,ymid+20+z,xmid-170,ymid+40+z);
	floodfill(xmid,ymid,15);
	}





}

void goalkeeper(int xmax,int ymax,int xmid,int ymid,int g)
{
	//GOALKEEPER
	int goal=g,k;
	setcolor(6);
	setfillstyle(SOLID_FILL,6);
	circle(xmid-40+g,ymid-70,15);
	rectangle(xmid-45+g,ymid-55,xmid-35+g,ymid+10);
	rectangle(xmid-90+g,ymid-45,xmid-45+g,ymid-40);
	rectangle(xmid-35+g,ymid-45,xmid-5+g,ymid-40);
	for(k=0;k<10;k++)
	{
		line(xmid-45+k+g,ymid+10,xmid-65+k+g,ymid+45);
		line(xmid-45+k+g,ymid+10,xmid-20+k+g,ymid+45);
	}
	floodfill(xmid-40+g,ymid-70,6);
	floodfill(xmid-40+g,ymid,6);
	floodfill(xmid-85+g,ymid-41,6);
	floodfill(xmid-6+g,ymid-41,6);
}

void ball(int xmax,int ymax,int xmid,int ymid,int p)
{
	//BALL
	setcolor(8);
	setfillstyle(SOLID_FILL,8);
	circle(xmid,ymax+55-p,20);
	floodfill(xmid,ymax+55-p,8);
}
void play(int xmax,int ymax,int xmid,int ymid,int p)
{
	int k;


	setcolor(8);
	setfillstyle(SOLID_FILL,8);
	circle(xmid-30,ymax-p,15);
	rectangle(xmid-35,ymax+15-p,xmid-25,ymax+50-p);
	for(k=0;k<10;k++)
	{
		line(xmid-35+k,ymax+50-p,xmid-45+k,ymax+85-p);
		line(xmid-35+k,ymax+50-p,xmid-25+k,ymax+85-p);
	}
	floodfill(xmid-30,ymax-p,8);


}

void final(int xmax,int ymax,int xmid,int ymid,int f)
{
	setcolor(8);
	setfillstyle(SOLID_FILL,8);
	circle(xmid+f,ymax-45-2*f,20);
	floodfill(xmid+f,ymax-45-2*f,8);
}

void main()
{
	int xmax,ymax,xmid,ymid,l1,l2,i,j,g=0,p,f;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TC\\BGI");

	xmax=getmaxx();
	ymax=getmaxy();
	xmid=xmax/2;
	ymid=ymax/2;


	for(l1=0;l1<100;l1=l1+1)
	{
	cleardevice();
	head(xmid,ymid);
	scene1(xmax,ymax,xmid,ymid,l1);
	delay(100);
	}

	for(l2=0;l2<180;l2=l2+1)
	{
	cleardevice();
	head(xmid,ymid);
	scene2(xmax,ymax,xmid,ymid,l2,l1);
	delay(100);
	}

	for(j=0;j<10;j++)
	{
	cleardevice();
	free(xmid,ymid);
	delay(100);
	}

	for (i=0;i<50;i++)
	{
	cleardevice();
	scene3(xmax,ymax,xmid,ymid,i);
	goalkeeper(xmax,ymax,xmid,ymid,g);
	delay(100);
	}
	for (p=0;p<100;p++)
	{
	cleardevice();
	scene3(xmax,ymax,xmid,ymid,i);
	goalkeeper(xmax,ymax,xmid,ymid,g);
	play(xmax,ymax,xmid,ymid,p);
	ball(xmax,ymax,xmid,ymid,p);
	delay(100);
	}
	for (f=0;f<120;f++)
	{
	cleardevice();
	scene3(xmax,ymax,xmid,ymid,i);
	play(xmax,ymax,xmid,ymid,p);
	final(xmax,ymax,xmid,ymid,f);
	g=f/2;
	goalkeeper(xmax,ymax,xmid,ymid,g);
	delay(100);
	}
	setcolor(8);
	settextstyle(GOTHIC_FONT, HORIZ_DIR,4 );
	outtextxy(xmid-100, 50, "WHITE WINS");


	getch();
	closegraph();
}
