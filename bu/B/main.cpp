#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const long long MOD=1e9+7;
string s[100005];
char ss[100005];
struct aaa{
    int pos[100005];
    char id;
}cnt[30];
int ma=0;
int link[30];
//int cnt[50][100000];
set<char>first;
long long mod_pow(long long x,long long n)
{
    long long res=1;
    while(n>0)
    {
        if(n&1) res*=x%MOD;
        x=x*x%MOD;
        n>>=1;
    }
    return res;
}
bool cmp(const struct aaa &a,const struct aaa &b)
{
    for(int i=ma;i>=0;i--)
    {
        if(a.pos[i]!=b.pos[i])
        {
            return a.pos[i]>b.pos[i];
        }
    }
    return false;
}
int main()
{
//    printf("%lld\n",mod_pow(26,0));
//    printf("%lld\n",mod_pow(26,1));
//    printf("%lld\n",mod_pow(26,2));
//    printf("%lld\n",mod_pow(26,3));
//    freopen("1002.in","r",stdin);
//    freopen("my.out","w",stdout);
    int n;
    int cases=1;
    while(~scanf("%d",&n))
    {
        first.clear();
        ma=0;
        memset(link,0,sizeof link);
        memset(cnt,0,sizeof cnt);
//        memset(s,0,sizeof s);
        for(int i=0;i<n;i++)
        {
            scanf("%s",ss);
            s[i]=ss;
            int len=strlen(ss);
            ma=max(ma,len);
            for(int k=0,j=len-1;k<len;k++,j--)
            {
                if(k==0) first.insert(ss[k]);
                cnt[ss[k]-'a'].pos[j]++;
                if(cnt[ss[k]-'a'].pos[j]>=26)
                {
                    ma=max(ma,j+1);
                    cnt[ss[k]-'a'].pos[j+1]+=cnt[ss[k]-'a'].pos[j]/26;
                    cnt[ss[k]-'a'].pos[j]%=26;
                }
            }
        }
        for(int i=0;i<26;i++)
        {
            cnt[i].id='a'+i;
        }
        sort(cnt,cnt+26,cmp);
        int num=25;
//        for(int i=0;i<26;i++)
//        {
//            if(first.find(cnt[i].id)!=first.end())
//            {
//                link[cnt[i].id-'a']=num--;
//            }
//        }
//        for(int i=0;i<26;i++)
//        {
//            if(first.find(cnt[i].id)==first.end())
//            {
//                link[cnt[i].id-'a']=num--;
//            }
//        }
        char x=0;
        for(int i=25;i>=0;i--)
        {
            if(first.find(cnt[i].id)==first.end())
            {
                link[cnt[i].id-'a']=0;
                x=cnt[i].id;
                break;
            }
        }
        for(int i=0;i<26;i++)
        {
            if(cnt[i].id!=x)
            {
                link[cnt[i].id-'a']=num--;
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            int p=s[i].length();
            for(int j=0;j<p;j++)
            {
                ans+=link[s[i][j]-'a']*mod_pow(26,p-1-j)%MOD;
            }
        }
        printf("Case #%d: %lld\n",cases++,ans%MOD);
    }
    return 0;
}
