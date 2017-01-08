                                            
  //File Name: cf616D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月21日 星期四 21时29分24秒

/*

给出一个长度为n的数组a，给出一个数k
1 <= n <= 1e5,0 <= ai <= 1e6

对于一个数组的一个区间[l,r]，如果这个区间出现的不同的数的数量
<= k的话，就说这个区间是k-good的，求这个数组的最长的k-good 的区间的
l,r，如果有多个，输出任意一个

思路：
树状数组+2个指针(尺取法)

2个树状数组：
sum[i]记录i在当前的2个指针l，r下出现的次数
have[i]记录i在当前的2个指针l,r下有没有出现

注意：
0.sum,have的数组范围要开到1e6
1.由于a[i]可能等于0，而树状数组的下标要从1开始，
  则输入的时候，a[i]++
2.2个指针l,r此时表示的区间是[l,r),左闭右开


然后在尺取的时候不断更新答案ansl,ansr的值

*/
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 500000+5;

int a[MAXN];
int have[MAXN << 1];
int sum[MAXN << 1];

inline int lb(int x)
{
	return x & (-x);
}

void update(int* arr,int x,int add,int n)
{
	while(x <= n){
		arr[x] += add;
		x += lb(x);
	}
}

int query(int* arr,int x)
{
	int res = 0;
	while(x > 0){
		res += arr[x];
		x -= lb(x);
	}
	return res;
}

void solve(const int n,const int k)
{
	int N = MAXN << 1;
	memset(have,0,sizeof have);
	memset(sum,0,sizeof sum);

	int ansl = 1,ansr = 1;

	int l = 1,r = 1;
	update(have,a[l],1,N);
	update(sum,a[l],1,N);

	while(l < n){
		while(r <= n && query(have,N) <= k){
			r++;
			if(r > n)
				break;
			//printf("%d\n",query(have,N));
			update(sum,a[r],1,N);
			if(query(have,a[r]) - query(have,a[r] - 1) == 0){
				update(have,a[r],1,N);

			}
		}
		if(r - 1 - l > ansr - ansl){
			ansl = l;
			ansr = r - 1;
		}
		update(sum,a[l],-1,N);
		if(query(sum,a[l]) - query(sum,a[l] - 1) == 0){
			update(have,a[l],-1,N);
		}
		l++;
		//puts("eeeeeeeeeeee");
	}

	printf("%d %d\n",ansl,ansr);
	return ;
}

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]++;
	}
	solve(n,k);

	return 0;
}
