#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char s[100005];
int main()
{
    scanf("%s",s);
    int len=strlen(s);
    int cnt1=0;
    int flag=len;
    for(int i=0;i<len;i++){
        if(s[i]=='0'){
            cnt1++;
        }else if(s[i]=='2')
        {
            flag=i;
            break;
        }
    }
    int cnt2=0;
    int cnt3=0;
    int cnt4=0;
    for(int i=0;i<len;i++){
        if(s[i]=='1'){
            cnt2++;
        }else if(s[i]=='2'){
            cnt3++;
        }else if(s[i]=='0'){
            cnt4++;
        }
    }
    for(int i=0;i<cnt1;i++){
        printf("0");
    }
    for(int i=0;i<cnt2;i++){
        printf("1");
    }
    for(int i=flag;i<len;i++){
        if(s[i]!='1'){
            printf("%c",s[i]);
        }
    }
    cout<<endl;
    return 0;
}
