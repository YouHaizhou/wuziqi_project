#include"wuziqi.h"

#include<iostream>
using namespace std;

//图的初始化，0为空
void init(){
    for(int i=0;i<row;i++){
        for(int j=0;j<line;j++){
            map[i][j]=0;
        }
    }
    flag=0;
}

//判断落子后是否五子连珠
int iswin(int x,int y){             //0表示未分出胜负，1表示黑棋胜，2表示白棋胜
    int color=map[x][y];
    
    int count=1;                             //对该子的竖直方向进行判断
    int xu=x-1,xd=x+1;             
    while(xd<=row-1){
        if(map[xd][y]==color){
            xd++;
            count++;
        }
        else
            break;
    }
    while(xu>=0){
        if(map[xu][y]==color){
            xu--;
            count++;
        }
        else
            break;
    }
    if(count>=5)
        return color;
    
//
    count=1;                                 //对该子的水平方向进行判断
    int yl=y-1,yr=y+1;                
    while(yl>=0){
        if(map[x][yl]==color){
            yl--;
            count++;
        }
        else
            break;
    }
    while(yr<=line-1){
        if(map[x][yr]==color){
            yr++;
            count++;
        }
        else
            break;
    }
    if(count>=5)
        return color;
    
//
    count=1;                                        //对该子的右斜方向进行判断
    int xru=x-1,xld=x+1,yru=y+1,yld=y-1;        
    while(xru>=0&&yru<=line-1){
        if(map[xru][yru]==color){
            xru--;
            yru++;
            count++;
        }
        else 
            break;
    }
    while(xld<=row-1 && yld>=0){
        if(map[xld][yld]==color){
            xld++;
            yld--;
            count++;
        }
        else
            break;
    }
    if(count>=5)
        return color;
    
//
    count=1;                                        //对该子的左斜方向进行判断
    int xlu=x-1,xrd=x+1,ylu=y-1,yrd=y+1;            
    while(xlu>=0 && ylu>=0){
        if(map[xlu][ylu]==color){
            xlu--;
            ylu--;
            count++;
        }
        else
            break;
    }
    while(xrd<=row-1 && yrd<=line-1){
        if(map[xrd][yrd]==color){
            xrd++;
            yrd++;
            count++;
        }
        else
            break;
    }
    if(count>=5)
        return color;
    return 0;
}
    
//落子操作，返回true表示落子成功，返回false表示落子失败 
bool playmore(int x,int y){
    if(map[x][y]==0){
        map[x][y]=(flag%2)+1;
        flag++;
        return true;
    }
    else
        return false;
}


//显示棋盘
void gameview_Showmap(){
    //0:空 1:黑棋 2:白棋
    for(int i=0;i<row;i++){
        for(int j=0;j<line;j++){
            if(map[i][j]==0)
                cout<<"  ";
            else if(map[i][j]==1)
                cout<<"●";
            else if(map[i][j]==2)
                cout<<"○";
        }
        cout<<'\n';
    }
}

//显示胜利界面
void winmenu(){
    if( (flag-1)%2 ==0)     //flag为奇数时，表示白棋胜利，为偶数时，表示黑棋胜利
        cout<<"black chess win！\n";
    else
        cout<<"white chess win！\n";
    char c;
    cin>>c;
    menuview();         //输入任意字符后返回主菜单
}

//显示游戏主界面
void menuview(){
    char c;
    cout<<"Please enter to begin game\n";
    cout<<"press q to exit the game\n";
    cin>>c;
    if(c=='q')
        exit(0);
    else if(c=='\n')
        gameview();
    else
        menuview();
}

//游戏程序
void gameview(){
    init();
    while(1){
        gameview_Showmap();
        int x,y;
        cout<<"Please enter coordinates\n";
        cin>>x>>y;
        if(playmore(x,y)){
            if(iswin(x,y)){
                gameview_Showmap();
                winmenu();
            }
        }
        else{
            cout<<"already chess there\n";
        }
    }
}

int main(){
    menuview();
    return 0;
}