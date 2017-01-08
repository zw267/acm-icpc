                                            
  //File Name: nod1471.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年09月15日 星期四 21时17分30秒

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#define LL long long
using namespace std;
const int MAXN = 100000 + 10;
const int NUM = 400;
int l[MAXN/NUM+5],r[MAXN/NUM+5],belong[MAXN];
int a[MAXN],tmp[NUM],cnt;
struct Block{
	int b[NUM],s[MAXN],head,tot;
	void build(const int l,const int r){
		tot = head = 0;
		memset(s,0,sizeof s);
		for(int i=l;i<=r;i++){
			b[tot++] = a[i];
			s[a[i]]++;
		}
	}
	void right(int st){
		head--;
		if(head < 0) head = tot - 1;
		cnt = b[head];
		s[cnt]--;
		b[head] = st;
		s[st]++;
	}
	void reset(){
		if(head == 0) return ;
		for(int i=0;i<tot;i++) tmp[i] = b[i];
		int u = 0;
		for(int i=head;i<tot;i++) b[u++] = tmp[i];
		for(int i=0;i<head;i++) b[u++] = tmp[i];
		head = 0;
	}
	void brute(int st,int l,int r){
		reset();
		cnt = b[r];
		s[cnt]--;
		for(int i=r;i>l;i--) b[i] = b[i-1];
		b[l] = st;
		s[st]++;
	}
	int get(int k){
		k = (head + k) % tot;
		return b[k];
	}
	int query(int k){
		return s[k];
	}
	int cal(int l,int r,int k){
		reset();
		int res = 0;
		for(int i=l;i<=r;i++)
			if(b[i] == k) res++;
		return res;
	}
}block[MAXN / NUM + 5];
void solve(int n){
	for(int i=1;i<=n;i++)
		belong[i] = (i - 1) / NUM;
	int tot = belong[n] + 1,u=1;
	for(int i=0;i<tot;i++,u+=NUM){
		l[i] = u;
		r[i] = min(u + NUM - 1,n);
	}
	for(int i=0;i<tot;i++)
		block[i].build(l[i],r[i]);
	int ans = 0,q,op,x,y,k;
	scanf("%d",&q);
	while(q--){
		scanf("%d %d %d",&op,&x,&y);
		if(op == 1){
			x = (x + ans - 1) % n + 1;
			y = (y + ans - 1) % n + 1;
			if(x > y) swap(x,y);
			int bx = belong[x],by = belong[y];
			if(bx == by){
				cnt = block[bx].get(y-l[bx]);
				block[bx].brute(cnt,x-l[bx],y-l[bx]);
			}
			else{
				cnt = block[by].get(y-l[by]);
				block[bx].brute(cnt,x-l[bx],r[bx]-l[bx]);
				for(int i=bx+1;i<by;i++)
					block[i].right(cnt);
				block[by].brute(cnt,0,y-l[by]);
			}
		}
		else{
			scanf("%d",&k);
			x = (x + ans - 1) % n + 1;
			y = (y + ans - 1) % n + 1;
			k = (k + ans - 1) % n + 1;
			if(x > y) swap(x,y);
			//cout << x << " " << y << " " << k << " " << endl;
			int bx = belong[x],by = belong[y];
			ans = 0;
			if(bx == by)
				ans = block[bx].cal(x-l[bx],y-l[bx],k);
			else{
				ans += block[bx].cal(x-l[bx],r[bx]-l[bx],k);
				for(int i=bx+1;i<by;i++)
					ans += block[i].query(k);
				ans += block[by].cal(0,y-l[by],k);
			}
			printf("%d\n",ans);
		}
	}
}
int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++) scanf("%d",a + i);
		solve(n);
	}
	return 0;
}

