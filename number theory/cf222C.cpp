                                            
  //File Name: cf222C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年12月18日 星期日 16时15分33秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 100000 + 3;
const int N = 10000000 + 3;
int prime[664580],fir[N],num[664580],tot;
int a[MAXN],b[MAXN];
set<int> rem[664580];
void init(){
	memset(fir,-1,sizeof(fir));
	tot = 0;
	for(int i=2;i<N;++i){
		if(fir[i] == -1){
			prime[tot++] = i;
			fir[i] = tot - 1;
		}
		for(int j=0;j<tot;++j){
			if((LL)i * prime[j] >= N) break;
			fir[i * prime[j]] = j;
			if(i % prime[j] == 0) break;
		}
	}	
//	printf("tot = %d\n",tot);
}
void cal(int &u,int f){
	if(f != -1){
		int x = u;
		while(x > 1){
			int i = fir[x];
			rem[i].insert(f);
			int p = prime[i];
			while(x % p == 0){
				++num[i];
				x /= p;
			}	
		}
	}
	else{
		int x = 1;
		while(u > 1){
			int i = fir[u];
			int p = prime[i];
			u /= p;
			if(num[i] > 0){
				int id = *rem[i].begin();
				--num[i];
				a[id] /= p;
				if(a[id] % p)
					rem[i].erase(rem[i].begin());
			}
			else
				x *= p;
		}
		u = x;
	}
}
void solve(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%d",a + i);
		cal(a[i],i);
	}
	for(int i=0;i<m;++i){
		scanf("%d",b + i);
		cal(b[i],-1);
	}
	printf("%d %d\n",n,m);
	for(int i=0;i<n;++i)
		printf("%d%c",a[i], i == n - 1 ? '\n' : ' ');
	for(int i=0;i<m;++i)
		printf("%d%c",b[i], i == m - 1 ? '\n' : ' ');
}
int main(){
	init();
	solve();
	return 0;
}
