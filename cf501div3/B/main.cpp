#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char s[1000];
char t[1000];
char p1[1000];
char p2[1000];
vector<int> v;
int main()
{
    int n;
    cin>>n;
    scanf("%s",s+1);
    scanf("%s",t+1);
    for(int i=1;i<=n;i++)
    {
        p1[i]=s[i];
    }
    p1[n+1]='\0';
    for(int i=1;i<=n;i++)
    {
        p2[i]=t[i];
    }
    p2[n+1]='\0';
    sort(p1+1,p1+1+n);
    sort(p2+1,p2+1+n);
//    printf("%s %s",p1+1,p2+1);
    if(strcmp(p1+1,p2+1)!=0)
    {
        printf("-1\n");
        return 0;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]!=t[i])
        {
            for(int j=i+1;j<=n;j++)
            {
                if(t[i]==s[j])
                {
                    for(int k=j-1;k>=i;k--)
                    {
                        cnt++;
                        v.push_back(k);
                        swap(s[k],s[k+1]);
                    }
                    break;
                }
            }
        }
    }
    printf("%d\n",v.size());
    for(int i=0;i<v.size();i++)
    {
        printf("%d ",v[i] );
    }
    cout<<endl;
    return 0;
}
