                                            
  //File Name: cf665E.cpp
  //Created Time: 2017年05月03日 星期三 22时24分21秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
struct AC{
	static const int MAXN = 3e7;
	int end;
	int tag[MAXN];
	int trie[MAXN][2];
	void init(){
		memset(trie,0,sizeof trie);
		memset(tag,0,sizeof tag);
		end = 2;
	}
	void add(const int s){
		int p(1);
		for(int i(29);i>=0;--i){
			int u = (s >> i) & 1;
			if(!trie[p][u])
				trie[p][u] = end++;
			p = trie[p][u];
			++tag[p];
		}
	}
	int cal(const int x,const int k){
		int p(1),res(0);
		for(int i(29);i>=0;--i){
			int u = (x >> i) & 1;
			int v = (k >> i) & 1;
			if(!v){
				res += tag[trie[p][u ^ 1]];
				p = trie[p][u];
			}
			else
				p = trie[p][u ^ 1];
		}
		res += tag[p];
		return res;
	}
};
AC ac;
int main(){
	ac.init();
	int n,k;
	scanf("%d %d",&n,&k);
	int pre(0);
	ac.add(0);
	LL ans(0);
	for(int i(1),x;i<=n;++i){
		scanf("%d",&x);
		pre ^= x;
		ans += ac.cal(pre,k);
		ac.add(pre);
	}
	printf("%lld\n",ans);
	return 0;
}
