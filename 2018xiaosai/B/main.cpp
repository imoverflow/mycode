#include<cstdio>
#include<cstring>
#include<ctime>
#include<algorithm>
const int maxn = 1000000+1000;
struct node
{
    int num,s;
    node(){}
    node(int _num,int _s){num=_num,s=_s;}
}p[maxn];
void work()
{
    int f=1,cnt;
    for(cnt=1;cnt<10;cnt++)
        p[cnt]=node(cnt,1<<cnt);
    while(cnt<=1000000)
    {
        int num=p[f].num,s=p[f].s;
        f++;
        for(int i=0;i<10;i++)
            if(!(s&(1<<i)))
                p[cnt++]=node(num*10+i,s|(1<<i));
    }
}
int main(void)
{
    //srand(time(NULL));
    //freopen("E://123.txt","r",stdin);
    //freopen("E://1233.txt","w",stdout);
    /*
    for(int i=1;i<=200;i++)
        printf("%d\n",rand()%1000);
    for(int i=1;i<=200;i++)
        printf("%d\n",rand()%10000);
    for(int i=1;i<=50;i++)
        printf("%d\n",rand()%100000);
    for(int i=1;i<=50;i++)
        printf("%d\n",((rand()%100000)*10+rand()%100000)%1000000);
    */
    work();
    int n,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("%d\n",p[n].num);
    }
    return 0;
}
