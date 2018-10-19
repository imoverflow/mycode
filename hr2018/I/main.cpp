#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <set>
#include <regex>
using namespace std;

string s[10];

int main()
{
    int t;
    scanf("%d",&t);
//    regex reg("@[0-9A-Za-Z_-]+");
    regex reg("[^A-Za-z0-9_-]*@([A-Za-z0-9_-]*)");
    smatch match_Results;

    while(t--)
    {
        int n;
        set<string>ans;
        scanf("%d",&n);
        getchar();
        for(int i=0;i<n;i++)
        {
            getline(cin,s[i]);
            string::const_iterator its=s[i].begin();
            string::const_iterator ite=s[i].end();
            while(regex_search(s[i],match_Results,reg))
            {
                ans.insert(match_Results[0]);
                s[i]=match_Results.suffix().str();
            }
        }
        printf("%d\n",ans.size());
        for(set<string>::iterator it=ans.begin();it!=ans.end();it++)
        {
            cout<<*it<<endl;
        }
        printf("\n");
    }
    return 0;
}
