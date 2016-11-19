#include"draw.h"
#include"init.h"
#include"process.h"
#include"control.h"

/*--------游戏开始 ----------*/
void gameBegin()
{
    init();
    refresh();
    produceBom();//生成地雷
    mouseControl();//鼠标控制
}
/*-------文件配置-----------*/
void openFile()
{
    FILE *fp1;
    fp1=fopen("ok.txt","r");
    fscanf(fp1,"%d",&DIFFICULTY);
    fclose(fp1);
    switch(DIFFICULTY)
            {
            case 1:
                HIGH=WIN_HIGH;
                WIDTH=WIN_WIDTH;
                SUM=SUMBOM;
		SUMWHITE=WIDTH*HIGH-SUM;
                break;
            case 2:
                HIGH=WIN_HIGH/3*4;
                WIDTH=WIN_WIDTH/3*4;
                SUM=SUMBOM*2;
		SUMWHITE=WIDTH*HIGH-SUM;
                break;
            case 3:
                HIGH=WIN_HIGH/3*5;
                WIDTH=WIN_WIDTH/3*5;
                SUM=SUMBOM*4;
		SUMWHITE=WIDTH*HIGH-SUM;
                break;
            }		
} 
/*----------初始化-----------*/
void init()
{
    initscr();//初始化
    clear();//清屏R
    noecho();//取消回显
    cbreak();//直接输出字符
    curs_set(0);// 光标隐藏
    WINFLAG=0;//点开的白格数为0
    TIME=0;//游戏时间初始化
    TIMESTART=0;//计时未启动
    mousemask(ALL_MOUSE_EVENTS,NULL);//监听鼠标事件
    mouseinterval(200);//设置单次点击鼠标间隔
   //-----画横线-----
    int i,j;  
    for(j=0;j<2*HIGH+2;j=j+2)
    {for(i=1;i<4*WIDTH;i++)
        {
            if((i%4)!=0)
            {mvaddch(j,i,ACS_HLINE);}
            else
            {mvaddch(j,i,'+');}
        }
    }
    //------画竖线----
    for(j=0;j<2*HIGH;j++)
    {
        for(i=0;i<4*WIDTH+4;i=i+4)
        {
          
            mvaddch(j,i,ACS_VLINE);
          
        }
    }
    //补充边角
    
    for(j=2;j<2*HIGH;j=j+2)
    {
        for(i=4;i<4*WIDTH;i=i+4)
        {
          
            mvaddch(j,i,ACS_PLUS);
          
        }
    }
    mvaddch(0,0,ACS_ULCORNER);
    mvaddch(0,4*WIDTH,ACS_URCORNER);
    mvaddch(2*HIGH,0,ACS_LLCORNER);
    mvaddch(2*HIGH,4*WIDTH,ACS_LRCORNER);
    for(i=4;i<4*WIDTH;i=i+4)
    {
      mvaddch(0,i,ACS_TTEE);
      mvaddch(2*HIGH,i,ACS_BTEE);
    }
    
    for(j=2;j<2*HIGH;j=j+2)
    {
      mvaddch(j,0,ACS_LTEE);
      mvaddch(j,4*WIDTH,ACS_RTEE);
    }

    //画点，表示未点开
    for(j=1;j<2*HIGH;j=j+2)
    {
        for(i=2;i<4*WIDTH;i=i+4)
        {
            attrset(A_REVERSE);
            mvaddch(j,i,' ');
            mvaddch(j,i+1,' ');
            mvaddch(j,i-1,' ');
            
        }
    }
    attrset(A_NORMAL);
    for(i=0;i<HIGH;i++)//初始化结构体
    {
        for(j=0;j<WIDTH;j++)
        {
            Mine[i][j].num=0;
            Mine[i][j].flag=0;
            Mine[i][j].roundnum=0;
            Mine[i][j].process=0;
        }
    }
    /*------显示时间雷数窗口-------*/
    //---------画编辑框----------
    
    for(i=4*WIDTH+3;i<4*WIDTH+33;i++)
        mvaddch(0,i,'*');
    for(i=4*WIDTH+3;i<4*WIDTH+33;i++)
        mvaddch(2*HIGH,i,'*');
    for(j=0;j<2*HIGH+1;j++)
        mvaddch(j,4*WIDTH+3,'*');
    for(j=0;j<2*HIGH+1;j++)
        mvaddch(j,4*WIDTH+33,'*');
    for(i=4*WIDTH+4;i<4*WIDTH+32;i++)
    {
        mvaddch((2*HIGH+1)/3,i,'*');
        mvaddch((2*HIGH+1)/3+1,i,'*');
    }
    //-------------编辑框信息-------------
    showSum();//显示剩余雷数
    showTime();//显示时间
    mvaddstr((2*HIGH+1)/3+2,4*WIDTH+4,"辉子");
    mvaddstr((2*HIGH+1)/3+3,4*WIDTH+4,"辉子豪华定制版扫雷");
    mvaddstr((2*HIGH+1)/3+5,4*WIDTH+4,"RESTART:              'r' ");
    mvaddstr((2*HIGH+1)/3+6,4*WIDTH+4,"LEAVE:                'l' ");
    mvaddstr((2*HIGH+1)/3+7,4*WIDTH+4,"DIFFICULTY:");
    mvaddstr((2*HIGH+1)/3+8,4*WIDTH+4,"EASY:                 '1' ");
    mvaddstr((2*HIGH+1)/3+9,4*WIDTH+4,"NORMAL:               '2' ");
    mvaddstr((2*HIGH+1)/3+10,4*WIDTH+4,"HARD:                 '3' ");
    mvaddstr((2*HIGH+1)/3+11,4*WIDTH+4,"PRESS KEY TO CHOOSE LEVEL");
}

/*----------文件保存------------*/
void saveFile()
{
    FILE *fp1;
    fp1=fopen("ok.txt","w");
    fprintf(fp1,"%d",DIFFICULTY);
    fclose(fp1);
}




