#include<stdio.h>


void test01()
{
	int nums[]={1,2,3,4};
	int target=3;
	   int i,j;
        for(i=0;i<4;i++)
        {
           for(j=i+1;j<4;j++)
           {
           	
               if(nums[i]+nums[j]==target)
               {
                  // return{i,j};
                   break;
               }
           }
        }
       printf("%d\n%d",i,j);
}



int main()
{
	test01();
	return 0;
	
}
