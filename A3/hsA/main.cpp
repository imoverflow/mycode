#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    char s1[60000],s2[60000];
    int t,a=0,b=0;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
       // int m=0,n=0,cou1=0,cou2=0;
        scanf("%s",s1);
        scanf("%s",s2);
//        for(int j=0;j<=strlen(s1);j++)
//        {
//            if(s1[j]!='0'||m!=0)
//            {
//                c[cou1++]=s1[j];
//                m=1;
//            }
//        }
//        for(int j=0;j<=strlen(s2);j++)
//        {
//            if(s2[j]!='0'||n!=0)
//            {
//                d[cou2++]=s2[j];
//                n=1;
//            }
//        }
        if(strcmp(s1,s2)>0)
            a++;
        else if(strcmp(s1,s2)<0)
            b++;
    }
    printf("%d %d",a,b);
    return 0;
}
