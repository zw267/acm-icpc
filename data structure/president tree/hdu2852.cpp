                                            
  //File Name: hdu2852.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月03日 星期日 23时49分20秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 100000;

int bit[MAXN + 10];

inline int lb(int x){
	return x & (-x);
}

void update(int pos,int add){
	while(pos <= MAXN){
		bit[pos] += add;
		pos += lb(pos);
	}
}

int query(int pos){
	int res = 0;
	while(pos > 0){
		res += bit[pos];
		pos -= lb(pos);
	}
	return res;
}

void solve(int n){
	memset(bit,0,sizeof bit);
	for(int i=1,op,a,k;i<=n;i++){
		scanf("%d",&op);
		if(op == 0){
			scanf("%d",&a);
			update(a,1);
		}
		else if(op == 1){
			scanf("%d",&a);
			int cur = query(a) - query(a - 1);
			if(cur == 0)
				puts("No Elment!");
			else
				update(a,-1);
		}
		else{
			scanf("%d %d",&a,&k);
			int base = query(a);
			if(query(MAXN) - base < k){
				puts("Not Find!");
				continue;
			}
			int l = a ,r = MAXN, mid,ans;
			while(r - l > 1){
				mid = (l + r) >> 1;
				if(query(mid) - base < k)
					l = mid;
				else
					r = mid;
			}
			printf("%d\n",r);
		}
	}
	return ;
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		solve(n);
	}
	return 0;
}
