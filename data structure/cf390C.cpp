                                            
  //File Name: cf390C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月21日 星期四 19时46分44秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <stdlib.h>

using namespace std;

const int MAXN = 100000 + 3;

int a[MAXN];
int pre[MAXN];
int f[MAXN + 20];
char ch[MAXN];

void solve(int n,int k,int q){
	pre[0] = 0;
	for(int i=1;i<=n;i++){
		pre[i] = pre[i - 1] + a[i];
	}
	for(int i=n;i>0;i--){
		if(i + k > n)
			f[i] = a[i];
		else
			f[i] = f[i + k] + a[i];
	}
	for(int i=1,x,y,z,l,r;i<=q;i++){
		scanf("%d %d",&l,&r);
		z = (r - l + 1) / k;
		x = pre[r] - pre[l - 1];
		l = l + k - 1;
		y = f[l] - f[r + k];
		//printf("x = %d y = %d z = %d\n",x,y,z);
		printf("%d\n",z + x - 2 * y);
	}
	return ;
}

int main(){
	int n,k,q;
	scanf("%d %d %d",&n,&k,&q);
	scanf("%s",ch + 1);
	for(int i=1;i<=n;i++){
		a[i] = ch[i] - '0';
	}
	solve(n,k,q);
	return 0;
}
