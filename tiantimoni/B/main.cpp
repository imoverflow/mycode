#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int hh,mm;
    scanf("%d:%d",&hh,&mm);
    int time=hh*60+mm;
    if(time>=0&&time<=720)
        printf("Only %02d:%02d.  Too early to Dang.",hh,mm);
    else{
        int cnt=hh%12+(mm!=0);
        for(int i=0;i<cnt;i++)
        {
            printf("Dang");
        }
    }
    return 0;
}
