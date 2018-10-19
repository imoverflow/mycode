#include <iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<ctime>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
int i, j, k , m, n;
char s[200050];
 char a[10] = "happiness";

bool check(int p)
{
    bool flag = 1;
    for(i = 0; i < 9; i ++)
        if(s[p+i]!=a[i])  flag = 0;
    return flag;
}

int main()
{
    cin>>s;
    m = strlen(s);
    vector<int>q;
    for(j = 0; j < m; j ++)
    {
        if(s[j]=='h')
            if(check(j))  q.push_back(j);
    }
    if(q.size()>2)  puts("NO");
    else    if(q.size()==2)
    {
        printf("YES\n%d %d\n",q[0]+1,q[1]+2);
    }
    else  if(q.size()==1)
        printf("YES\n%d %d\n",q[0]+1,q[0]+2);
    else
    {
       label:
       srand(time(0));
       int t=rand()%(m-1)+1;
       swap(s[t],s[0]);
       if(!check(0)) printf("YES\n1 %d\n",t+1);
       else
       {
           swap(s[t],s[0]);
        goto label;
       }
    }
    return 0;
}
