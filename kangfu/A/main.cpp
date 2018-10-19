#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long x=0;
    while(~scanf("%d",&n)){
        int zero=0,five=0;
        for(int i=0;i<n;i++){
            int a;
            scanf("%d",&a);
            if(a==0){
                zero++;
            }else{
                five++;
            }
        }
        if(five>=9&&zero>0){
            for(int i=0;i<five/9*9;i++){
                printf("5");
            }
            for(int i=0;i<zero;i++){
                printf("0");
            }
            printf("\n");
        }else if(zero>0){
            printf("0\n");
        }else{
            printf("-1\n");
        }
    }
    return 0;
}
