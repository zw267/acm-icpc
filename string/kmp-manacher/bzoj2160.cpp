                                            
  //File Name: bzoj2160.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月23日 星期六 20时13分09秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#define LL long long

using namespace std;

const int MAXN = 1000000 + 3;
const int MOD = 19930726;

LL sum[MAXN];
char str[MAXN];
char ma[MAXN << 1];
int mp[MAXN << 1];

int manacher(const char *s){
	int len = strlen(s),l = 0;
	ma[l++] = '$';
	ma[l++] = '#';
	for(int i=0;i<len;i++){
		ma[l++] = s[i];
		ma[l++] = '#';
	}
	ma[l] = 0;
	int mx = 0,id = 0;
	for(int i=0;i<l;i++){
		mp[i] = mx > i ? min(mx - i,mp[2 * id - i]) : 1;
		while(ma[i + mp[i]] == ma[i - mp[i]])
			mp[i]++;
		if(i + mp[i] > mx){
			mx = i + mp[i];
			id = i;
		}
	}
	for(int i=0;i<l;i++)
		mp[i]--;
	return l;
}

LL qp(LL x,LL y){
	LL res = 1;
	while(y){
		if(y & 1)
			res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

void solve(int n,LL K){
	int tot = manacher(str);
	int len = strlen(str);
	memset(sum,0,sizeof sum);
	for(int i=2;i<tot;i+=2){
		sum[1]++;
		sum[mp[i] + 1]--;
	}
	LL now = 0;
	for(int i=1;i<=len;i++){
		sum[i] += sum[i - 1];
		if(i % 2)
			now += sum[i];
	}
	if(now < K){
		puts("-1");
		return ;
	}
	LL ans = 1;
	for(int i=len;i>0 && K > 0;i--){
		if(i % 2 == 0)
			continue;
		now = min(K,sum[i]);
		ans = ans * qp(i,now) % MOD;
		K -= now;
	}
	printf("%lld\n",ans);
	return ;
}

int main(){
	int n;
	LL K;
	scanf("%d %lld",&n,&K);
	scanf("%s",str);
	solve(n,K);
	return 0;
}
