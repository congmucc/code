#include<bits/stdc++.h>
using namespace std;
struct Point{//����ṹ�� 
    double x, y;
}p[25*25];
map<pair<double,double>,int> line;//pair ��б��k�ͽؾ�b����ʾֱ��line ��mapȥ�� 
int main(){
    int cnt = 0;
    int col = 20, row = 21;//��������0��19(����0��19)֮�����������ô������20������col=20����������0��20����ô��21�����ߣ���row=21
    for(int i=0; i<col; i++)//ö�����е㣬��������p�� 
        for(int j=0; j<row; j++){
            p[cnt].x = i;
            p[cnt++].y = j;
        } 
    int linenum = row + col;//���ߺ����������������ȼ���linenum����ֵlinenum=row+col 
    for(int i=0; i<cnt; i++)
        for(int j=0; j<cnt; j++){//ö�����е� 
            if(p[i].x == p[j].x || p[i].y == p[j].y) continue;//����ж����һ��ֱ���ϣ� ��ô��Щ������������ȷ����ֱ����ͬһ��
            double k = (p[j].y - p[i].y) / (p[j].x - p[i].x);//����ֱ�ߵ�б��k 
            double b = ((p[j].x * p[i].y) - (p[j].y * p[i].x)) / (p[j].x - p[i].x);//����ֱ�ߵĽؾ�b 
            //�ж�(i,j)���������ֱ��line(k,b)�Ƿ�֮ǰ�Ѿ������linenum�� 
            if(line[{k,b}] == 0){//����ǳ�����������ֱ��line����ô��map��Ϊ1�����Ҽ���linenum����linenum++��
//�����ʾ֮ǰ�Ѿ����ֹ���ֱ��line(k,b)��������ͳ�� 
                line[{k,b}] = 1;
                linenum ++;
            }
        }
    cout << linenum << endl;
    return 0;
}

