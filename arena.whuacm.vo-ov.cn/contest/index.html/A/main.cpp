#include <iostream>
#include <bits/stdc++.h>
using namespace std;
unsigned long ans[2000006];
int main()
{
    ans[0]=0;
    bitset<32> s;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        char t[100];
        int x;
        scanf("%s%d",t,&x);
        if(t[1]=='o')
        {
            s^=x;
        }else{
            s=ans[x];
        }
        ans[i]=s.to_ulong();
        printf("%lu\n",ans[i]);
    }
    return 0;
}
