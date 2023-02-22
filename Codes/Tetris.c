//Halime Özge KABAK
//180403001
//EEE316-TETRIS GAME
//19.05.2022


#include "__T6963C.h"
#include <stdio.h>
#include  <stdlib.h>
#include "image.h"

// T6963C module connections
char T6963C_DataPort at PORTD;                   // DATA port

sbit T6963C_Ctrlwr  at RA2_bit;                  // WR write signal
sbit T6963C_Ctrlrd  at RA1_bit;                  // RD read signal
sbit T6963C_Ctrlcd  at RA0_bit;                  // CD command/data signal
sbit T6963C_Ctrlrst at RA4_bit;                  // RST reset signal
sbit T6963C_Ctrlwr_Direction  at TRISA2_bit;     // WR write signal
sbit T6963C_Ctrlrd_Direction  at TRISA1_bit;     // RD read signal
sbit T6963C_Ctrlcd_Direction  at TRISA0_bit;     // CD command/data signal
sbit T6963C_Ctrlrst_Direction at TRISA4_bit;     // RST reset signal

// Signals not used by library, they are set in main function
sbit T6963C_Ctrlce at RA3_bit;                   // CE signal
sbit T6963C_Ctrlfs at RA6_bit;                   // FS signal
sbit T6963C_Ctrlmd at RA5_bit;                   // MD signal
sbit T6963C_Ctrlce_Direction  at TRISA3_bit;     // CE signal direction
sbit T6963C_Ctrlfs_Direction  at TRISA6_bit;     // FS signal direction
sbit T6963C_Ctrlmd_Direction  at TRISA5_bit;     // MD signal direction


char GLCD_DataPort at PORTH;

sbit GLCD_CS1 at LATF6_bit;
sbit GLCD_CS2 at LATF1_bit;
sbit GLCD_RS  at LATF2_bit;
sbit GLCD_RW  at LATF3_bit;
sbit GLCD_EN  at LATF4_bit;
sbit GLCD_RST at LATF5_bit;

sbit GLCD_CS1_Direction at TRISF6_bit;
sbit GLCD_CS2_Direction at TRISF1_bit;
sbit GLCD_RS_Direction  at TRISF2_bit;
sbit GLCD_RW_Direction  at TRISF3_bit;
sbit GLCD_EN_Direction  at TRISF4_bit;
sbit GLCD_RST_Direction at TRISF5_bit;



//===================== LCD SCREEN =================
sbit LCD_RS at RC2_bit;
sbit LCD_EN at RC3_bit;
sbit LCD_D4 at RC4_bit;
sbit LCD_D5 at RC5_bit;
//sbit LCD_D6 at RC6_bit;
//sbit LCD_D7 at RC7_bit;
sbit LCD_D6 at RE5_bit;
sbit LCD_D7 at RE6_bit;

sbit LCD_RS_Direction at TRISC2_bit;
sbit LCD_EN_Direction at TRISC3_bit;
sbit LCD_D4_Direction at TRISC4_bit;
sbit LCD_D5_Direction at TRISC5_bit;
sbit LCD_D6_Direction at TRISE5_bit;
sbit LCD_D7_Direction at TRISE6_bit;

unsigned char blocks,locx,locy,num,asd,lcdx[240]={0},lcdy[128][14],image=0,i,j,x,y,v=10,abc,first=0,sa=0,sa2=0,abc2,abc3,sa3,zw,array[200],next,score=0,best=0,lines=0,bt;
unsigned int weight,h,deneme=0,time,cnt=0,des,next1,sad[100]={3,1,1,6,5,2,6,5,5,2,4,2,6,5,2,6,1,2,4,5};
char scoreText[] = "Score";
char bestText[]  = "Best";
char linetext[]="|Line|";
char gameScore[7];
char bestScore[7];
char lineScore[7];
int array_begin(){
while(1){
  for(i=0;i<100;i++)
      {
      array[i]=rand()%7;
      }


return 0;
}
}
int selectblock(){
 while(1)
 {

      v=16;

    switch(array[deneme]){
     case 1:
     locx=192;
     locy=32;
     weight=58;
     h=42;
        T6963C_sprite(locx, locy, Sblock, 48, 32);
        image=1;
         asd++;

        break;
     case 2:
     locx=160;
     locy=32;
     weight=74;
     h=26;
       T6963C_sprite(locx, locy, Iblock, 64, 16);
        image=2;

        asd++;
       break;
     case 3:
      locx=176;
     locy=32;
     weight=58;
     h=42;
      T6963C_sprite(locx,locy, Tblock, 48, 32);
      image=3;
       asd=asd+1;

      break;
     case 4:
      locx=176;
     locy=32;
      weight=58;
     h=42;
      T6963C_sprite(locx,locy, Zblock, 48, 32);
       image=4;
       asd++;

      break;
     case 5:

     locx=192;
     locy=32;
      weight=42;
     h=42;
      T6963C_sprite(locx, locy, Oblock, 32, 32);
       image=5;
       asd++;

      break;
     case 6:
      locx=192;
     locy=32;
      weight=42;
     h=58;
      T6963C_sprite(locx,locy, Lblock, 32, 48);
       image=6;
       asd++;

      break;
     case 7:
      locx=192;
     locy=32;
      weight=42;
     h=58;
      T6963C_sprite(locx,locy, Jblock, 32, 48);
       image=7;
       asd++;

      break;



    }

    return 0;
 }
}

int drawblock(){
   while(1){
    switch(image){
     case 1:
        T6963C_sprite(locx, locy, Sblock, 48, 32);

        break;
     case 2:
       T6963C_sprite(locx, locy, Iblock, 64, 16);
       break;
     case 3:
      T6963C_sprite(locx,locy, Tblock, 48, 32);
      break;
     case 4:
      T6963C_sprite(locx,locy, Zblock, 48, 32);
      break;
     case 5:
      T6963C_sprite(locx, locy, Oblock, 32, 32);
      break;
     case 6:
      T6963C_sprite(locx,locy, Lblock, 32, 48);
      break;
     case 7:
      T6963C_sprite(locx,locy, Jblock, 32, 48);
      break;
      case 10:
      T6963C_sprite(locx, locy, Sblockturn, 32, 48);
      break;
      case 20:
      T6963C_sprite(locx,locy, Iblockturn, 16, 64);
      break;
      case 30:
      T6963C_sprite(locx,locy, Tblockturn1, 32, 48);
      break;
      case 31:
      T6963C_sprite(locx,locy, Tblockturn2, 48, 32);
      break;
      case 32:
      T6963C_sprite(locx,locy, Tblockturn3, 32, 48);
      break;
      case 40:
      T6963C_sprite(locx, locy, Zblockturn, 32, 48);
      break;
       case 60:
      T6963C_sprite(locx,locy, Lblockturn1, 48,32);
      break;
       case 61:
      T6963C_sprite(locx,locy, Lblockturn2, 32, 48);
      break;
       case 62:
      T6963C_sprite(locx,locy, Lblockturn3, 48, 32);
      break;
      case 70:
      T6963C_sprite(locx,locy, Jblockturn1, 48, 32);
      break;
      case 71:
      T6963C_sprite(locx,locy, Jblockturn2, 32, 48);
      break;
      case 72:
      T6963C_sprite(locx,locy, Jblockturn3, 48, 32);
      break;
    }

    return 0;
  }
  }

 void clean(){

        T6963C_sprite(locx, locy, clear, weight, h);
        }



int turn()
{
 while(1){
    switch(image){
     case 1:
        image=10;
        weight=42;
        h=58;
        break;
     case 2:
       image=20;
       weight=26;
       h=74;
       break;
     case 3:
       image=30;
     weight=42;
     h=58;
      break;
     case 4:
      image=40;
      weight=42;
      h=58;
      break;
     case 5:

      break;
     case 6:
      image=60;
     weight=58;
     h=42;
      break;
     case 7:
     image=70;
     weight=58;
     h=42;
      break;
      case 10:
      image=1;
       weight=58;
        h=42;
        break;
      case 20:
      image=2;
      weight=74;
      h=26;
      break;
      case 30:
      image=31;
       weight=58;
     h=42;
      break;
      case 31:
       image=32;
       weight=42;
       h=58;
      break;
      case 32:
       image=3;
         weight=58;
     h=42;
      break;
      case 40:
      image=4;
      weight=58;
      h=42;
      break;
      case 60:
      image=61;
      weight=42;
      h=58;
      break;
      case 61:
      image=62;
      weight=58;
      h=42;
      break;
      case 62:
      image=6;
      weight=42;
      h=58;
      case 70:
     image=71;
     weight=42;
     h=58;
      break;
      case 71:
     image=72;
     weight=58;
     h=42;
      break;
      case 72:
     image=7;
     weight=42;
     h=58;
      break;
    }

    return 0;
  }
}
int Oblock_location(){
  while(1){
  if(first==1)
   {
    for(i=0;i<weight-10;i++)
    {
   lcdx[i]=1;
    }
    switch(sa2)
   {
   case 0:
   for(i=0;i<32;i++)
   {
   lcdy[i][0]=1;
   lcdy[i][1]=1;
   }
   break;
   case 1:
   for(i=16;i<48;i++)
   {
   lcdy[i][0]=1;
   lcdy[i][1]=1;
   }
   break;
   case 2:
   for(i=32;i<64;i++)
   {
   lcdy[i][0]=1;
   lcdy[i][1]=1;
   }
   break;
   case 3:
   for(i=48;i<80;i++)
   {
   lcdy[i][0]=1;
   lcdy[i][1]=1;
   }
   break;
   case 4:
   for(i=64;i<96;i++)
   {
   lcdy[i][0]=1;
   lcdy[i][1]=1;
   }
   break;
   case 5:
   for(i=80;i<112;i++)
   {
   lcdy[i][0]=1;
   lcdy[i][1]=1;
   }
   break;
   case 6:
   for(i=96;i<128;i++)
   {
   lcdy[i][0]=1;
   lcdy[i][1]=1;
   }
   break;
    }
   }

    if(abc==1)
   {
   switch(sa)
   { case 1:

      for(i=32;i<64;i++)
      {
      lcdx[i]=1;
      }
     switch(sa2)
   {
   case 0:
   for(i=0;i<32;i++)
   {
   lcdy[i][2]=1;
   lcdy[i][1]=1;
   }
   break;
   case 1:
   for(i=16;i<48;i++)
   {
   lcdy[i][2]=1;
   lcdy[i][1]=1;
   }
   break;
   case 2:
   for(i=32;i<64;i++)
   {
   lcdy[i][2]=1;
   lcdy[i][1]=1;
   }
   break;
   case 3:
   for(i=48;i<80;i++)
   {
   lcdy[i][2]=1;
   lcdy[i][1]=1;
   }
   break;
   case 4:
   for(i=64;i<96;i++)
   {
   lcdy[i][2]=1;
   lcdy[i][1]=1;
   }
   break;
   case 5:
   for(i=80;i<112;i++)
   {
   lcdy[i][2]=1;
   lcdy[i][1]=1;
   }
   break;
   case 6:
   for(i=96;i<128;i++)
   {
   lcdy[i][2]=1;
   lcdy[i][1]=1;
   }
   break;
    }
   break;
   case 2:

      for(i=32;i<64;i++)
      {
      lcdx[i]=1;
      }
           switch(sa2)
   {
   case 0:
   for(i=0;i<32;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][2]=1;
   }
   break;
   case 1:
   for(i=16;i<48;i++)
   {
  lcdy[i][3]=1;
   lcdy[i][2]=1;
   }
   break;
   case 2:
   for(i=32;i<64;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][2]=1;
   }
   break;
   case 3:
   for(i=48;i<80;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][2]=1;
   }
   break;
   case 4:
   for(i=64;i<96;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][2]=1;
   }
   break;
   case 5:
   for(i=80;i<112;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][2]=1;
   }
   break;
   case 6:
   for(i=96;i<128;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][2]=1;
   }
   break;
    }
    break;
    case 3:

      for(i=48;i<80;i++)
      {
      lcdx[i]=1;
      }
                   switch(sa2)
   {
   case 0:
   for(i=0;i<32;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][4]=1;
   }
   break;
   case 1:
   for(i=16;i<48;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][4]=1;
   }
   break;
   case 2:
   for(i=32;i<64;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][4]=1;
   }
   break;

   case 4:
   for(i=64;i<96;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][4]=1;
   }
   break;
   case 6:
   for(i=96;i<128;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][4]=1;
   }
   break;
    }
    break;
   case 4:

      for(i=64;i<96;i++)
      {
      lcdx[i]=1;
      }
                   switch(sa2)
   {
   case 0:
   for(i=0;i<32;i++)
   {
   lcdy[i][5]=1;
   lcdy[i][4]=1;
   }
   break;
   case 2:
   for(i=32;i<64;i++)
   {
   lcdy[i][5]=1;
   lcdy[i][4]=1;
   }
   break;
   case 4:
   for(i=64;i<96;i++)
   {
  lcdy[i][5]=1;
   lcdy[i][4]=1;
   }
   break;
   case 6:
   for(i=96;i<128;i++)
   {
   lcdy[i][5]=1;
   lcdy[i][4]=1;
   }
   break;
    }
    break;
     case 6:

      for(i=96;i<128;i++)
      {
      lcdx[i]=1;
      }
                   switch(sa2)
   {
   case 0:
   for(i=0;i<32;i++)
   {
   lcdy[i][7]=1;
   lcdy[i][6]=1;
   }
   break;
   case 2:
   for(i=32;i<64;i++)
   {
   lcdy[i][7]=1;
   lcdy[i][6]=1;
   }
   break;
   case 4:
   for(i=64;i<96;i++)
   {
  lcdy[i][7]=1;
   lcdy[i][6]=1;
   }
   break;
   case 6:
   for(i=96;i<128;i++)
   {
  lcdy[i][7]=1;
   lcdy[i][6]=1;
   }
   break;
    }
    break;
     case 7:

      for(i=128;i<160;i++)
      {
      lcdx[i]=1;
      }
                   switch(sa2)
   {
   case 0:
   for(i=0;i<32;i++)
   {
   lcdy[i][7]=1;
   lcdy[i][8]=1;
   }
   break;
   case 2:
   for(i=32;i<64;i++)
   {
   lcdy[i][7]=1;
   lcdy[i][8]=1;
   }
   break;
   case 4:
   for(i=64;i<96;i++)
   {
  lcdy[i][7]=1;
   lcdy[i][8]=1;
   }
   break;
   case 6:
   for(i=96;i<128;i++)
   {
  lcdy[i][7]=1;
   lcdy[i][8]=1;
   }
   break;
    }
    break;
     case 8:

      for(i=160;i<192;i++)
      {
      lcdx[i]=1;
      }
                   switch(sa2)
   {
   case 0:
   for(i=0;i<32;i++)
   {
   lcdy[i][9]=1;
   lcdy[i][8]=1;
   }
   break;
   case 2:
   for(i=32;i<64;i++)
   {
   lcdy[i][9]=1;
   lcdy[i][8]=1;
   }
   break;
   case 4:
   for(i=64;i<96;i++)
   {
  lcdy[i][8]=1;
   lcdy[i][9]=1;
   }
   break;
   case 6:
   for(i=96;i<128;i++)
   {
  lcdy[i][9]=1;
   lcdy[i][8]=1;
   }
   break;
    }
    break;
   }
    }
  return 0;
  }
}

int Sblock_control(){
  while(1){
  //sa3=(locx)/16;
  if(locx<=5)
     {
    v=0;
    first=1;
     sa2=locy/16;
    }
    if(((lcdx[locx-1]==1) && (lcdy[locy+16][sa3]==1)) || ((lcdx[locx-1]==1) && (lcdy[locy][sa3+1]==1)) )
    {
    v=0;
    abc=1;
    abc2=1;
    sa2=locy/16;
    sa=locx/16;

     }
   return 0;
   }
}

int Iblock_control(){
  while(1){
  //sa3=(locx)/16;
  if(locx<=5)
     {
    v=0;
    first=1;
     sa2=locy/16;
    }
    if((lcdx[locx-1]==1) && (lcdy[locy][sa3]==1) )
    {
    v=0;
    abc=1;
    abc2=1;
    sa2=locy/16;
    sa=locx/16;

     }
   return 0;
   }
}
int Iblock_location(){
  while(1){
  if(first==1)
   {
    for(i=0;i<weight-10;i++)
    {
   lcdx[i]=1;
    }
    switch(sa2)
   {
   case 0:
   for(i=0;i<h-10;i++)
   {
   lcdy[i][0]=1;
   lcdy[i][1]=1;
   lcdy[i][2]=1;
   lcdy[i][3]=1;
   }
   break;
   case 1:
   for(i=16;i<h+6;i++)
   {
   lcdy[i][0]=1;
   lcdy[i][1]=1;
   lcdy[i][2]=1;
   lcdy[i][3]=1;
   }
   break;
   case 2:
   for(i=32;i<h+22;i++)
   {
   lcdy[i][0]=1;
   lcdy[i][1]=1;
   lcdy[i][2]=1;
   lcdy[i][3]=1;
   }
   break;
   case 3:
   for(i=48;i<h+38;i++)
   {
   lcdy[i][0]=1;
   lcdy[i][1]=1;
   lcdy[i][2]=1;
   lcdy[i][3]=1;
   }
   break;
   case 4:
   for(i=64;i<h+54;i++)
   {
   lcdy[i][0]=1;
   lcdy[i][1]=1;
   lcdy[i][2]=1;
   lcdy[i][3]=1;
   }
   break;
   case 5:
   for(i=80;i<h+70;i++)
   {
   lcdy[i][0]=1;
   lcdy[i][1]=1;
   lcdy[i][2]=1;
   lcdy[i][3]=1;
   }
   break;
   case 6:
   for(i=96;i<h+86;i++)
   {
   lcdy[i][0]=1;
   lcdy[i][1]=1;
   lcdy[i][2]=1;
   lcdy[i][3]=1;
   }
   break;
    case 7:
   for(i=112;i<h+102;i++)
   {
   lcdy[i][0]=1;
   lcdy[i][1]=1;
   lcdy[i][2]=1;
   lcdy[i][3]=1;
   }
   break;
    }
   }

    if(abc==1)
   {
   switch(sa)
   { case 1:

      for(i=16;i<6+weight;i++)
      {
      lcdx[i]=1;
      }
   switch(sa2)
   {
   case 0:
   for(i=0;i<h-10;i++)
   {
   lcdy[i][1]=1;
   lcdy[i][4]=1;
   lcdy[i][2]=1;
   lcdy[i][3]=1;
   }
   break;
   case 1:
   for(i=16;i<h+6;i++)
   {
   lcdy[i][1]=1;
   lcdy[i][4]=1;
   lcdy[i][2]=1;
   lcdy[i][3]=1;
   }
   break;
   case 2:
   for(i=32;i<h+22;i++)
   {
   lcdy[i][1]=1;
   lcdy[i][4]=1;
   lcdy[i][2]=1;
   lcdy[i][3]=1;
   }
   break;
   case 3:
   for(i=48;i<h+38;i++)
   {
   lcdy[i][1]=1;
   lcdy[i][4]=1;
   lcdy[i][2]=1;
   lcdy[i][3]=1;
   }
   break;
   case 4:
   for(i=64;i<h+54;i++)
   {
   lcdy[i][1]=1;
   lcdy[i][4]=1;
   lcdy[i][2]=1;
   lcdy[i][3]=1;
   }
   break;
   case 5:
   for(i=80;i<h+70;i++)
   {
   lcdy[i][1]=1;
   lcdy[i][4]=1;
   lcdy[i][2]=1;
   lcdy[i][3]=1;
   }
   break;
   case 6:
   for(i=96;i<h+86;i++)
   {
   lcdy[i][1]=1;
    lcdy[i][4]=1;
   lcdy[i][2]=1;
   lcdy[i][3]=1;
   }
   break;
    case 7:
   for(i=112;i<h+102;i++)
   {
   lcdy[i][1]=1;
    lcdy[i][4]=1;
   lcdy[i][2]=1;
   lcdy[i][3]=1;
   }
   break;
    }
   break;
   case 2:

      for(i=32;i<22+weight;i++)
      {
      lcdx[i]=1;
      }
        switch(sa2)
   {
   case 0:
   for(i=0;i<h-10;i++)
   {
   lcdy[i][2]=1;
   lcdy[i][4]=1;
   lcdy[i][5]=1;
   lcdy[i][3]=1;
   }
   break;
   case 1:
   for(i=16;i<h+6;i++)
   {
   lcdy[i][2]=1;
    lcdy[i][4]=1;
   lcdy[i][5]=1;
   lcdy[i][3]=1;
   }
   break;
   case 2:
   for(i=32;i<h+22;i++)
   {
   lcdy[i][2]=1;
   lcdy[i][4]=1;
   lcdy[i][5]=1;
   lcdy[i][3]=1;
   }
   break;
   case 3:
   for(i=48;i<h+38;i++)
   {
   lcdy[i][2]=1;
   lcdy[i][4]=1;
   lcdy[i][5]=1;
   lcdy[i][3]=1;
   }
   break;
   case 4:
   for(i=64;i<h+54;i++)
   {
   lcdy[i][2]=1;
   lcdy[i][4]=1;
   lcdy[i][5]=1;
   lcdy[i][3]=1;
   }
   break;
   case 5:
   for(i=80;i<h+70;i++)
   {
   lcdy[i][2]=1;
   lcdy[i][4]=1;
   lcdy[i][5]=1;
   lcdy[i][3]=1;
   }
   break;
   case 6:
   for(i=96;i<h+86;i++)
   {
   lcdy[i][2]=1;
   lcdy[i][4]=1;
   lcdy[i][5]=1;
   lcdy[i][3]=1;
   }
   break;
    case 7:
   for(i=112;i<h+102;i++)
   {
   lcdy[i][2]=1;
   lcdy[i][4]=1;
   lcdy[i][5]=1;
   lcdy[i][3]=1;
   }
   break;
    }
    break;
    case 3:

      for(i=48;i<38+weight;i++)
      {
      lcdx[i]=1;
      }
    switch(sa2)
   {
   case 0:
   for(i=0;i<h-10;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][4]=1;
   lcdy[i][5]=1;
   lcdy[i][6]=1;

   }
   break;
   case 1:
   for(i=16;i<h+6;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][4]=1;
   lcdy[i][5]=1;
   lcdy[i][6]=1;

   }
   break;
   case 2:
   for(i=32;i<h+22;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][4]=1;
   lcdy[i][5]=1;
   lcdy[i][6]=1;

   }
   break;
   case 3:
   for(i=48;i<h+38;i++)
   {
   lcdy[i][3]=1;
    lcdy[i][4]=1;
   lcdy[i][5]=1;
   lcdy[i][6]=1;
   }
   break;
   case 4:
   for(i=64;i<h+54;i++)
   {
   lcdy[i][3]=1;
    lcdy[i][4]=1;
   lcdy[i][5]=1;
   lcdy[i][6]=1;

   }
   break;
   case 5:
   for(i=80;i<h+70;i++)
   {
   lcdy[i][3]=1;
    lcdy[i][4]=1;
   lcdy[i][5]=1;
   lcdy[i][6]=1;

   }
   break;
   case 6:
   for(i=96;i<h+86;i++)
   {
   lcdy[i][3]=1;
    lcdy[i][4]=1;
   lcdy[i][5]=1;
   lcdy[i][6]=1;

   }
   break;
    case 7:
   for(i=112;i<h+102;i++)
   {
   lcdy[i][3]=1;
    lcdy[i][4]=1;
   lcdy[i][5]=1;
   lcdy[i][6]=1;

   }
   break;
    }
    break;
   case 4:
   for(i=64;i<=54+weight;i++)
   {
   lcdx[i]=1;
   }
     switch(sa2)
   {
   case 0:
   for(i=0;i<h-10;i++)
   {
   lcdy[i][4]=1;
    lcdy[i][7]=1;
   lcdy[i][5]=1;
   lcdy[i][6]=1;
   }
   break;
   case 1:
   for(i=16;i<h+6;i++)
   {
   lcdy[i][4]=1;
    lcdy[i][7]=1;
   lcdy[i][5]=1;
   lcdy[i][6]=1;
   }
   break;
   case 2:
   for(i=32;i<h+22;i++)
   {
   lcdy[i][4]=1;
    lcdy[i][7]=1;
   lcdy[i][5]=1;
   lcdy[i][6]=1;
   }
   break;
   case 3:
   for(i=48;i<h+38;i++)
   {
   lcdy[i][4]=1;
    lcdy[i][7]=1;
   lcdy[i][5]=1;
   lcdy[i][6]=1;
   }
   break;
   case 4:
   for(i=64;i<h+54;i++)
   {
   lcdy[i][4]=1;
    lcdy[i][7]=1;
   lcdy[i][5]=1;
   lcdy[i][6]=1;
   }
   break;
   case 5:
   for(i=80;i<h+70;i++)
   {
   lcdy[i][4]=1;
    lcdy[i][7]=1;
   lcdy[i][5]=1;
   lcdy[i][6]=1;
   }
   break;
   case 6:
   for(i=96;i<h+86;i++)
   {
   lcdy[i][4]=1;
    lcdy[i][7]=1;
   lcdy[i][5]=1;
   lcdy[i][6]=1;
   }
   break;
    case 7:
   for(i=112;i<h+102;i++)
   {
   lcdy[i][4]=1;
    lcdy[i][7]=1;
   lcdy[i][5]=1;
   lcdy[i][6]=1;
   }
   break;
    }
   break;

    case 5:
   for(i=80;i<=70+weight;i++)
   {
   lcdx[i]=1;
   }
    switch(sa2)
   {
   case 0:
   for(i=0;i<h-10;i++)
   {
   lcdy[i][5]=1;
    lcdy[i][7]=1;
   lcdy[i][8]=1;
   lcdy[i][6]=1;

   }
   break;
   case 1:
   for(i=16;i<h+6;i++)
   {
   lcdy[i][5]=1;
    lcdy[i][7]=1;
   lcdy[i][8]=1;
   lcdy[i][6]=1;
   }
   break;
   case 2:
   for(i=32;i<h+22;i++)
   {
   lcdy[i][5]=1;
    lcdy[i][7]=1;
   lcdy[i][8]=1;
   lcdy[i][6]=1;
   }
   break;
   case 3:
   for(i=48;i<h+38;i++)
   {
   lcdy[i][5]=1;
   lcdy[i][7]=1;
   lcdy[i][8]=1;
   lcdy[i][6]=1;
   }
   break;
   case 4:
   for(i=64;i<h+54;i++)
   {
   lcdy[i][5]=1;
   lcdy[i][7]=1;
   lcdy[i][8]=1;
   lcdy[i][6]=1;
   }
   break;
   case 5:
   for(i=80;i<h+70;i++)
   {
   lcdy[i][5]=1;
   lcdy[i][7]=1;
   lcdy[i][8]=1;
   lcdy[i][6]=1;
   }
   break;
   case 6:
   for(i=96;i<h+86;i++)
   {
   lcdy[i][5]=1;
   lcdy[i][7]=1;
   lcdy[i][8]=1;
   lcdy[i][6]=1;
   }
   break;
    case 7:
   for(i=112;i<h+102;i++)
   {
   lcdy[i][5]=1;
   lcdy[i][7]=1;
   lcdy[i][8]=1;
   lcdy[i][6]=1;
   }
   break;
    }
   break;
   case 6:
   for(i=96;i<=86+weight;i++)
   {
   lcdx[i]=1;
   }
       switch(sa2)
   {
   case 0:
   for(i=0;i<h-10;i++)
   {
   lcdy[i][6]=1;
   lcdy[i][7]=1;
   lcdy[i][8]=1;
   lcdy[i][9]=1;
   }
   break;
   case 1:
   for(i=16;i<h+6;i++)
   {
   lcdy[i][6]=1;
    lcdy[i][7]=1;
   lcdy[i][8]=1;
   lcdy[i][9]=1;
   }
   break;
   case 2:
   for(i=32;i<h+22;i++)
   {
   lcdy[i][6]=1;
    lcdy[i][7]=1;
   lcdy[i][8]=1;
   lcdy[i][9]=1;
   }
   break;
   case 3:
   for(i=48;i<h+38;i++)
   {
   lcdy[i][6]=1;
    lcdy[i][7]=1;
   lcdy[i][8]=1;
   lcdy[i][9]=1;
   }
   break;
   case 4:
   for(i=64;i<h+54;i++)
   {
   lcdy[i][6]=1;
    lcdy[i][7]=1;
   lcdy[i][8]=1;
   lcdy[i][9]=1;
   }
   break;
   case 5:
   for(i=80;i<h+70;i++)
   {
   lcdy[i][6]=1;
    lcdy[i][7]=1;
   lcdy[i][8]=1;
   lcdy[i][9]=1;
   }
   break;
   case 6:
   for(i=96;i<h+86;i++)
   {
   lcdy[i][6]=1;
    lcdy[i][7]=1;
   lcdy[i][8]=1;
   lcdy[i][9]=1;
   }
   break;
    case 7:
   for(i=112;i<h+102;i++)
   {
   lcdy[i][6]=1;
    lcdy[i][7]=1;
   lcdy[i][8]=1;
   lcdy[i][9]=1;
   }
   break;
    }
   break;
   case 7:
   for(i=112;i<=102+weight;i++)
   {
   lcdx[i]=1;
   }
    switch(sa2)
   {
   case 0:
   for(i=0;i<h-10;i++)
   {
   lcdy[i][7]=1;
   

   }
   break;
   case 1:
   for(i=16;i<h+6;i++)
   {
   lcdy[i][7]=1;

   }
   break;
   case 2:
   for(i=32;i<h+22;i++)
   {
   lcdy[i][7]=1;

   }
   break;
   case 3:
   for(i=48;i<h+38;i++)
   {
   lcdy[i][7]=1;

   }
   break;
   case 4:
   for(i=64;i<h+54;i++)
   {
   lcdy[i][7]=1;

   }
   break;
   case 5:
   for(i=80;i<h+70;i++)
   {
   lcdy[i][7]=1;

   }
   break;
   case 6:
   for(i=96;i<h+86;i++)
   {
   lcdy[i][7]=1;

   }
   break;
    case 7:
   for(i=112;i<h+102;i++)
   {
   lcdy[i][7]=1;

   }
   break;
    }
   break;
   case 8:
    for(i=128;i<=128+weight;i++)
   {
   lcdx[i]=1;
   }
       switch(sa2)
   {
   case 0:
   for(i=0;i<h-10;i++)
   {
   lcdy[i][8]=1;
   }
   break;
   case 1:
   for(i=16;i<h+6;i++)
   {
   lcdy[i][8]=1;
   }
   break;
   case 2:
   for(i=32;i<h+22;i++)
   {
   lcdy[i][8]=1;
   }
   break;
   case 3:
   for(i=48;i<h+38;i++)
   {
   lcdy[i][8]=1;
   }
   break;
   case 4:
   for(i=64;i<h+54;i++)
   {
   lcdy[i][8]=1;
   }
   break;
   case 5:
   for(i=80;i<h+70;i++)
   {
   lcdy[i][8]=1;
   }
   break;
   case 6:
   for(i=96;i<h+86;i++)
   {
   lcdy[i][8]=1;
   }
   break;
    case 7:
   for(i=112;i<h+102;i++)
   {
   lcdy[i][8]=1;
   }
   break;
    }
   break;
    case 10:
    for(i=160;i<150+weight;i++)
      {
      lcdx[i]=1;
      }

      break;

   }
   }

  return 0;
  }
}

int Oblock_control(){
while(1){
  if(locx<=5)
     {
    v=0;
    first=1;
     sa2=locy/16;
    }
    if(((lcdx[locx-1]==1) && (lcdy[locy][sa3]==1)) || (lcdx[locx-1]==1) && (lcdy[locy+16][sa3]==1) )
    {
    v=0;
    abc=1;
    abc2=1;
    sa2=locy/16;
    sa=locx/16;

     }
   return 0;
   }
}
int Sblock_location(){
  while(1){
  if(first==1)
   {
    for(i=0;i<weight-10;i++)
    {
   lcdx[i]=1;
    }
    switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][1]=1;
      lcdy[i][2]=1;
   }
   for(i=16;i<32;i++)
   {
   lcdy[i][0]=1;
   lcdy[i][1]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][1]=1;
      lcdy[i][2]=1;
   }
   for(i=32;i<48;i++)
   {
   lcdy[i][0]=1;
   lcdy[i][1]=1;
   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][1]=1;
      lcdy[i][2]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][0]=1;
   lcdy[i][1]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][1]=1;
      lcdy[i][2]=1;
   }
   for(i=64;i<80;i++)
   {
   lcdy[i][0]=1;
   lcdy[i][1]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][1]=1;
      lcdy[i][2]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][0]=1;
   lcdy[i][1]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][1]=1;
      lcdy[i][2]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][0]=1;
   lcdy[i][1]=1;
   }
   break;
   case 6:
   for(i=96;i<112;i++)
   {
      lcdy[i][1]=1;
      lcdy[i][2]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][0]=1;
   lcdy[i][1]=1;
   }
   break;

    }
   }
   
    if(abc==1)
   {
   switch(sa)
   { case 1:

      for(i=16;i<6+weight;i++)
      {
      lcdx[i]=1;
      }
        switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][2]=1;
      lcdy[i][3]=1;
   }
   for(i=16;i<(h-10)/2;i++)
   {
   lcdy[i][1]=1;
   lcdy[i][2]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][2]=1;
      lcdy[i][3]=1;
   }
   for(i=32;i<48;i++)
   {
   lcdy[i][1]=1;
   lcdy[i][2]=1;
   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][2]=1;
      lcdy[i][3]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][1]=1;
   lcdy[i][2]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][2]=1;
      lcdy[i][3]=1;
   }
   for(i=64;i<80;i++)
   {
   lcdy[i][1]=1;
   lcdy[i][2]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][2]=1;
      lcdy[i][3]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][1]=1;
   lcdy[i][2]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][2]=1;
      lcdy[i][3]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][1]=1;
   lcdy[i][2]=1;
   }
   break;
   case 6:
   for(i=96;i<112;i++)
   {
      lcdy[i][2]=1;
      lcdy[i][3]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][1]=1;
   lcdy[i][2]=1;
   }
   break;

    }
   break;
   case 2:

      for(i=32;i<22+weight;i++)
      {
      lcdx[i]=1;
      }
   switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][3]=1;
      lcdy[i][4]=1;
   }
   for(i=16;i<(h-10)/2;i++)
   {
   lcdy[i][2]=1;
   lcdy[i][3]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][3]=1;
   }
   for(i=32;i<48;i++)
   {
   lcdy[i][2]=1;
   lcdy[i][3]=1;
   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][3]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][2]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][3]=1;
   }
   for(i=64;i<80;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][2]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][3]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][2]=1;
   lcdy[i][3]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][3]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][2]=1;
   }
   break;
   case 6:
   for(i=96;i<112;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][3]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][2]=1;
   }
   break;

    }
    break;
    case 3:

      for(i=48;i<96;i++)
      {
      lcdx[i]=1;
      }
 switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][5]=1;
   }
   for(i=16;i<(h-10)/2;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][4]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][5]=1;
   }
   for(i=32;i<48;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][4]=1;
   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][5]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][4]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][5]=1;
   }
   for(i=64;i<80;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][4]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][5]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][4]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][5]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][4]=1;
   }
   break;
   case 6:
   for(i=96;i<112;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][5]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][4]=1;
   }
   break;

    }
    break;
   case 4:
   for(i=64;i<=54+weight;i++)
   {
   lcdx[i]=1;
   }
     switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][5]=1;
      lcdy[i][6]=1;
   }
   for(i=16;i<(h-10)/2;i++)
   {
   lcdy[i][4]=1;
   lcdy[i][5]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][5]=1;
      lcdy[i][6]=1;
   }
   for(i=32;i<48;i++)
   {
   lcdy[i][4]=1;
   lcdy[i][5]=1;
   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][5]=1;
      lcdy[i][6]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][4]=1;
   lcdy[i][5]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][5]=1;
      lcdy[i][6]=1;
   }
   for(i=64;i<80;i++)
   {
   lcdy[i][4]=1;
   lcdy[i][5]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][5]=1;
      lcdy[i][6]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][4]=1;
   lcdy[i][5]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][5]=1;
      lcdy[i][6]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][4]=1;
   lcdy[i][5]=1;
   }
   break;
   case 6:
   for(i=96;i<112;i++)
   {
      lcdy[i][5]=1;
      lcdy[i][6]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][4]=1;
   lcdy[i][5]=1;
   }
   break;

    }

   break;

    case 5:
   for(i=80;i<=70+weight;i++)
   {
   lcdx[i]=1;
   }
    switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][6]=1;
      lcdy[i][7]=1;
   }
   for(i=16;i<(h-10)/2;i++)
   {
   lcdy[i][5]=1;
   lcdy[i][6]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][6]=1;
      lcdy[i][7]=1;
   }
   for(i=32;i<48;i++)
   {
   lcdy[i][5]=1;
   lcdy[i][6]=1;
   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][6]=1;
      lcdy[i][7]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][5]=1;
   lcdy[i][6]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][6]=1;
      lcdy[i][7]=1;
   }
   for(i=64;i<80;i++)
   {
   lcdy[i][5]=1;
   lcdy[i][6]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][6]=1;
      lcdy[i][7]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][5]=1;
   lcdy[i][6]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][6]=1;
      lcdy[i][7]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][5]=1;
   lcdy[i][6]=1;
   }
   break;
   case 6:
   for(i=96;i<112;i++)
   {
      lcdy[i][6]=1;
      lcdy[i][7]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][5]=1;
   lcdy[i][6]=1;
   }
   break;

    }
   break;
   case 6:
   for(i=96;i<=86+weight;i++)
   {
   lcdx[i]=1;
   }
     switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][8]=1;
   }
   for(i=16;i<(h-10)/2;i++)
   {
   lcdy[i][6]=1;
   lcdy[i][7]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][8]=1;
   }
   for(i=32;i<48;i++)
   {
   lcdy[i][6]=1;
   lcdy[i][7]=1;
   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][8]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][6]=1;
   lcdy[i][7]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][8]=1;
   }
   for(i=64;i<80;i++)
   {
   lcdy[i][6]=1;
   lcdy[i][7]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][8]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][6]=1;
   lcdy[i][7]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][8]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][6]=1;
   lcdy[i][7]=1;
   }
   break;
   case 6:
   for(i=96;i<112;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][8]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][6]=1;
   lcdy[i][7]=1;
   }
   break;

    }
   break;
   break;
   case 7:
   for(i=112;i<=102+weight;i++)
   {
   lcdx[i]=1;
   }
            switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][8]=1;
      lcdy[i][9]=1;
   }
   for(i=16;i<(h-10)/2;i++)
   {
   lcdy[i][7]=1;
   lcdy[i][8]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][8]=1;
      lcdy[i][9]=1;
   }
   for(i=32;i<48;i++)
   {
   lcdy[i][7]=1;
   lcdy[i][8]=1;
   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][8]=1;
      lcdy[i][9]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][7]=1;
   lcdy[i][8]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][8]=1;
      lcdy[i][9]=1;
   }
   for(i=64;i<80;i++)
   {
   lcdy[i][7]=1;
   lcdy[i][8]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][8]=1;
      lcdy[i][9]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][7]=1;
   lcdy[i][8]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][8]=1;
      lcdy[i][9]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][7]=1;
   lcdy[i][8]=1;
   }
   break;
   case 6:
   for(i=96;i<112;i++)
   {
      lcdy[i][8]=1;
      lcdy[i][9]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][7]=1;
   lcdy[i][8]=1;
   }
   break;

    }
   case 8:
    for(i=128;i<=118+weight;i++)
   {
   lcdx[i]=1;
   }

   break;
   case 9:
   for(i=144;i<=134+weight;i++)
   {
   lcdx[i]=1;
   }
   
   break;
    case 10:
    for(i=160;i<150+weight;i++)
      {
      lcdx[i]=1;
      }

      break;

   }
   }
  
  return 0;
  }
}
 int Zblock_location(){
  while(1){
  if(first==1)
   {
    for(i=0;i<weight-10;i++)
    {
   lcdx[i]=1;
    }
    switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][0]=1;
      lcdy[i][1]=1;
   }
   for(i=16;i<(h-10)/2;i++)
   {
   lcdy[i][1]=1;
   lcdy[i][2]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][0]=1;
      lcdy[i][1]=1;
   }
   for(i=32;i<48;i++)
   {
   lcdy[i][1]=1;
   lcdy[i][2]=1;
   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][0]=1;
      lcdy[i][1]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][1]=1;
   lcdy[i][2]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][0]=1;
      lcdy[i][1]=1;
   }
   for(i=64;i<80;i++)
   {
   lcdy[i][1]=1;
   lcdy[i][2]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][0]=1;
      lcdy[i][1]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][1]=1;
   lcdy[i][2]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][0]=1;
      lcdy[i][1]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][1]=1;
   lcdy[i][2]=1;
   }
   break;
   case 6:
   for(i=96;i<112;i++)
   {
      lcdy[i][0]=1;
      lcdy[i][1]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][1]=1;
   lcdy[i][2]=1;
   }
   break;

    }
   }

    if(abc==1)
   {
   switch(sa)
   { case 1:

      for(i=16;i<6+weight;i++)
      {
      lcdx[i]=1;
      }
        switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][1]=1;
      lcdy[i][2]=1;
   }
   for(i=16;i<(h-10)/2;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][2]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][2]=1;
      lcdy[i][1]=1;
   }
   for(i=32;i<48;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][2]=1;
   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][2]=1;
      lcdy[i][1]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][2]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][2]=1;
      lcdy[i][1]=1;
   }
   for(i=64;i<80;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][2]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][2]=1;
      lcdy[i][1]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][2]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][2]=1;
      lcdy[i][1]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][2]=1;
   }
   break;
   case 6:
   for(i=96;i<112;i++)
   {
      lcdy[i][2]=1;
      lcdy[i][1]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][2]=1;
   }
   break;

    }
   break;
   case 2:

      for(i=32;i<22+weight;i++)
      {
      lcdx[i]=1;
      }
   switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][2]=1;
      lcdy[i][3]=1;
   }
   for(i=16;i<(h-10)/2;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][4]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][2]=1;
      lcdy[i][3]=1;
   }
   for(i=32;i<48;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][4]=1;
   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][2]=1;
      lcdy[i][3]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][4]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][2]=1;
      lcdy[i][3]=1;
   }
   for(i=64;i<80;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][4]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][2]=1;
      lcdy[i][3]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][4]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][2]=1;
      lcdy[i][3]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][4]=1;
   }
   break;
   case 6:
   for(i=96;i<112;i++)
   {
      lcdy[i][2]=1;
      lcdy[i][3]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][3]=1;
   lcdy[i][4]=1;
   }
   break;

    }
    break;
    case 3:

      for(i=48;i<38+weight;i++)
      {
      lcdx[i]=1;
      }
        switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][3]=1;
      lcdy[i][4]=1;
   }
   for(i=16;i<(h-10)/2;i++)
   {
   lcdy[i][4]=1;
   lcdy[i][5]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][3]=1;
      lcdy[i][4]=1;
   }
   for(i=32;i<48;i++)
   {
   lcdy[i][4]=1;
   lcdy[i][5]=1;
   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][3]=1;
      lcdy[i][4]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][5]=1;
   lcdy[i][4]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][3]=1;
      lcdy[i][4]=1;
   }
   for(i=64;i<80;i++)
   {
   lcdy[i][5]=1;
   lcdy[i][4]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][3]=1;
      lcdy[i][4]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][5]=1;
   lcdy[i][4]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][3]=1;
      lcdy[i][4]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][5]=1;
   lcdy[i][4]=1;
   }
   break;
   case 6:
   for(i=96;i<112;i++)
   {
      lcdy[i][3]=1;
      lcdy[i][4]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][5]=1;
   lcdy[i][4]=1;
   }
   break;

    }
    break;
   case 4:
   for(i=64;i<=54+weight;i++)
   {
   lcdx[i]=1;
   }
      switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][5]=1;
   }
   for(i=16;i<(h-10)/2;i++)
   {
   lcdy[i][5]=1;
   lcdy[i][6]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][5]=1;
   }
   for(i=32;i<48;i++)
   {
   lcdy[i][5]=1;
   lcdy[i][6]=1;
   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][5]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][5]=1;
   lcdy[i][6]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][5]=1;
   }
   for(i=64;i<80;i++)
   {
   lcdy[i][5]=1;
   lcdy[i][6]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][5]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][5]=1;
   lcdy[i][6]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][5]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][5]=1;
   lcdy[i][6]=1;
   }
   break;
   case 6:
   for(i=96;i<112;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][5]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][5]=1;
   lcdy[i][6]=1;
   }
   break;

    }

   break;

    case 5:
   for(i=80;i<=70+weight;i++)
   {
   lcdx[i]=1;
   }
     switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][5]=1;
      lcdy[i][6]=1;
   }
   for(i=16;i<(h-10)/2;i++)
   {
   lcdy[i][6]=1;
   lcdy[i][7]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][5]=1;
      lcdy[i][6]=1;
   }
   for(i=32;i<48;i++)
   {
   lcdy[i][6]=1;
   lcdy[i][7]=1;
   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][5]=1;
      lcdy[i][6]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][6]=1;
   lcdy[i][7]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][5]=1;
      lcdy[i][6]=1;
   }
   for(i=64;i<80;i++)
   {
   lcdy[i][6]=1;
   lcdy[i][7]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][5]=1;
      lcdy[i][6]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][6]=1;
   lcdy[i][7]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][5]=1;
      lcdy[i][6]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][6]=1;
   lcdy[i][7]=1;
   }
   break;
   case 6:
   for(i=96;i<112;i++)
   {
      lcdy[i][5]=1;
      lcdy[i][6]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][6]=1;
   lcdy[i][7]=1;
   }
   break;

    }
   break;
   case 6:
   for(i=96;i<=86+weight;i++)
   {
   lcdx[i]=1;
   }
      switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][6]=1;
      lcdy[i][7]=1;
   }
   for(i=16;i<(h-10)/2;i++)
   {
   lcdy[i][7]=1;
   lcdy[i][8]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][6]=1;
      lcdy[i][7]=1;
   }
   for(i=32;i<48;i++)
   {
   lcdy[i][7]=1;
   lcdy[i][8]=1;
   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][6]=1;
      lcdy[i][7]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][7]=1;
   lcdy[i][8]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][6]=1;
      lcdy[i][7]=1;
   }
   for(i=64;i<80;i++)
   {
   lcdy[i][7]=1;
   lcdy[i][8]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][6]=1;
      lcdy[i][7]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][7]=1;
   lcdy[i][8]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][6]=1;
      lcdy[i][7]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][7]=1;
   lcdy[i][8]=1;
   }
   break;
   case 6:
   for(i=96;i<112;i++)
   {
      lcdy[i][6]=1;
      lcdy[i][7]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][7]=1;
   lcdy[i][8]=1;
   }
   break;

    }
   break;
   case 7:
   for(i=112;i<=102+weight;i++)
   {
   lcdx[i]=1;
   }
     switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][8]=1;
   }
   for(i=16;i<(h-10)/2;i++)
   {
   lcdy[i][8]=1;
   lcdy[i][9]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][8]=1;
   }
   for(i=32;i<48;i++)
   {
   lcdy[i][8]=1;
   lcdy[i][9]=1;
   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][8]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][8]=1;
   lcdy[i][9]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][8]=1;
   }
   for(i=64;i<80;i++)
   {
   lcdy[i][8]=1;
   lcdy[i][9]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][8]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][8]=1;
   lcdy[i][9]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][8]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][8]=1;
   lcdy[i][9]=1;
   }
   break;
   case 6:
   for(i=96;i<112;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][8]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][8]=1;
   lcdy[i][9]=1;
   }
   break;

    }
   break;
   case 8:
    for(i=128;i<=128+weight;i++)
   {
   lcdx[i]=1;
   }
        switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][8]=1;
      lcdy[i][9]=1;
   }
   for(i=16;i<(h-10)/2;i++)
   {
   lcdy[i][9]=1;
   lcdy[i][10]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][8]=1;
      lcdy[i][9]=1;
   }
   for(i=32;i<48;i++)
   {
   lcdy[i][9]=1;
   lcdy[i][10]=1;
   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][8]=1;
      lcdy[i][9]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][9]=1;
   lcdy[i][10]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][8]=1;
      lcdy[i][9]=1;
   }
   for(i=64;i<80;i++)
   {
   lcdy[i][9]=1;
   lcdy[i][10]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][8]=1;
      lcdy[i][9]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][9]=1;
   lcdy[i][10]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][8]=1;
      lcdy[i][9]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][9]=1;
   lcdy[i][10]=1;
   }
   break;
   case 6:
   for(i=96;i<112;i++)
   {
      lcdy[i][8]=1;
      lcdy[i][9]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][9]=1;
   lcdy[i][10]=1;
   }
   break;

    }
   break;
    case 10:
    for(i=160;i<150+weight;i++)
      {
      lcdx[i]=1;
      }

      break;

   }
   }

  return 0;
  }
}
int Zblock_control(){
  while(1){
  //sa3=(locx)/16;
  if(locx<=5)
     {
    v=0;
    first=1;
     sa2=locy/16;
    }
    if((lcdx[locx-1]==1) && (lcdy[locy][sa3]==1) || (lcdx[locx-1]==1) && (lcdy[locy+16][sa3+1]==1))
    {
    v=0;
    abc=1;
    abc2=1;
    sa2=locy/16;
    sa=locx/16;

     }
   return 0;
   }
}
int Tblock_location(){
  while(1){
  if(first==1)
   {
    for(i=0;i<weight-10;i++)
    {
   lcdx[i]=1;
    }
    switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][0]=1;
      lcdy[i][1]=1;
      lcdy[i][2]=1;
   }
   for(i=16;i<(h-10)/2;i++)
   {
   lcdy[i][1]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][0]=1;
      lcdy[i][1]=1;
      lcdy[i][2]=1;
   }
   for(i=32;i<48;i++)
   {
   lcdy[i][1]=1;

   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][0]=1;
      lcdy[i][2]=1;
      lcdy[i][1]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][1]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][0]=1;
      lcdy[i][1]=1;
      lcdy[i][2]=1;
   }
   for(i=64;i<80;i++)
   {
   lcdy[i][1]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][0]=1;
      lcdy[i][1]=1;
      lcdy[i][2]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][1]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][0]=1;
      lcdy[i][1]=1;
      lcdy[i][2]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][1]=1;
   }
   break;
   case 6:
   for(i=96;i<112;i++)
   {
      lcdy[i][0]=1;
      lcdy[i][1]=1;
      lcdy[i][2]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][1]=1;
   }
   break;

    }
   }

    if(abc==1)
   {
   switch(sa)
   { case 1:

      for(i=16;i<6+weight;i++)
      {
      lcdx[i]=1;
      }
    switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][3]=1;
      lcdy[i][1]=1;
      lcdy[i][2]=1;
   }
   for(i=16;i<(h-10)/2;i++)
   {
   lcdy[i][2]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][3]=1;
      lcdy[i][1]=1;
      lcdy[i][2]=1;
   }
   for(i=32;i<48;i++)
   {
   lcdy[i][2]=1;

   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][3]=1;
      lcdy[i][2]=1;
      lcdy[i][1]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][2]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][3]=1;
      lcdy[i][1]=1;
      lcdy[i][2]=1;
   }
   for(i=64;i<80;i++)
   {
   lcdy[i][2]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][3]=1;
      lcdy[i][1]=1;
      lcdy[i][2]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][2]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][3]=1;
      lcdy[i][1]=1;
      lcdy[i][2]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][2]=1;
   }
   break;
   case 6:
   for(i=96;i<112;i++)
   {
      lcdy[i][3]=1;
      lcdy[i][1]=1;
      lcdy[i][2]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][2]=1;
   }
   break;

    }

   break;
   case 2:

      for(i=32;i<22+weight;i++)
      {
      lcdx[i]=1;
      }
    switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][3]=1;
      lcdy[i][2]=1;
   }
   for(i=16;i<(h-10)/2;i++)
   {
   lcdy[i][3]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][3]=1;
      lcdy[i][2]=1;
   }
   for(i=32;i<48;i++)
   {
   lcdy[i][3]=1;

   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][2]=1;
      lcdy[i][3]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][3]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][3]=1;
      lcdy[i][2]=1;
   }
   for(i=64;i<80;i++)
   {
   lcdy[i][3]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][3]=1;
      lcdy[i][2]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][3]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][3]=1;
      lcdy[i][2]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][3]=1;
   }
   break;
   case 6:
   for(i=96;i<112;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][3]=1;
      lcdy[i][2]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][3]=1;
   }
   break;

    }
    break;
    case 3:

      for(i=48;i<38+weight;i++)
      {
      lcdx[i]=1;
      }
       switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][3]=1;
      lcdy[i][5]=1;
   }
   for(i=16;i<(h-10)/2;i++)
   {
   lcdy[i][4]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][3]=1;
      lcdy[i][5]=1;
   }
   for(i=32;i<48;i++)
   {
   lcdy[i][4]=1;

   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][5]=1;
      lcdy[i][3]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][4]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][3]=1;
      lcdy[i][5]=1;
   }
   for(i=64;i<80;i++)
   {
   lcdy[i][4]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][3]=1;
      lcdy[i][5]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][4]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][3]=1;
      lcdy[i][5]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][4]=1;
   }
   break;
   case 6:
   for(i=96;i<112;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][3]=1;
      lcdy[i][5]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][4]=1;
   }
   break;

    }
    break;
   case 4:
   for(i=64;i<=54+weight;i++)
   {
   lcdx[i]=1;
   }
             switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][6]=1;
      lcdy[i][5]=1;
   }
   for(i=16;i<(h-10)/2;i++)
   {
   lcdy[i][5]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][6]=1;
      lcdy[i][5]=1;
   }
   for(i=32;i<48;i++)
   {
   lcdy[i][5]=1;

   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][5]=1;
      lcdy[i][6]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][5]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][6]=1;
      lcdy[i][5]=1;
   }
   for(i=64;i<80;i++)
   {
   lcdy[i][5]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][6]=1;
      lcdy[i][5]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][5]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][6]=1;
      lcdy[i][5]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][5]=1;
   }
   break;
   case 6:
   for(i=96;i<112;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][6]=1;
      lcdy[i][5]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][5]=1;
   }
   break;

    }
   break;

    case 5:
   for(i=80;i<=70+weight;i++)
   {
   lcdx[i]=1;
   }
           switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][6]=1;
      lcdy[i][5]=1;
   }
   for(i=16;i<(h-10)/2;i++)
   {
   lcdy[i][6]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][6]=1;
      lcdy[i][5]=1;
   }
   for(i=32;i<48;i++)
   {
   lcdy[i][6]=1;

   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][6]=1;
      lcdy[i][5]=1;
      lcdy[i][7]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][6]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][6]=1;
      lcdy[i][5]=1;
   }
   for(i=64;i<80;i++)
   {
   lcdy[i][6]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][6]=1;
      lcdy[i][5]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][6]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][6]=1;
      lcdy[i][5]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][6]=1;
   }
   break;
   case 6:
   for(i=96;i<112;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][6]=1;
      lcdy[i][5]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][6]=1;
   }
   break;

    }
   break;
   case 6:
   for(i=96;i<=86+weight;i++)
   {
   lcdx[i]=1;
   }

           switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][6]=1;
      lcdy[i][8]=1;
   }
   for(i=16;i<(h-10)/2;i++)
   {
   lcdy[i][7]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][6]=1;
      lcdy[i][8]=1;
   }
   for(i=32;i<48;i++)
   {
   lcdy[i][7]=1;

   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][6]=1;
      lcdy[i][8]=1;
      lcdy[i][7]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][7]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][6]=1;
      lcdy[i][8]=1;
   }
   for(i=64;i<80;i++)
   {
   lcdy[i][7]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][6]=1;
      lcdy[i][8]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][7]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][6]=1;
      lcdy[i][8]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][7]=1;
   }
   break;
   case 6:
   for(i=96;i<112;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][6]=1;
      lcdy[i][8]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][7]=1;
   }
   break;

    }
   break;
   case 7:
   for(i=112;i<=102+weight;i++)
   {
   lcdx[i]=1;
   }

           switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][8]=1;
      lcdy[i][9]=1;
   }
   for(i=16;i<(h-10)/2;i++)
   {
   lcdy[i][6]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][8]=1;
      lcdy[i][9]=1;
   }
   for(i=32;i<48;i++)
   {
   lcdy[i][8]=1;

   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][9]=1;
      lcdy[i][8]=1;
      lcdy[i][7]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][8]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][8]=1;
      lcdy[i][9]=1;
   }
   for(i=64;i<80;i++)
   {
   lcdy[i][8]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][8]=1;
      lcdy[i][9]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][8]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][8]=1;
      lcdy[i][9]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][8]=1;
   }
   break;
   case 6:
   for(i=96;i<112;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][8]=1;
      lcdy[i][9]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][8]=1;
   }
   break;

    }
   break;
   case 8:
    for(i=128;i<=128+weight;i++)
   {
   lcdx[i]=1;
   }

           switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][8]=1;
      lcdy[i][9]=1;
      lcdy[i][10]=1;
   }
   for(i=16;i<(h-10)/2;i++)
   {
   lcdy[i][9]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][8]=1;
      lcdy[i][9]=1;
      lcdy[i][10]=1;
   }
   for(i=32;i<48;i++)
   {
   lcdy[i][9]=1;

   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][8]=1;
      lcdy[i][9]=1;
      lcdy[i][10]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][9]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][8]=1;
      lcdy[i][9]=1;
      lcdy[i][10]=1;
   }
   for(i=64;i<80;i++)
   {
   lcdy[i][9]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][8]=1;
      lcdy[i][9]=1;
      lcdy[i][10]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][9]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][8]=1;
      lcdy[i][9]=1;
      lcdy[i][10]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][9]=1;
   }
   break;
   case 6:
   for(i=96;i<112;i++)
   {
      lcdy[i][8]=1;
      lcdy[i][9]=1;
      lcdy[i][10]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][9]=1;
   }
   break;

    }
   break;
    case 10:
    for(i=160;i<150+weight;i++)
      {
      lcdx[i]=1;
      }

      break;

   }
   }

  return 0;
  }
}
 int Lblock_location(){
   while(1){
 if (image==6){
  if(first==1)
   {
    for(i=0;i<weight-10;i++)
    {
   lcdx[i]=1;
    }
    switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][0]=1;
      lcdy[i][1]=1;

   }
   for(i=16;i<32;i++)
   {
    lcdy[i][1]=1;


   }
    for(i=32;i<48;i++)
   {
   lcdy[i][1]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][0]=1;
      lcdy[i][1]=1;

   }
   for(i=32;i<48;i++)
   {
   lcdy[i][1]=1;

   }
     for(i=48;i<64;i++)
   {
   lcdy[i][1]=1;

   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][0]=1;
      lcdy[i][1]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][1]=1;
   }
    for(i=64;i<80;i++)
   {
   lcdy[i][1]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][0]=1;
      lcdy[i][1]=1;

   }
   for(i=64;i<80;i++)
   {
   lcdy[i][1]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][1]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][0]=1;
      lcdy[i][1]=1;

   }
   for(i=80;i<96;i++)
   {
   lcdy[i][1]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][1]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][0]=1;
      lcdy[i][1]=1;

   }
   for(i=96;i<112;i++)
   {
   lcdy[i][1]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][1]=1;
   }
   break;
    }
   }

    if(abc==1)
   {
   switch(sa)
   { case 1:

      for(i=16;i<6+weight;i++)
      {
      lcdx[i]=1;
      }
    switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][1]=1;
      lcdy[i][2]=1;

   }
   for(i=16;i<32;i++)
   {
   lcdy[i][2]=1;
   }
    for(i=32;i<48;i++)
   {
   lcdy[i][2]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][2]=1;
      lcdy[i][1]=1;

   }
   for(i=32;i<48;i++)
   {
   lcdy[i][2]=1;

   }
     for(i=48;i<64;i++)
   {
   lcdy[i][2]=1;

   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][2]=1;
      lcdy[i][1]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][2]=1;
   }
    for(i=64;i<80;i++)
   {
   lcdy[i][2]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][2]=1;
      lcdy[i][1]=1;

   }
   for(i=64;i<80;i++)
   {
   lcdy[i][2]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][2]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][2]=1;
      lcdy[i][1]=1;

   }
   for(i=80;i<96;i++)
   {
   lcdy[i][2]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][2]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][2]=1;
      lcdy[i][1]=1;

   }
   for(i=96;i<112;i++)
   {
   lcdy[i][2]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][2]=1;
   }
   break;
    }

   break;
   case 2:

      for(i=32;i<22+weight;i++)
      {
      lcdx[i]=1;
      }
     switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][2]=1;
      lcdy[i][3]=1;

   }
   for(i=16;i<32;i++)
   {
   lcdy[i][3]=1;
   }
    for(i=32;i<48;i++)
   {
   lcdy[i][3]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][3]=1;
      lcdy[i][2]=1;

   }
   for(i=32;i<48;i++)
   {
   lcdy[i][3]=1;

   }
     for(i=48;i<64;i++)
   {
   lcdy[i][3]=1;

   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][3]=1;
      lcdy[i][2]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][3]=1;
   }
    for(i=64;i<80;i++)
   {
   lcdy[i][3]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][3]=1;
      lcdy[i][2]=1;

   }
   for(i=64;i<80;i++)
   {
   lcdy[i][3]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][3]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {

      lcdy[i][3]=1;
      lcdy[i][2]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][3]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][3]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {

      lcdy[i][3]=1;
      lcdy[i][2]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][3]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][3]=1;
   }
   break;
    }
    break;
    case 3:

      for(i=48;i<38+weight;i++)
      {
      lcdx[i]=1;
      }
       switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][3]=1;

   }
   for(i=16;i<32;i++)
   {
   lcdy[i][4]=1;
   }
    for(i=32;i<48;i++)
   {
   lcdy[i][4]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][3]=1;
      lcdy[i][4]=1;

   }
   for(i=32;i<48;i++)
   {
   lcdy[i][4]=1;

   }
     for(i=48;i<64;i++)
   {
   lcdy[i][4]=1;

   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][3]=1;
      lcdy[i][4]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][4]=1;
   }
    for(i=64;i<80;i++)
   {
   lcdy[i][4]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][3]=1;
      lcdy[i][4]=1;

   }
   for(i=64;i<80;i++)
   {
   lcdy[i][4]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][4]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][3]=1;
      lcdy[i][4]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][4]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][4]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][3]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][4]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][4]=1;
   }
   break;
    }
    break;
   case 4:
   for(i=64;i<=54+weight;i++)
   {
   lcdx[i]=1;
   }
               switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][5]=1;

   }
   for(i=16;i<32;i++)
   {
   lcdy[i][5]=1;
   }
    for(i=32;i<48;i++)
   {
   lcdy[i][5]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][5]=1;
      lcdy[i][4]=1;

   }
   for(i=32;i<48;i++)
   {
   lcdy[i][5]=1;

   }
     for(i=48;i<64;i++)
   {
   lcdy[i][5]=1;

   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][5]=1;
      lcdy[i][4]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][5]=1;
   }
    for(i=64;i<80;i++)
   {
   lcdy[i][5]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][5]=1;
      lcdy[i][4]=1;

   }
   for(i=64;i<80;i++)
   {
   lcdy[i][5]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][5]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][5]=1;
      lcdy[i][4]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][5]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][5]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][4]=1;
      lcdy[i][5]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][5]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][5]=1;
   }
   break;
    }
   break;

    case 5:
   for(i=80;i<=70+weight;i++)
   {
   lcdx[i]=1;
   }
                         switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][6]=1;
      lcdy[i][5]=1;

   }
   for(i=16;i<32;i++)
   {
   lcdy[i][6]=1;
   }
    for(i=32;i<48;i++)
   {
   lcdy[i][6]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][5]=1;
      lcdy[i][6]=1;

   }
   for(i=32;i<48;i++)
   {
   lcdy[i][6]=1;

   }
     for(i=48;i<64;i++)
   {
   lcdy[i][6]=1;

   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][5]=1;
      lcdy[i][6]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][6]=1;
   }
    for(i=64;i<80;i++)
   {
   lcdy[i][6]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][5]=1;
      lcdy[i][6]=1;

   }
   for(i=64;i<80;i++)
   {
   lcdy[i][6]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][6]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][5]=1;
      lcdy[i][6]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][6]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][6]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][6]=1;
      lcdy[i][5]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][6]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][6]=1;
   }
   break;
    }


   break;
   case 6:
   for(i=96;i<=86+weight;i++)
   {
   lcdx[i]=1;
   }

                       switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][6]=1;

   }
   for(i=16;i<32;i++)
   {
   lcdy[i][7]=1;
   }
    for(i=32;i<48;i++)
   {
   lcdy[i][7]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][6]=1;

   }
   for(i=32;i<48;i++)
   {
   lcdy[i][7]=1;

   }
     for(i=48;i<64;i++)
   {
   lcdy[i][7]=1;

   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][6]=1;
      lcdy[i][7]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][7]=1;
   }
    for(i=64;i<80;i++)
   {
   lcdy[i][7]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][6]=1;

   }
   for(i=64;i<80;i++)
   {
   lcdy[i][7]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][7]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][6]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][7]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][7]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][6]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][7]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][7]=1;
   }
   break;
    }
   break;
   case 7:
   for(i=112;i<=102+weight;i++)
   {
   lcdx[i]=1;
   }
              switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][8]=1;

   }
   for(i=16;i<32;i++)
   {
   lcdy[i][8]=1;
   }
    for(i=32;i<48;i++)
   {
   lcdy[i][8]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][8]=1;
      lcdy[i][7]=1;

   }
   for(i=32;i<48;i++)
   {
   lcdy[i][8]=1;

   }
     for(i=48;i<64;i++)
   {
   lcdy[i][8]=1;

   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][8]=1;
   }
   for(i=48;i<64;i++)
   {
   lcdy[i][8]=1;
   }
    for(i=64;i<80;i++)
   {
   lcdy[i][8]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][8]=1;

   }
   for(i=64;i<80;i++)
   {
   lcdy[i][8]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][8]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][8]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][8]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][8]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][7]=1;
      lcdy[i][8]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][8]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][8]=1;
   }
   break;
    }
   break;
   case 8:
    for(i=128;i<=128+weight;i++)
   {
   lcdx[i]=1;
   }
              switch(sa2)
   {
   case 0:
   for(i=0;i<16;i++)
   {
      lcdy[i][8]=1;
      lcdy[i][9]=1;

   }
   for(i=16;i<32;i++)
   {
   lcdy[i][9]=1;
   }
    for(i=32;i<48;i++)
   {
   lcdy[i][9]=1;
   }
   break;
   case 1:
   for(i=16;i<32;i++)
   {
      lcdy[i][8]=1;
      lcdy[i][9]=1;

   }
   for(i=32;i<48;i++)
   {
   lcdy[i][9]=1;

   }
     for(i=48;i<64;i++)
   {
   lcdy[i][9]=1;

   }
   break;
   case 2:
   for(i=32;i<48;i++)
   {
      lcdy[i][8]=1;
      lcdy[i][9]=1;
   }
   {
   lcdy[i][9]=1;
   }
    for(i=64;i<80;i++)
   {
   lcdy[i][9]=1;
   }
   break;
   case 3:
   for(i=48;i<64;i++)
   {
      lcdy[i][9]=1;
      lcdy[i][8]=1;

   }
   for(i=64;i<80;i++)
   {
   lcdy[i][9]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][9]=1;
   }
   break;
   case 4:
    for(i=64;i<80;i++)
   {
      lcdy[i][8]=1;
      lcdy[i][9]=1;
   }
   for(i=80;i<96;i++)
   {
   lcdy[i][9]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][9]=1;
   }
   break;
   case 5:
    for(i=80;i<96;i++)
   {
      lcdy[i][9]=1;
      lcdy[i][8]=1;
   }
   for(i=96;i<112;i++)
   {
   lcdy[i][9]=1;
   }
   for(i=112;i<128;i++)
   {
   lcdy[i][9]=1;
   }
   break;
    }
   break;
    case 10:
    for(i=160;i<150+weight;i++)
      {
      lcdx[i]=1;
      }

      break;

   }
   }
   }
   else{

   }

  return 0;
  }
}
 
int Lblock_control(){
while(1){
  if(locx<=5)
     {
    v=0;
    first=1;
     sa2=locy/16;
    }
    if(((lcdx[locx-1]==1) && (lcdy[locy][sa3]==1)) || ((lcdx[locx-1]==1) && (lcdy[locy+16][sa3+1]==1)))
    {
    v=0;
    abc=1;
    abc2=1;
    sa2=locy/16;
    sa=locx/16;

     }
   return 0;
   }
}
 int lineclear(){
 while(1){

     if(lcdy[0][0]==1 && lcdy[16][0]==1 && lcdy[32][0]==1 && lcdy[64][0]==1 && lcdy[80][0]==1 && lcdy[96][0]==1 && lcdy[112][0]==1 && lcdy[127][0]==1 )
       {
        for(i=0;i<128;i++)
       {
       lcdy[i][0]=0;
       }
       T6963C_sprite(0, 0, line, 16, 128);
       lines=lines+1;
       score=score+80;
       for(j=1;j<14;j++)
       {
       for(i=0;i<128;i=i+16)
      {
       if(lcdy[i][j]==1)
       {
         // lcdy[i][j-1]=1;
          lcdy[i][j]=0;
       }
       }
       }
       }
       if(lcdy[0][1]==1 && lcdy[16][1]==1 && lcdy[32][1]==1 && lcdy[64][1]==1 && lcdy[80][1]==1 && lcdy[96][1]==1 && lcdy[112][1]==1 && lcdy[127][1]==1 )
       {
       T6963C_sprite(20,0, line, 16, 128);
       lines=lines+1;
       score=score+80;
        for(i=0;i<128;i++)
       {
       lcdy[i][1]=0;
       }
        for(j=2;j<14;j++)
       {
       for(i=0;i<128;i=i+16)
      {
       if(lcdy[i][j]==1)
       {
          lcdy[i][j-1]=1;
          lcdy[i][j]=0;
       }
       }
       }
       }/*
        if(lcdy[0][2]==1 && lcdy[16][2]==1 && lcdy[32][2]==1 && lcdy[64][2]==1 && lcdy[80][2]==1 && lcdy[96][2]==1 && lcdy[112][2]==1 && lcdy[127][2]==1 )
       {
       T6963C_sprite(36,0, line, 16, 128);
       lines=lines+1;
       score=score+80;
        for(i=0;i<128;i++)
       {
       lcdy[i][2]=0;
       }
        for(j=3;j<14;j++)
       {
       for(i=0;i<128;i=i+16)
      {
       if(lcdy[i][j]==1)
       {
          lcdy[i][j-1]=1;
          lcdy[i][j]=0;
       }
       }
       }
       }
       if(lcdy[0][3]==1 && lcdy[16][3]==1 && lcdy[32][3]==1 && lcdy[64][3]==1 && lcdy[80][3]==1 && lcdy[96][3]==1 && lcdy[112][3]==1 && lcdy[127][3]==1 )
       {
       T6963C_sprite(52,0, line, 16, 128);
       lines=lines+1;
       score=score+80;
        for(i=0;i<128;i++)
       {
       lcdy[i][3]=0;
       }
        for(j=4;j<14;j++)
       {
       for(i=0;i<128;i=i+16)
      {
       if(lcdy[i][j]==1)
       {
          lcdy[i][j-1]=1;
          lcdy[i][j]=0;
       }
       }
       }
       }
       if(lcdy[0][4]==1 && lcdy[16][4]==1 && lcdy[32][4]==1 && lcdy[64][4]==1 && lcdy[80][4]==1 && lcdy[96][4]==1 && lcdy[112][4]==1 && lcdy[127][4]==1 )
       {
       T6963C_sprite(68,0, line, 16, 128);
       lines=lines+1;
       score=score+80;
        for(i=0;i<128;i++)
       {
       lcdy[i][4]=0;
       }
        for(j=5;j<14;j++)
       {
       for(i=0;i<128;i=i+16)
      {
       if(lcdy[i][j]==1)
       {
          lcdy[i][j-1]=1;
          lcdy[i][j]=0;
       }
       }
       }
       }
       if(lcdy[0][5]==1 && lcdy[16][5]==1 && lcdy[32][5]==1 && lcdy[64][5]==1 && lcdy[80][5]==1 && lcdy[96][5]==1 && lcdy[112][5]==1 && lcdy[127][5]==1 )
       {
       T6963C_sprite(84,0, line, 16, 128);
       lines=lines+1;
       score=score+80;
        for(i=0;i<128;i++)
       {
       lcdy[i][5]=0;
       }
       }
       if(lcdy[0][6]==1 && lcdy[16][6]==1 && lcdy[32][6]==1 && lcdy[64][6]==1 && lcdy[80][6]==1 && lcdy[96][6]==1 && lcdy[112][6]==1 && lcdy[127][6]==1 )
       {
       T6963C_sprite(100,0, line, 16, 128);
       lines=lines+1;
       score=score+80;
        for(i=0;i<128;i++)
       {
       lcdy[i][6]=0;
       }
       }
       if(lcdy[0][7]==1 && lcdy[16][7]==1 && lcdy[32][7]==1 && lcdy[64][7]==1 && lcdy[80][7]==1 && lcdy[96][7]==1 && lcdy[112][7]==1 && lcdy[127][7]==1 )
       {
       T6963C_sprite(116,0, line, 16, 128);
       lines=lines+1;
       score=score+80;
        for(i=0;i<128;i++)
       {
       lcdy[i][7]=0;
       }
       }
       if(lcdy[0][8]==1 && lcdy[16][8]==1 && lcdy[32][8]==1 && lcdy[64][8]==1 && lcdy[80][8]==1 && lcdy[96][8]==1 && lcdy[112][8]==1 && lcdy[127][8]==1 )
       {
       T6963C_sprite(132,0, line, 16, 128);
       lines=lines+1;
       score=score+80;
        for(i=0;i<128;i++)
       {
       lcdy[i][8]=0;
       }


    }  */
    return 0;
 }
 }





 int onlyblock(){
  while(1){
    T6963C_image(screen);
      for(i=0;i<128;i=i+16)
      {
       if(lcdy[i][0]==1)
       {
        T6963C_sprite(0,i,oneblock, 16, 16);
       }
       if(lcdy[i][1]==1)
       {
        T6963C_sprite(16,i,oneblock, 16, 16);
       }
       if(lcdy[i][2]==1)
       {
        T6963C_sprite(32,i,oneblock, 16, 16);
       }
       if(lcdy[i][3]==1)
       {
        T6963C_sprite(48,i,oneblock, 16, 16);
       }
        if(lcdy[i][4]==1)
       {
        T6963C_sprite(64,i,oneblock, 16, 16);
       }
        if(lcdy[i][5]==1)
       {
        T6963C_sprite(80,i,oneblock, 16, 16);
       }
        if(lcdy[i][6]==1)
       {
        T6963C_sprite(96,i,oneblock, 16, 16);
       }
       if(lcdy[i][7]==1)
       {
        T6963C_sprite(112,i,oneblock, 16, 16);
       }



       }
       return 0;
       }

  }
void interrupt(){
     if(INT0F_bit==1 && cnt==0){
         time=100000;

        INT0F_bit=0;
        cnt=1;
        }
     if(INT0F_bit==1 && cnt==1){
            time=1;

        INT0F_bit=0;
        cnt=0;
        }
      if(PIR1.RC1IF==1)
      {  PORTE.RE7=1;
       if(UART1_Data_Ready()==1)
       {
           bt=UART1_Read();
       }
       des=1;
       PIR1.RC1IF=0;
      }
}

int bluetooth(){
switch(bt)
{ case '1':
  clean();
  if (locy>=96)
  {
  locy=112;
  }
  else
  {
  locy=locy+16;
  }
  clean();
  drawblock();
  break;
  case '2':
   clean();
  if (locy<=5)
  {
  locy=0;
  }
  else
  {
  locy=locy-16;
  }
  clean();
  drawblock();
  break;
  case '3':
  clean();
  turn();
  drawblock();
  break;
  case '4':
  clean();
   locx=locx-32;
   if(locx<=10)
   {(locx=locx);
     clean();
     drawblock();

   }
   clean();
   drawblock();
  break;
}
}
int main() {
  Menu:



  TRISC.RC0=1;


  ANCON0 = 0;
  ANCON1 = 0;
  ANCON2 = 0;
  TRISB.RB0=0;
  TRISB.RB1=1 ;
  TRISB.RB2=1 ;
  TRISB.RB3=1 ;
  TRISB.RB4=1;
  TRISB.RB5=1;
  TRISB.RB6=1;
  TRISB.RB7=1;
  TRISH=0;
  TRISF=0;
  TRISE=0;
  TRISJ=1;
  PIE1.RCIE=1;;
  IPR1.RCIP=1;
  IPR1.TXIP=1;
  RCSTA2.CREN=1;
  INTCON.PEIE=1;
  INTEDG0_bit=0; //External Interrupt 0 Edge Select bit
  INT0IF_bit=0; //INT0 interrupt Flag Bit Clear
  INT0IE_bit=1; //INT0 interrupt Enable Bit Set
  INTEDG1_bit=0; //External Interrupt 0 Edge Select bit
  INT1IF_bit=0; //INT0 interrupt Flag Bit Clear
  INT1IE_bit=1; //INT0 interrupt Enable Bit Set
  INTEDG2_bit=0; //External Interrupt 0 Edge Select bit
  INT2IF_bit=0; //INT0 interrupt Flag Bit Clear
  INT2IE_bit=1; //INT0 interrupt Enable Bit Set
  GIE_bit=1; // Global Interrupt Register Set
  UART1_Init(9600);

  Lcd_Init();
  Lcd_Cmd(_LCD_CLEAR);
  Lcd_Cmd(_LCD_CURSOR_OFF);
  Lcd_Out(1,1,bestText);
  Lcd_Out(1,6,linetext);
  Lcd_Out(1,12,scoreText);
  
  T6963C_ctrlce_Direction = 0;
  T6963C_ctrlce = 0;            // Enable T6963C
  T6963C_ctrlfs_Direction = 0;
  T6963C_ctrlfs = 0;            // Font Select 8x8
  T6963C_ctrlmd_Direction = 0;
  T6963C_ctrlmd = 0;            // Column number select

  T6963C_Init(240, 128, 8);
  Glcd_Init();
  Glcd_Fill(0);



  T6963C_Graphics(1);
  T6963C_Text(1);

  for(j=0;j<=240;j++)
  {
   lcdx[j]=0;
  }

  T6963C_image(intro);
  delay_ms(1000);
  T6963C_fill(0x00,0xFFFF,0xFFFF);
  delay_ms(1000);
  T6963C_image(HALMEZGE);
  delay_ms(1000);
  next1=0;
  while(1){
  T6963C_image(Tetris);
  delay_ms(150);
  T6963C_image(Tetris2);
  if(PORTB.RB1==1)
  { goto Begin;
  }
  if(PORTB.RB7==1 && next==0)
  {
     T6963C_image(about);
     delay_ms(2000);

  }

  }
  Begin:
  array_begin();
  START:
  lineclear();
  onlyblock();
  if(lcdx[192]==1)   {


         T6963C_image(over);
         delay_ms(3000);
         goto Menu;

    }
  selectblock();
  time=1;
  clean();
  while(1)
  {  T6963C_line(192, 0, 192, 127, T6963C_WHITE);
  Glcd_PartialImage(0, 0, 80,64, 80, 64, text);
    Glcd_PartialImage(75,0,48,64, 48, 64,glcd);
    IntToStr(lines, lineScore);
    Lcd_Out(2,3,lineScore);
    IntToStr(score, gameScore);
    Lcd_Out(2,10,gameScore);
    if(best<score)
    {
       best=score;
    }
    IntToStr(best, bestScore);
    Lcd_Out(2,0,bestScore);
   while(des==1)
    { 
    if(UART1_Data_Ready()==1)
       {
           bt=UART1_Read();
       }
     bluetooth();
     PORTE.RE7=1;
     des=0;
    }
  switch(array[deneme+1]){
    case 1:

       Glcd_PartialImage(85, 10, 32,48, 32, 48, glcd_one);
       break;
    case 2:

      Glcd_PartialImage(100, 0, 16,64, 16, 64, glcd_two);
      break;
    case 3:
      Glcd_PartialImage(85, 10, 32,48, 32, 48, glcd_three);
      break;
    case 4:
      Glcd_PartialImage(85, 10, 32,48, 32, 48, glcd_four);
     break;
     case 5:
      Glcd_PartialImage(85, 15, 32,32, 32, 32, glcd_five);
     break;
    case 6:
     Glcd_PartialImage(75, 15, 48,32, 48, 32, glcd_six);
    break;
    case 7:
     Glcd_PartialImage(75, 15, 48,32, 48, 32, glcd_seven);
    break;
    }
   locx=locx-v;
   sa3=(locx-1)/16;
   for(i=0;i<=time;i++)
    {
     delay_ms(1);
     }
   switch(image){
   case 1:
   Sblock_control();
   Sblock_location();
   break;
   case 2:
   Iblock_control();
   Iblock_location();
   break;
   case 3:
   Zblock_control();
   Tblock_location();
   break;
   case 4:
   Zblock_control();
   Zblock_location();
   break;
   case 5:
   Oblock_control();
   Oblock_location();
   break;
   case 6:
    Lblock_control();
   Lblock_location();
   break;
    }

    delay_ms(300);

    clean();
    drawblock();

  if(v==0)
  {
    clean();
    drawblock();
    deneme=deneme+1;
    goto START;
    break;
  }

  if(PORTB.RB6==1)
  {
     T6963C_fill(0x00,0xFFFF,0xFFFF);
     goto Menu;
  
  
  }
  if(PORTB.RB2==1)
  {
   clean();
  if (locy<=5)
  {
  locy=0;
  }
  else
  {
  locy=locy-16;
  }
  clean();
  drawblock();


  }
  if(PORTB.RB3==1)
  {
  clean();
  if (locy>=96)
  {
  locy=112;
  }
  else
  {
  locy=locy+16;
  }
  clean();
  drawblock();
  }
  if(PORTB.RB4==1){
   clean();
   locx=locx-32;
   if(locx<=10)
   {(locx=locx);
     clean();
     drawblock();

   }
   clean();
   drawblock();
  }
     if(PORTB.RB5==1)
   {clean();
    turn();
    drawblock();
   }
   
   }





}