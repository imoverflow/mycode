#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> s;
char sss[200006];
int mo;
void T(int x)
{
    if(x%2==0) return;
    int len=s.size();
    for(int i=0;i<len;i+=2)
    {
        swap(s[(i+mo+len)%len],s[(i+1+mo+len)%len]);
    }

}
void M(int x)
{
//    int len=s.size();
//    x=x%len;
//    if(x==0) return;
//    if(x>0)
//    {
//        for(int i=0;i<x;i++)
//        {
//            int c=s[len-1];
//            s.erase(--s.end());
//            s.insert(s.begin(),c);
//        }
//    }else{
//        for(int i=0;i<abs(x);i++)
//        {
//            int c=s[0];
//            s.erase(s.begin());
//            s.insert(s.end(),c);
//        }
//    }
    mo=x%s.size();
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        s.clear();
        int n,q;
        scanf("%d%d",&n,&q);
        for(int i=0;i<n;i++)
        {
            s.push_back(i+1);
        }
        int now=0,turn=0,p;
        mo=0;
        for(int i=0;i<q;i++)
        {
            if(now==0)
            {
                scanf("%d",&p);
                if(p==1)
                {
                    now=1;
                    int x;
                    scanf("%d",&x);
                    mo=x;
                }else{
                    now=2;
                    turn++;
                }
            }else{
                scanf("%d",&p);
                if(p==1)
                {
                    int x;
                    scanf("%d",&x);
                    mo+=n-(x%n);
                    if(now==p)
                    {
                        ;
                    }else{
                        T(turn);
//                        turn=0;
                    }
                    now=p;
                }else{
                    if(now==p)
                    {
                        turn++;
                    }else{
                        M(mo);
//                            mo=0;
                        turn++;
                    }
                    now=p;
                }
            }
        }
        if(turn!=0)
            T(turn);
//        if(mo!=0)
//            M(mo);
        for(int i=0;i<n;i++)
        {
            if(i==0)
                printf("%d",s[(i+mo)%n]);
            else
                printf(" %d",s[(i+mo)%n]);
        }
        printf("\n");
    }
    return 0;
}
/*
2
6 3
1 -2
1 -1
2
*/
