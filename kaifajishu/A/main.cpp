#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct point
{
    double x,y;
    point() {}
    point(double x,double y):x(x),y(y) {}
};

vector<point> g[500];
struct pre2next{
    point prelt,prerb,nxtlt,nxtrb;
    pre2next(){
        prelt=point(-1,-1);
        prerb=point(-1,-1);
        prelt=point(-1,-1);
        nxtrb=point(-1,-1);
    }
    pre2next(point prelt,point prerb,point nxtlt,point nxtrb):prelt(prelt),prerb(prerb),nxtlt(nxtlt),nxtrb(nxtrb){}
};
pre2next zoom;
double dis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void calc(pre2next a)
{
    if(fabs(dis(a.prelt,a.prerb)-dis(a.nxtlt,a.nxtrb))<1e-4)
       printf("Not Move!\n");
    else if(dis(a.prelt,a.prerb)-dis(a.nxtlt,a.nxtrb)>1e-4)
    {
        printf("Zoom out %.2f\n",dis(a.prelt,a.prerb)-dis(a.nxtlt,a.nxtrb));
    }else{
        printf("Zoom in %.2f\n",dis(a.nxtlt,a.nxtrb)-dis(a.prelt,a.prerb));
    }
}


void zoomer(vector<double> a,vector<double> b)
{
    int flag=-1;
    if(zoom.prelt.x<0){
        flag=0;
    }else if(zoom.nxtlt.x<0){
        flag=1;
    }else{
        flag=2;
    }
    if(a.size()==1&&b.size()==1||a.size()*b.size()>4) return;
    if(flag==0)
    {
        zoom.prelt=point(a[0],b[0]);
        zoom.prerb=point(a[a.size()-1],b[b.size()-1]);
//        return ;
    }else if(flag==1){
        zoom.nxtlt=point(a[0],b[0]);
        zoom.nxtrb=point(a[a.size()-1],b[b.size()-1]);
        calc(zoom);
    }else if(flag==2)
    {
        zoom.prelt=zoom.nxtlt;
        zoom.prerb=zoom.nxtrb;
        zoom.nxtlt=point(a[0],b[0]);
        zoom.nxtrb=point(a[a.size()-1],b[b.size()-1]);
        calc(zoom);
    }
    return;
}

void solve(vector<point> g[],int n)
{
    vector<int> res1;
    bool flag=false;
    for(int j=0; j<g[0].size()-1; j++)
    {
        point t1=g[0][j];
        point t2=g[0][j+1];
        if(t1.y>t2.y&&!flag)
        {
            flag=true;
            if(t1.y<10) continue;
            res1.push_back(j);
        }
        else
        {
            int t=j;
            while(t+1<g[0].size()&&g[0][t].y>g[0][t+1].y)
            {
                t++;
            }
            j=t;
            if(t!=g[0].size()-1)
                flag=false;
        }
    }
    if(!flag&&g[0][g[0].size()-1].y>=10)
    {
        res1.push_back(g[0].size()-1);
    }


    vector<int> res2;
    flag=false;
    for(int j=0; j<n-1; j++)
    {
        point t1=g[j][0];
        point t2=g[j+1][0];
        if(t1.x>t2.x&&!flag)
        {
            flag=true;
            if(t1.x<10) continue;
            res2.push_back(j);
        }
        else
        {
            int t=j;
            while(t+1<n&&g[t][0].x>g[t+1][0].x)
            {
                t++;
            }
            j=t;
            if(t!=n-1)
                flag=false;
        }
    }
    if(!flag&&g[n-1][0].x>=10)
    {
        res2.push_back(n-1);
    }
    //for test
    for(int i=0; i<res1.size(); i++)
    {
        for(int j=0; j<res2.size(); j++)
        {
            printf("(%d,%d)\n",res2[j],res1[i]);
        }
    }
    //end test
    vector<double> ans1;
    for(int i=0; i<res1.size(); i++)
    {
        int sum1=0,sum2=0;
        int k=res1[i];
        for(int j=1; j+k<g[0].size(); j++)
        {
            if(g[0][j+k].y>g[0][j+k-1].y)
                break;
            sum1+=(j+k)*g[0][j+k].y;
            sum2+=g[0][j+k].y;
        }
        for(int j=1; k-j>=0; j++)
        {
            if(g[0][k-j].y>g[0][k-j+1].y)
                break;
            sum1+=(k-j)*g[0][k-j].y;
            sum2+=g[0][k-j].y;
        }
        sum1+=k*g[0][k].y;
        sum2+=g[0][k].y;
        ans1.push_back(1.0*sum1/sum2);
    }

    vector<double> ans2;
    for(int i=0; i<res2.size(); i++)
    {
        int sum1=0,sum2=0;
        int k=res2[i];
        for(int j=1; j+k<n; j++)
        {
            if(g[j+k][0].x>g[j+k-1][0].x)
                break;
            sum1+=(j+k)*g[j+k][0].x;
            sum2+=g[j+k][0].x;
        }
        for(int j=1; k-j>=0; j++)
        {
            if(g[k-j][0].x>g[k-j+1][0].x)
                break;
            sum1+=(k-j)*g[k-j][0].x;
            sum2+=g[k-j][0].x;
        }
        sum1+=k*g[k][0].x;
        sum2+=g[k][0].x;
        ans2.push_back(1.0*sum1/sum2);
    }

    for(int i=0; i<ans1.size(); i++)
    {
        for(int j=0; j<ans2.size(); j++)
        {
            printf("(%.2f %.2f)\n",ans2[j],ans1[i]);
        }
    }
    sort(ans1.begin(),ans1.end());
    sort(ans2.begin(),ans2.end());
    zoomer(ans1,ans2);
}
int main()
{
    freopen("in2.txt","r",stdin);
    int n,m;
    zoom=pre2next();
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0; i<n; i++)
        {
            g[i].clear();
            for(int j=0; j<m; j++)
            {
                int a,b;
                scanf("%d%d",&a,&b);
                g[i].push_back(point(a,b));
            }
        }
        solve(g,n);
        cout<<endl;
    }
    return 0;
}
