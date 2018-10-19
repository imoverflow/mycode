#include <stdio.h>
#include <stdlib.h>

main()
{
    FILE *fl;
    char ad[50];
    char num;
    int c[50][5];
    int row=0;
    int col=0;
    int d[50];
    int wei=0;
    int count=0;
    int num1,num2;
    int i;
    printf("please input file address:");
    scanf("%s",ad);
    printf("%s",ad);
    if((fl=fopen(ad,"r"))==NULL)
    {
        printf("\nerror");
        exit(0);
    }
    else
    {
        printf("\nsuccess\n");
        while((fscanf(fl,"%d %d",&num1,&num2))!=EOF)
        {
            printf("%d\t",(num1+num2));
        }
    }
}
