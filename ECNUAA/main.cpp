#include <iostream>
#include <stdio.h>
#include<string.h>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
char s[1000];

char print(char t,int x)
{
    if(t=='a'&&x=='1')
        printf("��");
    else if(t=='a'&&x=='2')
        printf("��");
    else if(t=='a'&&x=='3')
        printf("��");
    else if(t=='a'&&x=='4')
        printf("��");
    if(t=='o'&&x=='1')
        printf("��");
    else if(t=='o'&&x=='2')
        printf("��");
    else if(t=='o'&&x=='3')
        printf("��");
    else if(t=='o'&&x=='4')
        printf("��");

}
int main()
{
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%s",s);
        int len=strlen(s);
        int flag=0;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='a')
            {
                flag=i;
                break;
            }else if(flag==0&&s[i]=='o'||flag==0&&s[i]=='e'||flag==0&&s[i]=='i'||flag==0&&s[i]=='u')
            {
                flag=i;
            }
        }
        for(int i=0;i<len;i++)
        {
            if(s[i]>='a'&&s[i]<='z')
            {
                if(i==flag)
                    print(s[i],s[len-1]);
                else
                    printf("%c",s[i]);
            }
        }
    }
    return 0;
}
