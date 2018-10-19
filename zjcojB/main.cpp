#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include <string.h>
#include <set>
using namespace std;


int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        map<string,int>ma;
        set<string>st;
        string s;
        int md=0;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            ma[s]++;
            st.insert(s);
        }
        set<string>::iterator it=st.begin();
        for(;it!=st.end();it++){
            if(ma[*it]>md)
            {
                md=ma[*it];
                s=*it;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
