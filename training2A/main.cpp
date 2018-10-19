#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    int x1,y1,x2,y2;
    cin>>m>>n>>x1>>y1>>x2>>y2;
    if(m>n)
        swap(m,n);
    if(x1>y1)
        swap(x1,y1);
    if(x2>y2)
        swap(x2,y2);
    if(x1+x2<=m&&max(y1,y2)<=n || max(x1,y2)<=m&&y1+x2<=n || max(y2,x1)<=n&&x2+y1<=m ||max(x1,x2)<=m&&y1+y2<=n || y1+y2<=n&&max(x1,x2)<=m)
        printf("YES\n");
    else
        printf("No\n");
    return 0;
}
