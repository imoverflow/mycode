#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int s[100][100];
bool check()
{
    set<int>ss;
    ss.clear();
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            ss.insert(s[i][j]);
        }
    }
    if(ss.size()!=1)
        return false;
    ss.clear();
    for(int i=0;i<2;i++)
    {
        for(int j=2;j<4;j++)
        {
            ss.insert(s[i][j]);
        }
    }
    if(ss.size()!=1)
        return false;
    ss.clear();
    for(int i=0;i<2;i++)
    {
        for(int j=4;j<6;j++)
        {
            ss.insert(s[i][j]);
        }
    }
    if(ss.size()!=1)
        return false;
    ss.clear();
    for(int i=2;i<4;i++)
    {
        for(int j=2;j<4;j++)
        {
            ss.insert(s[i][j]);
        }
    }
    if(ss.size()!=1)
        return false;
    ss.clear();
    for(int i=4;i<6;i++)
    {
        for(int j=2;j<4;j++)
        {
            ss.insert(s[i][j]);
        }
    }
    if(ss.size()!=1)
        return false;
    ss.clear();
    for(int i=6;i<8;i++)
    {
        for(int j=2;j<4;j++)
        {
            ss.insert(s[i][j]);
        }
    }
    if(ss.size()!=1)
        return false;
    ss.clear();
    return true;
}
bool turn1()
{
    int t1=s[0][2],t2=s[1][2];
    for(int i=2;i<8;i++)
    {
        s[i-2][2]=s[i][2];
    }
    s[6][2]=t1;
    s[7][2]=t2;
    return check();
}
bool turn2()
{
    int t1=s[6][2],t2=s[7][2];
    for(int i=7;i>=2;i--)
    {
        s[i][2]=s[i-2][2];
    }
    s[0][2]=t1;
    s[1][2]=t2;
    return check();
}
bool turn3()
{
    int t1=s[0][1];
    int t2=s[1][1];
    s[1][1]=s[7][2];
    s[0][1]=s[7][3];
    s[7][2]=s[0][4];
    s[7][3]=s[1][4];
    s[0][4]=s[2][3];
    s[1][4]=s[2][2];
    s[2][3]=t2;
    s[2][2]=t1;
    return check();
}
bool turn4()
{
    int t1=s[0][1];
    int t2=s[1][1];
    s[1][1]=s[2][3];
    s[0][1]=s[2][2];
    s[2][2]=s[1][4];
    s[2][3]=s[0][4];
    s[0][4]=s[7][2];
    s[1][4]=s[7][3];
    s[7][3]=t1;
    s[7][2]=t2;
    return check();
}
bool turn5()
{
    int t1=s[1][0];
    int t2=s[1][1];
    s[1][0]=s[1][2];
    s[1][1]=s[1][3];
    s[1][2]=s[1][4];
    s[1][3]=s[1][5];
    s[1][4]=s[4][3];
    s[1][5]=s[4][2];
    s[4][2]=t2;
    s[4][3]=t1;
    return check();
}
bool turn6()
{
    int t1=s[1][0];
    int t2=s[1][1];
    s[1][0]=s[4][3];
    s[1][1]=s[4][2];
    s[4][3]=s[1][4];
    s[4][2]=s[1][5];
    s[1][4]=s[1][2];
    s[1][5]=s[1][3];
    s[1][2]=t1;
    s[1][3]=t2;
    return check();
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        for(int i=0;i<8;i++)
        {
            for(int j=2;j<=3;j++)
            {
                int a;
                scanf("%d",&a);
                s[i][j]=a;
            }
        }
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<=1;j++)
            {
                int a;
                scanf("%d",&a);
                s[i][j]=a;
            }
        }
        for(int i=0;i<2;i++)
        {
            for(int j=4;j<=5;j++)
            {
                int a;
                scanf("%d",&a);
                s[i][j]=a;
            }
        }
        int flag=0;
        if(check())
            flag=1;
        if(turn1())
            flag=1;
        turn2();
        if(turn2())
            flag=1;
        turn1();
        if(turn3())
            flag=1;
        turn4();
        if(turn4())
            flag=1;
        turn3();
        if(turn5())
            flag=1;
        turn6();
        if(turn6())
            flag=1;
        turn5();
        if(flag)
        {
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
/*
1
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24
8*/
