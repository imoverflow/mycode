#include <bits/stdc++.h>

using namespace std;

vector<int>s;
vector<int>ans;
int main(){
    int t;
    scanf("%d",&t);
    while(t--)
    {
        s.clear();
        ans.clear();
        int n;
        scanf("%d",&n);
        int cnt=0;
        int num=0;
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            s.push_back(a);
        }
        vector<int>::iterator it=s.end();
        it--;
        for(int i=s.size()-1;i>=0;i--,it--)
        {
            if(i>=1)
                if(s[i]>s[i-1])
                {
                    vector<int>::iterator it1=it;
                    int tmp=s[i];
                    while(tmp>(*it1))
                    {
                        s.erase(it+1);
                        tmp=*it1;
                        it1--;
                    }
                }
        }
        printf("%d\n",s.size());
        for(int i=0;i<s.size();i++)
        {
            printf("%d ",s[i]);
        }
        printf("\n");
    }
    return 0;
}
