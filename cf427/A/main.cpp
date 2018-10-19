#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s,v1,v2,t1,t2;
    scanf("%d%d%d%d%d",&s,&v1,&v2,&t1,&t2);
    if(s*v1+2*t1<s*v2+2*t2)
    {
        printf("First\n");
    }else if(s*v1+2*t1>s*v2+2*t2)
    {
        printf("Second\n");
    }else{
        printf("Friendship\n");
    }
    return 0;
}
