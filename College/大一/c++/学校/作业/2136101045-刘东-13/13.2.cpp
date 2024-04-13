#include <iostream>

using namespace std;

void an(int *arr,int len);

void cm(int *arr,int len);
int main()
{
    int arr[10]={1,4,5,7,9,2,3,6,8,10};

    int len = sizeof(arr)/sizeof(arr[0]);

    an(arr,len);

    cm(arr,len);

    return 0;
}

void an(int *arr,int len)
{
    int i,j,s;
    for(i=0;i<len-1;i++)
    {
        for(j=0;j<len-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                s=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=s;
            }
        }
    }


}


void cm(int *arr,int len)
{
    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<endl;
    }
}


