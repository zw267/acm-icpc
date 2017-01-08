                                            
  //File Name: cf607A.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2015年12月24日 星期四 10时50分08秒
                                   
/*
题意：
给出n只怪兽的位置pos和pow，每只怪兽被激活时，距离这只怪兽的左边的距离在pow内的怪兽都被会消灭，自己没有事
并且激活的顺序是从最右到最左，被消灭的怪兽就不能再激活了
现在我们要在最右边的任意位置放置一只pow任意的怪兽，使得从右到左激活一遍后，被消灭的怪兽的数量最小

思路：
小按照位置小到大排序
注意要排序
dp
假设我们不放怪兽
设dp[i]表示第i只怪兽激活的话，被消灭的怪兽的数量
则转移：
dp[i]= dp[cur] + i - cur - 1
其中：cur是指i左边的怪兽中最右的没有被消灭的怪兽的下标
用二分在O(logn)内可以求出cur
我们加的怪兽的目的就是要让最右边的若干只怪兽被消灭，没有办法激活
所以 
res = min(dp[i] + n - i)

*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <cstdlib>

#define pos first
#define pow second

using namespace std;

const int MAXN = 100000+5;

pair<int,int> a[MAXN];
int dp[MAXN];

int bs(int cur)
{
	int l = 1,r = cur;
	while(r - l  > 1){
		int mid = (l + r) >> 1;
		if(a[cur].pos - a[mid].pos <= a[cur].pow)
			r = mid;
		else
			l = mid;
	}
	if(a[cur].pos - a[r].pos > a[cur].pow)
		return r;
	else
		return l;
}

void solve(int n)
{
	sort(a+1,a+n+1);

	dp[1] = 0;
	for(int i=2;i<=n;i++){
		if(a[i].pow >= a[i].pos - a[1].pos ){
			dp[i] = i - 1;
		}
		else{
			int cur = bs(i);
			//printf("%d %d\n",i,cur);
			dp[i] = dp[cur] + i - cur -1;
		}
	}
	
	int res = MAXN;
	for(int i=1;i<=n;i++){
		if(dp[i] + n - i < res)
			res = dp[i] + n - i;
	}
	printf("%d\n",res);
	return ;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[i].pos,&a[i].pow);
	}
	solve(n);

	return 0;
}
