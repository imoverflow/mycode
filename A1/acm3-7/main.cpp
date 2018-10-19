#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;


int main()
{
    char a[10000],b[10000],c[10000],d[10000];
    int flag1,flag2,flag3,flag4;
    while(scanf("%s %s",a,b)!=EOF)
    {
        int m=1,n=1;
        for(int i=0;i<strlen(a);i++)
            if(a[i]!='0'||a[i]=='.')
            {
                if(a[i]=='.')
                    flag1=i-1;
                else
                    flag1=i;
                break;
            }else flag1=flag2=0;
        if(strchr(a,'.')!=NULL)
        {
            for(int i=strlen(a)-1;i>=0;i--)
            if(a[i]!='0')
            {
                if(a[i]=='.')
                    flag2=i-1;
                else
                    flag2=i;
                break;
            }else flag1=flag2=0;
        }else if(flag2!=0){flag2=strlen(a)-1;}


        for(int i=0;i<strlen(b);i++)
            if(b[i]!='0'||b[i]=='.')
            {
                if(b[i]=='.')
                    flag3=i-1;
                else
                    flag3=i;
                break;
            }else flag3=flag4=0;
        if(strchr(b,'.')!=NULL)
        {
            for(int i=strlen(b)-1;i>=0;i--)
            {
            if(b[i]!='0')
            {
                if(a[i]=='.')
                    flag4=i-1;
                else
                    flag4=i;
                break;
            }else flag3=flag4=0;
            }
        }else if(flag4!=0){flag4=strlen(b)-1;}

        for(int i=flag3;i<=flag4;i++)
        {
            d[n]=b[i];
            n++;
        }
        for(int i=flag1;i<=flag2;i++)
        {
            c[m]=a[i];
            m++;
        }
        c[m]='\0';
        d[n]='\0';
        for(int i=0;i<10;i++)
            printf("%c-%c ",c[i],d[i]);
        if(strcmp(c,d)==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
