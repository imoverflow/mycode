#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int D,R,T;
    while(~scanf("%d%d%d",&D,&R,&T))
    {
        for(int rage=4;rage*rage+rage<=2*(R+T)+6;rage++)
        {
            int tage=rage-D;
            int rcandle=(rage*rage+rage)/2-6;
            int tcandle;
            if(tage<3)
                tcandle=0;
            else
                tcandle=(tage*tage+tage)/2-3;
            if(rcandle+tcandle==R+T)
            {
                printf("%d\n",R-rcandle);
                break;
            }
        }
    }
    return 0;
}
