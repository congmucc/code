#include "stdio.h"
#include "time.h"
 #include <windows.h>
 
  //===================================================
  //
  //  Title:  C����ʵ��С���ƶ� V1.0 
  //  Author: ����
  //  Date : 2020/05/28
 // 
 //=================================================== 
 
 
 
 int main(){
    int i,j;
     
     int P_X = 2; //����λ��X���� 
     int P_Y = 7; //����λ��Y���꣬�Խ�Ϊ׼ 
     int HEIGHT = 12; //�߶� 
     int WEIGHT = 12; //��� 
     int P_SPEED = 1; //�ƶ��ٶ�
    char WARNING[10] = " "; //�������� 
 
     char people_head = '0'; //��� 
     char people_arm = 'L'; //��� 
     char people_leg = 'X'; //��      
     char graph[HEIGHT][WEIGHT]; //��ͼ���� 
     
    while(1){
    for(i=0;i<HEIGHT;i++){ //���ɵ�ͼ 
         for(j=0;j<WEIGHT;j++){
             if(i==8){
                 graph[i][j] = '='; //½�� 
             }
             else{
                graph[i][j] = ' '; //����    
             }    
         }
     }
         
     if(GetAsyncKeyState(VK_SPACE)){ //��Ծ 
        
     }
     else if(GetAsyncKeyState(VK_LEFT)){ //����
        if(P_X>0 && P_X<=11){
             P_X-=P_SPEED;
             strcpy(WARNING," ");
         }
         else{
            strcpy(WARNING,"�����ƶ���");
             P_X+=1;
         }
     }
     else if(GetAsyncKeyState(VK_RIGHT)){ //���� 
         if(P_X>0 && P_X<=11){
             P_X+=P_SPEED;
             strcpy(WARNING," ");
         }
         else{
             strcpy(WARNING,"�����ƶ���");
             P_X-=1;
         }
     }
 
     graph[P_Y-2][P_X] = people_head; //������ 
     graph[P_Y-1][P_X] = people_arm;
     graph[P_Y][P_X] = people_leg;
     
     for(i=0;i<HEIGHT;i++){ //��ʾͼ�� 
         for(j=0;j<WEIGHT;j++){
             printf("%c ",graph[i][j]);
         }
         printf("\n");
     }
     printf("\n�˵� X ���꣺%d",P_X);
     printf("\n�˵� Y ���꣺%d",P_Y);
     printf("\n��Ϣ��%s",WARNING);

     system("cls"); //ˢ����Ļ 
     }
 return 0; 
 }
