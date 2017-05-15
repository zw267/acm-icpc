                                            
  //File Name: cf794C.cpp
  //Created Time: 2017年05月15日 星期一 00时03分55秒
                                   
#include <bits/stdc++.h>
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;
const int MAXN = 300000 + 5;
set<pii> a,b;
multiset<int> tmp;
map<int,int> rem;
int ans[MAXN];
char str[MAXN];
//从tmp里面拿前n个给a,if flag = true，元素放入a之前 * -1
void cal(multiset<int> &tmp,set<pii> &a,int n,bool flag){
	auto it = tmp.begin();
	while(n){
		int cur = *it;
		if(flag) cur = -cur;
		a.insert(pii(cur,rem[cur]--));
		n--;
		if(!n) break;
		++it;
	}
}
void solve(int n){
	memset(ans,-1,sizeof ans);
	int l(0),r(n);
	pii a_mi,a_ma,b_mi,b_ma;
	while(n >= 2){
		a_mi = *a.begin();
		b_ma = *b.rbegin();
		if(a_mi.fir >= b_ma.fir){
			a_ma = *a.rbegin();
			b_mi = *b.begin();
			ans[--r] = a_ma.fir;
			ans[--r] = b_mi.fir;
			a.erase(a_ma);
			b.erase(b_mi);
		}
		else{
			ans[l++] = a_mi.fir;
			a.erase(a_mi);
			a_mi = *a.begin();
			if(b_ma.fir > a_mi.fir){
				ans[l++] = b_ma.fir;
				b.erase(b_ma);
			}
			else{
				b_mi = *b.begin();
				ans[--r] = b_mi.fir;
				b.erase(b_mi);
			}
		}
		n -= 2;
	}
	if(l < r)
		ans[l] = (*a.begin()).fir;
}
int main(){
	scanf("%s",str);
	int n = strlen(str);
	for(int i(0);i<n;++i){
		rem[str[i] - 'a'] += 1;
		tmp.insert(str[i] - 'a');
	}
	int ma = (n + 1) / 2;
	cal(tmp,a,ma,0);
	tmp.clear();
	rem.clear();
	scanf("%s",str);
	for(int i(0);i<n;++i){
		rem[-(str[i] - 'a')] += 1;
		tmp.insert(-(str[i] - 'a'));
	}
	ma = n / 2;
	cal(tmp,b,ma,1);
	solve(n);
	for(int i(0);i<n;++i)
		printf("%c",ans[i] + 'a');
	puts("");
	return 0;
}
