                                            
  //File Name: cf380D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年05月20日 星期五 00时32分29秒

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <map>

#define LL long long
#define next NEXT

using namespace std;

const int MAXN = 100000 + 3;
const int MOD = (int)1e9 + 7;

int is[MAXN], pre[MAXN], next[MAXN];
LL f[MAXN],jie[MAXN];

void init(int n){
	jie[0] = 1;
	for(int i=1;i<=n;i++)
		jie[i] = jie[i-1] * i % MOD;
	int now = -1;
	for(int i=1;i<=n;i++){
		pre[i] = now;
		if(is[i]) now = i;
	}
	now = -1;
	for(int i=n;i>0;i--){
		next[i] = now;
		if(is[i]) now = i;
	}
}

LL qp(LL x,LL y){
	LL res = 1;
	while(y){
		if(y & 1) res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

LL get_c(LL x,LL y){
	if(y < 0 || x < y)	 return 0;
	if(y == 0 || y == x) return 1;
	return jie[x] * qp(jie[y] * jie[x - y] % MOD,MOD - 2) % MOD;	
}

LL solve(int n,bool flag){
	if(!flag) return qp(2,n - 1);
	init(n);
	//for(int i=1;i<=n;i++){
	//	printf("i = %d is = %d\n",i,is[i]);
	//}
	int L = n + 1, R = 0;
	for(int i=1;i<=n;i++){
		if(!is[i])	 continue;
		if(L <= is[i] && R >= is[i]) 
			return 0;
		if(pre[i] == -1 && next[i] == -1){
			LL ans = 0,now;
			for(int x=0;x < is[i];x++){
				now = get_c(i-1,x) * get_c(n-i,is[i]-x-1) % MOD;
				if(x > 1) ans = (ans + now * 2 % MOD) % MOD;
				else ans = (ans + now) % MOD;
			}
			return ans;
		}
		else if(pre[i] > 0){
			f[i] = f[pre[i]];
			//printf("i = %d pre = %d next = %d f = %d\n",i,pre[i],next[i],f[i]);
			if(is[i] > is[pre[i]]) R++;
			else L--;
			//printf("L = %d R = %d\n",L,R);
			if(next[i] == -1){
				return f[i] * get_c(n-i,L-1) % MOD;
			}
			else{
				if(is[next[i]] > R){
					//printf("i = %d f = %d\n",i,f[i]);
					f[i] = f[i] * get_c(next[i]-i-1,is[next[i]]-R-1) % MOD;
					R = is[next[i]] - 1;
					L = R + 2 - next[i];
					//printf("i = %d f = %d\n",i,f[i]);
				}
				else{
					//printf("i = %d f = %d\n",i,f[i]);
					f[i] = f[i] * get_c(next[i]-i-1,L-is[next[i]]-1) % MOD;
					L = is[next[i]] + 1;
					R = L + next[i] - 2;
					//printf("i = %d f = %d\n",i,f[i]);
				}
			}
			//printf("L = %d R = %d\n",L,R);
		}
		else{
			if(is[i] < is[next[i]]){
				R = is[next[i]] - 1;
				L = R + 2 - next[i];
			}
			else{
				L = is[next[i]] + 1;
				R = L + next[i] - 2;
			}
			int cnt = abs(is[next[i]] - is[i]);
			f[i] = 0;
			if(i == 1){
				f[i] = get_c(next[i]-2,R-is[i]);
			}
			else{
				//printf("is = %d L = %d R = %d\n",is[i],L,R);
				if(i-1 <= is[i]-L)
					f[i] = qp(2,i-2) * get_c(next[i]-i-1,is[i]-L-i+1) % MOD;
				//printf("f = %d\n",f[i]);
				if(i-1 <= R-is[i])
					(f[i] += qp(2,i-2) * get_c(next[i]-i-1,R-is[i]-i+1)% MOD) %= MOD;
				//printf("f = %d\n",f[i]);
			}
			//printf("i = %d pre = %d next = %d f = %d\n",i,pre[i],next[i],f[i]);
			//printf("L = %d R = %d\n",L,R);
		}
	}
	return -1;
}

int main(){
	int n,u;
	bool flag = false;
	scanf("%d",&n);
	memset(is,0,sizeof is);
	for(int i=1;i<=n;i++){
		scanf("%d",&u);
		if(u){
			is[u] = i;
			flag = true;
		}
	}
	printf("%d\n",(int)solve(n,flag));
	return 0;
}

