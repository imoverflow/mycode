#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        double st=5,p1,p2;
        int n;
        scanf("%d%lf%lf",&n,&p1,&p2);
        for(int i=0;i<n;i++)
        {
            st=p1*st*2+p2*st*1.5+(1-p1-p2)*st;
        }
        printf("Case #%d: %.2e\n",k,st);
    }
    return 0;
}
