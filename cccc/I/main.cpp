#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stack>
#include <math.h>
using namespace std;

int s[100005];
int main()
{
    int n,t;
    scanf("%d%d",&n,&t);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
    }
    int time=0;
    int a=0;
    for(int i=0;i<n;i++)
    {
        if(time+s[i]<=t)
        {
            a++;
            time+=s[i];
        }else{
            break;
        }
    }
    time=0;
    int b=0;
    for(int i=n-1;i>=0;i--)
    {
        if(time+s[i]<=t)
        {
            b++;
            time+=s[i];
        }else{
            break;
        }
    }
    if(a>b)
    {
        printf("Yan\n");
    }else if(a==b){
        printf("Empate\n");
    }else{
        printf("Nathan\n");
    }
    return 0;
}
