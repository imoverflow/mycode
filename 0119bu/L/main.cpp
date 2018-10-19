#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char s[55][55];
char key[105];
//char d1[]={'U','U','U','U','U','U','L','L','L','L','L','L','R','R','R','R','R','R','D','D','D','D','D','D'};
//char d2[]={'L','R','L','R','D','D','U','U','R','R','D','D','L','L','U','U','D','D'};
//char d3[]={'R','L','D','D','L','R','R','D','D','U','U','R','U','D','L','D','L','U'};
//char d4[]={'D','D','R','L','R','L','D','R','U','D','R','U','D','U','D','L','U','L'};
int n,m;
bool check(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m||s[x][y]=='#')
        return false;
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    int sx,sy,ex,ey;
    for(int i=0;i<n;i++)
    {
        scanf("%s",s[i]);
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='S')
            {
                sx=i;
                sy=j;
            }
            if(s[i][j]=='E')
            {
                ex=i;
                ey=j;
            }
        }
    }
    scanf("%s",key);
    int len=strlen(key);
    char ss[]={'L','R','U','D'};
    sort(ss,ss+4);
    int ans=0;
    do{
        int x=sx,y=sy;
        for(int i=0;i<len;i++)
        {
            if(ss[key[i]-'0']=='U')
            {
                x-=1;
                if(!check(x,y))
                {
                    break;
                }
            }else if(ss[key[i]-'0']=='D')
            {
                x+=1;
                if(!check(x,y))
                {
                    break;
                }
            }else if(ss[key[i]-'0']=='L')
            {
                y-=1;
                if(!check(x,y))
                {
                    break;
                }
            }else if(ss[key[i]-'0']=='R')
            {
                y+=1;
                if(!check(x,y))
                {
                    break;
                }
            }
            if(s[x][y]=='E')
            {
                ans++;
                break;
            }
        }
      //  printf("%d %d\n",x,y);
//        printf("yes~~~~\n");
    }while(next_permutation(ss,ss+4));
    printf("%d\n",ans);
    return 0;
}
/**
5 6
.....#
S....#
.#....
.#....
...E..
333300012

6 6
......
......
..SE..
......
......
......
01232123212302123021

5 3
...
.S.
###
.E.
...
3

**/
