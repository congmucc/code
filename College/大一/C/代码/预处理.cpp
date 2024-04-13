#include<stdio.h>
#include<stdbil.h>

int main()
{
    char* str;
    str=(char*)malloc(sizeof(char) * 5);
    gets(str);
    puts(str);
    return 0;
 } 
