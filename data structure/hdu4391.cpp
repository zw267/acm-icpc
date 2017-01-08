                                            
  //File Name: hdu4391.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月11日 星期一 16时35分28秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>

using namespace std;

const int MAXN = 100000 + 3;

map<int,int> m[335];
int c[MAXN];
int bel[MAXN];
int ly[335];
int s,n,num;

void pushdown(int x){
	if(ly[x] < 0)
		return ;
	int ma = min(x*s+s,n);
	m[x].clear();
	for(int i=x*s;i<ma;i++){
		c[i] = ly[x];
	}
	m[x][ly[x]] = ma - x * s;
	ly[x] = -1;
}

void update(int l,int r,int z){
	if(bel[l] == bel[r]){
		pushdown(bel[l]);
		m[bel[l]].clear();
		for(int i=bel[l]*s;i<l;i++){
			m[bel[l]][c[i]]++;
		}
		int ma = min(bel[l]*s+s,n);
		for(int i=r+1;i<ma;i++){
			m[bel[l]][c[i]]++;
		}
		for(int i=l;i<=r;i++)
			c[i] = z;
		m[bel[l]][z] += r - l + 1;
		return ;
	}
	update(l,bel[l]*s+s-1,z);
	update(bel[r]*s,r,z);
	for(int i=bel[l]+1;i<bel[r];i++){
		ly[i] = z;
		m[i].clear();
	}
}

int query(int l,int r,int z){
	int res = 0;
	if(bel[l] == bel[r]){
		if(ly[bel[l]] >= 0){
			if(ly[bel[l]] == z)
				res += r - l + 1;
		}
		else{
			for(int i=l;i<=r;i++){
				if(c[i] == z)
					res++;
			}	
		}
		return res;
	}
	res += query(l,bel[l]* s + s - 1,z);
	res += query(bel[r] * s,r,z);
	for(int i=bel[l]+1;i<bel[r];i++){
		if(ly[i] >= 0){
			if(ly[i] == z)
				res += s;
		}
		else{
			if(m[i].count(z))
				res += m[i][z];
		}
	}
	return res;
}

void solve(int q){
	memset(ly,-1,sizeof ly);
	s = (int)sqrt(n + 0.5);
	num = n / s;
	if(n % s)
		num++;
	for(int i=0;i<n;i++){
		bel[i] = i / s;
	}
	for(int i=0;i<num;i++)
		m[i].clear();
	for(int i=0;i<n;i++){
		m[bel[i]][c[i]]++;
	}
	for(int i=0,op,l,r,z;i<q;i++){
		scanf("%d %d %d %d",&op,&l,&r,&z);
		if(op == 1){
			update(l,r,z);
		}
		else{
			printf("%d\n",query(l,r,z));
		}
	}
	return ;
}

int main(){
	int q;
	while(~scanf("%d %d",&n,&q)){
		for(int i=0;i<n;i++){
			scanf("%d",&c[i]);
		}
		solve(q);
	}
	return 0;
}
