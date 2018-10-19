//#include <iostream>
//#include <bits/stdc++.h>
//#define INF 0x3f3f3f3f
//using namespace std;
//set<pair<int,int> >s;
//bool cmp(const pair<int,int>&a,const pair<int,int>&b)
//{
//    return a.first<b.first;
//}
//int main()
//{
//    for(int i=1;i<=25;i++)
//        s.insert(make_pair(INF,i));
//    pair<int,int>xx;
//    while(s.size()>=5)
//    {
//        vector<pair<int,int> >temp;
//        for(int i=0;i<5;i++)
//        {
//            temp.push_back(*s.begin());
//            printf("%d ",s.begin()->second);
//            s.erase(s.begin());
//        }
//        printf("\n");
//        fflush(stdout);
//        for(int i=0;i<5;i++)
//        {
//            scanf("%d",&temp[i].first);
//        }
//        sort(temp.begin(),temp.end(),cmp);
//        s.insert(temp[0]);
//        s.insert(temp[1]);
//        xx=temp[2];
//    }
//    vector<pair<int,int> >temp;
//    for(int i=0;i<4;i++)
//    {
//        temp.push_back(*s.begin());
//        printf("%d ",s.begin()->second);
//        s.erase(s.begin());
//    }
//    printf("%d\n",xx.second);
//    fflush(stdout);
//    temp.push_back(xx);
//    for(int i=0;i<5;i++)
//    {
//        scanf("%d",&temp[i].first);
//    }
//    sort(temp.begin(),temp.end(),cmp);
//    printf("%d %d 0 0 0\n",temp[0].second,temp[1].second);
//    fflush(stdout);
//    return 0;
//}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ans1 = 1, ans2 = 2;
    int a[6][6];
    int b[6][6];
    int c[6];
    int cnt = 1;
    map<int, int> m;
	for(int i = 1; i <= 5; i ++)
	{
		for(int j = 1; j <= 5; j ++)
		{
			a[i][j] = cnt++;
			m[a[i][j]] = i;
			//printf("%d%c", a[i][j], j==5?'\n':' ');
		}
		//fflush(stdout);
		//cout<<flush;
		for(int j = 1; j <= 5; j ++)
		{
			int x=0;	//scanf("%d", &x);
			b[i][x] = a[i][j];
		}
	}

	for(int i = 1; i <= 5; i ++)
	{
		//printf("%d%c", b[i][1], i==5?'\n':' ');
	}
	fflush(stdout);
	cout<<flush;
	for(int i = 1; i <= 5; i ++)
	{
		int x=0;	//scanf("%d", &x);
		c[x] = b[i][1];
	}
	//µÚ¶þÂÖ

	set<int> v;
	vector<int> s;
	v.insert(c[1]);
	v.insert(c[2]);
	v.insert(b[m[c[1]]][2]);
	v.insert(b[m[c[2]]][2]);
	for(int i = 1; i <= 25; i ++)
	{
		v.insert(i);
		if(v.size() == 5)	break;
	}
	set<int> :: iterator it = v.begin();
	while(it != v.end())
	{
		//cout<<*it;
		s.push_back(*it);
		it ++;
		//if(it == v.end())	cout<<endl;
		//else 	printf(" ");
	}
	fflush(stdout);
	cout<<flush;

	for(int i = 1; i <= 5; i ++)
	{
		int x=0;
		//scanf("%d", &x);
		c[x] = s[i-1];
	}
	printf("%c %c %c %c %c %c %c\n", 53,50,48,49,51,49,52);
	//fflush(stdout);
	//cout<<flush;
    return 0;
}
