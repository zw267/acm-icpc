                                            
  //File Name: cf140C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2015年12月30日 星期三 08时48分26秒
          
/*
题意：
给出一个序列，每一次可以从序列里面拿出3个不同的数，问最多可以拿多少组
并且输出每一组，如果有多个答案，都可以
思路：
1.先离散化或者用map
2.记录每一个数出现的次数，放到优先队列里面，大的优先级高
   每次从优先队列里面拿出3个数x,y,z，3个数只减去1，然后还>0就放回去
   直到队列元素个数<3
每次只减去1，一共就减去3，因为最多元素个数也就1e5,复杂度是可以的

刚开始的时候是贪心每次减去z,然后x,y还>0就放回去，但是这样是错的

*/                         

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <cstdlib>

#define LL long long

using namespace std;

const int MAXN = 1e5+5;

int r[MAXN];
int chg[MAXN];
int rev[MAXN];
int num[MAXN];
pair< pair<int,int> ,pair<int,int> > ans[MAXN];
struct Node 
{
	int num,r;
	bool operator < (const Node& x) const {
		if(x.num == num)
			return x.r > r;
		return x.num > num;
	}
};

void change(int& x,int& y,int & z) 
{
	if(x < z)
		swap(x,z);
	if(y > x)
		swap(y,x);
	if(y < z)
		swap(y,z);
}

void solve(int n)
{
	sort(r+1,r+n+1);
	int tot = 0;
	r[0] = 0;

	for(int i=1;i<=n;i++){
		if(r[i] == r[i-1])
			chg[i] = tot;
		else {
			chg[i] = ++tot;
			rev[tot] = r[i];
		}
	}
	/*
	printf("tot = %d\n",tot);
	for(int i=1;i<=n;i++)
		printf("%d  ",r[i]);
	puts("");
	for(int i=1;i<=n;i++)
		printf("%d  ",chg[i]);
	puts("");
	for(int i=1;i<=tot;i++)
		printf("%d ",rev[i]);
	puts("");
	*/
	for(int i=1;i<=n;i++){
		num[chg[i]]++;
	}
	priority_queue <Node> que;
	for(int i=1;i<=tot;i++) {
		que.push((Node){num[i],rev[i]});
		//printf("%d %d\n",num[i],rev[i]);
	}

	int res = 0;
	int len = 1;
	while(que.size() >= 3) {
		Node x = que.top();
		que.pop();
		Node y = que.top();
		que.pop();
		Node z = que.top();
		que.pop();
		res += 1;
		ans[len++] = make_pair(make_pair(1,z.r),make_pair(y.r,x.r));
		x.num -= 1;
		y.num -= 1;
		z.num -= 1;
		if(x.num > 0)
			que.push(x);
		if(y.num > 0)
			que.push(y);
		if(z.num > 0)
			que.push(z);
	}

	printf("%d\n",res);
	for(int i=1;i<len;i++) {
		int k = ans[i].first.first;
		int x = ans[i].first.second;
		int y = ans[i].second.first;
		int z = ans[i].second.second;
		change(x,y,z);
		for(int j=1;j<=k;j++){
			printf("%d %d %d\n",x,y,z);
		}
	}
	return ;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&r[i]);
	solve(n);
	return 0;
}
