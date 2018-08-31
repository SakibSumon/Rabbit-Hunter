# include "iGraphics.h"
# include "myheader.h"
#include <iostream>

struct point
{
	int tx, ty;
	int bx, by;
	bool isRabbit;
	bool isShow;
}parr[5];

int score = 0;

int step = 1;

int ftx, fty, fbx, fby;

int background , rabbit[5],fire , screenHeight=800 , screenWidth = 1600;
int hunter ,hunterWidth=450 ,hunterHeight=250 ;
int rabbitHeight = 60,rabbitWidth = 60;
int rabbit2Height=60, rabbit2Width=60,rabbit2[5];
int x=500,y=0,dx,dy,pic_x,pic_y,mx,my,x3=500,y3=screenHeight/6,radius=30,cy=screenHeight/6,cx;
int mposx;
int mposy;
int homemenu,highscore,about,help,newgame;
int gameState = -1;
int Hm,Hs,Ab,Hp,Ng;
clock_t cur, pre;
int menu_x,menu_y;
int rotate = 0;
bool show_fire;
int fire_time = 0;

bool run = true;

            //@@@@@@@@@@@@@@@structure@@@@@@@@@@@@@@@//

/*
struct rabbit2
{
	int x,y;
	rabbit2(){
		;
	}
	rabbit2(int _y){
	y=screenWidth/3;
	}
	void collisionCheck(){
	if(
	}
}rab2[5];


*/
void iDraw()
{
	

	if(gameState==-1)
	{   iClear();
		iShowImage(0,0,screenWidth,screenHeight,homemenu);

		    iShowImage(50,400,300,280,Ng);
		//    iShowImage(50,400,80,60,Hp);
			 iShowImage(50,390,300,280,Hs);
			iShowImage(50,380,300,280,Ab);
		   
			
			


		
	}
	else if(gameState==0)
	{  
		iClear();
		iShowImage(0,0,screenWidth,screenHeight,help);
	}
	else if(gameState==1)
	{
		iShowImage(0,0,screenWidth,screenHeight,about);
	}
	else if(gameState==2)
	{
		iShowImage(0,0,screenWidth,screenHeight,highscore);
	}	
	else if(gameState==4)
	{
		iShowImage(0,0,screenWidth,screenHeight,newgame);
	}
	else if(gameState==3)           // gamestate for starting
	{
		iShowImage(0, 0, screenWidth, screenHeight, background);//for bacground


	//------------------------------Rotating the Hunter-----------------------//


		switch(rotate)
		{
			case 0:
				break;
			case 1:
				iRotate(x, y, 10); // rotating hunter for 10 drgress upwards
				break;
			case 2:
				iRotate(x, y, -10);  // rotating hunter for 10 drgress down
		}

		iShowImage(x, y, hunterWidth, hunterHeight, hunter);// for showing hunter//

		iUnRotate();

		// ------------------------ showing rabbits sequentially-----------------//
	
		cur = clock();

		if (run)
		{
			if ((cur - pre) <= 5000 && parr[0].isShow == true)
			{
				parr[4].isShow = true;
				parr[4].isRabbit = false;
				parr[0].isRabbit = true;
				iShowImage(200, screenHeight / 3, rabbitWidth, rabbitHeight, rabbit[0]);//rabbit 1
			}
			if ((cur - pre) > 5001  && (cur - pre) <= 9000 && parr[1].isShow == true)
			{
				parr[0].isShow = true;
				parr[0].isRabbit = false;
				parr[1].isRabbit = true;
				iShowImage(500, screenHeight / 3, rabbitWidth, rabbitHeight, rabbit[1]);//rabbit 2
			}
			if ((cur - pre) > 9000 && (cur - pre) <= 12000 && parr[2].isShow == true)
			{
				parr[1].isShow = true;
				parr[1].isRabbit = false;
				parr[2].isRabbit = true;
				iShowImage(800, screenHeight / 3, rabbitWidth, rabbitHeight, rabbit[2]);//rabbit 3
			}
			if ((cur - pre) > 12000 && (cur - pre) <= 18000 && parr[3].isShow == true)
			{
				parr[2].isShow = true;
				parr[2].isRabbit = false;
				parr[3].isRabbit = true;
				iShowImage(1000, screenHeight / 3, rabbitWidth, rabbitHeight, rabbit[3]);//rabbit 4
			}
			if ((cur - pre) > 18000 && (cur - pre) <= 24000 && parr[4].isShow == true)
			{
				parr[3].isShow = true;
				parr[3].isRabbit = false;
				parr[4].isRabbit = true;
				iShowImage(1200, screenHeight / 3, rabbitWidth, rabbitHeight, rabbit[4]);//rabbit 5
			}

			/*if ((cur - pre) <= 6000)
				iShowImage(150, screenHeight / 4, rabbit2Width, rabbit2Height, rabbit2[0]);//rabbit 1

			if ((cur - pre) > 3000 && (cur - pre) <= 6000)
				iShowImage(400, screenHeight / 4, rabbit2Width, rabbit2Height, rabbit2[1]);//rabbit 2

			if ((cur - pre) > 6000 && (cur - pre) <= 9000)
				iShowImage(800, screenHeight / 4, rabbit2Width, rabbit2Height, rabbit2[2]);//rabbit 3

			if ((cur - pre) > 9000 && (cur - pre) <= 12000)
				iShowImage(600, screenHeight / 4, rabbit2Width, rabbit2Height, rabbit2[3]);//rabbit 4

			if ((cur - pre) > 12000 && (cur - pre) <= 15000)
				iShowImage(1100, screenHeight / 4, rabbit2Width, rabbit2Height, rabbit2[4]);//rabbit 5
			*/
		}
							  //-------------------------Showing fire--------------------//.
							  //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&//


		if ((cur - pre) > 24000 && step < 2)
			pre = cur, ++step, parr[0].isShow = true;

		if(show_fire)
		{
			if(rotate == 0)
			{
				iShowImage(x + 345, y + 280, 70, 60, fire);

				int xi[4] = {x + 345, x + 345 + 60, x + 345 + 60, x + 345};
				int yi[4] = {y + 280 + 70, y + 280 + 70, y + 280, y + 280};
 
				for (int i = 0; i < 5; ++i)
				{
					bool isFire = false;

					if (parr[i].isRabbit == true)
					{
						for (int j = 0; j < 4; ++j)
						{
							if (parr[i].tx <= xi[j] && parr[i].bx >= xi[j] && parr[i].ty >= yi[j] && parr[i].by <= yi[j])
								isFire = true;
						}

						if (isFire) 
						{
							++score;
							printf("%d\n", score);
							parr[i].isRabbit = false;
						}

					}
				}
			}

			else if(rotate == 1) // 
			{
				iShowImage(x + 390, y + 210, 70, 60, fire);

				int xi[4] = {x + 390, x + 390 + 60, x + 390 + 60, x + 390};
				int yi[4] = {y + 210 + 70, y + 210 + 70, y + 210, y + 210};
 
				for (int i = 0; i < 5; ++i)
				{
					bool isFire = false;

					if (parr[i].isRabbit == true)
					{
						for (int j = 0; j < 4; ++j)
						{
							if (parr[i].tx <= xi[j] && parr[i].bx >= xi[j] && parr[i].ty >= yi[j] && parr[i].by <= yi[j])
							{
								//printf("%d %d %d ----- %d %d %d\n", parr[i].tx, parr[i].bx, xi[j], parr[i].ty, parr[i].by, yi[j]); 
								isFire = true;
							}
						}
					}

					if (isFire) 
					{

						++score;
						printf("%d\n", score);
						parr[i].isShow = false;
						parr[i].isRabbit = false;
					}
				}
			}

			else if(rotate == 2)
			{
				iShowImage(x + 415, y + 135, 70, 60, fire);

				int xi[4] = {x + 415, x + 415 + 60, x + 415 + 60, x + 415};
				int yi[4] = {y + 135 + 70, y + 135 + 70, y + 135, y + 135};
 
				for (int i = 0; i < 5; ++i)
				{
					bool isFire = false;

					if (parr[i].isRabbit == true)
					{
						for (int j = 0; j < 4; ++j)
						{
							if (parr[i].tx <= xi[j] && parr[i].bx >= xi[j] && parr[i].ty >= yi[j] && parr[i].by <= yi[j])
								isFire = true;
						}

						if (isFire) 
						{
							++score;
							printf("%d\n", score);
							parr[i].isRabbit = false;
						}
					}
				}
			}

			if(fire_time > 100 )
			{
				fire_time = 0;
				show_fire = false;
			}
			fire_time++;
		}
	}

}





void iMouseMove(int mx, int my)
{
	
}


void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		menu_x=mx;
		menu_y=my;
		printf("%d %d\n",menu_x,menu_y);
		
		if(mx>=80 && mx<=80+260 && my>=100  && my<=100+90)
			{
				gameState=0;
			}
		
		
		
			else if(mx>=113 && mx<=312 && my>=442  && my<=497)
			{
				gameState=1;
			}
	
		
		
			else if(mx>=111 && mx<=311 && my>=513  && my<=563)
			{     
				gameState=2;
			}
		

		
		
		
			else if(mx>=112 && mx<=312 && my>=588  && my<=643)
			{
				gameState=3;
			}
		
	
		
		
			else if(mx>=50 && mx<=50+260 && my>=500  && my<=500+90)
			{
				gameState=4;
			}

	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your code here.
	}
}


//$$$$$$$$$$$$$$$$$$$$$$$ for rabbbit to appear randonmly $$$$$$$$$$$$$$$$$$$$4//

   /*void rabbitXChange(){
	for(int i=0;i<5;i++){
	rab2[i].x+= dx;
   }
}

void objectChange(){
dx=rand()%20;
}

*/
                                 //$$$$$$$$$$$$$$$$$$$$//



void iPassiveMouse(int mx,int my)
{
	

 mposx = mx;
 mposy = my;
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/

}

void iKeyboard(unsigned char key)
{
	if(key == 'f') // showing fire pressing 'space'
	{
		show_fire = true;
	}
	
	if (key=='a') // moving hunter left of the screen 
	{
		if(x>=20)
		{
			x-=5;
			x-=5;
			x-=5;
		}
	}
	else if(key=='d')   // moving hunter right of the screen 
	{
		if(x<=screenWidth-450)
		{
			x+=5;
			x+=5;
			x+=5;
		}
	}

	else if(key == 'w') // leaning hunter 10 degrees up 
	{
		rotate = 1;
	}

	else if(key == 's')   // default position of the hunter
	{
		rotate = 0;
	}

	else if(key == 'x')   // leaning hunter 10 degrees down
	{
		rotate = 2;
	}

}

void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}

	
}
               // +++++++++++++++++ main function++++++++++++++++++//
               //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//



int main()
{
	for (int i = 0; i < 5; ++i)
	{
		parr[i].tx = 200 + i * 300;
		parr[i].ty = screenHeight / 3 + rabbitHeight;

		parr[i].bx = 200 + i * 300 + screenWidth;
		parr[i].by = screenHeight / 3;

		parr[i].isRabbit = false;
		parr[i].isShow = true;
	}

	int i =0;
	iInitialize(screenWidth, screenHeight, "Rabbit");//screen and background

	

	dx = 5;
	dy = 7;

	pic_x = 0;
	pic_y = 0;

	homemenu=iLoadImage("Back1.jpg");

    Ng=iLoadImage("image\\NEW GAME.png");      //new game button loader

	Hs=iLoadImage("image\\HIGH SCORE.png");    // high score button loader

	Ab=iLoadImage("image\\ABOUT.png");         //about button loader 

	Hp=iLoadImage("image\\.png");              // help button loader

	about = iLoadImage("ABOUT_BACK.jpg");    // about background loader

	highscore = iLoadImage("HIGH_SCORE.jpg");  // highscore page loader
		
	

	background = iLoadImage("Back2.jpg");      //background image loader

	hunter = iLoadImage("hunter-2.png");        //hunter image loader

	fire = iLoadImage("flame1.png");            // fire image loader


	/*for five rabbits*/

		for (int i = 0; i < 5; i++)
	
	{
		rabbit[i] = iLoadImage("rabbit.png");
		
	}

	//for rabbit2


	

	/*for five rabbits*/
	

	for (int i = 0; i < 5; i++)
	
	{
		rabbit2[i] = iLoadImage("rabbit2.png");
	}
	

	iStart(); 

	return 0;
}

