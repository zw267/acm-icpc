#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int MAXN = 50000+5;

int pos[MAXN];
int ans[MAXN];
int a[MAXN];
int use[MAXN];

inline int lb(int x)
{
	return x & ( -x);
}

void update(int x,int add,int n)
{
	while(x <= n){
		pos[x] += add;
		x += lb(x);
	}
}

int query(int x)
{
	int res = 0;
	while(x > 0){
		res += pos[x];
		x -= lb(x);
	}
	return res;
}

int get(int tmp,int n)
{
	int l = tmp + 1;
	int r = n;
	while(r - l > 1){
		int mid = (l + r) >> 1;
		if(query(mid)+tmp > mid-1)
			l = mid;
		else
			r = mid;
	}
	if(query(l)+tmp == l - 1)
		return l;
	return r;
}

void solve(int n)
{
	memset(pos,0,sizeof pos);
	memset(use,0,sizeof use);
	
	for(int i=n;i>1;i--){
		int tmp = i - a[i] + a[i-1] - 1;
		ans[i] = get(tmp,n);
		update(ans[i],1,n);
		use[ans[i]] = 1;
	}

	for(int i=1;i<=n;i++){
		if(!use[i]){
			ans[1] = i;
			break;
		}
	}

	for(int i=1;i<n;i++)
		printf("%d ",ans[i]);
	printf("%d\n",ans[n]);

	return ;
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--) {
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}

		solve(n);
	}
	return 0;
}
