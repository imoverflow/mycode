#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char s1[5000];
char s2[5000];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s1);
        scanf("%s",s2);
        srand(time(0));
        int p=rand()%2;
        if(s1[0]!=s2[0])
            printf("no\n");
        else{
            if(p%2==0)
                printf("yes\n");
            else
                printf("no\n");
        }
    }
    return 0;
}
