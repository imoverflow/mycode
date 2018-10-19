#include <iostream>
#include<time.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
//    FILE *fp=freopen("in.txt","w",stdout);
//    srand((unsigned) time(NULL));
////    fprintf(fp,"%d\n",1000);
//    for(int i=0;i<100000;i++)
//    {
//        int a=1+ rand() % 10;
//        int b=1+ rand() % 100;
//        fprintf(fp,"%d\n",i);
//        for(int i=0;i<a;i++)
//        {
//            fprintf(fp,"%d ",1+rand()%10);
//        }
//        fprintf(fp,"\n");
//        for(int i=0;i<a;i++)
//        {
//            int x='a';
//            int y='z';
//            fprintf(fp,"%c",x+ rand() % (y-x+1));
//        }
//        fprintf(fp,"\n");
//        for(int i=0;i<b;i++)
//        {
//            fprintf(fp,"%d %d %d\n",1+ rand() % a,1+ rand() % a,1+ rand() % 100);
//        }
//    }
    FILE *fp1=fopen("stdout.txt","r");
    FILE *fp2=fopen("out.txt","r");
    freopen("a.txt","w",stdout);
        int cnt=0;
    while(!feof(fp1))
    {
        char s1[20000];
        char s2[20000];
        int a,b;
        fgets(s1,20000,fp1);
        fgets(s2,20000,fp2);
        cnt++;
        if(strcmp(s1,s2)!=0)
        {
            printf("NO.%d\n",cnt);
            printf("%s %s\n",s1,s2);
            printf("%d\n",cnt);
//            break;
        }
//        else
//            printf("ok\n");
    }
    return 0;
}
