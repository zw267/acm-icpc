                                            
  //File Name: cf407A.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2015年12月27日 星期日 00时18分54秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <math.h>
#include <vector>

using namespace std;

const int MAXN = 1005;

 vector< pair<int,int> > res[MAXN];

void init(int a,int b)
{
	int ma = a > b ? a: b;
	
	for(int i=1;i<=ma;i++){
		for(int j=1;j<=ma;j++){
			int tmp = i * i + j * j;
			int tmp2 = (int)sqrt(tmp+0.0);
			if(tmp2 <=1000 && tmp2 * tmp2 == tmp){
				res[tmp2].push_back(make_pair(i,j));
			}
		}
	}
}

void solve(int a,int b)
{
	init(a,b);
	if(res[a].size() == 0 && res[b].size() == 0)
		puts("NO");
	else{
		bool flag = false;
		for(int i=0;i<res[a].size();i++){
			for(int j=0;j<res[b].size();j++){
				int x1 = res[a][i].first;
				int y1 = res[a][i].second;
				int x2 = -res[b][j].first;
				int y2 = res[b][j].second;
				if(x1 * x2 + y1 * y2 == 0i && y1 != y2){
					flag = true;
					puts("YES");
					puts("0 0");
					printf("%d %d\n",x1,y1);
					printf("%d %d\n",x2,y2);
					break;
				}
			}
			if(flag)
				break;
		}
		if(!flag)
			puts("NO");
	}
	return ;
}

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	solve(a,b);
	return 0;
}
