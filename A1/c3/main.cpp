#include <iostream>
#include <stdio.h>
#include <string.h>
#define N 3
using namespace std;
void func(char s[], int n)
{
    int flag;
    int i=0;
    int count=0;
    while(s[i]!='\0')
    {
        count++;          //strlen(s)
        i++;
    }
    for(i=count-1;i>=0;i--)
    {
        if(s[i]!='*')
        {
            flag=i;
            break;
        }
    }
    if(count-flag-1>n&&n<7)
    {
        s[flag+n+1]='\0';
    }
}
int main()
{
    char s[20]="123*124****";
    func(s,4);
    puts(s);
    return 0;
}
