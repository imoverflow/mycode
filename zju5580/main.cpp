#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

int s[100005];
int lim[100005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&s[i]);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&lim[i]);
        }
        int lose=0;
        int win=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]%2==1&&lim[i]==2||s[i]%2==0&&lim[i]==1)
            {
                lose++;
            }
        }
        win=n-lose;
        if(win>=lose&&lose<2)
            printf("Alice\n");
        else
            printf("Bob\n");
    }
    return 0;
}
