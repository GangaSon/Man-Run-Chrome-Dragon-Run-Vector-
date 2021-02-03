#include<fstream.h>
#include<conio.h>
#include<dos.h>
#include<process.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<man.h>
#include<ctype.h>
int l=3,code,hi=0;
fstream D,B,H;
class SCORE
{
	long scor;
	char name[30];
	public:
	void in()
	{
		clrscr();
		textcolor(YELLOW);
		cprintf("Enter your name:");
		for(int j=0;j<30;j++)
		{
			name[j]=getch();
			if(name[j]>=48&&name[j]<=57)
				j--;
			else
			if(toupper(name[j])>=65&&toupper(name[j])<=90)
			{cout<<name[j];}
			else
			if(name[j]==13)
				if(name[0]==13)
					j--;
				else
					break;
			else
			if(name[j]==8)
			{	name[j-1]=' ';
				gotoxy((17+(j-1)),1);cout<<' ';
				gotoxy((17+(j-1)),1);
				--j;--j;
			}
			else
			if(name[j]==32)
				if(name[0]==32)
					--j;
				else
				{	name[j]=' ';cout<<' ';	}
			else
				--j;
		}
	}
	void get(long p)
	{
		scor=p;
	}
	void backup(long p)
	{
		D.open("vscore.txt",ios::out|ios::app);
		D<<name<<"\t"<<p<<"\n";
		D.close();
	}
	void board()
	{
		B.open("vscore.txt",ios::in);
		B>>name>>scor;
	}
	void display(int &i)
	{
		cout<<name;gotoxy(33,++i);cout<<scor<<endl;
	}
};
SCORE A,N[15];
void high(int hi)
{
	H.open("high.txt",ios::out);
	H<<hi;
	H.close();
}
void home();
void start();
void re();
void sboard();
void heart(int &l,long &p)
{
	char h=3,hj=13;
	--l;
	gotoxy(1,1);
	if(l==3)
		cout<<h<<h<<h;
	else
	if(l==2)
		cout<<"   "<<hj<<h<<h;
	else
	if(l==1)
		cout<<"  "<<hj<<h;
	else
	if(l==0)
	{
		cout<<" ";
		gotoxy(37,12);
		textcolor(RED);
		cprintf("GAME OVER");
		A.get(p);
		A.backup(p);delay(2000);
		::hi=((::hi>p)?::hi:p);
		high(::hi);
		re();l=3;
		start();
	}
}
void score(int &p,int l)
{
	textcolor(WHITE);
	char h=3,hj=13;
	gotoxy(1,1);
	if(l==3)
	{
	textcolor(RED);
	cprintf("%c%c%c",h,h,h);
	}
	else
	if(l==2)
	{
	textcolor(RED);
	cprintf("%c%c%c   ",hj,h,h);
	}
	else
	if(l==1)
	{
	textcolor(RED);
	cprintf("%c%c  ",hj,h);
	}
	++p;
	textcolor(GREEN);
	gotoxy(70,1);
	cprintf("%d",p);
	gotoxy(60,1);textcolor(BLUE);
	cprintf("HI %d ",::hi);
	gotoxy(1,24);
}
void re()
{
	char a,b=17;int z=1;
	gotoxy(38,14);textcolor(YELLOW);
	cprintf("RESTART");gotoxy(37,15);
	cprintf("SCOREBOARD");
	gotoxy(40,16);cprintf("EXIT");
	A:
	if(z==1)
	{	gotoxy(48,14);cout<<b;
		gotoxy(48,15);cout<<" ";
		gotoxy(48,16);cout<<" ";
		gotoxy(1,24);
	}
	else
	if(z==2)
	{
		gotoxy(48,14);cout<<" ";
		gotoxy(48,15);cout<<b;
		gotoxy(48,16);cout<<" ";
		gotoxy(1,24);
	}
	else
	if(z==3)
	{
		gotoxy(48,14);cout<<" ";
		gotoxy(48,15);cout<<" ";
		gotoxy(48,16);cout<<b;
		gotoxy(1,24);
	}  B:
	a=getch();
	if(a==80)
	{
		++z;
		if(z>3)
		{z=3;goto B;}
		else
		goto A;
	}
	else
	if(a==72)
	{
		--z;
		if(z<1)
		{z=1;goto B;}
		else
		goto A;
	}
	else
	if(a==13)
	{
		if(z==1)
			goto C;
		else
		if(z==2)
			sboard();
		else
		if(z==3)
		{
			gotoxy(38,18);cout<<"CLOSING.....";
			delay(2000);exit(0);
		}
	}
	else
		goto B;
	C:
	gotoxy(1,22);cout<<"Want to change your name (Y/N):";
	Z:
	a=getch();
	if(a=='y'||a=='Y')	{	A.in();goto me;	}
	else
	if(a=='n'||a=='N')	goto me;
	else			goto Z;
	me:
	clrscr();	::l=3;
	gotoxy(39,12);cout<<"READY";
	delay(2000);gotoxy(40,13);
	textcolor(GREEN);cprintf("RUN");
	delay(1000);
}
void coll(int x,int y,int &bx,int by,int &p)
{
	if(::code==1)
	{
		if(by==11)
		{
			if(bx<=30&&bx>=14)
			{
			heart(::l,p);bx=80;
			delay(1000);
			}
		}
		else
		{
			if(bx<=27&&bx>=11)
			{
			heart(::l,p);bx=80;
			delay(1000);
			}
		}
	}
	else
	if(::code==3)
	{
		if(by==11)
		{
			if(bx<=26&&bx>=16)
			{
			heart(::l,p);bx=80;
			delay(1000);
			}
		}
		else
		{
			if((bx<=25&&bx>=15)||((bx>=12&&bx<=15)&&by==y+8))
			{
			heart(::l,p);bx=80;
			delay(1000);
			}
		}
	}
	else
	if(::code==2)
	{
		if(by==11)
		{
			if(((bx>=12&&bx<=23)&&by==y+9)||((bx>=14&&bx<=26)&&(by>=y&&by<=y+8))||((bx>=16&&bx<=32)&&(by>=y+3&&by<=y+5))||((bx>=20&&bx<=25)&&(by>=y&&by<=y+2)))
			{
			heart(::l,p);bx=80;
			delay(1000);
			}
		}
		else
		{
			if(((bx>=14&&bx<=26)&&(by>=y&&by<=y+8))||((bx>=12&&bx<=23)&&by+3==y+9)||((bx>=9&&bx<=19)&&by+4==y+10)||((bx>=9&&bx<=10)&&by+5==y+11))
			{
			heart(::l,p);bx=80;
			delay(1000);
			}
		}
	}
	else
	if(::code==4)
	{
		if(((bx>=19&&bx<=21)&&(by>=y+9&&by<=y+13))||((bx>=17&&bx<=18)&&(by>=y+7&&by<=y+9))||(bx==16&&(by>=y+5&&by<=y+8))||((bx>=14&&bx<=19)&&(by>=y&&by<=y+7))||((bx>=21&&bx<=24)&&(by>=y+2&&by<=y+4)))
		{
			heart(::l,p);bx=80;
			delay(1000);
		}
	}
	else
	if(::code==5)
	{
		if(by==11)
		{
			if((bx>=18&&bx<=20)||(bx+1>=18&&bx+1<=20))
			{
				heart(::l,p);bx=80;
				delay(1000);
			}
		}
		else
		{
			if((bx>=14&&bx<=33)||(bx+2>=14&&bx+2<=33))
			{
				heart(::l,p);bx=80;
				delay(1000);
			}
		}
	}
	else
	if(::code==6)
	{
		if(by==15)
			if(bx>=10&&bx<=39)
			{
				heart(::l,p);bx=80;
				delay(1000);
			}
	}
	else
	if(::code==7)
	{
		if(by==11)
		{
			if((bx||bx+1)>=21&&(bx||bx+1)<=23)
			{
				heart(::l,p);bx=80;
				delay(1000);
			}
		}
		else
		{
			if((bx||bx+1)>=12&&(bx||bx+1)<=25)
			{
				heart(::l,p);bx=80;
				delay(1000);
			}
		}
	}
}
void back(int &bx,int &by);
void track(int p)
{
	char m=176,n=178;
	for(int i=1;i<=79;i+=2)
	{
		gotoxy(i,21);
		if(p%2==0)
		{       textcolor(BROWN);
			cprintf("%c%c",m,n);	}
		else
		{       textcolor(BROWN);
			cprintf("%c%c",n,m);	}
	}
	textcolor(WHITE);
}
void updown(int &x,int &bx,int &by,int &p,int &sp)
{
	for(int i=8;i>=2;i--)
		{
			clrscr();
			score(p,::l);textcolor(WHITE);
			man2(0,i);code=2;
			track(p);
			back(bx,by);
			coll(x,i,bx,by,p);
			gotoxy(1,24);
			delay(sp);
		}
	for(i=2;i<8;i++)
		{
			clrscr();
			score(p,::l);textcolor(WHITE);
			man4(0,i);code=4;
			track(p);
			back(bx,by);
			coll(x,i,bx,by,p);
			gotoxy(1,24);
			delay(sp);
		}
}
void downup(int &x,int &bx,int &by,int &p,int &sp)
{
	clrscr();
	score(p,::l);textcolor(WHITE);
	man5(0,11);::code=5;
	track(p);
	back(bx,by);
	coll(x,11,bx,by,p);
	gotoxy(1,24);
	delay(sp);
	for(int i=0;i<=9;i++)
		{
			clrscr();
			score(p,::l);textcolor(WHITE);
			man6(0,16);::code=6;
			track(p);
			back(bx,by);
			coll(x,16,bx,by,p);
			gotoxy(1,24);
			delay(sp);
		}
	clrscr();
	score(p,::l);textcolor(WHITE);
	man7(0,12);::code=7;
	track(p);
	back(bx,by);
	coll(x,12,bx,by,p);
	gotoxy(1,24);
	delay(sp);
}
void back(int &bx,int &by)
{
	char b=219,c=220;--bx;
	if(by==11)
	{
		textcolor(CYAN);
		gotoxy(--bx,by);cprintf("%c",b);gotoxy(bx,by);cprintf("%c",b);
		gotoxy(bx+1,by);cprintf("%c",b);gotoxy(bx+1,by);cprintf("%c",b);
		gotoxy(bx+2,by);cprintf("%c",b);gotoxy(bx+2,by);cprintf("%c",b);
		gotoxy(bx+3,by);cprintf("%c",b);gotoxy(bx+3,by);cprintf("%c",b);
		gotoxy(bx,by+1);cprintf("%c",b);gotoxy(bx,by+1);cprintf("%c",b);
		gotoxy(bx+1,by+1);cprintf("%c",b);gotoxy(bx+1,by+1);cprintf("%c",b);
		gotoxy(bx+2,by+1);cprintf("%c",b);gotoxy(bx+2,by+1);cprintf("%c",b);
		gotoxy(bx+3,by+1);cprintf("%c",b);gotoxy(bx+3,by+1);cprintf("%c",b);
	}
	else
	{
		textcolor(GREEN);
		gotoxy(--bx,by);cprintf("%c",b);
		gotoxy(bx,by+1);cprintf("%c",b);
		gotoxy(bx,by+2);cprintf("%c",b);
		gotoxy(bx,by+3);cprintf("%c",b);
		gotoxy(bx+1,by+3);cprintf("%c",c);
		gotoxy(bx+2,by+3);cprintf("%c",b);
		gotoxy(bx+2,by+2);cprintf("%c",b);
		gotoxy(bx,by+4);cprintf("%c",b);
		gotoxy(bx,by+5);cprintf("%c",b);
	}
	if(bx<=1)
	{
		bx=80;
		randomize();
		int z=random(100);
		if(z%2==0)
			by=11;
		else
		if(z%2!=0)
			by=15;
	}
	textcolor(WHITE);
}
void speed(int &p,int &sp)
{
	if(p>100)
	sp=95;
	if(p>200)
	sp=90;
	if(p>300)
	sp=85;
}
void kbhit(int &x,int &bx,int &by,int &p,int &sp)
{
	if(kbhit())
	{
		char c=getch();
		if(c==72)
		{
			updown(x,bx,by,p,sp);
		}
		else
		if(c==80)
		{
			man5(1);delay(sp);
			downup(x,bx,by,p,sp);
			man7(1);delay(sp);
		}
		else
		if(c=='q')
		{
			gotoxy(33,12);
			textcolor(YELLOW);
			cprintf("Are you Sure (Y/N):");
			y:
			c=getch();
			if(c=='y'||c=='Y')
			{
				gotoxy(38,13);cout<<"CLOSING.....";
				delay(2000);exit(0);
			}
			else
			if(c=='n'||c=='N')
				goto x;
			else
				goto y;
		} x:
	}
}
void sboard()
{
	char name[30],n,b;
	long score,m=1,f=0;
	int fl=0;
	B.open("vscore.txt",ios::in);
	clrscr();
	textcolor(BLUE);
	cprintf("NAME:                          SCORE:\n");
	gotoxy(1,2);
	for(int i=0;(!B.eof());i++)
	{
		B.get(n);
		if(toupper(n)>=65&&toupper(n)<=90)
		{
			char a=toupper(n);fl=1;
			if(f==1)
			{	delay(100);cout<<endl;f=0;	}
			textcolor(YELLOW);
			cprintf("%c",a);
		}
		else
		if(n==32)
			cout<<n;
		else
		if(n==9)
			gotoxy(32,++m);
		else
		if(n>=48&&n<=57)
		{	textcolor(GREEN);
			cprintf("%c",n);f=1;
		}
		else
		if(!fl==1)
		{
			gotoxy(1,3);cout<<"This location is empty.";
			goto end;
		}
	}
	end:
	B.close();
	textcolor(BROWN);gotoxy(45,12);
	cprintf("Press \'1\' to go to Main Menu");gotoxy(45,13);
	cprintf("Press \'2\' to EXIT");
	me:
	b=getch();
	if(b=='1')
	{
		home();
	}
	else
	if(b=='2')
	{
		gotoxy(45,14);cout<<"CLOSING.....";
		delay(1500);exit(0);
	}
	else
		goto me;
}
void home()
{
	clrscr();
	int cur=1;
	char arr;
	A:
	gotoxy(38,9);
	textcolor(MAGENTA);
	cprintf("VECTOR");
	if(cur==1)
	{
		gotoxy(37,11);
		textcolor(CYAN+BLINK);
		cprintf("NEW GAME");
		gotoxy(36,12);
		textcolor(BROWN);
		cprintf("SCOREBOARD");
		gotoxy(39,13);
		cprintf("EXIT");
	}
	else
	if(cur==2)
	{
		gotoxy(37,11);
		textcolor(BROWN);
		cprintf("NEW GAME");
		gotoxy(36,12);
		textcolor(CYAN+BLINK);
		cprintf("SCOREBOARD");
		gotoxy(39,13);
		textcolor(BROWN);
		cprintf("EXIT");
	}
	if(cur==3)
	{
		gotoxy(37,11);
		textcolor(BROWN);
		cprintf("NEW GAME");
		gotoxy(36,12);
		textcolor(BROWN);
		cprintf("SCOREBOARD");
		gotoxy(39,13);
		textcolor(CYAN+BLINK);
		cprintf("EXIT");
	}
	B:
	gotoxy(1,24);
	arr=getch();
	if(arr==80)
	{
		++cur;
		if(cur>3)
		{cur=3;goto B;}
		else
		goto A;
	}
	else
	if(arr==72)
	{
		--cur;
		if(cur<1)
		{cur=1;goto B;}
		else
		goto A;
	}
	else
	if(arr==13)
	{
		if(cur==1)
		{
			clrscr();A.in();clrscr();
			gotoxy(37,12);textcolor(RED);cprintf("LOADING.");
			delay(500);cprintf(".");
			delay(500);cprintf(".");
			delay(500);cprintf(".");
			delay(500);cprintf(".");
			delay(500);clrscr();
			gotoxy(39,12);textcolor(GREEN);cprintf("RUN");
			delay(700);	::l=3;
			start();
		}
		else
		if(cur==2)
			sboard();
		else
		if(cur==3)
		{
			gotoxy(37,15);cout<<"CLOSING.....";
			delay(1500);exit(0);
		}
	}
	else
		goto B;
}
void start()
{
	int x=10,y=16,bx=80,by=15,p=0,sp=100,i=0;
	H.open("high.txt",ios::in);
	H>>::hi;
	H.close();
	gotoxy(x,y);
	me:
	clrscr();
	{
		if(i==1)
		{man2(0);code=2;}
		if(i==2)
		{man1(0);code=1;}
		if(i==3)
		{
		man3(0);code=3;i=0;
		}
		++i;
	}
	gotoxy(1,24);			kbhit(x,bx,by,p,sp);
	score(p,::l);textcolor(WHITE);	kbhit(x,bx,by,p,sp);
	speed(p,sp);              	kbhit(x,bx,by,p,sp);
	back(bx,by);	        	kbhit(x,bx,by,p,sp);
	track(p);                       kbhit(x,bx,by,p,sp);
	delay(sp);                      kbhit(x,bx,by,p,sp);
	coll(x,y,bx,by,p);           	kbhit(x,bx,by,p,sp);
	goto me;
}
void vector()
{
	int x=28,y=7;
	for(int i=0;i<10;i++)
	{
		gotoxy(x+i,y+i);
		textcolor(MAGENTA);
		cprintf("VECTOR");delay(30);
	}
	for(int j=i;j>=0;i++,j--)
	{
		gotoxy(x+i,y+j);
		cprintf("VECTOR");delay(30);
	}
	gotoxy(1,24);textcolor(BROWN);
	cprintf("Loading");delay(700);cprintf(".");
	delay(700);cprintf(".");delay(700);cprintf(".");
	delay(700);cprintf(".");delay(700);cprintf(".");
	delay(700);
}
void main()
{
	clrscr();
	vector();
	home();
}