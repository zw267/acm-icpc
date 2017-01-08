                                            
  //File Name: hdu5606.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月05日 星期二 20时25分40秒
                 

//dsu                  

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1e5+5;

int fa[MAXN];
int sum[MAXN];

void init(int n)
{
	for(int i=1;i<=n;i++){
		fa[i] = i;
		sum[i] = 1;
	}
}

int find_fa(int u)
{
	if(fa[u] == u)
		return u;
	else{
		fa[u] = find_fa(fa[u]);
		sum[fa[u]] += sum[u];
		sum[u] = 0;
		return fa[u];
	}
}

void solve()
{
	int n;
	scanf("%d",&n);
	init(n);
	for(int i=1;i<n;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		if(!w){
			int fau = find_fa(u);
			int fav = find_fa(v);
			//printf("%d %d",fau,fav);
			if(fau != fav){
				fa[fau] = fav;
				sum[fav] += sum[fau];
				sum[fau] = 0;
			}
		}
	}
	int res = 0;
	for(int i=1;i<=n;i++){
		int tmp = find_fa(i);
		//printf("%d %d\n",tmp,sum[tmp]);
		res = res ^ sum[tmp];
	}
	printf("%d\n",res);
	return ;
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		solve();
	}
	return 0;
}
