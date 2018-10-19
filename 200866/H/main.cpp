//#include <iostream>
//#include <bits/stdc++.h>
//using namespace std;
//const long long INF = 1e11;
//long long pri[1000005];
//int c(long long n)
//{
//    int cnt=0;
//    for(long long i=2;i<=sqrt(n);i++)
//    {
//        if(n%i==0)
//        {
//            pri[cnt++]=i;
//            while(n%i==0)
//                n/=i;
//        }
//    }
//    pri[cnt++]=n;
//    return cnt;
//}
//bool cmp(const int &a,const int &b)
//{
//    return a>b;
//}
//long long s[100005];
//long long b[100005];
//int main()
//{
//    int t;
//    scanf("%d",&t);
//    while(t--)
//    {
//        long long sum=0;
//        int n;
//        scanf("%d",&n);
//        for(int i=0;i<n;i++)
//        {
//            scanf("%lld",&s[i]);
//            sum+=s[i];
//        }
//        int p=c(sum);
//        long long ans=INF;
//        for(int i=0;i<p;i++)
//        {
//            long long res=0;
//            long long sum1=0;
//            for(int j=0;j<n;j++)
//            {
//                b[j]=s[j]%pri[i];
//                sum1+=b[j];
//            }
//            sort(b,b+n,cmp);
//            int z=0;
//            while(sum1>0&&z<n)
//            {
//                res+=pri[i]-b[z];
//                sum1-=pri[i];
//                z++;
//            }
//            ans=min(res,ans);
//        }
//        printf("%lld\n",ans);
//    }
//    return 0;
//}
#include <bits/stdc++.h>

using namespace std;
typedef long long LL ;

LL minn ( LL  a , LL b ){
    return a > b ? b : a ;
}

bool cmp(const int &a ,const int &b){
    return a > b ;
}

LL a[100000 + 10 ]  ;
int  n;
LL b[100000 + 10 ] ;

LL solve(LL yinzi){
    LL ans = 0 ;
    for(int i = 1 ; i <= n ; i++){
        b[i] = a[i] % yinzi ;
    }
    sort(b + 1 , b + 1 + n  ,cmp ) ;

    int r = n , l = 1 ;


    while(b[l] != yinzi && b[l] != 0 && l <= n ){
        LL remain = yinzi - b[l] ;
        ans += remain ;
        while(remain && r >= 1 ){
            if(b[r] == 0 ) {r-- ;continue ;}
            if(b[r] <= remain) {remain -= b[r] , b[r] = 0 , r --; continue ; }
            if(b[r] > remain) {remain = 0 ; b[r] -= remain ; continue ;}
        }
        b[l++] = yinzi ;
    }

    return ans ;

}

void sushu(LL x){
    LL ans = 1e18 ;
    for(int i = 2 ; i <= sqrt(x) + 0.00001 ; i ++ ){
        if(x % i == 0){
            ans = minn (solve(i),ans);
        }
        while(x % i == 0) x /= i ;
    }

    if( x > 1 ) ans = minn(solve(x) , ans );
    printf("%lld\n",ans);

}

int main()
{
    int ca  ;
    scanf("%d",&ca);
    while(ca--){
        LL sum = 0;
        scanf("%d",&n);
        for(int i = 1 ; i<= n ; i++){
            scanf("%lld",&a[i]);
            sum += a[i];
        }
        sushu(sum);

    }
    return 0;
}
