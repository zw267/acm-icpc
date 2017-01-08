                                            
  //File Name: cf121C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月28日 星期日 23时47分47秒
                                   

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

#define LL long long

using namespace std;

int f[12][2];
int a[12];
int is[15];
int ans[15];
LL jie[15];

void init_jie()
{
	jie[0] = 1;
	for(int i=1;i<14;i++)
		jie[i] = jie[i-1] * i;
}

int bs(int k)
{
	int l = 1;
	int r = 13;
	int mid;
	while(r - l > 1){
		mid = (l + r) >> 1;
		if(jie[mid] <= k)
			l = mid;
		else
			r = mid;
	}
	if(jie[l] < k)
		return r;
	return l;
}

int dfs(int pos,int all,bool limit)
{
	if(!limit && f[pos][all] != -1)
		return f[pos][all];
	if(pos == 0){
		return all?0:1;
	}
	int res = 0;
	int ma = limit?a[pos]:9;
	for(int i=0;i<=ma;i++){
		if(i == 4 || i == 7){
			res += dfs(pos-1,0,limit && i == ma);
		}
		if(all && i == 0)
			res += dfs(pos-1,1,limit && i == ma);
	}
	return limit?res:f[pos][all] = res;
}

int get(int sum)
{
	int tot = 0;
	while(sum){
		a[++tot] = sum % 10;
		sum /= 10;
	}
	memset(f,-1,sizeof f);
	return dfs(tot,1,true);
}

int _find(int num,int cur)
{
	int cnt = 0;
	for(int i=1;i <= cur;i++){
		cnt += is[i];
		if(cnt == num){
			is[i] = 0;
			return i;
		}
	}
	return -1;
}

bool ok(int x)
{
	while(x){
		int cur = x % 10;
		if(cur !=4 && cur != 7)
			return false;
		x /= 10;
	}
	return true;
}

void solve(int n,int k)
{
	init_jie();
	if(n < 13 && jie[n] < (LL)k){
		puts("-1");
		return ;
	}
	int cur = bs(k);
	//cout << cur << endl;
	LL res = get(n - cur);
	//cout << res << endl;
	if(cur )
	for(int i=0;i<=cur;i++)
		is[i] = 1;
	
	for(int i=1;i<=cur;i++){
		int num = (k-1) / jie[cur-i] + 1;
		//cout << num << endl;
		ans[i] = _find(num,cur) + n - cur;
		//cout << i << " " << ans[i] << endl;
		k = k - (num-1) * jie[cur-i];
	}
	
	for(int i=1;i<=cur;i++){
		if(ok(n - cur + i) && ok(ans[i]))
			res++;
	}
	printf("%d\n",res);
	return ;
}

int main()
{
	int n,k;
	while(~scanf("%d %d",&n,&k)){
		solve(n,k);
	}
	return 0;
}
