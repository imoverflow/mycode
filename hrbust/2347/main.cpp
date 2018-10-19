#include <bits/stdc++.h>
using namespace std;

#define N 1005

char a[N][N];

void draw(int x, int y, int n)
{

    int temp = pow(3,n-2);
    if(n==1)
    {
        a[x][y] = '*';
    }
    else
    {
        draw(x,y,n-1);
        draw(x-temp,y,n-1);
        draw(x+temp,y,n-1);
        draw(x,y-temp,n-1);
        draw(x,y+temp,n-1);
    }
}

char s[100][100];
int main()
{
    int b;
    int n,m;
    while(~scanf("%d%D",&n,&m))
    {
        for(int i=0;i<n;i++)
            scanf("%s",s[i]);
        memset(a,' ',sizeof(a));
        if(m == 1)
        {
            draw(1,1,1);
        }
        else
        {
            int x= pow(3,m-2)+(pow(3,m-2)+1)/2;
            draw(x,x,b);

        }


        cout<<"Case #"<<m-n<<":"<<endl;
        int temp = pow(3,b-1);
        for(int i=1; i<=temp; i++)
        {
            for(int j=1; j<=temp; j++)
            {
                cout<<a[i][j];
            }
            cout<<endl;
        }
    }


    return 0;
}
