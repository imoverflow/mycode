#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,p;
    scanf("%d%d",&n,&p);
    int s[7][3]={{0,1,2},{1,0,2},{1,2,0},{2,1,0},{2,0,1},{0,2,1},{0,1,2}};
    printf("%d",s[n%6][p]);
    return 0;
}
