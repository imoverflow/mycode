#include <iostream>
#include <bits/stdc++.h>
using namespace std;

map<char,int>ma;
set<char>ss;
set<char>single;
set<char>nsingle;
char s[400005];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<n;i++)
    {
        ma[s[i]]++;
        ss.insert(s[i]);
    }
    int cnt=0;
    for(set<char>::iterator it=ss.begin();it!=ss.end();it++)
    {
        if(ma[(*it)]%2==1)
        {
            cnt++;
            single.insert(*it);
            if(ma[*it]>1)
                nsingle.insert(*it);
        }else{
            nsingle.insert(*it);
        }
    }

    int siz;
    if(cnt!=0)
        siz=n/cnt;
    else
        siz=0;
    if(siz%2!=1)
    {
        while(siz%2==0&&siz!=0)
        {
            siz/=2;
            cnt*=2;
        }
    }
    if(cnt!=0&&n%cnt!=0||cnt!=0&&siz==1||cnt==n)
    {
        printf("%d\n",n);
        for(int i=0;i<n;i++)
        {
            if(i==0)
                printf("%c",s[i]);
            else
                printf(" %c",s[i]);
        }
        printf("\n");
        return 0;
    }else{
        string ans="";
        if(cnt==0)
        {
            printf("1\n");
            for(set<char>::iterator it=nsingle.begin();it!=nsingle.end();it++)
                ans.insert(ans.length()/2,ma[*it],*it);
            cout<<ans<<endl;
            return 0;
        }
        if(cnt==1)
        {
            printf("1\n");
            for(set<char>::iterator it=nsingle.begin();it!=nsingle.end();it++)
            {
                single.erase(*it);
                ans.insert(ans.length()/2,ma[*it],*it);
            }
            for(set<char>::iterator it=single.begin();it!=single.end();it++)
                ans.insert(ans.length()/2,ma[*it],*it);
            cout<<ans<<endl;
            return 0;
        }
        printf("%d\n",cnt);
        while(cnt--)
        {
            int len=0;
            ans="";
            set<char>::iterator it1=nsingle.begin();
            set<char>::iterator it2=single.begin();
            if(single.size()!=0)
            {
                while(len<siz-1)
                {
                    it1=nsingle.begin();
                    int a=len;
                    len+=min(siz-1-len,ma[*it1]-(ma[*it1]%2!=0));
                    ans.insert(ans.length()/2,min(siz-1-a,ma[*it1]-(ma[*it1]%2!=0)),*it1);
//                    cout<<ans<<endl;
                    ma[*it1]-=min(siz-1-a,ma[*it1]-(ma[*it1]%2!=0));
                    if(ma[*it1]==0||ma[*it1]==1)
                        nsingle.erase(it1);
                }
                ans.insert(ans.length()/2,1,*it2);
                ma[*it2]--;
                single.erase(it2);
                cout<<ans<<" ";
            }
            else{
                while(len<siz-1)
                {
                    len+=min(siz-1,ma[*it1]);
                    ans.insert(ans.length()/2,min(siz-1,ma[*it1]),*it1);
                    ma[*it1]-=min(siz-1,ma[*it1]);
                    if(ma[*it1]==0)
                        nsingle.erase(it1);
                }
                it1=nsingle.begin();
                ans.insert(ans.length()/2,1,*it1);
                ma[*it1]--;
                if(ma[*it1]==0)
                    nsingle.erase(it1);
                cout<<ans<<" ";
            }
        }
        printf("\n");
    }
    return 0;
}
