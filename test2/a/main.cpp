#include <bits/stdc++.h>

using namespace std;
void shellInsert(int array[],int n,int dk)
{
    int i,j,temp;
    for (i=dk; i<n; i++) { //分别向每组的有序区域插入
        temp = array[i];
        for(j=i-dk; (j>=i%dk) && array[j]>temp ;j-=dk)//比较与记录后移同时进行
            array[j+dk]=array[j];
        if(j!=i-dk)
            array[j+dk]=temp;//插入
    }
}

//计算Hibbard增量
int dkHibbard(int t,int k)
{
    return int(pow(2,t-k+1)-1);
}

//希尔排序
void shellSort(int array[],int n,int t)
{
    void shellInsert(int array[],int n,int dk);
    int i;
    for(i=1;i<=t;i++)
        shellInsert(array,n,dkHibbard(t,i));
}
void bubble_sort(int arr[], int len)
{
    int i, j;  int temp;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
        if (arr[j] > arr[j + 1])
        {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
}
int s[1000006];
int main()
{
    srand(time(0));
    for(int i=0;i<1000000;i++)
    {
        s[i]=rand();
    }
    long long pre=clock();
    shellSort(s,1000000,int(log(1000000+1)/log(2)));
    long long last=clock();
    cout<<"Shell:"<<(last-pre)<<endl;

    pre=clock();
    bubble_sort(s,1000000);
    last=clock();
    cout<<"Bubble:"<<(last-pre)<<endl;
    return 0;
}


