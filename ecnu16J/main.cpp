//#include <iostream>
//#include <bits/stdc++.h>
//using namespace std;
//
//long long s[100];
//bool isI(double k)
//{
//    if(fabs((long long)(k+0.000001)-k)<1e-7)
//        return true;
//    else
//        return false;
//}
//int main()
//{
//    int n;
//    cin>>n;
//    int flag=-1;
//    for(int i=0;i<n;i++)
//    {
//        scanf("%lld",&s[i]);
//        if(s[i]==0)
//            flag=i;
//    }
//    if(flag==-1)
//    {
//        if(n==1)
//        {
//            printf("%lld",s[0]+1);
//            return 0;
//        }
//        else if(n==2){
//            printf("%lld %lld\n",s[0],s[0]);
//            return 0;
//        }
//        else if(n==3){
//            if(isI(sqrt(s[0]*s[2])))
//                s[1]=(long long)(sqrt(s[0]*s[2])+0.000001);
//            else
//                s[2]=(long long)(s[1]*((double)s[1]/s[0])+0.0000000001);
//        }else if(n==4)
//        {
//            if(s[0]*s[2]==s[1]*s[1])
//            {
//                s[3]=(long long)(s[2]*((double)s[1]/s[0]+0.0000001));
//            }else if(s[1]*s[3]==s[2]*s[2]){
//                s[0]=(long long)(s[1]/(double)(s[2]/s[1]));
//            }else{
//                s[1]=s[0]*(pow((double)s[3]/s[0],1.0/3)+0.0000000001)+0.000000001;
//                s[2]=s[1]*(pow((double)s[3]/s[0],1.0/3)+0.0000000001)+0.000000001;
//            }
//        }else{
//            double x1,x2,x3;
//            double q=0;
//            int index1=-1,index2=-1;
//            for(int i=1;i<n-1;i++)
//            {
//                x1=pow((double)s[i]/s[0],1.0/i);
//                x2=pow((double)s[i+1]/s[0],1.0/(i+1));
//                if(fabs(x1-x2)<1e-6){
//                    q=x1;
//                    index1=i;
//                    index2=i+1;
//                    break;
//                }
//            }
//            if(index1==1)
//            {
//                for(int i=1;i<n;i++)
//                {
//                    s[i]=(long long)(s[i-1]*q+0.00000001);
//                }
//            }else if(index1==-1){
//                s[0]=(long long)((double)s[1]/((double)s[2]/s[1])+0.00000001);
//            }
//            else{
//                for(int i=n-2;i>=0;i--)
//                {
//                    s[i]=(long long)(s[i+1]/q+0.00000001);
//                }
//            }
//
//        }
//    }else{
//        if(n==1){
//            printf("1\n");
//            return 0;
//        }
//        else if(n==2){
//            if(flag==0)
//                s[0]=s[1];
//            else if(flag==1)
//                s[1]=s[0];
//        }else if(n==3){
//            if(flag==0)
//                s[flag]=(long long)((double)(s[1]/(s[2]/s[1])+0.000000001));
//            else if(flag==1)
//                s[flag]=(long long)(sqrt(s[0]*s[2])+0.00001);
//            else if(flag==2)
//                s[flag]=(long long)(((double)s[1]/s[0])*s[1]+0.00000001);
//        }else{
//            if(flag==0)
//            {
//                s[0]=(long long)((double)s[1]/((double)s[2]/s[1])+0.000000001);
//            }else if(flag==n-1)
//            {
//                s[n-1]=(long long)(((double)s[1]/s[0])*s[n-2]+0.000000001);
//            }else{
//                s[flag]=(long long)(sqrt(s[flag-1]*s[flag+1])+0.000000001);
//            }
//        }
//    }
//    for(int i=0;i<n;i++)
//    {
//        if(i==0) printf("%lld",s[i]);
//        else printf(" %lld",s[i]);
//    }
//    return 0;
//}

#include <bits/stdc++.h>
using namespace std;

long long s[1000]={0};bool isI(double k)
{
    if(fabs((long long)(k+0.000001)-k)<1e-7)
        return true;
    else
        return false;
}
int main()
{
    int n;
    cin>>n;
    double q;
    int flag=-1;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&s[i]);
        if(s[i]==0)
            flag=i;
    }
    if(n==1&&s[0]>0)
        s[0]--;
    else if(n==1&&s[0]==0)
        s[0]++;
    else if(n==2)
    {
        if(flag==0)
        {
            if(s[0]==s[1]&&s[0]==1)
                s[1]=s[0]*2;
            else if(s[0]==s[1]&&s[0]!=1)
                s[0]=1;
            else if(s[1]!=1)
                s[0]=1;
            else if(s[1]==1)
                s[0]=2;
        }else{
            if(s[0]==0){
                if(isI(s[1]/2.0))
                    s[0]=s[1]/2.0+0.000001;
                else
                    s[0]=s[1]*2;
            }else{
                if(isI(s[0]/2.0))
                    s[1]=s[0]/2.0+0.000001;
                else
                    s[1]=s[0]*2;
            }
        }
    }else if(n==3){
        if(flag==-1){
            if(isI(sqrt(s[0])*sqrt(s[2])))
                s[1]=(long long)(sqrt(s[0])*sqrt(s[2])+0.000001);
            else if(isI(s[1]/( (double)s[2]/s[1] )))
                s[0]=(long long)(s[1]/( (double)s[2]/s[1] )+0.0000000001);
            else if(isI(s[1]*((double)s[1]/s[0])))
                s[2]=(long long)(s[1]*( (double)s[1]/s[0])+0.0000000001);
        }else{
            if(flag==0)
                s[flag]=(long long)((double)(s[1]/((double)s[2]/s[1])+0.000000001));
            else if(flag==1)
                s[flag]=(long long)(sqrt(s[0])*sqrt(s[2])+0.00000001);
            else if(flag==2)
                s[flag]=(long long)(((double)s[1]/s[0])*s[1]+0.00000001);
        }
    }else if(n==4){
        if(fabs(sqrt(s[0])*sqrt(s[2])-s[1])<1e-6)
        {
            s[3]=(long long)(s[2]*((double)s[1]/s[0]+0.0000001));
        }else if(sqrt(s[1])*sqrt(s[3])-s[2]<1e-6){
            s[0]=(long long)((double)s[1]/(double)((double)s[2]/s[1]));
        }else{
            s[1]=s[0]*(pow((double)s[3]/s[0],1.0/3)+0.0000000001)+0.000000001;
            s[2]=s[1]*(pow((double)s[3]/s[0],1.0/3)+0.0000000001)+0.000000001;
        }
    }else{
        if(fabs(sqrt(s[0])*sqrt(s[2])-s[1])<1e-6){
            q=(double)s[1]/s[0];
            for(int i=1;i<n;i++)
            {
                s[i]=(long long)(s[i-1]*q+0.0000001);
            }
        }else if(fabs(sqrt(s[n-1])*sqrt(s[n-3])-s[n-2])<1e-6)
        {
            q=(double)s[n-1]/s[n-2];
            for(int i=n-2;i>=0;i--)
            {
                s[i]=(long long)(s[i+1]/q+0.0000001);
            }
        }else{
            s[n/2]=(long long)(sqrt(s[n/2-1])*sqrt(s[n/2+1])+0.0000001);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(i==0) printf("%lld",s[i]);
        else printf(" %lld",s[i]);
    }
    return 0;
}
