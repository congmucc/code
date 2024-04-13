#include<bits/stdc++.h>
using namespace std;
struct Point{//定义结构体 
    double x, y;
}p[25*25];
map<pair<double,double>,int> line;//pair 存斜率k和截距b，表示直线line 用map去重 
int main(){
    int cnt = 0;
    int col = 20, row = 21;//横坐标是0到19(包含0和19)之间的整数，那么竖线有20条，即col=20；纵坐标是0到20，那么有21条横线，即row=21
    for(int i=0; i<col; i++)//枚举所有点，存入数组p中 
        for(int j=0; j<row; j++){
            p[cnt].x = i;
            p[cnt++].y = j;
        } 
    int linenum = row + col;//横线和竖线条数加起来先计入linenum，初值linenum=row+col 
    for(int i=0; i<cnt; i++)
        for(int j=0; j<cnt; j++){//枚举所有点 
            if(p[i].x == p[j].x || p[i].y == p[j].y) continue;//如果有多点在一条直线上， 那么这些点中任意两点确定的直线是同一条
            double k = (p[j].y - p[i].y) / (p[j].x - p[i].x);//计算直线的斜率k 
            double b = ((p[j].x * p[i].y) - (p[j].y * p[i].x)) / (p[j].x - p[i].x);//计算直线的截距b 
            //判断(i,j)构造出来的直线line(k,b)是否之前已经计入过linenum中 
            if(line[{k,b}] == 0){//如果是初次遇见的新直线line，那么就map其为1，并且计入linenum，即linenum++；
//否则表示之前已经出现过此直线line(k,b)，就无需统计 
                line[{k,b}] = 1;
                linenum ++;
            }
        }
    cout << linenum << endl;
    return 0;
}

