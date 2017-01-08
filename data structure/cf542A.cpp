                                            
  //File Name: cf542A.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年09月13日 星期二 21时15分35秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <set>
#include <stdlib.h>
#define LL long long
#define hash _hash_
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int MAXN = 200000 + 10;
int hash[MAXN*3],num[MAXN*3],tot,top;
void hash_init(){
	sort(num+1,num+top+1);
	tot = 0;
	hash[++tot] = num[1];
	for(int i=2;i<=top;i++)
		if(num[i] != num[i-1])
			hash[++tot] = num[i];
}
int hash_find(int x){
	int  l = 1,r = tot,mid;
	while(l <= r){
		mid = l + r >> 1;
		if(hash[mid] < x) l = mid + 1;
		else r = mid - 1;
	}
	return l;
}
struct Line{
	int fir,sec,id;
}line[MAXN];
struct Query{
	int l,r,c,ans,id,ansid;
}que[MAXN];
bool cmp_que_l(Query x,Query y){
	if(x.l == y.l) return x.r < y.r;
	return x.l < y.l;
}
bool cmp_que_r(Query x,Query y){
	if(x.r == y.r) return x.l > y.l;
	return x.r > y.r;
}
bool cmp_line_l(Line x,Line y){
	if(x.fir == y.fir) return x.sec < y.sec;
	return x.fir < y.fir;
}
bool cmp_line_r(Line x,Line y){
	if(x.sec == y.sec) return x.fir > y.fir;
	return x.sec > y.sec;
}
pii seg[MAXN * 12];
void build(int l,int r,int rt){
	seg[rt].fi = seg[rt].se = 0;
	if(l == r) return ;;
	int m = l + r >> 1;
	build(lson);
	build(rson);
}
void pushup(int rt){
	if(seg[rt<<1].fi >= seg[rt<<1|1].fi)
		seg[rt] = seg[rt<<1];
	else 
		seg[rt] = seg[rt<<1|1];
}
void update(int p,int add,int id,int l,int r,int rt){
	if(l == r){
		if(add > seg[rt].fi){
			seg[rt].fi = add;
			seg[rt].se = id;
		}
		return ;
	}
	int m = l + r >> 1;
	if(p <= m) update(p,add,id,lson);
	else update(p,add,id,rson);
	pushup(rt);
}
pii query(int L,int R,int l,int r,int rt){
	if(L <= l && R >= r) return seg[rt];
	int m = l + r >> 1;
	if(R <= m) return query(L,R,lson);
	else if(L > m) return query(L,R,rson);
	else{
		pii res1 = query(L,R,lson);
		pii res2 = query(L,R,rson);
		return max(res1,res2);
	}
}
set<pii> st;
LL solve(int n,int m){
	sort(line+1,line+n+1,cmp_line_r);
	sort(que+1,que+m+1,cmp_que_r);
	int now = 1;
	set<pii>::iterator it;
	for(int i=1;i<=m;i++){
		while(now<=n && line[now].sec >= que[i].r){
			st.insert(mp(line[now].fir,line[now].id));
			now++;
		}
		if(st.empty()) continue;
		it = st.begin();
		int len = que[i].r - max(it->fi,que[i].l);
		if(len > que[i].ans)
			que[i].ans = len,que[i].ansid = it->se;
	}
	sort(line+1,line+n+1,cmp_line_l);
	sort(que+1,que+m+1,cmp_que_l);
	now = 1;
	st.clear();
	set<pii>::reverse_iterator reit;
	for(int i=1;i<=m;i++){
		while(now <= n && line[now].fir <= que[i].l){
			st.insert(mp(line[now].sec,line[now].id));
			now++;
		}
		if(st.empty()) continue;
		reit = st.rbegin();
		int len = min(que[i].r,reit->fi) - que[i].l;
		if(len > que[i].ans)
			que[i].ans = len,que[i].ansid = reit->se;
	}
	hash_init();
	for(int i=1;i<=n;i++) line[i].sec = hash_find(line[i].sec);
	for(int i=1;i<=m;i++) que[i].r = hash_find(que[i].r);
	build(1,tot,1);
	now = n;
	for(int i=m;i>0;i--){
		while(now > 0 && line[now].fir >= que[i].l){
			update(line[now].sec,hash[line[now].sec]-line[now].fir,line[now].id,1,tot,1);
			now--;
		}
		int l = hash_find(que[i].l);
		pii tmp = query(l,que[i].r,1,tot,1);
		if(tmp.fi > que[i].ans)
			que[i].ans = tmp.fi,que[i].ansid = tmp.se;
	}
	LL res = 0;
	int u = 0;
	for(int i=1;i<=m;i++){
		LL tmp = 1LL * que[i].ans * que[i].c;
		if(tmp > res)
			res = tmp,u = i;
	}
	if(res == 0) puts("0");
	else{
		cout << res << endl;
		printf("%d %d\n",que[u].ansid,que[u].id);
	}
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	top = 0;
	for(int i=1;i<=n;i++){
		scanf("%d %d",&line[i].fir,&line[i].sec);
		line[i].id = i;
		num[++top] = line[i].sec;
	}
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&que[i].l,&que[i].r,&que[i].c);
		que[i].id = i;
		num[++top] = que[i].l;
		num[++top] = que[i].r;
	}
	solve(n,m);
	return 0;
}
