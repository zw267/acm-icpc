                                            
  //File Name: hdu4812.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月25日 星期一 09时51分50秒

/*
题意：给出一棵树，点有权值，n <= 1e5 ，给出一个数K
在树上求一条链，使得这条链上的点权之积 % (1e6+3) == K
输出2个端点a,b(a<b)
如果有多条链，输出字典序最小的链的端点

思路：
树分治 + 逆元

对于一条链，有3种情况：
0.经过重心且2个端点不在重心上
1.经过重心，刚好有一个端点在重心上
2.没有经过重心

对于2，递归处理
对于1,求0的时候特殊判断一下

那么怎么求0呢？

从重心开始dfs，求出每一点到重心这一部分链的乘积(不包括重心)
遍历，已知一部分链的乘积为x
则有：x*y*val[s] =K(mod MOD)
则另外一部分链的乘积必须是y
这里用逆元可以求得y=inv(x*val[s]) * K % MOD
然后判断有没有链的乘积为y

这里需要2个数组：
num[i] 节点i到重心这部分链的乘积
id[i] 乘积为i的节点的编号，没有则为-1

注意：
0.求的时候姿势要对，防止2个节点在同一颗子树的情况(因为这个wa了一晚上)
1.这道题时限卡的很紧，要预处理出0~MOD-1的逆元
2.可以想到的可以加快速度的我都加了

*/
                                   

#pragma comment(linker,"/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>

#define LL long long
#define fir first
#define sec second

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5+5;
const int MOD = 1e6+3;

struct Edge
{
	int to,next;
};
Edge edge[MAXN << 1];
int head[MAXN];
int val[MAXN];
int K,N,tot;
bool cen[MAXN];
int sub_size[MAXN];
int num[MAXN];
int id[MOD];
int ans1,ans2;
int now[MAXN];
LL inv[MOD];

void init()
{
	memset(head,-1,sizeof head);
	tot = 0;
	memset(cen,false,sizeof cen);
	memset(id,-1,sizeof id);
	memset(num,-1,sizeof num);
	ans1 = ans2 = INF;
}

void addedge(int u,int v)
{
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] =tot++;
}

LL qp(LL x,LL y)
{
	LL res = 1;
	while(y){
		if(y & 1)
			res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

int get_sub_size(int u,int fa)
{
	int tmp = 1;
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == fa || cen[v])
			continue;
		tmp += get_sub_size(v,u);
	}
	sub_size[u] = tmp;
	return tmp;
}

pair<int,int> get_cen(int u,int fa,int sum)
{
	pair<int,int> res = make_pair(INF,-1);
	int s = 1,m = 0;
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == fa || cen[v])
			continue;
		res = min(res, get_cen(v,u,sum));
		m = max(m,sub_size[v]);
		s += sub_size[v];
	}
	m = max(m,sum-s);
	res = min(res,make_pair(m,u));
	return res;
}

void update(int l,int r)
{
	if(l > r)
		swap(l,r);
	if(l > ans1)
		return ;
	if(l == ans1 && r >= ans2)
		return ;
	ans1 = l;
	ans2 = r;
}

void dfs0(int u,int fa,LL sum,int& d)
{
	num[u] = (LL)val[u] * sum % MOD;
	now[d++] = u;
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == fa || cen[v])
			continue;
		dfs0(v,u,num[u],d);
	}
}

void dfs1(int u,int fa,LL sum)
{
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == fa || cen[v])
			continue;
		int cnt = (LL)val[v] * sum % MOD;
		id[cnt] = -1;
		dfs1(v,u,cnt);
	}
}

void solve_sub(int root)
{
	get_sub_size(root,root);
	if(sub_size[root] == 1){
		return ;
	}
	int s = get_cen(root,root,sub_size[root]).sec;
	cen[s] = true;
	int d;	
	for(int i=head[s];~i;i=edge[i].next){
		int v = edge[i].to;
		if(cen[v])
			continue;
		d = 0;
		dfs0(v,s,1,d);
		for(int j=0;j<d;j++){
			int a = now[j];
			int x = (LL)num[a] * val[s] % MOD;
			if(x == K)
				update(a,s);
			int y = (LL)inv[x] * K % MOD;
			if(id[y] == -1 || id[y] == a)
				continue;
			update(id[y],a);
		}
		for(int j=0;j<d;j++){
			int a = now[j];
			int x = num[a];
			if(id[x] == -1)
				id[x] = a;
			else
				id[x] = min(id[x],a);
		}
	}
	dfs1(s,s,1);

	for(int i=head[s];~i;i=edge[i].next){
		int v = edge[i].to;
		if(cen[v])
			continue;
		solve_sub(v);
	}
	cen[s] = false;
}

int main()
{
	inv[0] = 0;
	inv[1] = 1;
	for(int i=2;i<MOD;i++){
		inv[i] =qp(i,MOD-2);
	}
	while(scanf("%d %d",&N,&K) != EOF){
		init();
		for(int i=1;i<=N;i++){
			scanf("%d",&val[i]);
		}
		int u,v;
		for(int i=1;i<N;i++){
			scanf("%d %d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		
		solve_sub(1);

		if(ans1 == INF || ans2 == INF)
			puts("No solution");
		else
			printf("%d %d\n",ans1,ans2);
	}
	return 0;
}
