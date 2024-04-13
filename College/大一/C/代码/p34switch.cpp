#include<stdio.h>



int main()
{
	int score;
	scanf("%d",&score);
    switch(score/10)
    {
    	case 10:
    		printf("优秀"); 
            break;
    	case 9:
    		printf("良好");
    		break;
    		
    	default:  //和else差不多 
    	printf("不及格");
    	break;
	}
	
	 
	return 0;
 } 
