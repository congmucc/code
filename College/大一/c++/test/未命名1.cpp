#include<stdio.h>
int main()
{
	int a=5,b=4,c=3,d=2;
	if(a>b>c>d)
	{
        printf("%d",d);
	}
    else if((c-1>=d)==1)
        printf("%d",d+1);
    else
	    printf("%d",d+2) ;
        return 0;
}
