#include<stdio.h>



int main()
{
	int score;
	scanf("%d",&score);
    switch(score/10)
    {
    	case 10:
    		printf("����"); 
            break;
    	case 9:
    		printf("����");
    		break;
    		
    	default:  //��else��� 
    	printf("������");
    	break;
	}
	
	 
	return 0;
 } 
