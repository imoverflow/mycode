#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int c;
   //freopen("test.txt","r",stdin);
    while(scanf("%d",&c)!=EOF)
    {
        getchar();
        for(int i=0;i<c;i++)
        {
            char a[51]="";
            int b=0,e=0;
            char d;
            gets(a);
            if((a[0]>='a'&&a[0]<='z')||(a[0]>='A'&&a[0]<='Z')||a[0]=='_')
            {
                for(int j=1;j<strlen(a);j++)
                {
                    if((a[j]<='9'&&a[j]>='0')||a[j]=='_'||(a[j]>='a'&&a[j]<='z')||(a[j]>='A'&&a[j]<='Z'))
                        b=1;
                    else
                    {
                        b=0;
                        break;
                    }
                }
            }else
            {
                b=0;
            }
            if(b==1)
            printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
