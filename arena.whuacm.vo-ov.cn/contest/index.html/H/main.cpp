#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
vector<ull> s(1000006);
ull A,B,s0;
long long L,n;
void allocate(ull A, ull B, ull s0)
{
    s[0]=s0;
    for (int i = 1,j=0; i < n; i++,j++) {
        s[i]=s[i - 1] * A + B;
        if(j==1000000)
        {
            nth_element(s.begin(),s.begin()+s.size()/2,s.end());
            if(s.size()/2<L){
                L-=s.size()/2;
                s.erase(s.begin(),s.begin()+s.size()/2);
            } else{
                nth_element(s.begin(),s.begin()+L,s.end());
                cout<<s[L]<<endl;
            }
            j=0;
        }
    }
}
int main()
{


    return 0;
}
