#include<map>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int main(void){
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    freopen("database.in", "r", stdin);
    freopen("database.out", "w", stdout);
    int n, m;
    while(~scanf("%d%d", &m,&n)){
		getchar();
		string s[10009];
		map<pi, int> mm;
		map<string, int> ma[19];
        for(int i=1; i<=m; i++)
            getline(cin, s[i]);
        string t1;
        int cnt, ans[5], flag=0;
        for(int i=1; i<=m; i++){
			cnt=1;							//cnt,��������,������������,�ͼ�1.
			for(int j=0; j<s[i].length(); j++){
				if(s[i][j]!=','&&j!=s[i].length()-1)
					t1+=s[i][j];			//t1,����һ����Ԫ����ַ���.
				else{
					if(j==s[i].length()-1)	//�ӵ�.
						t1+=s[i][j];
					if(!ma[cnt][t1])		//t1�����ַ���,������cnt��һ�и��ַ�����δ����,���¼����.
						ma[cnt][t1]=i;
					else{					//ͬ��.
						int t2=ma[cnt][t1];
						pi t3(t2,i);
						if(!mm[t3])			//�ж��Ƿ��ǵ�һ��ͬ��,�����ǳ���ͬ��,��ô��¼��.
							mm[t3]=cnt;
						else				//����,�����еڶ���ͬ��,�õ���.
							ans[1]=t2, ans[2]=i, ans[3]=mm[t3], ans[4]=cnt, flag=1;
					}
					cnt++; t1.erase();
				}
			}
        }
        if(flag==1)
			printf("NO\n%d %d\n%d %d\n",ans[1],ans[2],ans[3],ans[4]);
        else
            printf("YES\n");
    }
    return 0;
}
