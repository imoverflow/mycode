#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
//    printf("%d",(int)log(2)/log(10));
    int m;
    int cases=1;
    while(~scanf("%d",&m))
    {
        printf("Case #%d: %d\n",cases++,(int)(m*log(2)/log(10)));
    }
    return 0;
}
