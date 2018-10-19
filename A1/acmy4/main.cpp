#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
using namespace std;
void ins(char a[100],int n)
{
        int k;
        k=n/100;
        switch (k)
    {
    case 4:
        strcat(a,"-r--\0");
        break;
    case 2:
        strcat(a,"-w-\0");
        break;
    case 1:
        strcat(a,"--x\0");
        break;
    case 6:
        strcat(a,"-rw-\0");
        break;
    case 5:
        strcat(a,"-r-x\0");
        break;
    case 3:
        strcat(a,"-wx\0");
        break;
    case 7:
        strcat(a,"-rwx\0");
        break;
    }
    k=(n%100)/10;
    switch (k)
    {
    case 4:
        strcat(a,"r--\0");
        break;
    case 2:
        strcat(a,"-w-\0");
        break;
    case 1:
        strcat(a,"--x\0");
        break;
    case 6:
        strcat(a,"rw-\0");
        break;
    case 5:
        strcat(a,"r-x\0");
        break;
    case 3:
        strcat(a,"-wx\0");
        break;
    case 7:
        strcat(a,"rwx\0");
        break;
    }
    k=n%10;
    switch (k)
    {
    case 4:
        strcat(a,"r--\0");
        break;
    case 2:
        strcat(a,"-w-\0");
        break;
    case 1:
        strcat(a,"--x\0");
        break;
    case 6:
        strcat(a,"rw-\0");
        break;
    case 5:
        strcat(a,"r-x\0");
        break;
    case 3:
        strcat(a,"-wx\0");
        break;
    case 7:
        strcat(a,"rwx\0");
        break;
    }

}
int main()
{
    int a,b,c,d;
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
        char s[100];
        char cmp[100];
        cmp[0]='\0';
        scanf("%d %s",&b,s);
        ins(cmp,b);
        if(strcmp(s,cmp)==0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
