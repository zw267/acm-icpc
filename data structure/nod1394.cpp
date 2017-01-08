                                            
  //File Name: nod1394.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月15日 星期五 15时19分39秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <stdlib.h>

#define LL long long
#define fir first
#define sec second
#define hash _hash_
#define pii pair<int,int>

using namespace std;

const int MAXN = 100000 + 3;

int num[MAXN<<1],hash[MAXN<<1],tot,top;

void hash_init(){
	sort(num+1,num+top+1);
	tot = 0;
	hash[++tot] = num[1];
	for(int i=2;i<=top;i++){
		if(num[i] != num[i-1])
			hash[++tot] = num[i];
	}
}

int hash_find(int x){
	int l = 1, r = tot ,mid;
	while(l <= r){
		mid = (l + r) >> 1;
		if(hash[mid] < x)
			l = mid + 1;
		else
			 r= mid - 1;
	}
	return l;
}

LL bit1[MAXN << 1],bit2[MAXN << 1];
map<int,int> mp;
pii q[MAXN << 1];

void update(int x,int add,LL *bit){
	while(x <= tot){
		bit[x] += add;
		x += x & (-x);
	}
}

LL query(int x,LL *bit){
	LL res = 0;
	while(x){
		res += bit[x];
		x -= x & (-x);
	}
	return res;
}

void solve(int n){
	hash_init();
	mp.clear();
	memset(bit1,0,sizeof (bit1));
	memset(bit2,0,sizeof (bit2));
	int l = 0,r = 0,sum = 0;
	LL ans = 0;
	for(int i=1,u;i<=n;i++){
		if(q[i].fir == 1){
			u = hash_find(q[i].sec);
			sum++;
			mp[q[i].sec]++;
			update(u,1,bit1);
			update(u,q[i].sec,bit2);
			ans = ans + (2LL * query(u-1,bit1) - sum + (LL)mp[q[i].sec]) * q[i].sec;
			ans = ans - 2LL * query(u-1,bit2) + query(tot,bit2) - (LL)mp[q[i].sec] * q[i].sec;
		}
		else if(q[i].fir == 2){
			if(mp[q[i].sec] == 0){
				puts("-1");
				continue;
			}
			u = hash_find(q[i].sec);
			ans = ans - (2LL * query(u-1,bit1) - sum + (LL)mp[q[i].sec]) * q[i].sec;
			ans = ans + 2LL * query(u-1,bit2) - query(tot,bit2) + (LL)mp[q[i].sec] * q[i].sec;
			sum--;
			mp[q[i].sec]--;
			update(u,-1,bit1);
			update(u,-q[i].sec,bit2);
		}
		else{
			printf("%lld\n",ans);
		}
	}	
	
}

int main(){
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		top = 0;
		for(int i=1;i<=n;i++){
			q[i].fir = 1;
			scanf("%d",&q[i].sec);
			num[++top] = q[i].sec;
		}
		for(int i=n+1;i<=n+m;i++){
			scanf("%d",&q[i].fir);
			if(q[i].fir != 3){
				scanf("%d",&q[i].sec);
				num[++top] = q[i].sec;
			}
		}
		solve(n+m);
	}
	return 0;
}
