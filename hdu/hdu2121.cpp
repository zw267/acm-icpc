                                            
  //File Name: hdu2121.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月23日 星期六 22时56分45秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#define fir first
#define sec second
#define LL long long

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXV = 1010;
const int MAXE = 10010;

struct Edge
{
	int u,v,cost;
	int init_v;
};
Edge edge[MAXE];

int pre[MAXV],id[MAXV],visit[MAXV];
int in[MAXV];

pair<int,int> zhuliu(int root,int n,int m)
{
	pair<int,int> res;
	res.fir = 0;
	int v;
	while(1){
		for(int i=0;i<n;i++){
			in[i] = INF;
		}
		for(int i=0;i<m;i++){
			if(edge[i].u != edge[i].v && edge[i].cost < in[edge[i].v]){
				pre[edge[i].v] = edge[i].u;
				in[edge[i].v] = edge[i].cost;
				if(edge[i].u == root)
					res.sec = edge[i].init_v;
			}
		}

		for(int i=0;i<n;i++){
			if(i != root && in[i] == INF)
				return make_pair(-1,-1);
		}

		int tn = 0;
		memset(id,-1,sizeof id);
		memset(visit,-1,sizeof visit);

		in[root] = 0;
		for(int i=0;i<n;i++){
			res.fir += in[i];
			v = i;
			while(visit[v] != i && id[v] == -1 && v != root){
				visit[v] = i;
				v = pre[v];
			}

			if(v != root && id[v] == -1){
				for(int u = pre[v];u != v;u = pre[u]){
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

int main()
{
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		int sum = 0;
		int tot  = 0;
		for(int i=0;i<m;i++){
			int u,v,cost;
			scanf("%d %d %d",&u,&v,&cost);
			if(u == v)
				continue;
			edge[tot].u = u;
			edge[tot].v = v;
			edge[tot].cost = cost;
			edge[tot++].init_v = v;
			sum += cost;
		}

		for(int i=0;i<n;i++){
			edge[tot].u = n;
			edge[tot].v = i;
			edge[tot].cost = sum+1;
			edge[tot++].init_v = i;
		}
		n++;

		pair<int,int> res = zhuliu(n-1,n,tot);

		res.fir -= (sum+1);

		if(res.fir < 0 || res.fir > sum)
			printf("impossible\n\n");
		else
			printf("%d %d\n\n",res.fir,res.sec);
	}
	return 0;
}
