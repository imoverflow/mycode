#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
//http://acm.hdu.edu.cn/showproblem.php?pid=1532

struct Node
{
    int to,cap,rev;
};
vector<Node> g[2500];
bool used[2500];

void add_edge(long long from,long long to,long long cap)
{
//    Node n;
//    n.to=to;
//    n.cap=cap;
//    n.rev=g[to].size();
//    g[from].push_back(n);
//    n.to=from;
//    n.cap=0;
//    n.rev=g[from].size()-1;
//    g[to].push_back(n);
    g[from].push_back((Node){to,cap,g[to].size()});
    g[to].push_back((Node){from,0,g[from].size()-1});
}

long long dfs(long long v,long long t,long long f)
{
    if(v==t) return f;
    used[v]=true;
    for(int i=0;i<g[v].size();i++)
    {
        Node &e=g[v][i];
        if(!used[e.to]&&e.cap>0)
        {
            long long d=dfs(e.to,t,min((long long)f,(long long)e.cap));
            if(d>0)
            {
                e.cap-=d;                  //Flow to zero
                g[e.to][e.rev].cap+=d;     //rev to zero
                return d;
            }
        }
    }
    return 0;
}
long long max_flow(long long s,long long t)
{
    long long flow=0;
    while(1)
    {
        memset(used,0,sizeof(used));
        long long f=dfs(s,t,INF);
        if(f==0) return flow;
        flow+=f;
//        printf("running\n");
    }
}
int main()
{
    int m,n;
    for(n=18;n<=18;n++){
            memset(g,0,sizeof g);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                add_edge(i,j,i^j);
            }
        }
        add_edge(n,0,INF);
        add_edge(n-1,n+1,INF);
        if((log(n)/log(2))-(int)(log(n)/log(2)+0.001)<0.0001)
            printf("\n");
        printf("%lld\t",max_flow(n,n+1));
    }
    return 0;
}
/*
2 - 0
3 - 1
4 - 1
5 - 4
6 - 1
7 - 4
8 - 1
9 - 16
10 - 1
11 - 4
12 - 1
13 - 16
14 - 1
15 - 4
16 - 1
17 - 64
18 - 1
19 - 4
20 - 1
21 - 16
22 - 1
23 - 4
24 - 1
25 - 64
26 - 1
27 - 4
28 - 1
29 - 16
30 - 1
31 - 4
32 - 1
33 - 256
34 - 1
35 - 4
36 - 1
37 - 16
38 - 1
39 - 4
40 - 1
41 - 64
42 - 1
43 - 4
44 - 1
45 - 16
46 - 1
47 - 4
48 - 1
49 - 256
50 - 1
51 - 4
52 - 1
53 - 16
54 - 1
55 - 4
56 - 1
57 - 64
58 - 1
59 - 4
60 - 1
61 - 16
62 - 1
63 - 4
64 - 1
65 - 1024
66 - 1
67 - 4
68 - 1
69 - 16
70 - 1
71 - 4
72 - 1
73 - 64
74 - 1
75 - 4
76 - 1
77 - 16
78 - 1
79 - 4
80 - 1
81 - 256
82 - 1
83 - 4
84 - 1
85 - 16
86 - 1
87 - 4
88 - 1
89 - 64
90 - 1
91 - 4
92 - 1
93 - 16
94 - 1
95 - 4
96 - 1
97 - 1024
98 - 1
99 - 4
100 - 1
101 - 16
102 - 1
103 - 4
104 - 1
105 - 64
106 - 1
107 - 4
108 - 1
109 - 16
110 - 1
111 - 4
112 - 1
113 - 256
114 - 1
115 - 4
116 - 1
117 - 16
118 - 1
119 - 4
120 - 1
121 - 64
122 - 1
123 - 4
124 - 1
125 - 16
126 - 1
127 - 4
128 - 1
129 - 4096
*/
