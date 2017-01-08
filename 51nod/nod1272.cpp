#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 50000+10;

struct Node
{
	int id;
	int val;
	bool operator<(const Node & a) const
	{
		return a.id>id;
	}
};

Node node[MAXN];

bool cmp(Node a,Node b)
{
	if(a.val == b.val)
		return a.id > b.id;
	return a.val>b.val;
}

int solve(int n)
{
	int ret = 0;
	sort(node+1,node+n+1,cmp);
	
	priority_queue<Node>que;
	while(!que.empty())
		que.pop();
	for(int i=1;i<=n;i++){
		que.push(node[i]);
		int tmp = que.top().id;
		//printf("%d",que.top().id);
		ret = max(ret, max(0,tmp-node[i].id));
	}
	//while(!que.empty()){
	//	printf("%d ",que.top().val);
	//	que.pop();
	//}
	return ret;
}

int main()
{
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++){
			scanf("%d",&node[i].val);
			node[i].id = i;
		}
		printf("%d\n",solve(n));
	}
	return 0;
}


