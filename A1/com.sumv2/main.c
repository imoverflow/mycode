/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
main()
{
    char ad[100];
    int temp;
    int a[500][1001];
    int r=0;
    int c=0;
    int i,j;
    int k,l;
    int flag1=-1;
    int flag2=-1;
    int flag=0;
    int num;
    int count=1;
    int st[1002];
    int m,n,p;
    int scount=0;

    for(i=0;i<500;i++)
    {
        for(j=0;j<1001;j++)
            a[i][j]=-1;
    }
    printf("please input:");
    scanf("%s",ad);
    FILE *fl;
    if((fl=fopen(ad,"r"))==NULL)
    {
        printf("fail");
    }
    else
    {
        while ((temp=fgetc(fl))!=EOF)
        {
           // printf("%d",temp);
            if(temp!=32&&temp!=10)
                {
                    int translate(int ascii);
                    num=translate(temp);
                    a[r][c]=num;
                    //printf("%d\t",num);
                    c++;
                }
           else
           {
               r++;
               c=0;
           }

        }

        for(k=0;k<=500;k+=2)
        {

          for(l=10001;l>=0;l--)
          {
            if(a[k][l]!=-1&&flag1==-1)
                flag1=l;
            if(a[k+1][l]!=-1&&flag2==-1)
                flag2=l;
            if(flag1!=-1&&flag2!=-1)
            {
                m=flag1>flag2?flag1:flag2;
                printf("\n%d",m);
                for(n=0;n<=1002;n++)
                    st[n]=-1;
                for(m;m>=0;m--)
                {
                    if(flag1>=0&&flag2>=0)
                    {
                        if((a[k][flag1]+a[k+1][flag2]+flag)>9)
                        {
                            st[scount]=(a[k][flag1]+a[k+1][flag2]+flag)%10;
                            flag=1;
                        }
                        else
                        {
                            st[scount]=a[k][flag1]+a[k+1][flag2]+flag;
                        }
                            flag1--;
                            flag2--;
                            scount++;
                    }

                }
                flag1=flag2=-1;
                flag=0;
                scount=0;
            }
          }
        }

    }
    fclose(fl);
}

int translate(int ascii)
{
    switch(ascii)
    {
    case 48:
        return 0;
        break;
    case 49:
        return 1;
        break;
    case 50:
        return 2;
        break;
    case 51:
        return 3;
        break;
    case 52:
        return 4;
        break;
    case 53:
        return 5;
        break;
    case 54:
        return 6;
        break;
    case 55:
        return 7;
        break;
    case 56:
        return 8;
        break;
    case 57:
        return 9;
        break;
    }
}
*/
#include<stdio.h>
#include<string.h>
int main()
{
int t,m;
char a[1001],b[1001],s[1001];
int i,j;
int l,k;
int d;
scanf("%d",&m);
    for(t=1;t<=m;t++)
    {
        if(m>20||m<1)
        {
            break;
        }
        if(t!=1)
        {
            printf("\n");
        }
scanf("%s%s",a,b);
l=strlen(a);
k=strlen(b);
if(l>=k)
{
    d=0;            //½øÎ»
    j=k-1;
    for(i=l-1;i>=l-k;i--)
    {
        if(d==0)
        {
            s[i+1]='0'+((a[i]+b[j]-2*'0')%10);
        }
        else
        {
            s[i+1]='0'+((a[i]+b[j]-2*'0'+1)%10);
        }
    d=(a[i]+b[j]-2*'0'+d)/10;
    j--;
    }
for(j=i;j>=0;j--)
{
if(d==1)
{
s[j+1]=(a[j]-'0'+1)%10+'0';
d=(a[j]-'0'+1)/10;
}
else
{
s[j+1]=a[j];
d=0;
}
}
}
else
{
d=0;
j=l-1;
for(i=k-1;i>=k-l;i--)
{
if(d==0)
{
s[i+1]='0'+((b[i]+a[j]-2*'0')%10);
}
else
{
s[i+1]='1'+((b[i]+a[j]-2*'0')%10);
}
d=(b[i]+a[j]-2*'0')/10;
j--;
}
for(j=i;j>=0;j--)
{
if(d==1)
{
s[j+1]=(b[j]-'0'+1)%10+'0';
d=(b[j]-'0'+1)/10;
}
else
{
s[j+1]=b[j];
d=0;
}
}
}
printf("Case %d:\n",t);
if(k<=l)
{
if(d>0)
{
s[0]='1';
printf("%s + %s = ",a,b);
for(i=0;i<=l;i++)
{
printf("%c",s[i]);
}
}
else
{
printf("%s + %s = ",a,b);
for(i=1;i<=l;i++)
{
printf("%c",s[i]);
}
}
printf("\n");
}
else if(l<k)
{
if(d>0)
{
s[0]='1';
printf("%s + %s = ",a,b);
for(i=0;i<=k;i++)
{
printf("%c",s[i]);
}
}
else
{
printf("%s + %s = ",a,b);
for(i=1;i<=k;i++)
{
printf("%c",s[i]);
}
}
printf("\n");
}
}
return 0;
}
