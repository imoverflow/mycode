#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

char a[100005],b[100005];
int main()
{
    char *t=NULL;
    scanf("%s %s",a,b);
    if(strcmp(a,b)==0)
        printf("-1");
    else
        printf("%d",max(strlen(a),strlen(b)));
    return 0;
}
