#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int a,b,c,sum;
    char s1[1001];
    char s2[1001];
    int s3[1002];
    while(scanf("%d",&a)!=EOF)
    {
        for(int i=0;i<a;i++)
        {
            scanf("%s",s1);
            scanf("%s",s2);
            void plus(char sub1[],char sub2[],int a[]);
            plus(s1,s2,s3);
            b=strlen(s1)>strlen(s2)?strlen(s1):strlen(s2);
            if(s3[b]!=0)
            {
                    printf("Case %d:\n",i+1);
                    printf("%s + %s = ",s1,s2);
                for(int j=b;j>=0;j--)
                {
                    printf("%d",s3[j]);
                }

            }else
            {
                printf("Case %d:\n",i+1);
                printf("%s + %s = ",s1,s2);
                for(int j=b-1;j>=0;j--)
                {
                    printf("%d",s3[j]);
                }
            }
            if(i==a-1)
            printf("\n");
            else
            printf("\n\n");
        }

    }
    return 0;
}

void plus(char sub1[],char sub2[],int a[])
{
    int len1=strlen(sub1)-1,len2=strlen(sub2)-1;
    int b=0,flag=0;
    while(len1>=0||len2>=0)
    {
        if(len1>=0&&len2>=0)
        {
            if(sub1[len1]-'0'+sub2[len2]-'0'+flag<=9)
            {
                a[b]=(sub1[len1]-'0')+(sub2[len2]-'0')+flag;
                b++;
                len1--;
                len2--;
                flag=0;
            }
            else
            {
                a[b]=((sub1[len1]-'0')+(sub2[len2]-'0')+flag)%10;
                b++;
                len1--;
                len2--;
                flag=1;
            }
        }else if(len1<0&&len2>=0)
        {
            if(sub2[len2]-'0'+flag<=9)
            {
                a[b]=(sub2[len2]-'0')+flag;
                b++;
                len2--;
                flag=0;
            }
            else
            {
                a[b]=((sub2[len2]-'0')+flag)%10;
                b++;
                len2--;
                flag=1;
            }
        }else if(len2<0&&len1>=0)
        {
            if(sub1[len1]-'0'+flag<=9)
            {
                a[b]=(sub1[len1]-'0')+flag;
                b++;
                len1--;
                flag=0;
            }
            else
            {
                a[b]=((sub1[len1]-'0')+flag)%10;
                b++;
                len1--;
                flag=1;
            }
        }
    }
    a[b]=flag;
}
