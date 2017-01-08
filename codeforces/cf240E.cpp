                                            
  //File Name: cf240E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月24日 星期日 15时11分22秒
                                   
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 100000+5;

struct Edge
{
	int u,v,cost;
	int init_u,init_v,init_id;
};
Edge edge[MAXN];

int pre[MAXN],id[MAXN],visit[MAXN],in[MAXN];
int in_edge[MAXN];

int zhuliu(int root,int n,int m)
{
	int res = 0;
	memset(in_edge,-1,sizeof in_edge);
	int v;

	while(true) {
		for(int i=1;i<=n;i++){
			in[i] = INF;
		}

		for(int i=1;i<=m;i++){
			if(edge[i].u != edge[i].v && edge[i].cost < in[edge[i].v]){
				pre[edge[i].v] = edge[i].u;
				in[edge[i].v] = edge[i].cost;

				if(edge[i].v == root)
					continue;
				if(edge[i].cost){
					in_edge[edge[i].init_v] = edge[i].init_id;
				}
				else{
					in_edge[edge[i].init_v] = -1;
				}
			}
		}

		for(int i=1;i<=n;i++){
			if(i != root && in[i] == INF){
				return -1;
			}
		}

		int tn = 1;
		memset(id,-1,sizeof id);
		memset(visit,-1,sizeof visit);

		in[root] = 0;
		for(int i=1;i<=n;i++){
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

		if(tn == 1)
			break;

		for(int i=1;i<=n;i++){
			if(id[i] == -1)
				id[i] = tn++;
		}

		for(int i=1;i<=m;){
			v = edge[i].v;
			edge[i].u = id[edge[i].u];
			edge[i].v = id[edge[i].v];
			if(edge[i].u != edge[i].v)
				edge[i++].cost -= in[v];
			else
				swap(edge[i],edge[m--]);
		}

		n = tn - 1;
		root = id[root];
	}
	return res;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int n,m;
	while(~scanf("%d %d",&n,&m)){
		for(int i=1;i<=m;i++){
			scanf("%d %d %d",&edge[i].u,&edge[i].v,&edge[i].cost);
			edge[i].init_id = i;
			edge[i].init_u = edge[i].u;
			edge[i].init_v = edge[i].v;
		}

		int res = zhuliu(1,n,m);

		if(res < 0)
			puts("-1");
		else if(res == 0)
			puts("0");
		else{
			printf("%d\n",res);
			sort(in_edge,in_edge+n+1);
			int l = 0;
			while(in_edge[l] == -1)
				l++;
			int first = 0;
			for(int i=l;i<=n;i++){
				if(first)
					printf(" ");
				first++;
				printf("%d",in_edge[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
