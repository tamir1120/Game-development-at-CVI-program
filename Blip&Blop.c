#include "bass.h" 
#include "windows.h" 
#include "toolbox.h"
#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "Blip&Blop.h"


void hitblip2(int i);
void suprise1(int i);
void updatelevel2();
void updatescoreboard();
void hitgrenpa(int i);
void bullmovegargamel(int i);
void gargamelshoting(int i);
void heatgargamel(int i); 
void bullet(int i);
void BulletMove(int i);
void shooting();
void hitenemy(int i);
void level1enemymove(int i);
void enemyjunp(); 
void level2enemymove(int i);
void enemyspwn(int i);
void grenpaspwn(int i); 
void score();
void hitgeneral();


//------------------------------------------------------------------------------ panels  

static int panelHandle,panelHandle2,panelHandle3,panelHandle4,panelHandle5,panelHandle6,panelHandle7;

//------------------------------------------------------------------------------ sounds 

HSTREAM Music_SND, shoot_SND, jump_SND, sad_SND,boom_SND,boomenemy_SND, startmusic_SND,stage1_SND,stage2_SND,stage3_SND,round1_SND,round2_SND,round3_SND,gargamel_SND,winsound1_SND,level2new_SND,level3new_SND,cat_SND; 

//------------------------------------------------------------------------------ Level

int lel1flag=0,lel2flag=0,lel3flag=0;


//------------------------------------------------------------------------------ Start Game

int a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46;

//------------------------------------------------------------------------------ pictures 

int enemynum=35,enemynum1=50,left_fire,fireup,right_blip_pic,explosion1,explosion2,explosion3,explosion4,left_blip_pic,right_fire,rightfire,smurfs,smurfs_right,background,smurfs_walk_left2,j,smurfs_died,health1,health2,health3,health4,health5,background2,smurfsleft,backgroundnum1,opendoor,closedoor,smursnewleft,smursnewright,suprise,blipup,gameover,gargamelspriteleft,gargameright,g0,g1,g2,g3,gargamellife,gragamelnew,gragamelnewright,youwin,smurfsgranpaleft;
int jumpy=0,shotCounter = -1,move1,moveon=0,step =0,animation=0 ,animation1=0,animation2=0,animation3=0,animation4=0,animation5=0,animation6=0,time1=0,time2=1,time4=0,time5=0,time6=0,timezone,timezone1,timezone2;	   
int moverightscreen=0;
int heart1=0,heart2=0,heart3=0,heart4=0,heart5=0,injured=0,d=0;


//------------------------------------------------------------------------------- variables level 1 

int state_bullet=0,state_enemy=0,state_screen=0,piccounter=0,jump1=0,score1=0,hit,enemygone=0,numofbullet=60,respwnbullet, nobullet,flagdraw1=0;;

int height,vy=0,vx=100,top,left,width,xfl,e=0,j=0,bullet_y=20,keys=0,i,k,count=0,shoot=0,ax,x,healh=0;

int flag1=0,flag2=0,flag3=0,flag4=0,flag5=0,flag6=0,flag8,flag7,flag10=0,flag11=0,flag12=0,flag14=0,flag15=0,flag16=0,flag56=0,flag17=0,flag45=0,flag46=0,shield,first=0,flagbullet=0,fist10=0,catflag=0,catflag2=0,catflag1=0;;

double dt=0.01,time3=0;

int enemyvy=0,enemyjump=0,jump4=0;

//------------------------------------------------------------------------------- variables level 2

int gargameleft, aa=0, flagargamel1=0,flagargamel2=0,flagbull=0,injured2=0,flagbullg2=0,timer3=0,timer4=0,flag48=0,timer8=0,shotinggargamel=1,hitblip1=0,flag18=0,scorelevel2=0,flag47=0,flag23=0; 
int hearta=0,heartb=0,heartc=0,heartd=0,hearte=0,smurfsgranparight;


//------------------------------------------------------------------------------- flags level 2 

int flaga=0,flagb=0;

int lifeg3=0,lifeg2=0,lifeg1=0, lifeg0=0;
//--------------------------------------------------------------------------------MAIN FLAGS Levels

int level1,level2=0,level3;

//--------------------------------------------------------------------------------- level3   

int background3, flag21=0,cat,scoregargamel=0,catleft,run=0,rungame,flag80=0,flag81=0;

//---------------------------------------------------------------------------------- windows keybord    

//variables for keyboard monitoring
int Callback_Data;
int Posting_Handle;
int Keys_Down[256]= {0};

//Receives information from windows regarding key presses 

int CVICALLBACK Key_DownFunc(int panel, int message, unsigned int* wParam, unsigned int* lParam, void* callbackData)
{
	unsigned int Key = *wParam;
	Keys_Down[Key] = 1;
	return 0;
}

//Receives information from windows regarding key releases
int CVICALLBACK Key_UpFunc(int panel, int message, unsigned int* wParam, unsigned int* lParam, void* callbackData)
{
	unsigned int Key = *wParam;
	Keys_Down[Key] = 0;
	return 0;
}

//asking windows to send keyboard press and release events to our software
//Specifing 'Key_DownFunc' and 'Key_UpFunc' as the functions to call
void Connect_To_Windows_Events(void)
{
	InstallWinMsgCallback(panelHandle,WM_KEYDOWN,Key_DownFunc,VAL_MODE_IN_QUEUE,&Callback_Data,&Posting_Handle);
	InstallWinMsgCallback(panelHandle,WM_KEYUP,Key_UpFunc,VAL_MODE_IN_QUEUE,&Callback_Data,&Posting_Handle);
}


//---------------------------------------------------------------------------------player struct   
typedef struct
{
	int score12;
	char name[50];

} players;

players player[6];



//---------------------------------------------------------------------------------------------------------------- scoreboard

FILE *scoreboardfile;
int scoretemps=0;
char scoreboardbuffer[10000];
char tablesnames[50];
char currentplayername[50];

char val[50];

FILE *fp ;
int t=0;

typedef struct{
int score3;
char name[50];

} tablescores;

tablescores tables[7];

char linebuffer[100], names[200]={0} ,tablesnames[50]={0};
int scores[6]={0};


//------------------------------------------------------------------------------------------------------------------------- scoreboard update func


void TableFunc()
{ 	
	 	t=1;
		fp = fopen ("score.txt","r") ;
		
		while (fgets (linebuffer, 99, fp) != 0) 
		{
		sscanf(linebuffer,"%s , %d",tables[t].name ,&tables[t].score3);
		SetTableCellVal (panelHandle6, PANEL_6_TABLE, MakePoint(1,t), tables[t].name) ;
		SetTableCellVal (panelHandle6, PANEL_6_TABLE, MakePoint(2,t), tables[t].score3) ;
		t++ ;
		}
		fclose(fp);
	 
}




void writeTable()
{		
		int min;	
	    SetMouseCursor (VAL_DEFAULT_CURSOR);
		t=1;
		fp = fopen ("score.txt","r") ;
		while (fgets (linebuffer, 99, fp) != 0) 
		{
		sscanf(linebuffer,"%s , %d",tables[t].name ,&tables[t].score3);
		SetTableCellVal (panelHandle6, PANEL_6_TABLE, MakePoint(1,t), tables[t].name) ;
		SetTableCellVal (panelHandle6, PANEL_6_TABLE, MakePoint(2,t), tables[t].score3) ;
		t++ ;
		}
		strcpy(tables[6].name,val);
		tables[6].score3 = score1;
		for(i=1;i<6;i++)  //selection sort
			{
				min = i;
				for(j=i+1;j<=6;j++)
				{
					 if(tables[j].score3 < tables[min].score3)
							min = j; 
				}
				
			scoretemps = tables[min].score3 ;	//swap score
			tables[min].score3 = tables[i].score3; 
			tables[i].score3 = scoretemps;
			strcpy(tablesnames, tables[min].name); //swap name
			strcpy(tables[min].name, tables[i].name); 
			strcpy(tables[i].name, tablesnames);
			}
			
		fclose(fp);
		
		fp = fopen ("score.txt","w") ;   // arrange table values 
		for(t=6;t>=2;t--)
		fprintf(fp,"%s , %d\n",tables[t].name ,tables[t].score3);
		fclose(fp);	
		 
		t=1;
		fp = fopen ("score.txt","r") ;
		
		while (fgets (linebuffer, 99, fp) != 0)   //rewrite table values
		{
		sscanf(linebuffer,"%s , %d",tables[t].name ,&tables[t].score3);
		SetTableCellVal (panelHandle6, PANEL_6_TABLE, MakePoint(1,t), tables[t].name) ;
		SetTableCellVal (panelHandle6, PANEL_6_TABLE, MakePoint(2,t), tables[t].score3) ;
		t++ ;
		}
	   
		
}


//----------------------------------------------------------------------------------------------------------------- SOUND     


void soundgame()
{
	BASS_Init( -1,44100, 0,0,NULL);
	Music_SND=BASS_StreamCreateFile(FALSE,"music//music.mp3",0,0,0);
	shoot_SND=BASS_StreamCreateFile(FALSE,"music//shoot.mp3",0,0,0);
	jump_SND=BASS_StreamCreateFile(FALSE,"music//jump.mp3",0,0,0);
	sad_SND=BASS_StreamCreateFile(FALSE,"music//sad.mp3",0,0,0);
	boom_SND= BASS_StreamCreateFile(FALSE,"music//bomb.mp3",0,0,0);
	boomenemy_SND= BASS_StreamCreateFile(FALSE,"music//boomenemy.mp3",0,0,0);
	startmusic_SND =  BASS_StreamCreateFile(FALSE,"music//startmusic.mp3",0,0,0);
	stage1_SND = BASS_StreamCreateFile(FALSE,"music//stage1.mp3",0,0,0);
	round1_SND = BASS_StreamCreateFile(FALSE,"music//round1.mp3",0,0,0);
	round2_SND = BASS_StreamCreateFile(FALSE,"music//round2.mp3",0,0,0);
	round3_SND = BASS_StreamCreateFile(FALSE,"music//round3.mp3",0,0,0);
	gargamel_SND = BASS_StreamCreateFile(FALSE,"music//gargamel.mp3",0,0,0);
	winsound1_SND = BASS_StreamCreateFile(FALSE,"music//winsound1.mp3",0,0,0);
	cat_SND= BASS_StreamCreateFile(FALSE,"music//cat.mp3",0,0,0);
	level2new_SND= BASS_StreamCreateFile(FALSE,"music//level2new.mp3",0,0,0);
	level3new_SND= BASS_StreamCreateFile(FALSE,"music//level3new.mp3",0,0,0); 
	
	
}






//------------------------------------------------------------------------------- blip struct  

typedef struct
{
	int movex;								   
	int movey;
	int direction;
	int state; //0 dead, 1 for alive;  
	
} blips;

blips blip;


//------------------------------------------------------------------------------- enemy struct    

typedef struct
{
	//type1
	int movex;
	int movexleft;
	int movey;
	int speed;
	int direction;
	int state; //0 dead, 1 for alive;
	
	//suprise
	int upmovey;
	int upmovex;
	int speed1;
	
	
	//type2
	int movex2;
	int movex3;
	int movex4; 
	int movexleft2;
	int movey2;
	int speed2;
}	enemies;

enemies enemy[50];


//------------------------------------------------------------------------------- bullets struct

typedef struct
{
	int bulletx;
	int bullety;
	int speed;
	int direction;
	int state; //0 dead, 1 for alive;

} bullets;

bullets bull[1500];

//------------------------------------------------------------------------------- Enemy Gragamel

typedef struct
{
	int movex;								   
	int movey;
	int direction;
	int state; //0 dead, 1 for alive
	int catx;
	int catxleft;
	int caty;
	int try;
	
} gargamels;

gargamels gargamel;


typedef struct
{
	int bullx;
	int bullx2;
	int bully;
	int direction;
	int state; //0 dead, 1 for alive
	
} gargamelbull;

gargamelbull bullg[100];





//------------------------------------------------------------------------------- Enemy red smurfs level 2

typedef struct
{
	int movex;								   
	int movey;
	int movexleft;
	int direction;
	int speed;
	int state; //0 dead, 1 for alive
	
	int try;
	
} grenpas;

grenpas grenpa[50];





//----------------------------------------------------------------------------------------------------------------- Blip Jump  

void jump()
{
	
	if(blip.movey>60)
			{
			   vy=vy-9.81*dt*500;
			   blip.movey=blip.movey-vy*dt-(4.905*dt*dt*4000);
			   if (blip.movey>height-45)
			   {
				   jumpy=0;
				   blip.movey=height-45;
			   }
			}
	
}
//----------------------------------------------------------------------------------------------------------------- first pictures
void picturs()
{
	GetBitmapFromFile ("frame of the beginning\\1.png", &a1);
	GetBitmapFromFile ("frame of the beginning\\2.png", &a2); 
	GetBitmapFromFile ("frame of the beginning\\3.png", &a3); 
	GetBitmapFromFile ("frame of the beginning\\4.png", &a4); 
	GetBitmapFromFile ("frame of the beginning\\5.png", &a5); 
	GetBitmapFromFile ("frame of the beginning\\6.png", &a6); 
	GetBitmapFromFile ("frame of the beginning\\7.png", &a7); 
	GetBitmapFromFile ("frame of the beginning\\8.png", &a8); 
	GetBitmapFromFile ("frame of the beginning\\9.png", &a9); 
	GetBitmapFromFile ("frame of the beginning\\10.png", &a10); 
	GetBitmapFromFile ("frame of the beginning\\11.png", &a11); 
	GetBitmapFromFile ("frame of the beginning\\12.png", &a12); 
	GetBitmapFromFile ("frame of the beginning\\13.png", &a13); 
	GetBitmapFromFile ("frame of the beginning\\14.png", &a14); 
	GetBitmapFromFile ("frame of the beginning\\15.png", &a15); 
	GetBitmapFromFile ("frame of the beginning\\16.png", &a16); 
	GetBitmapFromFile ("frame of the beginning\\17.png", &a17); 
	GetBitmapFromFile ("frame of the beginning\\18.png", &a18); 
	GetBitmapFromFile ("frame of the beginning\\19.png", &a19); 
	GetBitmapFromFile ("frame of the beginning\\20.png", &a20); 
	GetBitmapFromFile ("frame of the beginning\\21.png", &a21); 
	GetBitmapFromFile ("frame of the beginning\\22.png", &a22); 
	GetBitmapFromFile ("frame of the beginning\\23.png", &a23); 
	GetBitmapFromFile ("frame of the beginning\\24.png", &a24); 
	GetBitmapFromFile ("frame of the beginning\\25.png", &a25); 
	GetBitmapFromFile ("frame of the beginning\\26.png", &a26); 
	GetBitmapFromFile ("frame of the beginning\\27.png", &a27); 
	GetBitmapFromFile ("frame of the beginning\\28.png", &a28); 
	GetBitmapFromFile ("frame of the beginning\\29.png", &a29); 
	GetBitmapFromFile ("frame of the beginning\\30.png", &a30); 
	GetBitmapFromFile ("frame of the beginning\\31.png", &a31); 
	GetBitmapFromFile ("frame of the beginning\\32.png", &a32); 
	GetBitmapFromFile ("frame of the beginning\\33.png", &a33); 
	GetBitmapFromFile ("frame of the beginning\\34.png", &a34); 
	GetBitmapFromFile ("frame of the beginning\\35.png", &a35); 
	GetBitmapFromFile ("frame of the beginning\\36.png", &a36); 
	GetBitmapFromFile ("frame of the beginning\\37.png", &a37);
	GetBitmapFromFile ("frame of the beginning\\38.png", &a38);
	GetBitmapFromFile ("frame of the beginning\\39.png", &a39);
	GetBitmapFromFile ("frame of the beginning\\40.png", &a40);
	GetBitmapFromFile ("frame of the beginning\\41.png", &a41);
	GetBitmapFromFile ("frame of the beginning\\42.png", &a42);
	GetBitmapFromFile ("frame of the beginning\\43.png", &a43);
	GetBitmapFromFile ("frame of the beginning\\44.png", &a44);
	GetBitmapFromFile ("frame of the beginning\\45.png", &a45);
	GetBitmapFromFile ("frame of the beginning\\46.png", &a46);

	
	
	
}


//----------------------------------------------------------------------------------------------------------------- INIT


void init()
{
	srand(time(0));
	
	GetBitmapFromFile ("Data\\backgroundnum1.png", &backgroundnum1);
	GetBitmapFromFile ("Data\\background.png", &background);
	GetBitmapFromFile ("Data\\background2.png", &background2);
	GetBitmapFromFile ("Data\\right_blip_pic.png", &right_blip_pic);
	GetBitmapFromFile ("Data\\left_blip_pic.png", &left_blip_pic); 
	GetBitmapFromFile ("Data\\right_fire.png", &right_fire);
	GetBitmapFromFile ("Data\\left_fire.png", &left_fire);  
	GetBitmapFromFile ("Data\\rightfire.png", &rightfire);  
	GetBitmapFromFile ("Data\\smurfs.png", &smurfs);
	GetBitmapFromFile ("Data\\smurfs_died.png", &smurfs_died); 
	GetBitmapFromFile ("Data\\smurfs_walk_left2.png", &smurfs_walk_left2); 
	GetBitmapFromFile ("Data\\smurfs_walk_left2.png", &smurfs_right);
	GetBitmapFromFile ("Data\\smurfsleft.png", &smurfsleft);
	GetBitmapFromFile ("Data\\explosion.png", &explosion1);
	GetBitmapFromFile ("Data\\health1.png", &health1);
	GetBitmapFromFile ("Data\\health2.png", &health2);
	GetBitmapFromFile ("Data\\health3.png", &health3);
	GetBitmapFromFile ("Data\\health4.png", &health4);
	GetBitmapFromFile ("Data\\health5.png", &health5);
	GetBitmapFromFile ("Data\\respwnbullet.png", &respwnbullet);
	GetBitmapFromFile ("Data\\opendoor.png", &opendoor);
	GetBitmapFromFile ("Data\\closedoor.png", &closedoor);
	GetBitmapFromFile ("Data\\nobullet.png", &nobullet);
	GetBitmapFromFile ("Data\\smursnewleft.png", &smursnewleft);
	GetBitmapFromFile ("Data\\smursnewright.png", &smursnewright);
	GetBitmapFromFile ("Data\\suprise.png", &suprise);
	GetBitmapFromFile ("Data\\gameover.png", &gameover);
	GetBitmapFromFile ("Data\\fireup.png", &fireup); 
	GetBitmapFromFile ("Data\\gargameleft.png", &gargameleft);
	GetBitmapFromFile ("Data\\gargameright.png", &gargameright);
	GetBitmapFromFile ("Data\\gargamellife3.png", &g3);
	GetBitmapFromFile ("Data\\gargamellife2.png", &g2);
	GetBitmapFromFile ("Data\\gargamellife1.png", &g1);
	GetBitmapFromFile ("Data\\gargamellife0.png", &g0);
	GetBitmapFromFile ("Data\\gargamellife.png", &gargamellife);
	GetBitmapFromFile ("Data\\background3.png", &background3);
	GetBitmapFromFile ("Data\\gragamelnew.png", &gragamelnew); 
	GetBitmapFromFile ("Data\\gragamelnewright.png", &gragamelnewright);
	GetBitmapFromFile ("Data\\youwin.png", &youwin);
	GetBitmapFromFile ("Data\\smurfsgranpaleft.png", &smurfsgranpaleft);
	GetBitmapFromFile ("Data\\shield.png", &shield); 
	GetBitmapFromFile ("Data\\smurfsgranparight.png", &smurfsgranparight); 
	GetBitmapFromFile ("Data\\cat.png", &cat);
	GetBitmapFromFile ("Data\\catleft.png", &catleft);  
	GetBitmapFromFile ("Data\\rungame.png", &rungame);

	TableFunc();
	
	GetCtrlAttribute (panelHandle, PANEL_CANVAS, ATTR_HEIGHT, &height); 
	GetCtrlAttribute (panelHandle, PANEL_CANVAS, ATTR_TOP, &top);  
	GetCtrlAttribute (panelHandle, PANEL_CANVAS, ATTR_LEFT, &left);   
	GetCtrlAttribute (panelHandle, PANEL_CANVAS, ATTR_WIDTH, &width);
	blip.movey=height-45;
	blip.movex=left+10;

	

  for(int i=0;i<enemynum1;i++)
	{
		grenpaspwn(i);
		
	}
	
  for(int i=0;i<enemynum;i++)
	{
		enemyspwn(i);
	}

}

//---------------------------------------------- LEVEL 1 -----------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------- Blip Move


void move()
{
	if(run==0)
	{
	flag1=0; // always look right
	if(Keys_Down[39] && flag1==0) //-------------------- right
		{
			if(blip.movex<width)
			{
			 blip.movex=blip.movex+4;
			 blip.direction=0;
			}
		}
	 if(Keys_Down[37]) //-------------------- left
		{
			flag1=2;
			blip.movex=blip.movex-4;
			blip.direction=1;
			CanvasDrawBitmap (panelHandle, PANEL_CANVAS, left_blip_pic, VAL_ENTIRE_OBJECT, MakeRect ( blip.movey,blip.movex, 40, 80));	
		}
		
		
	if(Keys_Down[40]) //-------------------- down
		{
			blip.direction=3;
			if(blip.movey<382)
			blip.movey=blip.movey+4;
		}
		
		if (jumpy==1)
			jump();
		
       if(blip.movex>=800)
	    {
		state_screen=1;
	    }
	}
	
	if(run==1)
	{
			flag1=0; // always look right
	if(Keys_Down[39] && flag1==0) //-------------------- right
		{
			if(blip.movex<width)
			{
			 blip.movex=blip.movex+8;
			 blip.direction=0;
			}
		}
	 if(Keys_Down[37]) //-------------------- left
		{
			flag1=2;
			blip.movex=blip.movex-8;
			blip.direction=1;
			CanvasDrawBitmap (panelHandle, PANEL_CANVAS, left_blip_pic, VAL_ENTIRE_OBJECT, MakeRect ( blip.movey,blip.movex, 40, 80));	
		}
		
		
	if(Keys_Down[40]) //-------------------- down
		{
			blip.direction=3;
			if(blip.movey<382)
			blip.movey=blip.movey+8;
		}
		
		if (jumpy==1)
			jump();
		
       if(blip.movex>=800)
	    {
		state_screen=1;
	    }
		
	}
}


//----------------------------------------------------------------------------------------------------------------- Timer Jump Blip 

void timerjumpblip()
{
	if(Keys_Down[38]) //-------------------- up
		{
			BASS_ChannelPlay(jump_SND,TRUE);
			blip.direction=2;
			jumpy=1;
			vy=300;
		}		
	
}




//----------------------------------------------------------------------------------------------------------------- Bullet Move(need to fix!!!!) 


void BulletMove(int i) 
{
	switch(bull[i].direction)
	{
		case 0:   // bullet right
			bull[i].bulletx = bull[i].bulletx + bull[i].speed;
			CanvasDrawBitmap (panelHandle, PANEL_CANVAS, right_fire, VAL_ENTIRE_OBJECT, MakeRect (bull[i].bullety,bull[i].bulletx, 10, 30));
			break;
			
		case 1:  // bullet left
			bull[i].bulletx = bull[i].bulletx - bull[i].speed;
			CanvasDrawBitmap (panelHandle, PANEL_CANVAS, left_fire, VAL_ENTIRE_OBJECT, MakeRect (bull[i].bullety-8,bull[i].bulletx-75, 30, 40));
			break;
			
		case 2:  // bullet up  
			bull[i].bullety = bull[i].bullety - bull[i].speed;
			CanvasDrawBitmap (panelHandle, PANEL_CANVAS, fireup, VAL_ENTIRE_OBJECT, MakeRect (bull[i].bullety-15,bull[i].bulletx-30, 30, 40));
			break;
	}
}




void shooting()
{
	if(first!=1)
	{
	  if(Keys_Down[' '] && numofbullet>0)
	  {
		BASS_ChannelPlay(shoot_SND,TRUE);
		numofbullet--; 
		bull[i].direction==0;
		shotCounter++;
		bullet(shotCounter);
		first=1;
	  }
	}

   if(first!=1)
	{	
	 if(Keys_Down[' '] && Keys_Down[37] &&  numofbullet>0)
	 {
		BASS_ChannelPlay(shoot_SND,TRUE);
		bull[i].direction==1;
		shotCounter++;
		bullet(shotCounter);
		first=1;
	 } 
	}
	
	if(first!=1)
	{
		if(Keys_Down[' '] && Keys_Down[40] &&  numofbullet>0) 
		{
			BASS_ChannelPlay(shoot_SND,TRUE);
		    bull[i].direction==2;
		    shotCounter++;
		    bullet(shotCounter);
		    first=1;
		}
	}

}




//----------------------------------------------------------------------------------------------------------------- Bullet Location



void bullet(int i)
{
	if(flag17==0)
	bull[i].bulletx=blip.movex+60;
	bull[i].bullety=blip.movey+20;
	bull[i].speed = 5;
	bull[i].direction=blip.direction;

}







//----------------------------------------------------------------------------------------------------------------- Enemy Move level 1
void level1enemymove(int i)
{
	
	if(enemy[i].state == 1)
	{
		if(i<15)
		{
		
		 if ((RectIntersection (MakeRect(bull[i].bullety, bull[i].bulletx, 20, 8), MakeRect(enemy[j].upmovey, enemy[j].upmovex, 20, 8), NULL) == 0))
		 {
		  enemy[i].upmovey =enemy[i].upmovey + enemy[i].speed1;
		  CanvasDrawBitmap (panelHandle, PANEL_CANVAS, suprise, VAL_ENTIRE_OBJECT, MakeRect (enemy[i].upmovey,enemy[i].upmovex, 40, 40));
		 }
			
		 }
	
		enemy[i].movex = enemy[i].movex - enemy[i].speed;
		enemy[i].movexleft = enemy[i].movexleft + enemy[i].speed;
		

	   
		
		if ((RectIntersection (MakeRect(bull[i].bullety, bull[i].bulletx, 20, 8), MakeRect(enemy[i].movey, enemy[i].movex, 20, 8), NULL) == 0) && (RectIntersection (MakeRect(bull[i].bullety, bull[i].bulletx, 20, 8), MakeRect(enemy[i].movey, enemy[i].movexleft, 20, 8), NULL) == 0) && (RectIntersection (MakeRect(bull[i].bullety, bull[i].bulletx, 20, 8), MakeRect(enemy[1].movey2, enemy[1].movex2, 20, 8), NULL) == 0) && (RectIntersection (MakeRect(bull[i].bullety, bull[i].bulletx, 20, 8), MakeRect(enemy[1].movey2, enemy[1].movex3, 20, 8), NULL) == 0) && (RectIntersection (MakeRect(bull[i].bullety, bull[i].bulletx, 20, 8), MakeRect(enemy[1].movey2, enemy[1].movex4, 20, 8), NULL) == 0))
		{
		  CanvasDrawBitmap (panelHandle, PANEL_CANVAS, smursnewleft, MakeRect(0,(34*animation)+5,32,30), MakeRect (enemy[i].movey-10,enemy[i].movex, 48, 40));
		  
		  CanvasDrawBitmap (panelHandle, PANEL_CANVAS, smursnewright, MakeRect(0,(34*animation)+5,38,30), MakeRect (enemy[i].movey-10,enemy[i].movexleft, 60, 40));
		  
		  CanvasDrawBitmap (panelHandle, PANEL_CANVAS, smursnewleft, MakeRect(0,(34*animation)+5,32,30), MakeRect (enemy[1].movey2-10,enemy[1].movex2, 50, 50));
		  
		  CanvasDrawBitmap (panelHandle, PANEL_CANVAS, smursnewright, MakeRect(0,(34*animation)+5,38,30), MakeRect (enemy[1].movey2,enemy[1].movex3, 45, 50));
		  
		  CanvasDrawBitmap (panelHandle, PANEL_CANVAS, smursnewright, MakeRect(0,(34*animation)+5,38,30), MakeRect (enemy[1].movey2,enemy[1].movex4, 45, 50)); 
		}
	}

	
}

//----------------------------------------------------------------------------------------------------------------- Enemy Jump


void enemyjunp()
{
	
   	if(enemy[1].movex2 == 600 || enemy[1].movex2 == 300)
		{
			enemyjump=1;
			enemyvy = 900;
		}
	
	enemy[1].movex2 = enemy[1].movex2 - 1;
	
	if(enemyjump ==1)
		{
		 if(enemy[1].movey2>60)
		  {
			enemyvy = enemyvy -9.81*dt*500;
			enemy[1].movey2 = enemy[1].movey2 - enemyvy*dt - (4.905*dt*dt*4000);
			
			if(enemy[1].movey2 > height-45)
			{
				enemyjump=0;
				enemy[1].movey2 = height-45;
			}
			
		  }
		}
		
	
		 
		if(enemy[1].movex3 == 400 || enemy[1].movex3 == 600)
		{
			enemyjump=1;
			enemyvy = 900;
		}
		enemy[1].movex3 = enemy[1].movex3 + 1;
		
		if(enemyjump ==1)
		{
		 if(enemy[1].movey2>60)
		  {
			enemyvy = enemyvy -9.81*dt*500;
			enemy[1].movey2 = enemy[1].movey2 - enemyvy*dt - (4.905*dt*dt*4000);
			
			if(enemy[1].movey2 > height-45)
			{
				enemyjump=0;
				enemy[1].movey2 = height-45;
			}
			
		  }
		}
	
	 
		
		if(enemy[1].movex4 == 120 || enemy[1].movex4 == 450)
		{
			enemyjump=1;
			enemyvy = 900;
		}
		
		 enemy[1].movex4 = enemy[1].movex4 + 1; 
		

}


//----------------------------------------------------------------------------------------------------------------- Enemy Random Location 


void enemyspwn(int i)
{
	// The sumrs1
	enemy[i].movey = 420;
	
	enemy[i].movexleft = -3000+rand()%(1500);

	enemy[i].movex = 1500+rand()%(6000);
	enemy[i].speed = 1+rand()%5;
	enemy[i].state = 1;
	
	// The suprise
	enemy[i].speed1 = 1+rand()%7;
	enemy[i].upmovey = -1000 + rand()%(500);
	enemy[i].upmovex = 1 + rand()%800;
	
	// The sumrs2 right

	enemy[i].movex2 = 1200; 
	enemy[i].movey2 = 420;
	
	// The sumrs2 left

	enemy[i].movex3 = -300;
	enemy[i].movex4 = 90; 
	
}





//----------------------------------------------------------------------------------------------------------------- if the bullet hits the sumrs 


void hitenemy(int i)
{
	for(int j=0;j<enemynum;j++)
	{
	if(bull[i].bulletx<950 && bull[i].bulletx>-15)
	{
	  if ((RectIntersection (MakeRect(bull[i].bullety, bull[i].bulletx, 20, 20), MakeRect(enemy[j].movey, enemy[j].movex, 20, 20), NULL) == 1) || (RectIntersection (MakeRect(bull[i].bullety, bull[i].bulletx, 20, 20), MakeRect(enemy[j].movey, enemy[j].movexleft+60, 20, 20)  , NULL) == 1) || (RectIntersection (MakeRect(bull[i].bullety, bull[i].bulletx, 20, 20), MakeRect(enemy[1].movey2, enemy[1].movex2, 40, 40)  , NULL) == 1) || (RectIntersection (MakeRect(bull[i].bullety, bull[i].bulletx, 20, 20), MakeRect(enemy[1].movey2, enemy[1].movex3, 40, 40)  , NULL) == 1) || (RectIntersection (MakeRect(bull[i].bullety, bull[i].bulletx, 20, 20), MakeRect(enemy[1].movey2, enemy[1].movex4, 40, 40)  , NULL) == 1))
	   {
		 BASS_ChannelPlay(boomenemy_SND,TRUE);   
		 score1++;
		 enemy[j].movey=-100;
		 enemy[j].movex=-400;
		 bull[i].bulletx=-1000;
		 bull[i].bullety=-500;
		 enemy[j].movexleft=-2000;

		 enemy[1].movex2 = 1500;
		 enemy[1].movex3 = -890;
		 enemy[1].movex4 = 1890;
	   }
	   
	   if((RectIntersection (MakeRect(bull[i].bullety, bull[i].bulletx, 40, 40), MakeRect(enemy[j].upmovey, enemy[j].upmovex, 60, 40), NULL) == 1))
	   {
		  BASS_ChannelPlay(boomenemy_SND,TRUE);
		  enemy[j].upmovey = -3000;
		  enemy[j].upmovex = 2000;
		  bull[i].bulletx=-1000;
		  bull[i].bullety=-500;
	   }
	}
	}
	
}

																													 
//----------------------------------------------------------------------------------------------------------------- if the sumrs hit the blip

void hitblip(i)
{
	if ((RectIntersection (MakeRect(blip.movey, blip.movex, 20, 4), MakeRect(enemy[i].movey, enemy[i].movex, 20, 4), NULL) == 1) || (RectIntersection (MakeRect(blip.movey, blip.movex, 4, 20), MakeRect(enemy[i].upmovey, enemy[i].upmovex, 2, 10), NULL) == 1) || (RectIntersection (MakeRect(blip.movey, blip.movex, 20, 4), MakeRect(enemy[i].movey, enemy[i].movexleft, 20, 4), NULL) == 1) || (RectIntersection (MakeRect(blip.movey, blip.movex, 20, 1), MakeRect(enemy[1].movey2, enemy[1].movex2, 4, 1), NULL) == 1) || (RectIntersection (MakeRect(blip.movey, blip.movex, 20, 1), MakeRect(enemy[1].movey2, enemy[1].movex3, 4, 1), NULL) == 1)|| (RectIntersection (MakeRect(blip.movey, blip.movex, 20, 1), MakeRect(enemy[1].movey2, enemy[1].movex4, 1, 1), NULL) == 1))
	   {
		 CanvasDrawBitmap (panelHandle, PANEL_CANVAS, explosion1, VAL_ENTIRE_OBJECT, MakeRect (blip.movey, blip.movex, 45, 50));
		 BASS_ChannelPlay(boomenemy_SND,TRUE); 
		 injured++;
		 heart5=1;
		 enemy[i].movey=-500;
		 if(injured==1)
		 {
			 heart4=1;
		 }
		 if(injured==2)
		 {
			heart3=1; 
		 }
		 if(injured==3)
		 {
			 heart2=1;
		 }
		 
	   }
	   SetCtrlVal (panelHandle, PANEL_INJURED, injured);
	 if(injured==4)
	 {
		 writeTable(); 
		 SetCtrlAttribute (panelHandle, PANEL_REGMAEMENU, ATTR_DIMMED,0 );  
		 heart1=1;
		 BASS_ChannelPlay(sad_SND,TRUE);
		 CanvasDrawBitmap (panelHandle, PANEL_CANVAS, gameover, VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);
		 SetCtrlAttribute (panelHandle, PANEL_TIMER, ATTR_ENABLED, 0);


	 }
	
}








//----------------------------------------------------------------------------------------------------------------- limitBlip 



void limitmove()  // level 1 - blip jump to tier1
{
	switch(move1)
	{
		case 0:
	     if(blip.movex<160 && blip.movex >-60 && blip.movey<=270)
	     {
			 Keys_Down[38] =1;
			 if((Keys_Down[39] || Keys_Down[37] || Keys_Down[38] || Keys_Down[40] ))
			 {
				 blip.movey = 270;
				 blip.movey = blip.movey +1;
			 }
	     }
		  if(blip.movex>160)
				Keys_Down[38] =0;
		 
		  
		  
		 if(blip.movex <650 && blip.movex>550 && blip.movey<=330)
		 {
			 Keys_Down[38] =1;
			 if((Keys_Down[39] || Keys_Down[37] || Keys_Down[38] || Keys_Down[40] ))
			 {
				 blip.movey = 330;
				 blip.movey = blip.movey +1;
			 }
		 }
		 if(blip.movex>650)
				Keys_Down[38] =0;
			break;
		case 1:
			break;
	}
}


//----------------------------------------------------------------------------------------------------------------- score 


void score()
{
	SetCtrlVal (panelHandle, PANEL_KILLED, score1);
    SetCtrlVal (panelHandle, PANEL_NUMOFBULLET, numofbullet);
}


//----------------------------------------------------------------------------------------------------------------- Hit General 


void hitgeneral()
{
	if(flag14==0) // if the blip take another bullet
	{
	  if (RectIntersection (MakeRect(blip.movey, blip.movex, 20, 20), MakeRect(329, 600, 30, 30), NULL) == 1)
	  {
		flagbullet=1;
		numofbullet=numofbullet+5;
		flag14=1;
	  }
	}
}



//----------------------------------------------------------------------------------------------------------------- Update Game  

void updategame()
{
	if(score1>=25)  // condition to the next level
	{
		moveon=1;
		CanvasDrawBitmap (panelHandle, PANEL_CANVAS, opendoor, VAL_ENTIRE_OBJECT, MakeRect ( 355,810, 110, 110));
		if(blip.movex==810)
		{
			
			blip.movey=height-45;
	        blip.movex=left+10;
			
			lel1flag = 1;
			lel3flag = 1;
			moveon=0;
			BASS_ChannelStop(stage1_SND);
			BASS_ChannelPlay(level2new_SND ,TRUE);

		}
		
	}
	
	if(numofbullet==0)		// if the bullet is emptry picture
	{
		CanvasDrawBitmap (panelHandle, PANEL_CANVAS, nobullet, VAL_ENTIRE_OBJECT, MakeRect ( 20,185, 90, 120));
	}
	
}

//----------------------------------------------------------------------------------------------------------------- Step Picture CANVAS

void stepicure()
{
	step++;
	if(step>=30)
		step=0;
}




//----------------------------------------------------------------------------------------------------------------- DRAW 


void draw()
{

	if(time1%2==0)
	animation++;
	if(animation>=5)
		animation=0;
	
	
	CanvasStartBatchDraw (panelHandle, PANEL_CANVAS);
	CanvasClear (panelHandle, PANEL_CANVAS, VAL_ENTIRE_OBJECT);
	
	CanvasDrawBitmap (panelHandle, PANEL_CANVAS, backgroundnum1, VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);
	
	if(flag1==0)	// flag1 look right
	CanvasDrawBitmap (panelHandle, PANEL_CANVAS, right_blip_pic, VAL_ENTIRE_OBJECT, MakeRect ( blip.movey,blip.movex, 40, 80));
    for(int i=0;i<50;i++)
	{
	   hitenemy(i);
	}
	
	
	if(Keys_Down[' ']==0)
		first=0;
	
    for(int i=0;i<50;i++) // enemy level 1
	{
	   level1enemymove(i);
	   
	}

	enemyjunp(i);
	for(int i=0;i<50;i++)
	{
	  hitblip(i);
	}
	for(int i=0;i<=shotCounter;i++)
	{
		BulletMove(i);
	}
	
	
	if(flagbullet==0) // conditon to take AMMO
	{
		CanvasDrawBitmap (panelHandle, PANEL_CANVAS, respwnbullet, VAL_ENTIRE_OBJECT, MakeRect ( 332,600, 35, 35));
	}
	
	if(heart1==0)
	CanvasDrawBitmap (panelHandle, PANEL_CANVAS, health1, VAL_ENTIRE_OBJECT, MakeRect ( 50,30, 50, 50));   // health1
	if(heart2==0) 
	CanvasDrawBitmap (panelHandle, PANEL_CANVAS, health2, VAL_ENTIRE_OBJECT, MakeRect ( 50,72, 50, 50));
	if(heart3==0) 
	CanvasDrawBitmap (panelHandle, PANEL_CANVAS, health3, VAL_ENTIRE_OBJECT, MakeRect ( 50,112, 50, 50));
	if(heart4==0)    
	CanvasDrawBitmap (panelHandle, PANEL_CANVAS, health4, VAL_ENTIRE_OBJECT, MakeRect ( 50,154, 50, 50));
	if(heart5==0) 
	CanvasDrawBitmap (panelHandle, PANEL_CANVAS, health5, VAL_ENTIRE_OBJECT, MakeRect ( 50,196, 50, 50));
	if(moveon==0)
	CanvasDrawBitmap (panelHandle, PANEL_CANVAS, closedoor, VAL_ENTIRE_OBJECT, MakeRect ( 360,830, 100, 70)); 

	


	
	animation3++;
	CanvasEndBatchDraw (panelHandle, PANEL_CANVAS);
}



//---------------------------------------------------------  Main  ---------------------------------------------------------



int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "Blip&Blop.uir", PANEL)) < 0)
		return -1;
	if ((panelHandle2 = LoadPanel (0, "Blip&Blop.uir", PANEL_2)) < 0)
		return -1;
	if ((panelHandle3 = LoadPanel (0, "Blip&Blop.uir", PANEL_3)) < 0)
		return -1;
	if ((panelHandle4 = LoadPanel (0, "Blip&Blop.uir", PANEL_4)) < 0)
		return -1;
	if ((panelHandle5 = LoadPanel (0, "Blip&Blop.uir", PANEL_5)) < 0)
		return -1;
	if ((panelHandle6 = LoadPanel (0, "Blip&Blop.uir", PANEL_6)) < 0)
		return -1;
	if ((panelHandle7 = LoadPanel (0, "Blip&Blop.uir", PANEL_7)) < 0)
		return -1;
	picturs();
	init();
	soundgame();
	Connect_To_Windows_Events();
	DisplayPanel (panelHandle3); 
	RunUserInterface ();
	DiscardPanel (panelHandle);
	DiscardPanel (panelHandle2);
	return 0;
}		

int CVICALLBACK MainPanel (int panel, int event, void *callbackData,
						   int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			QuitUserInterface(0);
			break;
	}
	return 0;
}


//------------------------------------------------------------- LEVEL 3 ------------------------------------------------------------------------





//------------------------------------------------------------------------------------------------------------------------- Gargamel Move  

void gargamelmove()  // on timer
{


		if(blip.movex != gargamel.movex )
		{
			if(scoregargamel<150)
			{
			if(blip.movex < gargamel.movex)
			{
				animation2=0;
				flagargamel1=0;  // if gargamel shot left
				gargamel.movex = gargamel.movex - 1;
				CanvasDrawBitmap (panelHandle, PANEL_CANVAS, gragamelnew, MakeRect(0,(animation1*140)+6, 150, 140), MakeRect( gargamel.movey-88,gargamel.movex, 150, 150));
				if(animation1>=4)
					animation1=0;
				 
			}
			if(blip.movex > gargamel.movex)
			{
				animation1=0;
				flagargamel1=1; // if gargamel shot right  
				gargamel.movex = gargamel.movex + 1;
				CanvasDrawBitmap (panelHandle, PANEL_CANVAS, gragamelnewright, MakeRect(0,(animation2*140)-2, 150, 140), MakeRect ( gargamel.movey-88,gargamel.movex, 150, 150));
				if(animation2>=4)
					animation2=0;
			}
			}
			if(scoregargamel>150)
			{
			 if(blip.movex < gargamel.movex)
			{
				animation2=0;
				flagargamel1=0;  // if gargamel shot left
				gargamel.movex = gargamel.movex - 2;
				CanvasDrawBitmap (panelHandle, PANEL_CANVAS, gragamelnew, MakeRect(0,(animation1*140)+6, 150, 140), MakeRect( gargamel.movey-88,gargamel.movex, 150, 150));
				if(animation1>=4)
					animation1=0;
				 
			}
			if(blip.movex > gargamel.movex)
			{
				animation1=0;
				flagargamel1=1; // if gargamel shot right  
				gargamel.movex = gargamel.movex + 2;
				CanvasDrawBitmap (panelHandle, PANEL_CANVAS, gragamelnewright, MakeRect(0,(animation2*140)-2, 150, 140), MakeRect ( gargamel.movey-88,gargamel.movex, 150, 150));
				if(animation2>=4)
					animation2=0;
			}
				
			}
			
				
		}
		if(catflag==1)
		{
			if(catflag1==0)
			{
			gargamel.catx =gargamel.catx +3;
			CanvasDrawBitmap (panelHandle, PANEL_CANVAS, cat, MakeRect(0,(animation6*102)+2, 80, 102), MakeRect ( gargamel.caty,gargamel.catx, 100, 100));
			}
			if(gargamel.catx>=900)
			{
				catflag1=1;
				CanvasDrawBitmap (panelHandle, PANEL_CANVAS, catleft, MakeRect(0,(animation6*102)+2, 80, 102), MakeRect ( gargamel.caty,gargamel.catxleft, 100, 100));
				gargamel.catxleft =gargamel.catxleft -3;
				if(gargamel.catxleft<=0)
				{
					flag23=0;
					catflag1=0;
					
				}
				
			}
			if(animation6>=4)
				animation6=0;
				
		}
	
}





//------------------------------------------------------------------------------------------------------------------------- Gargamel move shoting


void gargamelshotingmove(int i)   //bull gargamel shoting
{
	if (hitblip1==0) 
	{
   	    if(blip.movex != gargamel.movex)
		{
			if(bullg[i].bullx2 > blip.movex)
			{
				bullg[i].bullx2 =bullg[i].bullx2 -2;
				CanvasDrawBitmap (panelHandle, PANEL_CANVAS, left_fire, VAL_ENTIRE_OBJECT, MakeRect ( bullg[i].bully-30,bullg[i].bullx2, 100, 100)); 
			}
			
			else if(bullg[i].bullx2 < blip.movex)
			{
				bullg[i].bullx2 =bullg[i].bullx2 +2;
				CanvasDrawBitmap (panelHandle, PANEL_CANVAS, right_fire, VAL_ENTIRE_OBJECT, MakeRect ( bullg[i].bully-25,bullg[i].bullx2, 52, 60));
			}
			
	}
			
			
			if(blip.movex > gargamel.movex + 150)
			{
				bullg[i].direction==1;
				fist10=1;
			}
	           
		 }
		
   
}





//------------------------------------------------------------------------------------------------------------------------- Blip Hit Gargamel 

void heatgargamel(int i)
{
	if ((RectIntersection (MakeRect(bull[i].bullety, bull[i].bulletx, 20, 20), MakeRect(gargamel.movey, gargamel.movex, 200, 12), NULL) == 1))
	{
		scoregargamel++;
		score1++;
		player[5].score12=score1;
		if(scoregargamel>10 && scoregargamel<80)
		{
			lifeg0=1; //the animation of the gargamel life
			lifeg1=1; //the animation of the gargamel life  
		}
		if(scoregargamel>80 && scoregargamel<150)
		{
			lifeg0=1;
			lifeg1=1;
			
		}
		
		if(scoregargamel>150 && scoregargamel<300)
		{
			
			BASS_ChannelPlay(cat_SND,TRUE);
			
			catflag=1;
			lifeg0=1;
			lifeg1=0;
			lifeg2=1;
		
			
		}
		
		if(scoregargamel>300)
		{
			lifeg0=1;
			lifeg1=0;
			lifeg2=0;
			lifeg3=1;
		}
		
		if(scoregargamel>320 && scoregargamel<400)
		{
			catflag=1;
			lifeg0=1;
			lifeg1=0;
			lifeg2=0;
			lifeg3=1;
	 
			writeTable(); 
	        BASS_ChannelPlay(winsound1_SND,TRUE);
			CanvasDrawBitmap (panelHandle, PANEL_CANVAS, youwin, VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);
			SetCtrlAttribute (panelHandle, PANEL_TIMER, ATTR_ENABLED, 0);
			
		
			SetCtrlAttribute (panelHandle, PANEL_REGMAEMENU, ATTR_DIMMED,0 ); 
			
		}
			

	}
	
}
//------------------------------------------------------------------------------------------------------------------- staff
void level2staff()
{
	if(flag56==0)
	{
	 if(flagbull==0)
	 CanvasDrawBitmap (panelHandle, PANEL_CANVAS, respwnbullet, VAL_ENTIRE_OBJECT,  MakeRect ( 224 ,660, 40, 50));
	

	   if ((RectIntersection (MakeRect(blip.movey, blip.movex, 20, 20), MakeRect(200, 600, 30, 30), NULL) == 1))
	   {
		flagbull=1;
		numofbullet=numofbullet+100;
		flag56=1;
	   }
	   flag18=1;
	}

	
	if(numofbullet==0)		// if the bullet is emptry picture
	{
		CanvasDrawBitmap (panelHandle, PANEL_CANVAS, nobullet, VAL_ENTIRE_OBJECT, MakeRect ( 20,185, 90, 120));
		
	}
	
	
	
}

//---------------------------------------------------------------------------------------------------------------
void bliplife()
{
	
	if(heart1==0)
	CanvasDrawBitmap (panelHandle, PANEL_CANVAS, health1, VAL_ENTIRE_OBJECT, MakeRect (50, 30, 50, 50));   // health1
	if(heart2==0) 
	CanvasDrawBitmap (panelHandle, PANEL_CANVAS, health2, VAL_ENTIRE_OBJECT, MakeRect ( 50,72, 50, 50));
	if(heart3==0) 
	CanvasDrawBitmap (panelHandle, PANEL_CANVAS, health3, VAL_ENTIRE_OBJECT, MakeRect ( 50,112, 50, 50));
	if(heart4==0)    
	CanvasDrawBitmap (panelHandle, PANEL_CANVAS, health4, VAL_ENTIRE_OBJECT, MakeRect ( 50,154, 50, 50));
	if(heart5==0) 
	CanvasDrawBitmap (panelHandle, PANEL_CANVAS, health5, VAL_ENTIRE_OBJECT, MakeRect ( 50,196, 50, 50));
	
}


//-------------------------------------------------------------------------------------------------------------------hitblip2

void hitblip2(int i)
{
	if ((RectIntersection (MakeRect(bullg[i].bully, bullg[i].bullx2, 20, 5), MakeRect(blip.movey, blip.movex, 20, 5), NULL) == 1) || (RectIntersection (MakeRect(gargamel.movey, gargamel.movex, 20, 5), MakeRect(blip.movey, blip.movex, 20, 5), NULL) == 1) ||(RectIntersection (MakeRect(bullg[i].bully, bullg[i].bullx2, 20, 5), MakeRect(blip.movey, blip.movex, 20, 5), NULL) == 1)||(RectIntersection (MakeRect(gargamel.caty, gargamel.catx, 20, 5), MakeRect(blip.movey, blip.movex, 20, 5), NULL) == 1) || (RectIntersection (MakeRect(gargamel.caty, gargamel.catxleft, 20, 5), MakeRect(blip.movey, blip.movex, 20, 5), NULL) == 1))
	{
		injured2++;
		hearte=1;
		bullg[i].bullx2=-1000;
		bullg[i].bully = 50;
		SetCtrlVal (panelHandle, PANEL_INJURED, injured2);
		hitblip1=1;
		if(injured2>10 && injured2<20)
		  heart5=1;
		  heartd=1;
		if(injured2>20 && injured2<30)
		  heart4=1;
		  heartc=1;
		if(injured2>30 && injured2<40)
		  heart3=1;
		  heartb=1;
		if(injured2>40 && injured2<50)
		   
		  hearta=1;
		
		if(hearta==1)
		{
			writeTable();
			BASS_ChannelPlay(sad_SND,TRUE);
		    CanvasDrawBitmap (panelHandle, PANEL_CANVAS, gameover, VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);
			SetCtrlAttribute (panelHandle, PANEL_REGMAEMENU, ATTR_DIMMED,0 ); 
		    SetCtrlAttribute (panelHandle, PANEL_TIMER, ATTR_ENABLED, 0);
			
		}
		
	}
	
}


//----------------------------------------------------------------------------------------------------------------- suprise

void suprise1(int i)
{
	if ((RectIntersection (MakeRect(bull[i].bullety, bull[i].bulletx, 20, 8), MakeRect(enemy[j].upmovey, enemy[j].upmovex, 20, 8), NULL) == 0)) 
	{
       enemy[i].upmovey =enemy[i].upmovey + enemy[i].speed1;
       CanvasDrawBitmap (panelHandle, PANEL_CANVAS, suprise, VAL_ENTIRE_OBJECT, MakeRect (enemy[i].upmovey,enemy[i].upmovex, 40, 40));
	}
	
	if((RectIntersection (MakeRect(bull[i].bullety, bull[i].bulletx, 40, 40), MakeRect(enemy[j].upmovey, enemy[j].upmovex, 60, 40), NULL) == 1))
	   {
		  BASS_ChannelPlay(boomenemy_SND,TRUE);
		  enemy[j].upmovey = -3000;
		  enemy[j].upmovex = 2000;
		  bull[i].bulletx=-1000;
		  bull[i].bullety=-500;
	   }
	   
	   
	   
	   if ((RectIntersection (MakeRect(blip.movey, blip.movex, 4, 20), MakeRect(enemy[i].upmovey, enemy[i].upmovex, 2, 10), NULL) == 1)) 
	   {
		 CanvasDrawBitmap (panelHandle, PANEL_CANVAS, explosion1, VAL_ENTIRE_OBJECT, MakeRect (blip.movey, blip.movex, 45, 50));
		 BASS_ChannelPlay(boomenemy_SND,TRUE); 
		 injured++;
		 heart5=1;
		 enemy[i].movey=-500;
		 if(injured==1)
		 {
			 heart4=1;
		 }
		 if(injured==2)
		 {
			heart3=1; 
		 }
		 if(injured==3)
		 {
			 heart2=1;
		 }
		 
	   }
	   
	   if ((RectIntersection (MakeRect(blip.movey, blip.movex, 4, 20), MakeRect(185, 100, 70, 70), NULL) == 1))
	   {
		 run=1;
		 flag80=1;
		   
	   }
	   
	
	
}




//------------------------------------------------------------------------------------------------------------------- Draw2 


void draw2()   //GARGAMEL LEVEL
{
	
	CanvasStartBatchDraw (panelHandle, PANEL_CANVAS);
	CanvasClear (panelHandle, PANEL_CANVAS, VAL_ENTIRE_OBJECT);
	CanvasDrawBitmap (panelHandle, PANEL_CANVAS, background2, VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);
	if(flag1==0)	// flag1 look right
	CanvasDrawBitmap (panelHandle, PANEL_CANVAS, right_blip_pic, VAL_ENTIRE_OBJECT, MakeRect ( blip.movey,blip.movex, 40, 80));
	
	level2staff();
	
	if(Keys_Down[' ']==0)
		first=0;
	if(run==0 && flag81==0)
	CanvasDrawBitmap (panelHandle, PANEL_CANVAS, rungame, VAL_ENTIRE_OBJECT, MakeRect (185, 100, 70, 70));

	if(flag80==1 && run==1)
	CanvasDrawBitmap (panelHandle, PANEL_CANVAS, rungame, VAL_ENTIRE_OBJECT, MakeRect (45, 243, 50, 50));
	
	
	for(int i=0;i<=shotCounter;i++) // count the num of the blip shoting
	{
		BulletMove(i);
	}
	
	bliplife();
	

	for(int i=0;i<shotinggargamel;i++)
	{
	   gargamelshotingmove(0);
	}
	
		
	for(int i=0;i<1;i++)
		hitblip2(i);
	
	
	for(int i=0;i<10;i++)
	{
			enemy[i].speed1 = 1+rand()%3;
	        enemy[i].upmovey = -1000 + rand()%(500);
	        enemy[i].upmovex = 1 + rand()%800;
	}
	
	for(int i=0;i<20;i++)
	{
		suprise1(i);
	}
	
	if(flag80==1)
	{
		timezone2=time5*0.02;
		 time6++;
		 if(time6>=800)
		 {
			 run=0;
			 flag80=0;
			 flag81=1;
		 }
	}
		
	if(timer3%6==0)
	animation1++;
	if(timer3%6==0)
	animation2++;
	
	if(timer8%6==0)
	animation6++;	
	timer3++;
	timer8++;
	CanvasEndBatchDraw (panelHandle, PANEL_CANVAS);   
	
}


//------------------------------------------------------------------------------------------------------------------- Gargamel Life


void canvas()
{
	CanvasDrawBitmap (panelHandle, PANEL_CANVAS, gargamellife, VAL_ENTIRE_OBJECT,  MakeRect ( -7,620, 40, 120));
	if(lifeg0==0)
	CanvasDrawBitmap (panelHandle, PANEL_CANVAS, g0, VAL_ENTIRE_OBJECT,  MakeRect ( 10,620, 40, 250));
	
	if(lifeg1==1)
	CanvasDrawBitmap (panelHandle, PANEL_CANVAS, g1, VAL_ENTIRE_OBJECT,  MakeRect ( 17,620, 32, 250));
	
	if(lifeg2==1)
	CanvasDrawBitmap (panelHandle, PANEL_CANVAS, g2, VAL_ENTIRE_OBJECT,  MakeRect ( 15,625, 40, 250));
	
	if(lifeg3==1)
	CanvasDrawBitmap (panelHandle, PANEL_CANVAS, g3, VAL_ENTIRE_OBJECT,  MakeRect ( 15,625, 40, 250));
	
}



//------------------------------------------------------------------------------------------------------------------- level 3 - blip jump to tier1

void limitmove2()  // level 3 - blip jump to tier1
{
	switch(move1)
	{
		case 0:
	     if(blip.movex<160 && blip.movex >-60 && blip.movey<=200)
	     {
			 Keys_Down[38] =1;
			 if((Keys_Down[39] || Keys_Down[37] || Keys_Down[38] || Keys_Down[40] ))
			 {
				 blip.movey = 200;
				 blip.movey = blip.movey +1;
			 }
	     }
		  if(blip.movex>160)
				Keys_Down[38] =0;
		 
		  
		  
		 if(blip.movex <950 && blip.movex>550 && blip.movey<=225)
		 {
			 Keys_Down[38] =1;
			 if((Keys_Down[39] || Keys_Down[37] || Keys_Down[38] || Keys_Down[40] ))
			 {
				 blip.movey = 225;
				 blip.movey = blip.movey +1;
			 }
		 }
		 if(blip.movex>950)
				Keys_Down[38] =0;
			break;
	
	}
}





 //---------------------------------------------------------LEVEL 2--------------------------------------------------------------------------------- 







void grenpaspwn(int i)
{
	grenpa[i].movey = 420;
	grenpa[i].movex = 1500 + rand()%(6000);
	grenpa[i].speed = 1+ rand()%3;
	grenpa[i].movexleft = -3000+rand()%(1500); 
}


void enemyredwalk(int i)
{
	 if (RectIntersection (MakeRect(bull[i].bullety, bull[i].bulletx, 20, 5), MakeRect (grenpa[i].movey, grenpa[i].movex, 46, 5), NULL) == 0)
	 {
	    grenpa[i].movex=grenpa[i].movex-grenpa[i].speed;
		CanvasDrawBitmap (panelHandle, PANEL_CANVAS, smurfsgranpaleft, MakeRect (0, (animation4*40), 48, 40), MakeRect(grenpa[i].movey-113,grenpa[i].movex, 150, 170));
		if(animation4>=2)
		  animation4=0;
	 }
	 
	 if (RectIntersection (MakeRect(bull[i].bullety, bull[i].bulletx, 20, 5), MakeRect (grenpa[i].movey, grenpa[i].movexleft, 46, 5), NULL) == 0)
	 {
		 grenpa[i].movexleft=grenpa[i].movexleft+grenpa[i].speed;
		 CanvasDrawBitmap (panelHandle, PANEL_CANVAS, smurfsgranparight, MakeRect (0, (animation4*40), 48, 40), MakeRect(grenpa[i].movey-113,grenpa[i].movexleft, 150, 170));
		 if(animation4>=2)
		  animation4=0;
	 }
	 

	
}


void hitbliplevel2(int i)
{
	if(flag45==0)
	{
	if ((RectIntersection (MakeRect(blip.movey, blip.movex, 20, 5), MakeRect (grenpa[i].movey, grenpa[i].movex, 46, 5), NULL) == 1)||(RectIntersection (MakeRect(blip.movey, blip.movex, 20, 5), MakeRect (grenpa[i].movey, grenpa[i].movexleft, 46, 5), NULL) == 1))
	{
		 CanvasDrawBitmap (panelHandle, PANEL_CANVAS, explosion1, VAL_ENTIRE_OBJECT, MakeRect (blip.movey, blip.movex, 45, 50));
		 BASS_ChannelPlay(boomenemy_SND,TRUE); 
		 injured++;
		 heart5=1;
		 if(injured==1)
		 {
			 heart4=1;
		 }
		 if(injured==2)
		 {
			heart3=1; 
		 }
		 if(injured==3)
		 {
			 heart2=1;
		 }
		 
	   }
	   SetCtrlVal (panelHandle, PANEL_INJURED, injured);
	 if(injured==4)
	 {
		 writeTable(); 
		 heart1=1;
		 BASS_ChannelPlay(sad_SND,TRUE);
		 CanvasDrawBitmap (panelHandle, PANEL_CANVAS, gameover, VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);
		 SetCtrlAttribute (panelHandle, PANEL_TIMER, ATTR_ENABLED, 0);
		 SetCtrlAttribute (panelHandle, PANEL_REGMAEMENU, ATTR_DIMMED,0 ); 
	 }
	}
	
}


void hitgrenpa(int i)
{
	for(int j=0;j<enemynum1;j++)
	{
	  if(bull[i].bulletx<950 && bull[i].bulletx>-15) 
	  {
	   if ((RectIntersection (MakeRect(bull[i].bullety, bull[i].bulletx, 65, 5), MakeRect (grenpa[j].movey, grenpa[j].movex, 65, 5), NULL) == 1) || (RectIntersection (MakeRect(bull[i].bullety, bull[i].bulletx-70, 65, 5), MakeRect (grenpa[j].movey, grenpa[j].movexleft, 65, 5), NULL) == 1))
	    {
		 BASS_ChannelPlay(boomenemy_SND,TRUE);
		 scorelevel2++;
		 score1++;
		 player[5].score12=score1;
		 grenpa[j].movey=-1000;
		 grenpa[j].movex=-1000;
		 grenpa[j].movexleft = 1000;
		 bull[i].bulletx=1500;
		 bull[i].bullety=-500;
	    }
	  }
	}
	
}


void updatelevel2()
{
	
	 if (RectIntersection (MakeRect(blip.movey, blip.movex, 20, 5), MakeRect (185, 100, 20, 5), NULL) == 1)
	 {
		 flag47=1;
	 }
		 
	
	
	if(scorelevel2>=30)		 // Condition to level 3
	{
		moveon=1;
		CanvasDrawBitmap (panelHandle, PANEL_CANVAS, opendoor, VAL_ENTIRE_OBJECT, MakeRect ( 355,810, 110, 110));
		if(blip.movex==810)
		{
			
			blip.movey=height-45;
	        blip.movex=left+10;
			
			lel1flag = 1;
			lel2flag = 1;
			lel3flag = 0;
			BASS_ChannelStop(level2new_SND);
			BASS_ChannelPlay(level3new_SND ,TRUE);

		}
		
	}
	
}


//------------------------------------------------------------------------------------------------------------------- draw3 

void draw3()
{
	CanvasStartBatchDraw (panelHandle, PANEL_CANVAS);
	CanvasClear (panelHandle, PANEL_CANVAS, VAL_ENTIRE_OBJECT);
	CanvasDrawBitmap (panelHandle, PANEL_CANVAS, background3, VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);
	if(flag1==0)	// flag1 look right
	CanvasDrawBitmap (panelHandle, PANEL_CANVAS, right_blip_pic, VAL_ENTIRE_OBJECT, MakeRect ( blip.movey,blip.movex, 40, 80));
	
	if(flag45==0 && flag48==0)
	CanvasDrawBitmap (panelHandle, PANEL_CANVAS, shield, VAL_ENTIRE_OBJECT, MakeRect (185, 100, 70, 70));
	
	if(Keys_Down[' ']==0)
		first=0;
	
	for(int i=0;i<=shotCounter;i++) // count the num of the blip shoting
	{
		BulletMove(i);
	}
	
	for(int i=0;i<40;i++)
		enemyredwalk(i);
	
	for(int i=0;i<40;i++)
	    hitbliplevel2(i);
	
	for(int i=0;i<100;i++)
	   hitgrenpa(i); 
	
	
	if(timer4%6==0)
		animation4++;
	timer4++;
	
	
	if(heart1==0)
	CanvasDrawBitmap (panelHandle, PANEL_CANVAS, health1, VAL_ENTIRE_OBJECT, MakeRect (50, 30, 50, 50));   // health1
	if(heart2==0) 
	CanvasDrawBitmap (panelHandle, PANEL_CANVAS, health2, VAL_ENTIRE_OBJECT, MakeRect ( 50,72, 50, 50));
	if(heart3==0) 
	CanvasDrawBitmap (panelHandle, PANEL_CANVAS, health3, VAL_ENTIRE_OBJECT, MakeRect ( 50,112, 50, 50));
	if(heart4==0)    
	CanvasDrawBitmap (panelHandle, PANEL_CANVAS, health4, VAL_ENTIRE_OBJECT, MakeRect ( 50,154, 50, 50));
	if(heart5==0) 
	CanvasDrawBitmap (panelHandle, PANEL_CANVAS, health5, VAL_ENTIRE_OBJECT, MakeRect ( 50,196, 50, 50));
	if(moveon==0)
	CanvasDrawBitmap (panelHandle, PANEL_CANVAS, closedoor, VAL_ENTIRE_OBJECT, MakeRect ( 360,830, 100, 70));
	
	
	
	if(flag47==1)
	{
		 flag45=1;
		 timezone1=time5*0.02;
		 time5++;
		 if(time5>=800)
		 {
			 flag46=1;
			 flag45=0;
			 flag48=1;
		 }
	}
	if (flag46==0 && flag47==1)
	{
	  CanvasDrawBitmap (panelHandle, PANEL_CANVAS, shield, VAL_ENTIRE_OBJECT, MakeRect (45, 243, 50, 50));		//UP SHILED ICON
	}
	

	CanvasEndBatchDraw (panelHandle, PANEL_CANVAS); 
	
}



//-------------------------------------------------------  Main Timer  --------------------------------------------------- 


int CVICALLBACK TimerFunc (int panel, int control, int event,
						   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_TIMER_TICK:
			
		if(lel1flag==0)	   // level 1
		{
	
		  draw();
		  shooting();
		  BASS_ChannelStop(startmusic_SND);
		  timerjumpblip(); 
		  updategame(); 
		  hitgeneral();
		  limitmove(); 
		  move(); 
		  time1++;
		  time2++;
		  score();
		  stepicure();
		  /*
		  updatescoreboard();
		  */
		
		}
		
		
		if(lel2flag==1 && lel1flag==1)   // level 3
		{
			
			if(flag23==0)
			{
			  gargamel.catx=-100;
			  gargamel.catxleft=1000;
			  gargamel.caty=361;
				
				flag23=1;
			}
			
			if(flag21==0)
			{
			  flag56=0;
			  flagbull=0;
		      gargamel.movex = 500;
              gargamel.movey = 400;
			  for(int i=0;i<10;i++)
	          {
	            bullg[i].bully = 420;
	            bullg[i].bullx2 = 400;

	          }
	          SetCtrlVal (panelHandle, PANEL_KILLED, score1);
			  flag21=1;  
			}
	
		   draw2();
		   shooting();
		   timerjumpblip();
		   move();
		   limitmove2();
		   gargamelmove();
		   score();
		   canvas();
		   
		   
		  for(i=0;i<200;i++)
		   heatgargamel(i);
			if(flagb==0)
			{
			  BASS_ChannelPlay(gargamel_SND,TRUE);
			  flagb=1;
			}
			 /*
		  updatescoreboard();
		  */ 
		}
		
		if(lel3flag==1) // level 2
		{
			draw3();
			shooting();
			timerjumpblip();
			move();
			score();
			limitmove2();
			level2staff();
			updatelevel2();
			 /*
		  updatescoreboard();
		  */ 
			

		}
	
		
		timezone=time3*0.02;
		time3++;
		time4++;
		SetCtrlVal (panelHandle, PANEL_GAMETIME, time3*0.02);

		
			break;
	}
	return 0;
}






int CVICALLBACK MenuPanel (int panel, int event, void *callbackData,
					   int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			 QuitUserInterface(0);
			break;
	}
	return 0;
}



int CVICALLBACK StartFunc (int panel, int control, int event,
						   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
		 
		 DisplayPanel (panelHandle);
		 SetCtrlAttribute (panelHandle, PANEL_TIMER, ATTR_ENABLED, 1);
		 HidePanel (panelHandle2);
		 BASS_ChannelPlay(stage1_SND,TRUE);
		 if(BASS_ChannelPlay(round1_SND,TRUE)==0)
		 BASS_ChannelPlay(stage1_SND,TRUE);
			break;
	}
	return 0;
}

int CVICALLBACK Timer3 (int panel, int control, int event,
						void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_TIMER_TICK:
		BASS_ChannelPlay(startmusic_SND,TRUE);
		
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a1 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);
		Delay (0.2);
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a2 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);
		 Delay (0.2); 
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a3 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);
		Delay (0.2); 
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a4 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);
		 Delay (0.2); 
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a5 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);
		Delay (0.2); 
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a6 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);
		Delay (0.2); 
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a7 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);
		Delay (0.2); 
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a8 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);
		Delay (0.2);  
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a9 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);
		Delay (0.2); 
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a10 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);
		Delay (0.2); 
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a11 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);
		Delay (0.2); 
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a12 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);
		Delay (0.2);  
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a13 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);
		Delay (0.2); 
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a14 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);
		Delay (0.2); 
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a15,  VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);
		Delay (0.2); 
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a16 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);
		Delay (0.2); 
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a17 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);
		Delay (0.2); 
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a18 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);
		Delay (0.2); 
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a19 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);
		Delay (0.2); 
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a20 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);
		Delay (0.2); 
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a21 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);
		Delay (0.2); 
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a22 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT); 
		Delay (0.2);
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a23 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT); 
		Delay (0.2);
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a24 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT); 
		Delay (0.2);
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a25 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT); 
		Delay (0.2);
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a26 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT); 
		Delay (0.2);
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a27 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT); 
		Delay (0.2);
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a28 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT); 
		Delay (0.2);
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a29 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT); 
		Delay (0.2);
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a30 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT); 
		Delay (0.2);
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a31 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT); 
		Delay (0.2);
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a32 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT); 
		 Delay (0.2);
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a33 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT); 
		Delay (0.2);
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a34 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT); 
		 Delay (0.2);
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a35 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT); 
		 Delay (0.2);
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a36 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT); 
		Delay (0.2);
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a37 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT); 
		Delay (0.2);
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a38 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);
		Delay (0.2);
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a38 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);   
		 Delay (0.2);
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a39 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);   
		 Delay (0.2);
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a40 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);   
		Delay (0.2);
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a41 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);   
		 Delay (0.2);
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a42 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);   
		Delay (0.2);
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a43 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);   
		Delay (0.2);
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a44 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);   
		Delay (0.2);
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a45 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);
		 Delay (0.2);
		CanvasDrawBitmap (panelHandle3, PANEL_3_CANVAS,a46 , VAL_ENTIRE_OBJECT, VAL_ENTIRE_OBJECT);
		
		SetCtrlAttribute (panelHandle3, PANEL_3_TIMER, ATTR_ENABLED, 0);
		HidePanel (panelHandle3);
		HidePanel (panelHandle2);
		DisplayPanel (panelHandle7); 
			break;
	}
	return 0;
}

int CVICALLBACK PanelPatiha (int panel, int event, void *callbackData,
							 int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
		   QuitUserInterface(0);
			break;
	}
	return 0;
}

int CVICALLBACK AboutFunc (int panel, int control, int event,
						   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			DisplayPanel (panelHandle4);
			break;
	}
	return 0;
}

int CVICALLBACK AboutFuncion (int panel, int event, void *callbackData,
							  int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			 HidePanel (panelHandle4);
			break;
	}
	return 0;
}

int CVICALLBACK KeysFunc (int panel, int control, int event,
						  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
		 DisplayPanel (panelHandle5);
			break;
	}
	return 0;
}

int CVICALLBACK PanelHowToPlay (int panel, int event, void *callbackData,
								int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			HidePanel (panelHandle5);
			break;
	}
	return 0;
}

int CVICALLBACK ExitButton (int panel, int control, int event,
							void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
		  QuitUserInterface (0);
			break;
	}
	return 0;
}


void CVICALLBACK aboutFunc (int menuBar, int menuItem, void *callbackData,
							   int panel_2)
{
	DisplayPanel (panelHandle4);
	
}

int CVICALLBACK RecordsFunc (int panel, int control, int event,
							 void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			 DisplayPanel (panelHandle6);
			break;
	}
	return 0;
}

int CVICALLBACK Panel6Func (int panel, int event, void *callbackData,
							int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			HidePanel (panelHandle6);  
			break;
	}
	return 0;
}

int CVICALLBACK PanelName (int panel, int event, void *callbackData,
						   int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
		 	HidePanel (panelHandle7);  
			break;
	}
	return 0;
}

int CVICALLBACK SubmitFunc (int panel, int control, int event,
							void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
		   GetCtrlVal (panelHandle7, PANEL_7_STRING, val);
		   if(strlen(val)>1)
		   {
		   DisplayPanel (panelHandle2); 
		   HidePanel (panelHandle7);
		   }
			break;
	}
	return 0;
}

int CVICALLBACK ReGame (int panel, int control, int event,
						void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

		 picturs();
	     init();
	     soundgame();
		 lel1flag=0;
		 lel2flag=0;
		 lel3flag=0; 
		 HidePanel (panelHandle); 
		 DisplayPanel (panelHandle2);
			break;
	}
	return 0;
}

int CVICALLBACK volume (int panel, int control, int event,
						void *callbackData, int eventData1, int eventData2)
{
	float vol;
	switch (event)
	{
		case EVENT_COMMIT:
		  GetCtrlVal (panelHandle, control, &vol);
		  BASS_SetVolume(vol);
			break;
	}
	return 0;
}

int CVICALLBACK HelpFunc (int panel, int control, int event,
						  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			OpenDocumentInDefaultViewer ("help.pdf", VAL_NO_ZOOM);

			break;
	}
	return 0;
}

int CVICALLBACK DemoFunc (int panel, int control, int event,
						  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
		  OpenDocumentInDefaultViewer ("video.mp4", VAL_NO_ZOOM);
			break;
	}
	return 0;
}
