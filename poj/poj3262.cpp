                                            
  //File Name: poj3262.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月08日 星期五 18时05分37秒
                                   


#include <cstdio>
#include <cstring>
#include <algorithm>

#define LL long long

using namespace std;

const int MAXN = 100000+5;

struct Node
{
	int t,d;
	double l;
};
Node node[MAXN];

bool cmp(Node x,Node y)
{
	return x.l > y.l;
}

void solve(int n)
{
	sort(node+1,node+n+1,cmp);
	LL res = 0LL;
	LL sum = 0LL;
	for(int i=1;i<=n;i++)
		sum+=(LL)node[i].d;

	for(int i=1;i<=n;i++){
		sum -= node[i].d;
		res += (LL)sum * 2LL * node[i].t;
	}

	printf("%lld\n",res);
	return ;
}

int main()
{
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++){
			scanf("%d %d",&node[i].t,&node[i].d);
			node[i].l = (double)node[i].d / node[i].t;
		}

		solve(n);
	}
	return 0;
}


