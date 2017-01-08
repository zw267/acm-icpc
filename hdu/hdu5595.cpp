#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF= 0x3f3f3f3f;

int a,b,c;

inline int fun(int x)
{
	return a * x * x + b * x + c;
}

void solve(int l,int r)
{
	int ma = -INF;
	int mi = INF;
	for(int i=l;i<=r;i++){
		int cur = fun(i);
		if(cur > ma)
			ma = cur;
		if(cur < mi)
			mi = cur;
	}
	printf("%d %d\n",ma,mi);
	return ;
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		int l,r;
		scanf("%d %d %d %d %d",&a,&b,&c,&l,&r);
		solve(l,r);
	}
	return 0;
}
