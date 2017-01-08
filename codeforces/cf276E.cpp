#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define pb push_back
//#define debug printf("eeeeeeeeeeeeeeeeeeeeeeeeeeeeee\n")

using namespace std;

const int MAXN = 100000+10;

vector<int>G[MAXN];        //保存树
int from[MAXN];            //记录节点i离root的距离
int to[MAXN];              //记录节点i离所在链的终点的距离
int c1[MAXN];              //树状数组，c1[i]表示距离root为i-1以内的节点更新的部分权值
						 	//为什么i表示的是i-1?是为了避免下标为0，产生死循环
int c2[MAXN];              //表示重新编号的节点chg[v]的更新的部分和，这一部分和与
							//v在c1中被更新的那部分和的总和就是answer
							//注意2个数组下标意义不同
int chg[MAXN];              //保存重新编号后的编号
int n,tot;                  //tot用于重新编号，2个变量设置为全局变量比较方便

//初始化
void init()
{
	for(int i=0;i<=n;i++){
		G[i].clear();
		c1[i] = 0;
		c2[i] = 0;
	}
}

inline int lb(int x)
{
	return x & (-x);
}

//c1数组插点问段
void update_c1(int x,int add)
{
	if(x <= 0)
		return ;
	while(x <= n + 1){
		c1[x] += add;
		x += lb(x);
	}	
}

int query_c1(int x)
{
	int ret = 0;
	while(x > 0){
		ret += c1[x];
		x -= lb(x);
	}
	return ret;
}

//c2数组插段问点
void update_c2(int x,int add)
{
	while(x > 0){
		c2[x] += add;
		x -= lb(x);
	}
}

int query_c2(int x)
{
	int ret = 0;
	if(x <= 0)
		return ret;
	while(x <= n + 1){
		ret += c2[x];
		x += lb(x);
	}
	return ret;
}

//求出from,to数组
void dfs1(int u,int fa)
{
	to[u] = 0;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v == fa)
			continue;
		from[v] = from[u] + 1;
		dfs1(v,u);
		to[u] = to[v] + 1;
	}	
	
}

//重新编号
void dfs2(int u,int fa)
{
	chg[u] = ++tot;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v == fa)
			continue;
		dfs2(v,u);
	}
}

void solve(int q)
{
	from[1] = 0;
	dfs1(1,1);
	/*
	for(int i=1;i<=n;i++)
		printf("%d %d\n",from[i],to[i]);
	*/
	tot = 0;
	dfs2(1,1);
	/*
	for(int i=1;i<=n;i++)
		printf("%d\n",chg[i]);
	*/
	for(int i=0;i<q;i++){
		int op;
		scanf("%d",&op);
		if(op == 0){
			//更新的时候要分4种情况选择更新的动作
			int v,x,dis;
			scanf("%d %d %d",&v,&x,&dis);
			if(v==1){
				update_c1(dis+1,x);
				//for(int i=1;i<=n+1;i++)
				//	printf("%d\n",c1[i]);
			}
			else if(dis >= from[v] && dis < 2 * from[v]){
				update_c1(dis-from[v]+1,x);
				int l = chg[v]+dis-2*from[v]+1;
				int r = chg[v]+min(to[v],dis);
				if(l > r)
					continue;
				update_c2(r,x);
				update_c2(l-1,-x);
			}
			else if(dis < from[v]){
				int l = chg[v] - dis;
				int r = chg[v] + min(to[v],dis);
				if(l > r)
					continue;
				update_c2(r,x);
				update_c2(l-1,-x);
				
			}
			else{
				update_c1(dis-from[v]+1,x);
				int l = min(to[v],dis - 2 * from[v]) + chg[v] + 1;
				int r = min(to[v],dis) + chg[v];
				if(l > r)
					continue;
				update_c2(r,x);
				update_c2(l-1,-x);
				//printf("bbbbbbbbbb");
			}
		}
		else{
			//查询的时候答案是2个部分的和
			int v;
			scanf("%d",&v);
			int ans = query_c2(chg[v]) + query_c1(n+1) - query_c1(from[v]);
			printf("%d\n",ans);
		}
	}
}

int main()
{
	int q;
	scanf("%d %d",&n,&q);
	init();
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
	}
	solve(q);

	return 0;
}

