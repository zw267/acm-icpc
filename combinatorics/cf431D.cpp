                                            
  //File Name: cf431D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月09日 星期六 21时34分35秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

int a[100],tot;
LL f[100][100];

void init(){
	memset(f,0,sizeof f);
	for(int i=0;i<100;i++){
		f[i][0] = 1;
		for(int j=1;j<=i;j++)
			f[i][j] = f[i-1][j] + f[i-1][j-1];
	}
}

LL go(LL x,int k){
	tot = 0;
	while(x){
		a[++tot] = x % 2;
		x >>= 1;
	}
	LL ans = 0;
	int pre = 0;
	for(int i=tot;i>0;i--){
		if(a[i] == 1)
			pre++;
		else{
			if(k - pre - 1 >= 0)
				ans += f[i-1][k-pre-1];
			else 
				break;
		}
	}
	if(pre == k)
		ans++;
	return ans;
}

LL get(LL x,int k){
	LL ans = go(x,k);
	LL y = (1LL << tot);
	//printf("x = %lld y = %lld\n",x,y);
	ans = ans + go(y,k) - go(2 * x + 1,k);
	return ans;
}

LL solve(LL m,int k){
	LL l = m,r = (LL)1e18 + 1,mid;
	while(r - l > 1){
		mid = (l + r) >> 1;
		LL cur = get(mid,k);
		//printf("mid = %lld  cur = %lld\n",mid,cur);
		if(cur <= m)
			l = mid;
		else
			r = mid;
	}
	if(get(l,k) == m)
		return l;
	else 
		return r;
}

int main(){
	init();
	LL m;
	int k;
	cin >> m >> k;
	cout << solve(m,k) << endl;
	return 0;
}
