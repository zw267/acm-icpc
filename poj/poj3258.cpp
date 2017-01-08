                                            
  //File Name: poj3258.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月25日 星期五 16时59分10秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;

const int MAXN = 50000+5;

int d[MAXN];

bool ok(int len,int n,int m,int x){
	int cur = 0, sum = 0;
	int pos = 1;
	while(true){
		while(pos < n && d[pos] - cur < x){
			pos++;
			sum++;
		}
		if(pos == n)
			break;
		if(d[pos] + x > len){
			sum += n - pos;
			break;
		}
		cur = d[pos];
		pos++;
	}
	if(sum <= m)
		return true;
	return false;
}

void solve(int len,int n,int M){
	if(n == 1){
		printf("%d\n",len);
		return ;
	}
	sort(d,d+n+1);
	int l = 1,r = len,mid;
	while(r - l > 1){
		mid = (l + r) >> 1;
		if(ok(len,n,M,mid))
			l = mid;
		else
			r = mid;
	}
	printf("%d\n",l);
	return ;
}

int main(){
	int L,n,m;
	while(~scanf("%d %d %d",&L,&n,&m)){
		for(int i=1;i<=n;i++){
			scanf("%d",&d[i]);
		}
		d[0] = 0;
		d[++n] = L;
		solve(L,n,m);
	}
	return 0;
}
