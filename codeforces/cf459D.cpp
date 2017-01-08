                                            
  //File Name: cf459D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2015年12月29日 星期二 22时05分37秒


/*
题意：
给出一个数组，长度为n<=1e6,然后问这个数组里面有多少点对(i,j)满足：
1.1 <= i < j <= n
2. ai在区间1～i出现的次数  > aj在区间j~n出现的次数

思路：
1.用数组存：pre[i] 表示ai在区间1～i出现的次数
   用数组存：post[i] 表示ai在区间i~n出现的次数
   用map可以解决
2.遍历数组pre对于每一个i，统计数组post在区间i+1~n里有多少个数 是小于 pre[i]的
   要完成2，只要遍历pre的顺序为从后往前，用一个树状数组可以解决

*/                               

#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>

#define LL long long 

using namespace std;

const int MAXN = 1e6+10;

int c[MAXN];
int a[MAXN];
int post[MAXN];
int pre[MAXN];

inline int lb(int x)
{
	return x&(-x);
}

void update(int x,int add,int n)
{
	while(x <= n){
		c[x] += add;
		x += lb(x);
	}
}

int query(int x)
{
	if(x == 0)
		return 0;
	int ret = 0;
	while(x > 0){
		ret += c[x];
		x -= lb(x);
	}
	return ret;
}

void solve(int n)
{
	map<int,int> mp;
	for(int i=1;i<=n;i++){
		pre[i] = (++mp[a[i]]);
	}
	//for(int i=1;i<=n;i++)
	//	printf("%d ",pre[i]);
	//puts("");
	mp.clear();
	for(int i=n;i>0;i--){
		post[i] = (++mp[a[i]]);
	}
	//for(int i=1;i<=n;i++)
	//	printf("%d ",post[i]);
	//puts("");

	LL res = 0;
	for(int i=n;i>0;i--){
		res += (LL)query(pre[i] - 1);
		update(post[i],1,n);
	}

	printf("%lld\n",res);
	return ;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	solve(n);
	return 0;
}
