#include <iostream>
#include <map>
#include <cstring>
#include <set>
#include <stdio.h>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
map<string,set<int> >times;
map<string,int>score;

char s[40][40];
struct node{
    int win,Ascore,Bscore;
    node(){}
    node(int win,int Ascore,int Bscore):win(win),Ascore(Ascore),Bscore(Bscore){}
    bool operator == (const node &a)const{
        return (a.Ascore==Ascore&&a.Bscore==Bscore&&a.win==win);
    }
    bool operator < (const node &a)const{
        if(a.win!=win) return win<a.win;
        if(a.Bscore!=Bscore) return Bscore>a.Bscore;
        return Ascore<a.Ascore;
    }
};

map<string,node>ans;
node dfs(string x)
{
    if(ans.find(x)!=ans.end()) return ans[x];
    node m(1,INF,0);
    for(int i=0;i<26;i++)
    {
        char p=i+'a';
        if(score.find(x+p)!=score.end())
        {
            node a=dfs(x+p);
            if(a<m) m=a;
        }
        if(score.find(p+x)!=score.end())
        {
            node a=dfs(p+x);
            if(a<m) m=a;
        }
    }
    if(m==node(1,INF,0))
        return ans[x]=node(0,0,score[x]);
    else
        return ans[x]=node(m.win^1,m.Bscore,m.Ascore+score[x]);
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        ans.clear();
        score.clear();
        times.clear();
        for(int i=0;i<n;i++)
        {
            scanf("%s",s[i]);
        }
        for(int i=0;i<n;i++)
        {
            int len=strlen(s[i]);
            for(int j=0;j<len;j++)
            {
                string ss="";
                int maxval=0;
                int sum=0;
                for(int k=j;k<len;k++)
                {
                    ss+=s[i][k];
                    sum+=s[i][k]-'a'+1;
                    times[ss].insert(i);
                    maxval=max(maxval,s[i][k]-'a'+1);
                    score[ss]=maxval*sum;
                }
            }
        }
        for(auto it=score.begin();it!=score.end();it++){
            string str=it->first;
            it->second+=times[str].size();
        }
        node ans=dfs("");
        if(ans.win==0)
        {
            cout<<"Bob"<<endl;
        }else{
            cout<<"Alice"<<endl;
        }
        cout<<ans.Ascore<<" "<<ans.Bscore<<endl;
    }
    return 0;
}
