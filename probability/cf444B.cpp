                                            
  //File Name: cf444B.cpp
  //Created Time: 2017年03月01日 星期三 17时19分59秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 100000 + 5;
int a[MAXN],b[MAXN],rev[MAXN];
int pos[MAXN],tot;
LL x;
LL get_next_x(){
	x = (x * 37 + 10007) % 1000000007;
	return x;
}
void init(int n,int d){
	for(int i=0;i<n;++i)
		a[i] = i + 1;
	for(int i=0;i<n;++i)
		swap(a[i],a[get_next_x() % (i + 1)]);
	for(int i=0;i<n;++i){
		if(i < d) b[i] = 1;
		else b[i] = 0;
	}
	for(int i=0;i<n;++i)
		swap(b[i],b[get_next_x() % (i + 1)]);
	tot = 0;
	for(int i=0;i<n;++i){
		rev[a[i]] = i;
		if(b[i]) pos[tot++] = i;
	}
}
void solve(int n,int d){
	init(n,d);
	int s = min(50,n);
	for(int i=0;i<n;++i){
		int now;
		for(now=n;now>n-s;--now){
			if(rev[now] <= i && b[i - rev[now]]){
				printf("%d\n",now);
				break;
			}
		}
		if(now <= n - s){
			int ma = 0;
			for(int j=0;j<tot && pos[j] <= i;++j){
				ma = max(ma,a[i - pos[j]]);
			}
			printf("%d\n",ma);
		}
	}
}
int main(){
	int n,d;
	scanf("%d %d %lld",&n,&d,&x);
	solve(n,d);
	return 0;
}
