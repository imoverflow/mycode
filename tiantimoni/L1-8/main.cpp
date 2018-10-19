#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int day,hh,mm;
        scanf("%d%d:%d",&day,&hh,&mm);
        if(day==0)
        {
            printf("%d %02d:%02d\n",day,hh,mm);
            continue;
        }
        int time=(day-1)*24*60+hh*60+mm;
        time/=2;
        int wday=time/(48*60);
        time-=wday*48*60;
        int wh=time/60;
        if(wh>=24)
        {
            wday++;
            wh-=24;
        }
        if(wh==24)
        {
            time-=wh*60;
            wday++;
            wh=0;
        }
        time-=wh*60;
        int wm=time;
        printf("%d %02d:%02d\n",wday+1,wh,wm);
    }
    return 0;
}
