#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 200000+5;

int ans[MAXN];
struct Node
{
	int hei,l,r;
};
Node node[MAXN];

bool cmp(Node x,Node y)
{
	return x.hei < y.hei;
}

void solve()
{
	int n;
	scanf("%d",&n);
	n++;
	for(int i=1;i<n;i++){
		scanf("%d",&node[i].hei);
	}

	node[0].hei = 0;
	node[n].hei = 0;

	for(int i=1;i<n;i++){
		node[i].l = i - 1;
		while(i > 0 && node[node[i].l].hei >= node[i].hei){
			node[i].l = node[node[i].l].l;
		}
	}
	for(int i=n-1;i>0;i--){
		node[i].r = i + 1;
		while(i < n && node[node[i].r].hei >= node[i].hei){
			node[i].r = node[node[i].r].r;
		}
	}
	
	memset(ans,-1,sizeof ans);

	sort(node+1,node+n,cmp);

	for(int i=1;i<n;i++){
		int pos = node[i].r - node[i].l - 1;
		ans[pos] = max(ans[pos],node[i].hei);
	}

	for(int i=n-1;i>0;i--){
		ans[i] = max(ans[i],ans[i+1]);
	}

	for(int i=1;i<n-1;i++)
		printf("%d ",ans[i]);
	printf("%d\n",ans[n-1]);

	return ;
}

int main()
{
	solve();
	return 0;
}
