                                            
  //File Name: nod1165.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月13日 星期三 17时49分35秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <math.h>

#define LL long long

using namespace std;

const int MAXN = 10000000 + 2;
const int N = 10000 + 2;

bool check[N];
int prime[N],tot;
int L,R;
int num[N],val[N],len;
set<int> st;

void init_prime(){
	memset(check,false,sizeof check);
	tot = 0;
	for(int i=2;i<N;i++){
		if(!check[i]){
			prime[tot++] = i;
		}
		for(int j=0;j<tot;j++){
			if(i * prime[j] >= N)
				break;
			check[i * prime[j]] = true;
			if(i % prime[j] == 0)
				break;
		}
	}
}

void get(int n){
	len = 0;
	int ma = sqrt(n + 0.5);
	for(int i=0;i<tot && prime[i] <= ma;i++){
		if(n % prime[i] == 0){
			len++;
			val[len] = prime[i];
			num[len] = 0;
			while(n % prime[i] == 0){
				num[len]++;
				n /= prime[i];
			}
			num[len] *= 2;
		}
	}
	if(n > 1){
		len++;
		val[len] = n;
		num[len] = 2;
	}
}

void dfs(int iter,LL v){
	if(L < v && R > v && !(v&1))
		st.insert(v);
	if(iter > len || v >= R)
		return ;
	LL cnt = 1;
	for(int i=0;i<=num[iter];i++){
		dfs(iter+1,v * cnt);
		cnt *= val[iter];
		if(v * cnt >= R) break;
	}
}

int solve(int n){
	if(n & 1) return 0;
	L = n * sqrt(2.0);
	R = n * 2;
	get(n);
	st.clear();
	dfs(1,1);	
	//set<int>::iterator it;
	//for(it=st.begin();it!=st.end();it++)
	//	printf("%d  ",*it);
	return (int)st.size();
}

int main(){
	init_prime();
	int test;
	scanf("%d",&test);
	while(test--){
		int n;
		scanf("%d",&n);
		printf("%d\n",solve(n));
	}
	return 0;
}
