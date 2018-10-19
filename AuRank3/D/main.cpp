#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int tool[200];
int ans[5000];
int main()
{
    int n;
    int uni=0;
    scanf("%d",&n);
    int flag=1;
    int cnt=0;
    memset(ans,0,sizeof ans);
    memset(tool,0,sizeof tool);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        if(a>0)
            tool[a]++;
        else if(a==0)
            uni++;
        else{
            if(tool[-a]>0)
            {
                tool[-a]--;
            }else{
                if(uni>0)
                {
                    ans[cnt++]=-a;
                    uni--;
                }else{
                    flag=0;
                }
            }
        }
    }
    if(flag==0)
        printf("No\n");
    else{
        printf("Yes\n");
        for(int i=0;i<cnt;i++)
        {
            if(i==0)
                printf("%d",ans[i]);
            else
                printf(" %d",ans[i]);
        }
        if(uni!=0)
        {
            if(cnt!=0)
            {
                while(uni--)
                {
                    printf(" 1");
                }
            }else{
                for(int i=0;i<uni;i++)
                {
                    if(i==0)
                        printf("1");
                    else
                        printf(" 1");
                }
            }
        }
    }
    return 0;
}
