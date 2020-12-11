#include<stdio.h>
#include<conio.h>
#include<graphics.h>
struct times
{
       int p,art,but,wtt,tat,rnt;
};


void sortart(struct times a[],int pro)
{
       int i,j;
       struct times temp;
       for(i=0;i<pro;i++)
       {
	      for(j=i+1;j<pro;j++)
	      {
		     if(a[i].art > a[j].art)
		     {
			   temp = a[i];
			   a[i] = a[j];
			   a[j] = temp;
		     }
	      }
       }
       return;
}


void grass(int xmid,int ymid,int xmax,int ymax)
{
       //	setfillstyle(SOLID_FILL,10);
       //	setcolor(10);
	rectangle(0,0,xmid-60,ymid-50);
	rectangle(xmid+60,0,xmax,ymid-50);
	rectangle(0,ymid+50,xmid-60,ymax);
	rectangle(xmid+60,ymid+50,xmax,ymax);

       //	floodfill(xmid+61,1,10);
       //	floodfill(1,1,10);
       //	floodfill(1,ymid+51,10);
       //	floodfill(xmid+61,ymid+51,10);
}
void light1(int xmid,int ymid,int signal1)
{

	setfillstyle(SOLID_FILL,signal1);
	setcolor(signal1);
	circle(xmid-70,ymid-20,10);
	circle(xmid-70,ymid+20,10);

	floodfill(xmid-70,ymid-20,signal1);
	floodfill(xmid-70,ymid+20,signal1);
}

void light3(int xmid,int ymid,int signal3)
{
	setfillstyle(SOLID_FILL,signal3);
	setcolor(signal3);
	circle(xmid+70,ymid-20,10);
	circle(xmid+70,ymid+20,10);
	floodfill(xmid+70,ymid-20,signal3);
	floodfill(xmid+70,ymid+20,signal3);
}

void light4(int xmid,int ymid,int signal4)
{
	setfillstyle(SOLID_FILL,signal4);
	setcolor(signal4);
	circle(xmid-25,ymid-60,10);
	circle(xmid+25,ymid-60,10);
	floodfill(xmid-25,ymid-60,signal4);
	floodfill(xmid+25,ymid-60,signal4);
}

void light2(int xmid,int ymid,int signal2)
{
	setfillstyle(SOLID_FILL,signal2);
	setcolor(signal2);
	circle(xmid-25,ymid+60,10);
	circle(xmid+25,ymid+60,10);
	floodfill(xmid-25,ymid+60,signal2);
	floodfill(xmid+25,ymid+60,signal2);
}

void central(int xmid,int ymid)
{
	int i,j=xmid+100,k=ymid+70;
	setcolor(15);
	for(i=0;i<230;i=i+60)
	{
		rectangle(i,ymid-5,i+50,ymid+5);
		rectangle(j,ymid-5,j+50,ymid+5);
		j=j+60;
	}
	for(i=0;i<170;i=i+60)
	{
		rectangle(xmid-5,i,xmid+5,i+50);
		rectangle(xmid-5,k,xmid+5,k+50);
		k=k+60;
	}

}




void main()
{       int x,k,pro,time,remain,flag=0,ts;
       int gt[50],wt[50],tat[50],m=0,n=0,o=0,p=0;
       struct times a[100];
       float avgwt=0,avgtt=0;
	int gd=DETECT,gm,i,j,limit;
	char str[3],str1[3],str2[3],str3[3];
	int xmax,ymax,ymid,xmid;
	int signal1,signal2,signal3,signal4;
	int w1,w2,w3,w4=0;
	clrscr();
	printf("\n\n--------------------------------------------------------------------------------\n ");
	printf("\n\t\t\t\tOPERATING SYSTEM\n ");
	printf("\n\n--------------------------------------------------------------------------------\n\n ");
	printf("\n\tNOTE ----> Scheduling algorithm followed is Round Robin\n ");
	printf("\n\t           Arrival Time of atleast one processes should be zero\n ");
	printf("\n\t           Initially all signals will be closed\n ");
	printf("\n\n\n\n\n\n\t\t\t\tTime Slot : ");
	scanf("%d",&ts);

       clrscr();
       pro=4;
       remain=pro;
       printf("\n\n--------------------------------------------------------------------------------\n ");
	printf("\n\t\t\t\tOPERATING SYSTEM\n ");
	printf("\n\n--------------------------------------------------------------------------------\n\n ");
	printf("\n\t\t\t\tTime Slot : %d ",ts);
       for(i=0;i<pro;i++)
       {
	      printf("\n\t\tEnter Arrival time & Burst time for Road %d : ",i+1);
	      scanf("%d%d",&a[i].art,&a[i].but);
	      //a[i].art=0;
	      a[i].p = i;
	      a[i].rnt = a[i].but;
       }
       sortart(a,pro);
       clrscr();
       printf("\n********************************************************************************************************\n");
       printf("Gantt Chart\n");
       printf("0");
       x=0;
       for(time=0,i=0;remain!=0;)
       {

	      if(a[i].rnt<=ts && a[i].rnt>0)
	      {
		     time = time + a[i].rnt;
		     printf(" -> [P%d] <- %d",a[i].p,time);
		     for(k=x;k<time;k++)
		     {


		     gt[k]=a[i].p;
		     x++;
		     }
		     a[i].rnt=0;
		     flag=1;
	      }
	      else if(a[i].rnt > 0)
	      {
		     a[i].rnt = a[i].rnt - ts;
		     time = time + ts;
		     printf(" -> [P%d] <- %d",a[i].p,time);
		     for(k=x;k<time;k++)
		     {
		     gt[k]=a[i].p;
		     x++;
		     }
	      }
	      if(a[i].rnt==0 && flag==1)
	      {
		     remain--;
		     a[i].tat = time-a[i].art;
		     a[i].wtt = time-a[i].art-a[i].but;
		     avgwt = avgwt + time-a[i].art-a[i].but;
		     avgtt = avgtt + time-a[i].art;
		     flag=0;
	      }
	      if(i==pro-1)
		     i=0;
	      else if(a[i+1].art <= time)
		     i++;
	      else
		     i=0;

       }
       printf("\n\n");
       printf("**************************************************************************************************\n");
       printf("Pro\tArTi\tBuTi\tTaTi\tWtTi\n");
       printf("************************************************************************************************\n");
       for(i=0;i<pro;i++)
       {      wt[i]=a[i].wtt;
		tat[i]=a[i].tat;
	      printf("P%d\t%d\t%d\t%d\t%d\n",a[i].p,a[i].art,a[i].but,a[i].tat,a[i].wtt);
       }
       printf("******************************************************************************\n");
       avgwt = avgwt/pro;
       avgtt = avgtt/pro;
       printf("Average Waiting Time : %.2f\n",avgwt);
       printf("Average Turnaround Time : %.2f\n",avgtt);
       printf("Press Enter to continue ----------->");
       limit=time;
	getch();
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	ymax=getmaxy();
	xmax=getmaxx();
	xmid=xmax/2;
	ymid=ymax/2;
	for(i=0;i<limit;i++)
	{
	cleardevice();
	if(gt[i]==0)
	{
		signal1=2;
		signal2=4;
		signal3=4;
		signal4=4;
		if(w2<=wt[1])
			w2++;
		if(w3<=wt[2])
			w3++;
		if(w4<=wt[3])
			w4++;



		outtextxy(5,15,"Waiting Time : ");
		sprintf(str,"%d",w1);
		outtextxy(150,15,str);

		outtextxy(xmid+65,15,"Waiting Time : ");
		sprintf(str,"%d",w4);
		outtextxy(xmid+200,15,str);

		outtextxy(5,ymid+65,"Waiting Time : ");
		sprintf(str,"%d",w2);
		outtextxy(150,ymid+65,str);


		outtextxy(xmid+65,ymid+65,"Waiting Time : ");
		sprintf(str,"%d",w3);
		outtextxy(xmid+200,ymid+65,str);


	}
	else if(gt[i]==1)
	{

		signal1=4;
		signal2=2;
		signal3=4;
		signal4=4;

		if(w1<=wt[0])
			w1++;
		if(w3<=wt[2])
			w3++;
		if(w4<=wt[3])
			w4++;



		outtextxy(5,15,"Waiting Time : ");
		sprintf(str,"%d",w1);
		outtextxy(150,15,str);

		outtextxy(xmid+65,15,"Waiting Time : ");
		sprintf(str,"%d",w4);
		outtextxy(xmid+200,15,str);

		outtextxy(5,ymid+65,"Waiting Time : ");
		sprintf(str,"%d",w2);
		outtextxy(150,ymid+65,str);


		outtextxy(xmid+65,ymid+65,"Waiting Time : ");
		sprintf(str,"%d",w3);
		outtextxy(xmid+200,ymid+65,str);


	}
	else if(gt[i]==2)
	{

		signal1=4;
		signal2=4;
		signal3=2;
		signal4=4;
		if(w2<=wt[1])
			w2++;
		if(w1<=wt[0])
			w1++;
		if(w4<=wt[3])
			w4++;



		outtextxy(5,15,"Waiting Time : ");
		sprintf(str,"%d",w1);
		outtextxy(150,15,str);

		outtextxy(xmid+65,15,"Waiting Time : ");
		sprintf(str,"%d",w4);
		outtextxy(xmid+200,15,str);

		outtextxy(5,ymid+65,"Waiting Time : ");
		sprintf(str,"%d",w2);
		outtextxy(150,ymid+65,str);


		outtextxy(xmid+65,ymid+65,"Waiting Time : ");
		sprintf(str,"%d",w3);
		outtextxy(xmid+200,ymid+65,str);


	}
	else if(gt[i]==3)
	{

		signal1=4;
		signal2=4;
		signal3=4;
		signal4=2;

		if(w2<=wt[1])
			w2++;
		if(w3<=wt[2])
			w3++;
		if(w1<=wt[0])
			w1++;



		outtextxy(5,15,"Waiting Time : ");
		sprintf(str,"%d",w1);
		outtextxy(150,15,str);

		outtextxy(xmid+65,15,"Waiting Time : ");
		sprintf(str,"%d",w4);
		outtextxy(xmid+200,15,str);

		outtextxy(5,ymid+65,"Waiting Time : ");
		sprintf(str,"%d",w2);
		outtextxy(150,ymid+65,str);


		outtextxy(xmid+65,ymid+65,"Waiting Time : ");
		sprintf(str,"%d",w3);
		outtextxy(xmid+200,ymid+65,str);



	}
	sprintf(str,"%d",i);
	outtextxy(xmid,ymid,str);

	outtextxy(5,5,"SIGNAL 1 ");

	outtextxy(xmid+65,5,"SIGNAL 4 ");

	outtextxy(5,ymid+55,"SIGNAL 2 ");

	outtextxy(xmid+65,ymid+55,"SIGNAL 3 ");

	grass(xmid,ymid,xmax,ymax);
	light1(xmid,ymid,signal1);
	light2(xmid,ymid,signal2);
	light3(xmid,ymid,signal3);
	light4(xmid,ymid,signal4);
	central(xmid,ymid);
	delay(1000);
	}
	cleardevice();
	signal1=signal2=signal3=signal4=4;
	grass(xmid,ymid,xmax,ymax);
	light1(xmid,ymid,signal1);
	light2(xmid,ymid,signal2);
	light3(xmid,ymid,signal3);
	light4(xmid,ymid,signal4);
	central(xmid,ymid);
	sprintf(str,"%d",i);
	outtextxy(xmid,ymid,str);

	outtextxy(5,5,"SIGNAL 1 ");
	outtextxy(5,15,"Waiting Time : ");
	outtextxy(5,30,"TurnAround Time : ");
	sprintf(str,"%d",wt[0]);
	outtextxy(150,15,str);
	sprintf(str,"%d",tat[0]);
	outtextxy(150,30,str);

	outtextxy(xmid+65,5,"SIGNAL 4 ");
	outtextxy(xmid+65,15,"Waiting Time : ");
	outtextxy(xmid+65,30,"TurnAround Time : ");
	sprintf(str,"%d",wt[3]);
	outtextxy(xmid+200,15,str);
	sprintf(str,"%d",tat[3]);
	outtextxy(xmid+200,30,str);

	outtextxy(5,ymid+55,"SIGNAL 2 ");
	outtextxy(5,ymid+65,"Waiting Time : ");
	outtextxy(5,ymid+75,"TurnAround Time : ");
	sprintf(str,"%d",wt[1]);
	outtextxy(150,ymid+65,str);
	sprintf(str,"%d",tat[1]);
	outtextxy(150,ymid+75,str);

	outtextxy(xmid+65,ymid+55,"SIGNAL 3 ");
	outtextxy(xmid+65,ymid+65,"Waiting Time : ");
	outtextxy(xmid+65,ymid+75,"TurnAround Time : ");
	sprintf(str,"%d",wt[2]);
	outtextxy(xmid+200,ymid+65,str);
	sprintf(str,"%d",tat[2]);
	outtextxy(xmid+200,ymid+75,str);



	getch();
	closegraph();

}
