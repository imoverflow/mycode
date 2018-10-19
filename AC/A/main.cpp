#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int nxt[500010][26],fail[500010],endd[500010];
struct Trie
{
    int root,L;
    int newnode()
    {
        for(int i = 0;i < 26;i++)
            nxt[L][i] = -1;
        endd[L++] = 0;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        for(int i = 0;i < len;i++)
        {
            if(nxt[now][buf[i]-'a'] == -1)
            nxt[now][buf[i]-'a'] = newnode();
            now = nxt[now][buf[i]-'a'];
        }
        endd[now]++;
    }
    void build()
    {
        queue<int>Q;
        fail[root] = root;
        for(int i = 0;i < 26;i++)
            if(nxt[root][i] == -1)
                nxt[root][i] = root;
            else
            {
                fail[nxt[root][i]] = root;
                Q.push(nxt[root][i]);
            }
            while( !Q.empty() )
            {
                int now = Q.front();
                Q.pop();
                for(int i = 0;i < 26;i++)
                    if(nxt[now][i] == -1)
                        nxt[now][i] = nxt[fail[now]][i];
                    else
                    {
                        fail[nxt[now][i]]=nxt[fail[now]][i];
                        Q.push(nxt[now][i]);
                    }
            }
    }
    int query(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        int res = 0;
        for(int i = 0;i < len;i++)
        {
            now = nxt[now][buf[i]-'a'];
            int temp = now;
            while( temp != root )
            {
                res += endd[temp];
                endd[temp] = 0;
                temp = fail[temp];
            }
        }
        return res;
    }
    void debug()
    {
        for(int i = 0;i < L;i++)
        {
            printf("id = %3d,fail = %3d,endd = %3d,chi = [",i,fail[i],endd[i]);
            for(int j = 0;j < 26;j++)
                printf("%2d",nxt[i][j]);
            printf("]\n");
        }
    }
};
char buf[1000010];
Trie ac;
int main()
{
    int T;
    int n;
    scanf("%d",&T);
    while( T-- )
    {
        scanf("%d",&n);
        ac.init();
        for(int i = 0;i < n;i++)
        {
            scanf("%s",buf);
            ac.insert(buf);
        }
        ac.build();
        scanf("%s",buf);
        printf("%d\n",ac.query(buf));
    }
    return 0;
}
