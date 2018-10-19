#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char s[5006];
bool ispa(int l,int r)
{
    for(int i=l,j=r;i<j;i++,j--)
    {
        if(s[i]!=s[j])
            return false;
    }
    return true;
}
int ans[5005];
int len;
bool dfs(int num,int l,int r)
{
    if(num>len) return false;
    ans[num]++;
    if(r-l>0&&ispa(l,(l+r)/2-((r-l+1)%2==1))&&ispa((l+r)/2+((r-l+1)%2==1),r))
    {
        dfs(num+1,l,(l+r)/2-((r-l+1)%2==1));
    }

}
int main()
{
    freopen("in.txt","r",stdin);
    memset(ans,0,sizeof(ans));
    scanf("%s",s);
    len=strlen(s);
//    for(int i=0;i<len;i++)
//    {
//        for(int j=i;j<len;j++)
//        {
//            dfs(i,j);
//        }
//    }
    for(int i=0;i<len;i++)
    {
        for(int j=i;j<len;j++)
        {
            if(ispa(i,j))
                dfs(1,i,j);
        }
    }
    for(int i=1;i<=len;i++)
    {
        printf("%d ",ans[i]);
    }
    return 0;
}
