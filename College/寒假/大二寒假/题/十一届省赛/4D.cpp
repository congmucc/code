#include<iostream>
using namespace std;
int judge(int year)
{
     if((year%4==0&&year%100!=0)||year%400==0)
	 {
	    return 1;	
     }	
     else return 0;
} 
int main()
{
	int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int y,m,d;
	int w=6;
	int step=0;
	for(y=2000;y<=2020;y++)
	   for(m=1;m<=12;m++)
	      for(d=1;d<=day[m]+((m==2)?judge(y):0);d++,w=w%7+1)
	      {
	      	 step++;
	      	 if(d==1||w==1) step++;
	      	 if(y==2020&&m==10&&d==1)
	      	 {
	      	    cout << step << endl;	
			 }
		  }
	return 0;
}
