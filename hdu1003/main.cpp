#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int t,a,b,c,oldsum,newsum,olds,olde,news,newe;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&a);
        for(int i=1;i<=a;i++)
        {
            scanf("%d",&c);
            if(i==1)
            {
                olds=olde=news=newe=i;
                oldsum=newsum=c;
            }else{
                if(oldsum>newsum+c)
                {
                    olde=i-1;
                    news=i;
                    newsum+=c;
                }else{
                    oldsum+=c;
                }
            }
            if(newsum>oldsum)
            {
                olds=news;
                olde=newe;
                oldsum=newsum;
            }
        }
    }
    return 0;
}
