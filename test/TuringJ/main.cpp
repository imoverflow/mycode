#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string s[30009];

int d[30009], e[30009], cnt;
set<string> se[30009];

struct Node{
    string s;
    string s1;
    int d;
}no[30009];

bool cmp(Node a, Node b){
    return a.s1<b.s1;
}

bool cmp1(int a, int b){
    if(d[a]!=d[b]) return d[a]>d[b];
    set<string>::iterator st=se[a].begin(), st2=se[b].begin();
    return *st<*st2;
}

int main()
{
//    freopen("in.txt", "r", stdin);
    cnt=0;
    while(cin>>no[cnt].s){
        no[cnt].s1=no[cnt].s;
        sort(no[cnt].s1.begin(), no[cnt].s1.end());
        cnt++;
    }
    int t1=-1;
    sort(no, no+cnt, cmp);
//    for(int i=0; i<cnt; i++){
//        cout<<no[i].s<<' '<<no[i].s1<<endl;
//    }
    string last="";
    for(int i=0; i<cnt; i++){
        if(no[i].s1!=last){
            se[++t1].insert(no[i].s);
            d[t1]++;
            last=no[i].s1;
        }
        else{
            se[t1].insert(no[i].s);
            d[t1]++;
        }
    }
//    cout<<t1<<endl;
    for(int i=0; i<=t1; i++)
        e[i]=i;
//    for(int i=0; i<=t1; i++)
//        cout<<d[i]<<endl;
    sort(e, e+t1+1, cmp1);
        for(int i=0; i<=min(t1, 4); i++){
            int t2=e[i];
            printf("Group of size %d: ", d[t2]);
            for(set<string>::iterator it=se[t2].begin(); it!=se[t2].end(); it++)
                cout<<*it<<' ';
            cout<<'.'<<endl;
        }



    return 0;
}
//aaaa aaaa aaaa aaaa aaaa aaaaaaaa aaaaaaaa aaaa bbbb bbbbbbbbbbbbbbbb bbbb bbbb bbbb bbbb
