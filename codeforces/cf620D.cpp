                                            
  //File Name: cf620D.cpp
  //Created Time: 2017年04月27日 星期四 00时17分49秒
                                   
#include <bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;
const int MAXN = 2002;
LL a[MAXN],b[MAXN];
LL tmp[MAXN];
pii ans[3];
map<LL,pii> rem;
LL sa,sb;
void update(int ai,int aj,int bi,int bj,LL &res,int &flag){
	LL cur_sa = sa - a[ai] - a[aj] + b[bi] + b[bj];
	LL cur_sb = sb - b[bi] - b[bj] + a[ai] + a[aj];
	if(abs(cur_sa - cur_sb) < res){
		res = abs(cur_sa - cur_sb);
		flag = 2;
		ans[1] = pii(ai,bi);
		ans[2] = pii(aj,bj);
	}
}
void solve(int n,int m){
	sa = sb = 0;
	for(int i=0;i<n;++i)
		sa += a[i];
	for(int i=0;i<m;++i)
		sb += b[i];
	LL res = abs(sa - sb);
	int flag = 0;
	for(int i=0;i<3;++i) 
		ans[i] = pii(-1,-1);
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			LL cur_sa = sa - a[i] + b[j];
			LL cur_sb = sb - b[j] + a[i];
			if(abs(cur_sa - cur_sb) < res){
				ans[0] = pii(i,j);
				res = abs(cur_sa - cur_sb);
				flag = 1;
			}
		}
	}
	for(int i=0;i<n;++i){
		for(int j=i+1;j<n;++j){
			LL tmp = sb + 2 * a[i] + 2 * a[j];
			rem[tmp] = pii(i,j);
		}
	}
	for(int i=0;i<m;++i){
		for(int j=i+1;j<m;++j){
			LL tmp = sa + 2 * b[i] + 2 * b[j];
			auto it = rem.lower_bound(tmp);
			if(it != rem.end())
				update((it->sec).fir,(it->sec).sec,i,j,res,flag);
			if(it != rem.begin()){
				--it;
				update((it->sec).fir,(it->sec).sec,i,j,res,flag);
			}
		}
	}
	printf("%lld\n",res);
	if(flag == 0){
		puts("0");
	}
	else if(flag == 1){
		puts("1");
		printf("%d %d\n",ans[0].fir + 1,ans[0].sec + 1);
	}
	else{
		puts("2");
		for(int i=1;i<3;++i)
			printf("%d %d\n",ans[i].fir + 1,ans[i].sec + 1);
	}
}
int main(){
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%lld",a + i);
	scanf("%d",&m);
	for(int j=0;j<m;++j)
		scanf("%lld",b + j);
	solve(n,m);
	return 0;
}
