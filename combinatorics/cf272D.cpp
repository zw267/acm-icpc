                                            
  //File Name: cf272D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月08日 星期五 18时13分58秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>

#define LL long long 
#define pii pair<int,int> 
#define fir first
#define sec second
#define mp make_pair

using namespace std;

const int MAXN = 200000 + 2;

int MOD;
pii a[MAXN];

LL get(int x,int k){
	LL ans = 1;
	for(int i=1;i<=x;i++){
		int t = i;
		while(k && !(t & 1))
			t >>= 1 , k--;
		ans = ans * t % MOD;
	}
	return ans;
}

LL solve(int n){
	sort(a+1,a+n+1);
	LL ans = 1;
	pii pre = mp(a[1].fir,a[1].sec);
	int num = 1,k = 0;
	for(int i=2;i<=n;i++){
		if(a[i].fir != pre.fir){
			ans = ans * get(num,k) % MOD;
			pre = a[i];
			num = 1;
			k = 0;
		}
		else{
			if(a[i].sec == pre.sec)
				k++;
			pre = a[i];
			num++;
		}
	}
	ans = ans * get(num,k) % MOD;
	return ans;
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		n *= 2;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i].fir);
			a[i].sec = i;
			if(i > n / 2)
				a[i].sec -= n / 2;
		}
		scanf("%d",&MOD);
		printf("%d\n",(int)solve(n));
	}
	return 0;
}
