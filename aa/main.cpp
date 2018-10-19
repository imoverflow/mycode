#include <stdio.h>
#include <stdlib.h>
#define N 10
#define COMPARE(x,y) (((x) < (y)) ? -1: ((x) = = (y) ) ? 0 :1)
int binsearch (int [],int,int,int);

int main()
{

    int left,right,searchnum,k;
    int list[N] = {0,1,2,3,4,5,6,7,8,9};
    left = 0;
    right = N-1;
    printf("Please enter the integer number you want to search:");
    scanf("%d",&searchnum);
    k=binsearch(list,searchnum,left,right);
    printf("%d",k);
    return 0;
}

int binsearch(int list[N],int searchnum,int left,int right)
{
    /* search list[0] <= list[1] <= . . . <= list[N-1] for
    searchnum. Return its position if found. Otherwise return -1 */
    int middle;
    while (left <= right)
    {
        middle = (left + right)/2;
        switch (COMPARE(list[middle],searchnum))
        {
            case -1: left = middle + 1; break;
            case 0: return middle; break;
            case 1: right = middle - 1; break;
            default : break;
        }
    }
    return -1;
}
