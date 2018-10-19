#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int s[4]={0};
int die(int a,int b,int c,int d,int blood,int fee)
{
    if(blood<=0)
        return 1;
    if(c+1<=s[2] && fee>=2 && die(a,b,c+1,d,blood,fee-2))
        return 1;
    if(d+1<=s[3] && fee>=4 && die(a,b,c,d+1,blood,fee-4))
        return 1;
    if(a+1<=s[0] && fee>=4 && die(a+1,b,c,d,blood-6-c-d*2,fee-4))
        return 1;
    if(b+1<=s[1] && fee>=2 && die(a,b+1,c,d,blood-3-c-d*2,fee-2))
        return 1;
    return 0;
}
int main()
{
    char s1[100];
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int card,blood;
        scanf("%d %d",&card,&blood);
        for(int i=0;i<card;i++)
        {
            scanf("%s",s1);
            if(strcmp(s1,"Fire")==0)
                s[0]++;
            else if(strcmp(s1,"Ice")==0)
                s[1]++;
            else if(strcmp(s1,"Dog")==0)
                s[2]++;
            else if(strcmp(s1,"Evolved")==0)
                s[3]++;
        }
        int m=die(0,0,0,0,blood,10);
        if(m==1)
            printf("Yes\n");
        else
            printf("No\n");
        for(int i=0;i<4;i++)
        {
            s[i]=0;
        }
    }
    return 0;
}
