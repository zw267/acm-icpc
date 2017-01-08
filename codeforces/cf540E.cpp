                                            
  //File Name: cf540E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2015年12月30日 星期三 23时36分52秒


/*
题意：
给出一个无限的数组1，2，3，4，5，6，7，8，，，
然后给出n个询问 n <= 2e5, 每一个询问给出2个数 1<=a,b <=1e9,表示把数组a，b位置的数对换
问经过n个操作后，这个数组的逆序数

思路：
虽然数组是无限远的，但其实我们只要关注它交换的最远的那个位置即可，后面的不用考虑
但是它最远的也有1e9那么远啊
所以第一步：离散化
逆序数，我们只要考虑前面比它大的数的个数即可
对于一个数组，我们可以把一些连续的数看成是一个集合，因为它们具有相同的性质：
比里面一个数大，就比所有的数大，比一个数小，就比所有的数小
所以我们就把这个数组转化为元素为集合的数组了
那么离散化的时候：
如果一个位置被操作过，那么这个数单独是一个集合，个数为1
如果连续一个区间都没有被操作过，那么这个区间是一个集合，个数为区间的个数
离散化后，就相当于是一个普通的数组了，树状数组求逆序数即可
*/
                                   

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <cstdlib>

#define LL long long

using namespace std;

const int MAXN = 8e5+10;

LL c[MAXN];         //树状数组，为离散化后的点代表的集合中的元素个数
int num[MAXN];      //离散化后的点代表的集合个数
int chg[400000+10]; //id为i的点被离散话化为chg[i]
int a[MAXN];        //被操作的数组
int rev[MAXN];      //离散化后的点原来的点

struct Node         //为了离散化
{
	int id,val;
};
Node node[400000+10];

bool cmp1(Node x,Node y)
{
	if(x.val == y.val)
		return x.id < y.id;
	return x.val < y.val;
}

inline int lb(int x)
{
	return x&(-x);
}

void update(int x,int add,int n)
{
	while(x <= n) {
		c[x] += add;
		x += lb(x);
	}
}

LL query(int x)
{
	LL ret = 0;
	while(x > 0) {
		ret += c[x];
		x -= lb(x);
	}
	return ret;
}

void solve(int n)
{
	sort(node+1,node+2*n+1,cmp1);

	int tot = 0;
	node[0].val = 0;
	rev[0] = 0;

	for(int i=1;i<=2*n;i++) {
		if(node[i].val == node[i-1].val) {
			chg[node[i].id] = tot;
		}
		else {
			tot += 2;                 //2个被操作的数中间还有一段没有被操作的区间，那段也要新编号
			chg[node[i].id] = tot;
			rev[tot] = node[i].val;
		}
	}

	for(int i=2;i<=tot;i+=2) {             //求出各个区间的个数
		num[i] = 1;
		num[i-1] = rev[i] - rev[i-2] - 1;
	}

	for(int i=1;i<=tot;i++)                //按照操作顺序进行操作
		a[i] = i;
	for(int i=1;i<=n;i++) {
		swap(a[chg[2*i-1]],a[chg[2*i]]);
	}
	
	LL res = 0;
	for(int i=1;i<=tot;i++){                 //求数组a的逆序数个数
		LL cur = query(tot) - query(a[i]);
		res = res + cur * num[a[i]];
		//printf("%d\n",cur);
		update(a[i],num[a[i]],tot);
	}
	printf("%lld\n",res);
	return ;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d %d",&node[2*i-1].val,&node[2*i].val);
		node[2*i-1].id = 2*i-1;           //为了离散化放在同一个数组里面，第i个询问操作的数是2*i-1和2*i
		node[2*i].id = 2*i;
	}
	solve(n);
	return 0;
}
