#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct P{
    long long x,y;
    P(){}
    P(long long x,long long y):x(x),y(y){}
    P operator +(P p)
    {
        return P(x+p.x,y+p.y);
    }
    P operator -(P p)
    {
        return P(x-p.x,y-p.y);
    }
    P operator *(long long d)
    {
        return P(x*d,y*d);
    }
    long long dot(P p)
    {
        return x*p.x+y*p.y;
    }
    long long det(P p)
    {
        return x*p.y-y*p.x;
    }
}s[100005];
bool cmp(const P &p,const P &q)
{
    if(p.x!=q.x) return p.x<q.x;
    return p.y<q.y;
}
bool on_seg(P p1,P p2,P q)
{
    return (p1-q).det(p2-q)==0;
    //&&(p1-q).dot(p2-q)<=0;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s[i].x>>s[i].y;
    }
    if(n<=3)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    if(on_seg(s[0],s[1],s[2]))
    {
        int index=-1;
        for(int i=3;i<n;i++)
        {
            if(!on_seg(s[0],s[1],s[i]))
            {
                index=i;
                break;
            }
        }
        if(index==-1)
        {
            cout<<"YES"<<endl;
            return 0;
        }
        int a[]={0,1,2};
        bool ans=false;
        bool res=true;
        P line2;
        bool flag=false;
        for(int i=index+1;i<n;i++)
        {
            if(flag==false)
            {
                if(on_seg(s[a[0]],s[a[1]],s[i]))
                {
                    ;
                }else{
                    flag=true;
                    line2=s[i];
                }
            }else{
                if(on_seg(s[0],s[1],s[i])||on_seg(s[index],line2,s[i]))
                {
                    ;
                }else{
                    res=false;
                    break;
                }
            }
        }
        ans|=res;
        if(ans)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }else{
        int a[]={0,1,2};
        bool ans=false;
        do{
            bool res=true;
            P line2;
            bool flag=false;
            for(int i=3;i<n;i++)
            {
                if(flag==false)
                {
                    if(on_seg(s[a[0]],s[a[1]],s[i]))
                    {
                        ;
                    }else{
                        flag=true;
                        line2=s[i];
                    }
                }else{
                    if(on_seg(s[a[0]],s[a[1]],s[i])||on_seg(s[a[2]],line2,s[i]))
                    {
                        ;
                    }else{
                        res=false;
                        break;
                    }
                }
            }
            ans|=res;
        }while(next_permutation(a,a+3));
        if(ans)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}

