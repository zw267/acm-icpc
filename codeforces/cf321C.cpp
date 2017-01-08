                                            
  //File Name: cf321C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月24日 星期日 23时23分27秒

/*

有一棵无根无向树，n <= 1e5，现在要给这棵树的每一个节点分配一个等级，
有26个等级，编号为A～Z，A最高，Z最低
要求：任意2个不同的节点x,y，如果他们的等级相同，则在路径path(x,y)上
必须有一个节点的等级高于他们

如果能够构造出来，输出每一个节点的等级
如果不能，输出Impossible!

思路：
树分治
对于一棵子树，其中一条路径要么经过重心，要么不经过重心

所以我们可以每次对重心赋等级，从高到低，分治处理

这样处理使得经过重心的路径的2个节点有重心做保证，
不经过重心的节点，赋值相互没有影响

注意：
无向图的话，链式前向星的时候，数组要开成边数的2倍

*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

const int MAXN  = 1e5+5;
const int INF = 0x3f3f3f3f;

struct Edge
{
	int to,next;
};
Edge edge[MAXN << 1];
int head[MAXN];
int ans[MAXN];
int cnt;
int sub_size[MAXN];
bool cen[MAXN];

void init(int n)
{
	memset(cen,false,sizeof cen);
	memset(head,-1,sizeof head);
	cnt = 0;
	for(int i=0;i<=n;i++)
		ans[i] = INF;	
}

void addedge(int u,int v)
{
	edge[cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
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
	int s = 1;
	int m = 0;
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == fa || cen[v])
			continue;
		res = min(res,get_cen(v,u,sum));
		m = max(m,sub_size[v]);
		s += sub_size[v];
	}
	m = max(m,sum - s);
	res = min(res,make_pair(m,u));
	return res;
}

void solve_sub(int root,int tot)
{
	get_sub_size(root,root);
	if(sub_size[root] == 1){
		ans[root] = tot;
		return ;
	}
	int s = get_cen(root,root,sub_size[root]).second;
	cen[s] = true;
	ans[s] = tot;
	for(int i=head[s];~i;i=edge[i].next){
		int v = edge[i].to;
		if(cen[v])
			continue;
		solve_sub(v,tot+1);
	}
	cen[s] = false;
}

int main()
{
	int n;
	scanf("%d",&n);
	init(n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}

	solve_sub(1,0);
	bool flag = true;
	for(int i=1;i<=n;i++){
		if(ans[i] >= 0 && ans[i] <= 25)
			continue;
		flag = false;
		break;
	}
	if(!flag){
		puts("Impossible!");
	}
	else{
		for(int i=1;i<n;i++){
			printf("%c ",(char)ans[i] + 'A');
		}
		printf("%c\n",(char)ans[n] + 'A');
	}

	return 0;
}

