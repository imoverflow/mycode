#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int ppp(char p)
{
    if(p=='N')
        return 1;
    else if(p=='E')
        return 2;
    else if(p=='S')
        return 3;
    else
        return 4;
}
int main()
{
    int sx,sy,ex,ey;
    char po;
    scanf("%d %d %c",&sx,&sy,&po);
    scanf("%d%d",&ex,&ey);
    int pos=ppp(po);
    if(sx==ex&&sy==ey)
    {
        printf("0\n");
        return 0;
    }
    if(sx>ex&&sy<ey)
    {
        if(pos==1)
        {
            printf("5\n");
            printf("A %d\n",abs(sy-ey));
            printf("D\n");
            printf("D\n");
            printf("D\n");
            printf("A %d\n",abs(sx-ex));
        }else if(pos==2)
        {
            printf("5\n");
            printf("D\n");
            printf("D\n");
            printf("A %d\n",abs(sx-ex));
            printf("D\n");
            printf("A %d\n",abs(sy-ey));
        }else if(pos==3)
        {
            printf("4\n");
            printf("D\n");
            printf("A %d\n",abs(sx-ex));
            printf("D\n");
            printf("A %d\n",abs(sy-ey));
        }else if(pos==4)
        {
            printf("3\n");
            printf("A %d\n",abs(sx-ex));
            printf("D\n");
            printf("A %d\n",abs(sy-ey));
        }
    }else if(sx<ex&&sy<ey){
        if(pos==1)
        {
            printf("3\n");
            printf("A %d\n",abs(sy-ey));
            printf("D\n");
            printf("A %d\n",abs(sx-ex));
        }else if(pos==2)
        {
            printf("5\n");
            printf("A %d\n",abs(sx-ex));
            printf("D\n");
            printf("D\n");
            printf("D\n");
            printf("A %d\n",abs(sy-ey));
        }else if(pos==3)
        {
            printf("5\n");
            printf("D\n");
            printf("D\n");
            printf("A %d\n",abs(sy-ey));
            printf("D\n");
            printf("A %d\n",abs(sx-ex));
        }else if(pos==4)
        {
            printf("4\n");
            printf("D\n");
            printf("A %d\n",abs(sy-ey));
            printf("D\n");
            printf("A %d\n",abs(sx-ex));
        }
    }else if(sx<ex&&sy>ey){
        if(pos==1)
        {
            printf("4\n");
            printf("D\n");
            printf("A %d\n",abs(sx-ex));
            printf("D\n");
            printf("A %d\n",abs(sy-ey));
        }else if(pos==2)
        {
            printf("3\n");
            printf("A %d\n",abs(sx-ex));
            printf("D\n");
            printf("A %d\n",abs(sy-ey));
        }else if(pos==3)
        {
            printf("5\n");
            printf("A %d\n",abs(sy-ey));
            printf("D\n");
            printf("D\n");
            printf("D\n");
            printf("A %d\n",abs(sx-ex));
        }else if(pos==4)
        {
            printf("5\n");
            printf("D\n");
            printf("D\n");
            printf("A %d\n",abs(sx-ex));
            printf("D\n");
            printf("A %d\n",abs(sy-ey));
        }
    }else if(sx>ex&&sy>ey){
        if(pos==1)
        {
            printf("5\n");
            printf("D\n");
            printf("D\n");
            printf("A %d\n",abs(sy-ey));
            printf("D\n");
            printf("A %d\n",abs(sx-ex));
        }else if(pos==2)
        {
            printf("4\n");
            printf("D\n");
            printf("A %d\n",abs(sy-ey));
            printf("D\n");
            printf("A %d\n",abs(sx-ex));
        }else if(pos==3)
        {
            printf("3\n");
            printf("A %d\n",abs(sy-ey));
            printf("D\n");
            printf("A %d\n",abs(sx-ex));
        }else if(pos==4)
        {
            printf("5\n");
            printf("A %d\n",abs(sx-ex));
            printf("D\n");
            printf("D\n");
            printf("D\n");
            printf("A %d\n",abs(sy-ey));
        }
    }else if(sx==ex)
    {
        int epos;
        if(sy>ey)
            epos=3;
        else
            epos=1;
        printf("%d\n",(epos-pos<0?epos+4-pos:epos-pos)+1);
        int p=(epos-pos<0?epos+4-pos:epos-pos);
        for(int i=0;i<p;i++)
        {
            printf("D\n");
        }
        printf("A %d\n",abs(sy-ey));
    }else if(sy==ey)
    {
        int epos;
        if(sx>ex)
            epos=4;
        else
            epos=2;
        printf("%d\n",(epos-pos<0?epos+4-pos:epos-pos)+1);
        int p=(epos-pos<0?epos+4-pos:epos-pos);
        for(int i=0;i<p;i++)
        {
            printf("D\n");
        }
        printf("A %d\n",abs(sx-ex));
    }
    return 0;
}
