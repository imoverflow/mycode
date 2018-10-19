#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    char s[105];
    while(t--)
    {
        getchar();
        scanf("%s",s);
        int len=strlen(s);
        int ans=len,cnt=0;
        for(int i=0;i<len;i++)
        {
            while(s[i]>='A'&&s[i]<='Z'&&i<len)
            {
                cnt++;
                i++;
            }
            if(cnt>=2)
                ans+=2;
            else if(cnt==1)
                ans+=1;
            cnt=0;
        }
        printf("%d\n",ans);
    }
    return 0;
}
