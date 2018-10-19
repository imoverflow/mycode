#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int s[100005];
int main()
{
    int n;
    scanf("%d",&n);
    long long sum=0,ans=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
        sum+=s[i];
    }
    sort(s,s+n);
    long long p=sum/n;
    int flag=sum%n;
    if(flag==0){
        for(int i=0;i<n;i++)
        {
            if(s[i]<p)
                ans+=p-s[i];
        }
    }else{
        for(int i=n-1,j=0;i>=0;i--)
        {
            if(s[i]>p+1&&j++<flag)
                ans+=s[i]-(p+1);
            else if(s[i]>p&&j>flag)
                ans+=s[i]-p;
        }
    }

//    if(sum%n==0) flag=0;
//    else flag=1;
//    int l=0,r=n-1;
//    while(l<r)
//    {
//        if(p-s[l]<=0) break;
//        if(flag==0)
//        {
//            if(s[r]-(p-s[l])>=p)
//            {
//                ans+=p-s[l];
//                s[l]+=p-s[l];
//                l++;
//                s[r]-=p-s[l];
//            }else{
//                ans+=s[r]-p;
//                s[r]-=s[r]-p;
//                s[l]+=s[r]-p;
//                r--;
//            }
//        }else{
//            if(s[r]-(p-s[l])>=p+1)
//            {
//                ans+=p-s[l];
//                s[l]=p;
//                l++;
//                s[r]-=p-s[l];
//            }else{
//                ans+=s[r]-p-1;
//                s[r]=p+1;
//                s[l]+=s[r]-p-1;
//                r--;
//            }
//        }
//        if(s[r]-(p-s[l])>=p)
//        {
//            ans+=p-s[l];
//            s[r]-=p-s[l];
//            s[l]+=p-s[l];
//            l++;
//        }else{
//            ans+=s[r]-p;
//            s[l]+=s[r]-p;
//            s[r]-=s[r]-p;
//            r--;
//        }
//    }
//    sort(s,s+n);
//    for(int i=n-1;i>=0;i--)
//    {
//        if(s[i]>p+1)
//            ans+=s[i]-(p+1);
//        else break;
//    }
    printf("%lld",ans);
    return 0;
}
