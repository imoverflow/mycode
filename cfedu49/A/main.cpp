#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char s[200];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        scanf("%s",s);
        bool flag=true;
        for(int i=0,j=n-1;i<n/2;i++,j--)
        {
//            cout<<s[i]-s[j]<<endl;
            if(abs(s[i]-s[j])!=2&&abs(s[i]-s[j])!=0)
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
