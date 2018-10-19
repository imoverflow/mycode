#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char key[100];
char a[100];
char b[100];
vector<int>ans;
int main()
{
    scanf("%s",key);
    reverse(key,key+strlen(key));
    scanf("%s",a);
    reverse(a,a+strlen(a));
    scanf("%s",b);
    reverse(b,b+strlen(b));
    int len=max(strlen(a),strlen(b));
    int st=0;
    for(int i=0;i<len;i++)
    {
        int jingzhi=key[i]-'0'==0?10:key[i]-'0';
        if(a[i]<'0'||a[i]>'9')
            a[i]='0';
        if(b[i]<'0'||b[i]>'9')
            b[i]='0';
        ans.push_back((a[i]-'0'+b[i]-'0'+st)%jingzhi);
        st=(a[i]-'0'+b[i]-'0'+st)/jingzhi;
    }
    ans.push_back(st);
    long long res=0;
    for(int i=ans.size()-1;i>=0;i--)
    {
        res=res*10+ans[i];
    }
    printf("%lld\n",res);
    return 0;
}
