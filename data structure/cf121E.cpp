                                            
  //File Name: cf121E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年05月03日 星期二 00时30分49秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <map>

using namespace std;

const int MAXN = 100000 + 5;

int a[MAXN];
int bel[MAXN];
int ly[350];
int mp[350][10000 + 5];
int sz,sz_num,n;
bool is[10000 + 5];
int can[350];
int the[30];

void init(){
	is[0] = false;
	is[10000] = false;
	for(int i=1,j,a;i<10000;i++){
		j = i;
		bool flag = true;
		while(j){
			a = j % 10;
			if(a != 4 && a != 7){
				flag = false;
				break;
			}
			j /= 10;
		}
		is[i] = flag;
	}
	int j = 0;
	for(int i=1;i<10000;i++){
		if(is[i]) the[j++] = i;
	}
}

void update(int l,int r,int d){
	if(bel[l] == bel[r]){
		for(int i=l;i<=r;i++){
			mp[bel[l]][a[i]]--;
			a[i] += d;
			mp[bel[l]][a[i]]++;
		}
		can[bel[l]] = -1;
		return ;
	}
	update(l,bel[l] * sz + sz,d);
	update(bel[r] * sz + 1,r,d);
	for(int i=bel[l] + 1;i<bel[r];i++){
		ly[i] += d;
		can[i] = -1;
	}
}

int query(int l,int r){
	int res = 0;
	if(bel[l] == bel[r]){
		for(int i=l;i<=r;i++){
			if(a[i] + ly[bel[l]] <= 10000 && is[a[i] + ly[bel[l]]]) 
				res++;
		}
		return res;
	}
	res += query(l,bel[l] * sz + sz);
	res += query(bel[r] * sz + 1,r);
	for(int i=bel[l] + 1;i<bel[r];i++){
		if(can[i] >= 0){
			res += can[i];
			continue;
		}
		int cnt = 0;
		for(int j=0;j<30;j++){
			if(the[j] - ly[i] > 0)
				cnt += mp[i][the[j] - ly[i]];
		}
		can[i] = cnt;
		res += cnt;
	}
	return res;
}

char ch[10];

void solve(int m){
	sz = (int)sqrt(n + 0.5);
	sz_num = n / sz;
	if(n % sz) sz_num++;
	for(int i=1;i<=n;i++){
		bel[i] = (i - 1) / sz;
	}
	memset(mp,0,sizeof mp);
	for(int i=0;i<sz_num;i++){
		ly[i] = 0;
		int l = i * sz + 1;
		int r = min(i * sz + sz,n);
		for(int j=l;j<=r;j++)
			mp[i][a[j]]++;
	}
	memset(can,-1,sizeof can);
	for(int i=1,l,r,d;i<=m;i++){
		scanf("%s",ch);
		if(ch[0] == 'a'){
			scanf("%d %d %d",&l,&r,&d);
			update(l,r,d);
		}
		else{
			scanf("%d %d",&l,&r);
			printf("%d\n",query(l,r));
		}
	}
}

bool you[10];

int main(){
	init();
	int m;
	while(~scanf("%d %d",&n,&m)){
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		solve(m);
	}
	return 0;
}
