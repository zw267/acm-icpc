                                            
  //File Name: cf501E.cpp
  //Created Time: 2017年05月05日 星期五 17时59分35秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 100000 + 2;
int a[MAXN];
int tmp[MAXN];
vector<int> pos[MAXN];
int l1,l2,mid,mid_val;
int cal(const int n){
	for(int i(1);i<=n;++i)
		pos[i].clear();
	int res(l2),ma(n + 1 - l1);
	for(int i(l1);i<=ma;++i){
//		if((mid_val == -1 || mid_val == a[mid])&& l2 < i && i < n + 1 - l2) 
//			continue;
		pos[a[i]].push_back(i);
	}
	for(int i=1;i<=n;++i){
		if(!pos[i].size()) continue;
		int now = (pos[i].size() - 1) / 2;
		bool flag(false);
		if(i == mid_val && pos[i][now] == mid){
			--now;
			flag = true;
		}
		int next = now + 1;
		if(flag) ++next;
		while(now >= 0 && pos[i][now] > res){
			if(next >= pos[i].size()) puts("fuck");
			if(pos[i][now] + pos[i][next] == n + 1){
				--now;
				++next;
			}
			else
				break;
		}
		res = max(res,pos[i][now]);
	}
	return res;
}
LL solve(const int n){
	mid_val = -1;
	int cur(0);
	for(int i(1);i<=n;++i){
		if(tmp[i] & 1){
			++cur;
			mid_val = i;
		}
	}
	if((n % 2 == 0 && cur) || (n % 2 && cur > 1)) return 0;
	mid = n / 2;
	if(n & 1) ++mid;
	l1 = 1;
	while(l1 <= mid && a[l1] == a[n + 1 - l1])
		++l1;
	if(l1 > mid) return (LL)(n + 1) * n / 2;
	l2 = mid;
	if(n & 1) --l2;
	while(l2 >= 1 && a[l2] == a[n + 1 - l2])
		--l2;
//	printf("l1 = %d l2 = %d\n",l1,l2);
	LL res = -(LL)l1 * l1;
	cur = cal(n);
//	printf("cur = %d\n",cur);
	res += (LL)l1 * (n + 1 - cur);
	for(int i(l1);i<=mid;++i)
		swap(a[i],a[n + 1 - i]);
	cur = cal(n);
//	printf("cur = %d\n",cur);
	res += (LL)l1 * (n + 1 - cur);
	return res;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i(1);i<=n;++i){
		scanf("%d",a + i);
		++tmp[a[i]];
	}
	printf("%lld\n",solve(n));
//	cout << solve(n) << endl;
	return 0;
}
