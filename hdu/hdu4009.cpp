                                            
  //File Name: hdu4009.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月23日 星期六 13时59分38秒

/*

build a graph and solved by the min directed spanning tree   

*/   
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>

#define LL long long

using namespace std;

const int MAXN = 1005;
const int MAXM = 1e6+5000;
const LL INF = 0x3f3f3f3f3f3f3f;

struct Node
{
	LL a,b,c;
};
Node node[MAXN];

struct Edge
{
	int u,v;
	LL cost;
};
Edge edge[MAXM];

int pre[MAXN],id[MAXN],visit[MAXN];
LL in[MAXN];

LL zhuliu(int root,int n,int m)
{
	LL res = 0;
	int v;
	while(1){
		for(int i=0;i<n;i++){
			in[i] = INF;
		}
		for(int i=0;i<m;i++){
			if(edge[i].u != edge[i].v && edge[i].cost < in[edge[i].v]){
				pre[edge[i].v] = edge[i].u;
				in[edge[i].v] = edge[i].cost;
			}
		}

		for(int i=0;i<n;i++){
			if(i != root && in[i] == INF)
				return -1;
		}

		int tn = 0;
		memset(id,-1,sizeof id);
		memset(visit,-1,sizeof visit);

		in[root] = 0;
		for(int i=0;i<n;i++){
			res += in[i];
			v = i;
			while(visit[v] != i && id[v] == -1 && v != root){
				visit[v] = i;
				v = pre[v];
			}

			if(v != root && id[v] == -1){
				for(int u=pre[v];u != v;u = pre[u]){
					id[u] = tn;
				}
				id[v] = tn++;
			}
		}

		if(tn == 0)
			break;

		for(int i=0;i<n;i++){
			if(id[i] == -1)
				id[i] = tn++;
		}

		for(int i=0;i<m;){
			v = edge[i].v;
			edge[i].u = id[edge[i].u];
			edge[i].v = id[edge[i].v];

			if(edge[i].u != edge[i].v){
				edge[i++].cost -= in[v];
			}
			else{
				swap(edge[i],edge[--m]);
			}
		}

		n = tn;
		root = id[root];
	}

	return res;
}

LL g[MAXN][MAXN];

int main()
{
	int n;
	int x,y,z;
	while(~scanf("%d %d %d %d",&n,&x,&y,&z)){
		if(!n && !x && !y && !z)
			break;
		n++;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				g[i][j] = INF;
		}

		for(int i=1;i<n;i++){
			scanf("%d %d %d",&node[i].a,&node[i].b,&node[i].c);
		}
		//puts("eeeeeeee");

		for(int i=1;i<n;i++)
			g[0][i] = node[i].c * x;

		for(int i=1;i<n;i++){
			int num;
			scanf("%d",&num);
			while(num--){
				int tmp;
				scanf("%d",&tmp);
				if(tmp == i)
					continue;
				g[i][tmp] = (LL)(abs(node[tmp].c - node[i].c) +  abs(node[tmp].a - node[i].a) + abs(node[tmp].b - node[i].b)) * y;
				if(node[tmp].c > node[i].c)
					g[i][tmp] += z;
			}
		}
		int len = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(g[i][j] < INF){
					edge[len].u = i;
					edge[len].v = j;
					edge[len++].cost = g[i][j];
				}
			}
		}
		//puts("eeeeeeee");
		LL ans = zhuliu(0,n,len);
		//puts("eeeeeeeee");
		if(ans == -1)
			puts("poor XiaoA");
		else
			cout << ans << endl;
	}

	return 0;
}
