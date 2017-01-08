#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#define fir first
#define sec second

using namespace std;

const int MAXN = 100000 + 10;

struct Edge
{
	int is,w,id;
};
Edge edge[MAXN];
int deg[MAXN];
pair<int,int>res[MAXN];

bool cmp(Edge x,Edge y)
{
	if(x.w == y.w)
		return x.is > y.is;
	return x.w < y.w;
}

inline int lb(int x)
{
	return x&(-x);
}

void update(int x,int add,int n)
{
	while(x <= n){
		deg[x] += add;
		x += lb(x);
	}
}

int query(int x)
{
	int ret = 0;
	while(x > 0){
		ret += deg[x];
		x -= lb(x);
	}
	return ret;
}

pair<int,int> find_edge(int num,int n)
{
	int l=1,r=num;
	while(r-l > 1){
		int mid=(l+r)>>1;
		if(query(mid) <= 0)
			l = mid;
		else
			r = mid;
	}
	int tmp;
	if(query(r) == 0)
		tmp = r;
	else
		tmp = l;
	tmp++;
	int tmp_deg = query(tmp);
	pair<int,int> ret = make_pair(tmp-tmp_deg,tmp);
	update(tmp,-1,n);
	return ret;
}

void solve(int n,int m)
{
	memset(deg,0,sizeof deg);
	int num = 1;
	int sum = 0;
	bool flag = true;
	sort(edge+1,edge+m+1,cmp);
	
	for(int i=1;i<=m;i++){
		if(edge[i].is){
			num++;
			update(num,num-2,n);
			//for(int j=1;j<=n;j++){
			//	printf("deg[%d] = %d\n",j,query(j) - query(j-1));
			//}
			sum += num - 2;
			res[edge[i].id] = make_pair(1,num);
		}
		else{
			if(sum <= 0){
				flag = false;
				break;
			}
			else{
				sum--;
				res[edge[i].id] = find_edge(num,n);
			}
		}
	}
	if(!flag)
		puts("-1");
	else{
		for(int i=1;i<=m;i++){
			printf("%d %d\n",res[i].fir,res[i].sec);
		}
	}
	return ;
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&edge[i].w,&edge[i].is);
		edge[i].id = i;
	}

	solve(n,m);

	return 0;
}
