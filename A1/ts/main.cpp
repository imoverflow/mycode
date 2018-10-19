#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
	int age[100000];
	int year,i,j,a;
	int count=0;

		while(scanf("%d",&a)!=EOF)
        {
            age[0]=4;
		age[1]=0;
		for(i=2;i<100000;i++)
            {
			age[i]=-1;
		}
            if(a==0)
                exit(0);
            count=0;
            for(year=1;year<a;year++){
			for(j=99999;j>=0;j--){
				if(age[j]!=-1){
                    age[j]=age[j]+1;
					if(age[j]>=3){
						count++;
						age[count]=0;
					}
				}else{
					continue;
				}
			}
		}
		printf("%d\n",count+1);
        }
    return 0;
}
