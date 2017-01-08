                                            
  //File Name: cf484D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月23日 星期三 01时21分29秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 1000000+5;

int up[MAXN];
int down[MAXN];
LL a[MAXN];
LL f[MAXN];

void solve(int n){
	for(int i=0;i<=n;i++){
		up[i] = i;
		down[i] = i;
	}
	for(int i=2;i<=n;i++){
		if(a[i-1] >= a[i]){
			up[i] = up[i-1];
		}
		if(a[i-1] <= a[i]){
			down[i] = down[i-1];
		}
	}

	f[0] = f[1] = 0;
	for(int i=2;i<=n;i++){
		f[i] = max(f[up[i]-1] + a[up[i]] - a[i],f[down[i]-1] + a[i] - a[down[i]]);
		if(up[i] < i)
			f[i] = max(f[i],f[up[i]] + a[up[i] + 1] - a[i]);
		if(down[i] < i)
			f[i] = max(f[i],f[down[i]] + a[i] - a[down[i] + 1]);
	}

	cout << f[n] << endl;
	return ;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
	}
	solve(n);
	return 0;
}
