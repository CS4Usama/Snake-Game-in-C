#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int width=40,height=40;
int x,y,fruitx,fruity,score,gameover,flag,pause=0;
int tailx[100],taily[100],counttail=0;

void setup()
{
	gameover=0;
	x=width/2;
	y=height/2;
	
	label1:
	fruitx=rand()%40;
	if(fruitx==0)
	goto label1;
	
	label2:
	fruity=rand()%28;
	if(fruity==0)
	goto label2;
	score=0;
}

void draw()
{
	int i,j,k;
	system("cls");
	for(i=0;i<=width;i++)
	{
		for(j=0;j<=height;j++)
		{
			if(i==0||i==width||j==0||j==height)
			{
				printf("||");
			}
			else
			{
				if(i==x && j==y)
				 printf("O ");
				else if(i==fruitx && j==fruity)
				 printf("* ");
				else
				{
					
					for(k=0;k<counttail;k++)
					{
					  if(i==tailx[k] && j==taily[k])
					  {
					  	printf("o");
					    
					  }
					}
					  
				       printf("  ");
				}
				 
			}
		}
		printf("\n");
	}
	printf("SCORE: %d",score);
}

void input()
{
	if(kbhit())
	{
		switch(getch())
		{
			case'a':
		     flag=1;
			 break;
			case'd':
			 flag=2;
			 break;
			case'w':
			 flag=3;
			 break;
			case's':
			 flag=4;
			 break;
			case'o':
			 gameover=1;
			 break;
			case'p':
			 pause=1;
			 break;
		}
	}
}

void logic()
{
	int i;
	int prevx=tailx[0],prevy=taily[0];
	int prev2x, prev2y;
	tailx[0]=x;
	taily[0]=y;
	for(i=1;i<counttail;i++)
	{
		prev2x=tailx[i];
		prev2y=taily[i];
		tailx[i]=prevx;
		taily[i]=prevy;
		prevx=prev2x;
		prevy=prev2y;
	}
	
	
	switch(flag)
	{
		case 1:
			y--;
			break;
		case 2:
			y++;
			break;
		case 3:
			x--;
		    break;
		case 4:
			x++;
			break;
		default:
			break;
	}
	if(x<0||x>width||y<0||y>height)
	gameover=1;
	if(x==fruitx && y==fruity)
	{
		label3:
	fruitx=rand()%28;
	if(fruitx==0)
	goto label3;
	
	label4:
	fruity=rand()%28;
	if(fruity==0)
	goto label4;
	score+=10;
	counttail++;
	}
}

int main()
{
	int m,n;
	char c;
	label5:
	setup();
	while(!gameover)
	{
	 draw ();
	 input();
	 logic();
	 for(m=0;m<1000;m++){
	 	for(n=0;n<100000;n++){
	 	 }
	 }
	}
	printf("\nPress Y to Continue again..");
	scanf("%c",&c);
	if(c=='y'||c=='Y')
	goto label5;
    return 0;
}
