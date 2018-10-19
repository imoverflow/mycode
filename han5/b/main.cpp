#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

vector<int>v;
int main()
{
    int n;
    while(cin>>n)
    {
        v.clear();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            v.push_back(a);
        }
        while(v.size())
        {
            int now=INF;
            for(vector<int>::iterator it=v.begin();it!=v.end();)
            {
                if(*it<=now)
                {
                    now=*it;
                    it=v.erase(it);
                }else{
                    it++;
                }
            }
            cnt++;
//            printf("%d\n",v.size());
        }
        cout<<cnt<<endl;
    }
    return 0;
}
