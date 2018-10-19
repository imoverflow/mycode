#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int t1=n%3;
    int t2=n/3;
    for(int i=-2;i<=2;i++)
    {
        for(int j=-2;j<=2;j++)
        {
            for(int k=-2;k<=2;k++)
            {
                int a=t2+i,b=t2+j,c=t2+k;
                if(a+b+c==n&&a%3!=0&&b%3!=0&&c%3!=0&&a>=0&&b>0&&c>0)
                {
                    cout<<a<<" "<<b<<" "<<c<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
