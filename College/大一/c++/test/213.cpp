#include "stdio.h"
#include "time.h"
 #include <windows.h>
 
  //===================================================
  //
  //  Title:  C语言实现小人移动 V1.0 
  //  Author: 邹阳
  //  Date : 2020/05/28
 // 
 //=================================================== 
 
 
 
 int main(){
    int i,j;
     
     int P_X = 2; //身体位置X坐标 
     int P_Y = 7; //身体位置Y坐标，以脚为准 
     int HEIGHT = 12; //高度 
     int WEIGHT = 12; //宽度 
     int P_SPEED = 1; //移动速度
    char WARNING[10] = " "; //警告内容 
 
     char people_head = '0'; //胳臂 
     char people_arm = 'L'; //胳臂 
     char people_leg = 'X'; //腿      
     char graph[HEIGHT][WEIGHT]; //地图数组 
     
    while(1){
    for(i=0;i<HEIGHT;i++){ //生成地图 
         for(j=0;j<WEIGHT;j++){
             if(i==8){
                 graph[i][j] = '='; //陆地 
             }
             else{
                graph[i][j] = ' '; //空气    
             }    
         }
     }
         
     if(GetAsyncKeyState(VK_SPACE)){ //跳跃 
        
     }
     else if(GetAsyncKeyState(VK_LEFT)){ //向左
        if(P_X>0 && P_X<=11){
             P_X-=P_SPEED;
             strcpy(WARNING," ");
         }
         else{
            strcpy(WARNING,"不能移动！");
             P_X+=1;
         }
     }
     else if(GetAsyncKeyState(VK_RIGHT)){ //向右 
         if(P_X>0 && P_X<=11){
             P_X+=P_SPEED;
             strcpy(WARNING," ");
         }
         else{
             strcpy(WARNING,"不能移动！");
             P_X-=1;
         }
     }
 
     graph[P_Y-2][P_X] = people_head; //放置人 
     graph[P_Y-1][P_X] = people_arm;
     graph[P_Y][P_X] = people_leg;
     
     for(i=0;i<HEIGHT;i++){ //显示图像 
         for(j=0;j<WEIGHT;j++){
             printf("%c ",graph[i][j]);
         }
         printf("\n");
     }
     printf("\n人的 X 坐标：%d",P_X);
     printf("\n人的 Y 坐标：%d",P_Y);
     printf("\n信息：%s",WARNING);

     system("cls"); //刷新屏幕 
     }
 return 0; 
 }
