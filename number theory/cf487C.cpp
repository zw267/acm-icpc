                                            
  //File Name: cf487C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年12月18日 星期日 14时30分27秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 100000 + 10;
int ans[MAXN];
bool is_prime(int x){
	for(int i=2;i*i<=x;i++)
		if(x % i == 0) return false;
	return true;
}
LL qp(LL x,LL y,LL p){
	LL res = 1;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % p;
		x = x * x % p;
	}
	return res;
}
void solve(int n){
	if(n == 1) printf("YES\n1\n");
	else if(n == 4) printf("YES\n1\n3\n2\n4\n");
	else if(!is_prime(n)) puts("NO");
	else{
		printf("YES\n1\n");
		for(int i=2;i<n;i++)
			printf("%d\n",1LL * i * qp(i-1,n - 2,n) % n);
		printf("%d\n",n);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	solve(n);
	return 0;
}
