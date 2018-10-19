#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//char s[100];
//char s1[100];
//map<char,int> ma;
//bool vis[200];
//long long st(long long x)
//{
//    long long ans=1;
//    for(int i=1;i<=x;i++)
//    {
//        ans*=i;
//    }
//    return ans;
//}
//int main()
//{
//    int t;
//    scanf("%d",&t);
//    while(t--)
//    {
//        scanf("%s",s);
//        strcpy(s1,s);
//        long long ans=0;
//        while(strlen(s)!=1)
//        {
//            ma.clear();
//            sort(s1,s1+strlen(s1));
//    //        cout<<s1;
//            int len=strlen(s1);
//            for(int i=0;i<len;i++)
//            {
//                if(ma[s1[i]]==0)
//                    ma[s1[i]]=i;
//            }
//            bool flag=0;
//            for(int i=0;i<len;i++)
//            {
//                int cnt=0;
//                memset(vis,0,sizeof vis);
//                for(int j=i+1;j<len;j++)
//                {
//                    if(vis[s[j]]==false)
//                    {
//                        cnt++;
//                        vis[s[j]]=true;
//                    }
//                }
//                if(ma[s[i]]>=ma[s1[i]])
//                    ans+=(ma[s[i]]-ma[s1[i]])*st(cnt);
//                else
//                {
//                    flag=1;
//                    strcpy(s1,s+i);
//                    strcpy(s,s+i);
//                    break;
//                }
//            }
//            if(flag==0)
//                break;
//        }
////        ans+=(ma[s1[0]]-ma[s[0]])*(ma[s[0]]<ma[s1[0]]);
////        cout<<s[0]<<s1[0]<<endl;
//        printf("%lld\n",ans);
//    }
//    return 0;
//}

char s[100];
char s1[100];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        strcpy(s1,s);
        sort(s1,s1+strlen(s1));
        long long ans=0;
        int len=strlen((s1));
        while(strcmp(s1,s)!=0)
        {
            ans++;
            next_permutation(s1,s1+len);

        }
        printf("%lld\n",ans);
    }
    return 0;
}

