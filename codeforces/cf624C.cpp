                                            
  //File Name: cf624C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月05日 星期五 22时12分28秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

#define fir first
#define sec second

using namespace std;

const int MAXN = 505;

vector<int> G[MAXN];
vector< pair<int,int> > edge;
char str[MAXN];
bool vis[MAXN];
int deg[MAXN];
int chg[MAXN];

void init(int n)
{
	for(int i=1;i<=n;i++){
		str[i] = 'd';
		G[i].clear();
	}
	edge.clear();
	memset(deg,0,sizeof deg);
}

void addedge(int u,int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
}

void dfs(int u,int k)
{
	vis[u] = true;
	chg[u] = k;
	for(int i=0;i<G[u].size();i++){
		int v = G[u][i];
		if(!vis[v])
			dfs(v,k);
	}
}

void solve(int n)
{
	for(int i=1;i<=n;i++){
		if(deg[i] == n - 1){
			str[i] = 'b';
		}
	}
	for(int i=0;i<edge.size();i++){
		int u = edge[i].fir;
		int v = edge[i].sec;
		if(str[u] == 'd' && str[v] == 'd'){
			addedge(u,v);
		}
	}
	int num = 0;
	memset(vis,false,sizeof vis);
	memset(chg,0,sizeof chg);
	for(int i=1;i<=n;i++){
		if(!vis[i] && str[i] == 'd'){
			dfs(i,++num);
		}
	}

	if(num > 2){
		puts("No");
		return ;
	}

	bool flag = true;
	int num_a = 0,num_c = 0;
	for(int i=1;i<=n;i++){
		if(chg[i] == 1)
			num_a++;
		else if(chg[i] == 2)
			num_c++;
	}

	for(int i=1;i<=n;i++){
		if(chg[i] == 1){
			if(G[i].size() != num_a - 1){
				flag = false;
				//cout << "eeeeeeeee"<<endl;
				break;
			}
			str[i] = 'a';
		}
		else if(chg[i] == 2){
			if(G[i].size() != num_c - 1){
				flag = false;
				//cout << "hehehe" << endl;
				break;
			}
			str[i] = 'c';
		}
	}
	if(!flag)
		puts("No");
	else{
		puts("Yes");
		printf("%s\n",str+1);
	}
	return ;
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	init(n);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		edge.push_back(make_pair(u,v));
		deg[u]++;
		deg[v]++;
	}

	solve(n);
	return 0;
}
