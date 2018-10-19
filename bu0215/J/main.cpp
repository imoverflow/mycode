#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long sum[500005];
long long a[500005];
int main()
{
    int q;
    cin>>q;
    int cnt=0;
    memset(a,0,sizeof a);
    memset(sum,0,sizeof sum);
    double ans=0;
    while(q--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            cin>>a[cnt];
            int l=0,r=cnt;
            if(cnt>=1)
                sum[cnt]=sum[cnt-1]+a[cnt];
            else
                sum[cnt]=a[cnt];
            while(l<r)
            {
                int mid=(l+r)/2;
                long long fi;
                if(mid!=0)
                    fi=a[cnt]+sum[mid-1]-a[mid]*(mid+1);
                else
                    fi=a[cnt]-a[mid]*(mid+1);
                if(fi<=0) r=mid;
                else l=mid+1;
            }
            double avg=1.0*(sum[r-1]+a[cnt])/(r+1);
            double tmp=a[cnt]-avg;
            ans=max(ans,tmp);
            cnt++;
        }else{
            printf("%.10f\n",ans);
        }
    }
    return 0;
}
