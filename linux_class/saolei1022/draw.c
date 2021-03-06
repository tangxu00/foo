#include"draw.h"
#include"init.h"
void drawFlag(int i,int j)                  //画旗
{
    attrset(A_REVERSE);
    mvaddch(2*i+1,4*j+2,'P');
    mvaddch(2*i+1,4*j+1,' ');
    mvaddch(2*i+1,4*j+3,' ');
    attrset(A_NORMAL);
    refresh();
}
void eraseFlag(int i,int j)                 //擦旗
{
    attrset(A_REVERSE);
    mvaddch(2*i+1,4*j+2,' ');
    mvaddch(2*i+1,4*j+1,' ');
    mvaddch(2*i+1,4*j+3,' ');
    attrset(A_NORMAL);
    refresh();
}
void drawWhite(int i,int j)                 //画白格
{
    mvaddch(2*i+1,4*j+2,' ');
    mvaddch(2*i+1,4*j+1,' ');
    mvaddch(2*i+1,4*j+3,' ');
    refresh();
}
void drawNum(int i,int j,int k)             //画数字
{
    char a;
    sprintf(&a,"%d",k);                     //整型转字符型
    mvaddch(2*i+1,4*j+2,a);
    mvaddch(2*i+1,4*j+1,' ');
    mvaddch(2*i+1,4*j+3,' ');
    refresh();
}
void drawBom(int i,int j)                   //画地雷
{
    mvaddch(2*i+1,4*j+2,ACS_DIAMOND);
    mvaddch(2*i+1,4*j+1,' ');
    mvaddch(2*i+1,4*j+3,' ');
    refresh();
}
void showSum()                              //显示剩余雷数 
{
    char a,b;
    sprintf(&a,"%d",iBoom_Num/10);          //整型转字符型 
    sprintf(&b,"%d",iBoom_Num-10*(iBoom_Num/10));
                                            //整型转字符型    
    mvaddstr((2*iHigh+1)/3/2,4*iWidth+20,"BOM : ");
    mvaddch((2*iHigh+1)/3/2,4*iWidth+27,a);
    mvaddch((2*iHigh+1)/3/2,4*iWidth+28,b);
    refresh();
}
void showTime()                             //显示时间
{
    mvaddstr((2*iHigh+1)/3/2,4*iWidth+6,"TIME : ");
    mvprintw((2*iHigh+1)/3/2,4*iWidth+14,"%d",iGame_Time);
    iGame_Time++;
    refresh();
}


