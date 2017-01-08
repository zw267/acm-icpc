#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <set>

#define mp make_pair
#define fir first
#define sec second

using namespace std;

const int MAXN = 100000+10;

struct  Node
{
	int r,l,id,num;
};
Node part[MAXN];
Node peo[MAXN];
int ans[MAXN];

multiset< pair<pair<int,int>,pair<int,int> > >ms;
multiset< pair<pair<int,int>,pair<int,int> > > ::iterator it;
pair< pair<int,int>,pair<int,int> > tmp;

bool cmp(Node x,Node y)
{
	if(x.l == y.l)
		return x.r < y.r;
	return x.l < y.l;
}

void solve(int n,int m)
{
	ms.clear();
	sort(part+1,part+n+1,cmp);
	sort(peo+1,peo+m+1,cmp);
	
	int pos = 1;
	bool flag = true;

	for(int i=1;i<=n;i++){
		while(pos <= m && peo[pos].l <= part[i].l){
			ms.insert(mp( mp(peo[pos].r,peo[pos].l),mp(peo[pos].id,peo[pos].num)));
			pos++;
		}
		if(ms.empty()){
			flag = false;
			break;
		}
		it = ms.lower_bound(mp(mp(part[i].r,1),mp(1,1)));
		if(it == ms.end()){
			flag = false;
			break;
		}
		tmp = *it;
		ans[part[i].id] = tmp.sec.fir;
		ms.erase(it);
		tmp.sec.sec--;
		if(tmp.sec.sec > 0)
			ms.insert(tmp);	
	}

	if(!flag)
		puts("NO");
	else{
		puts("YES");
		for(int i=1;i<n;i++)
			printf("%d ",ans[i]);
		printf("%d\n",ans[n]);
	}
	return ;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&part[i].l,&part[i].r);
		part[i].id = i;
	}
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&peo[i].l,&peo[i].r,&peo[i].num);
		peo[i].id = i;
	}
	solve(n,m);
	
	return 0;
}
