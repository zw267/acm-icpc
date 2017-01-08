                                            
  //File Name: cf145E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年06月03日 星期五 12时29分35秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>

using namespace std;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

const int MAXN = 1000000 + 3;

struct Seg{
	int s44,s47,s77,s74,ly;
	Seg(){}
	Seg(int _s44,int _s47,int _s77,int _s74){
		s44 = _s44, s47 = _s47, s77 = _s77, s74 = _s74;
	}
}seg[MAXN << 2];

char str[MAXN];

void pushup(int rt){
	int l = rt<<1,r = rt<<1|1;
	seg[rt].s44 = seg[l].s44 + seg[r].s44;
	seg[rt].s77 = seg[l].s77 + seg[r].s77;
	seg[rt].s47 = max(seg[l].s47 + seg[r].s77,seg[l].s44 + seg[r].s47);
	seg[rt].s47 = max(seg[rt].s47,seg[l].s44 + seg[r].s77);
	seg[rt].s74 = max(seg[l].s77 + seg[r].s74,seg[l].s77 + seg[r].s44);
	seg[rt].s74 = max(seg[rt].s74,seg[l].s74 + seg[r].s44);
}

void change(int l){
	int s44 = seg[l].s44,s47 = seg[l].s47,s77 = seg[l].s77,s74 = seg[l].s74;
	seg[l].s44 = s77;
	seg[l].s77 = s44;
	seg[l].s47 = s74;
	seg[l].s74 = s47;
}

void pushdown(int rt){
	if(seg[rt].ly){
		int l = rt<<1,r = rt<<1|1;
		seg[l].ly ^= 1;
		seg[r].ly ^= 1;
		change(l);
		change(r);
		seg[rt].ly = 0;
	}
}

void build(int l,int r,int rt){
	seg[rt].ly = 0;
	if(l == r){
		seg[rt].s44 = seg[rt].s47 = seg[rt].s74 = seg[rt].s77 = 0;
		if(str[l] == '4') seg[rt].s44 = 1;
		else seg[rt].s77 = 1;
		return ;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	pushup(rt);
}

void update(int L,int R,int l,int r,int rt){
	if(L <= l && R >= r){
		seg[rt].ly ^= 1;
		change(rt);
		return ;
	}
	pushdown(rt);
	int m = (l + r) >> 1;
	if(L <= m) update(L,R,lson);
	if(R > m) update(L,R,rson);
	pushup(rt);
}

char ch[10];

void solve(int n,int m){
	build(1,n,1);
	for(int i=0,l,r,ans;i<m;i++){
		scanf("%s",ch);
		if(ch[0] == 'c'){
			ans = max(seg[1].s44,seg[1].s47);
			ans = max(ans,seg[1].s77);
			printf("%d\n",ans);
		}
		else{
			scanf("%d %d",&l,&r);
			update(l,r,1,n,1);
		}
	}
}

int main(){
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		scanf("%s",str+1);
		solve(n,m);
	}
	return 0;
}
