                                            
  //File Name: cf792D.cpp
  //Created Time: 2017年03月28日 星期二 15时42分25秒
                                   
#include <bits/stdc++.h>
#define LL long long 
using namespace std;
const int MAXN = 100000 + 4;
char str[MAXN];
LL p2[61];
LL n,height,root;
map<LL,LL> father;
LL find_height(LL s){
	LL h = height - 1;
	LL cur = root,to;
	while(cur != s){
		if(s < cur)
			to = cur - p2[h - 1];
		else
			to = cur + p2[h - 1];
		--h;
		father[to] = cur;
		cur = to;
	}
	return h;
}
LL query(LL s,LL h){
	int len = strlen(str);
	LL to;
	for(int i=0;i<len;++i){
		if(str[i] == 'L'){
			if(!h) continue;
			to = s - p2[h - 1];
			father[to] = s;
			s = to;
			--h;
		}
		else if(str[i] == 'R'){
			if(!h) continue;
			to = s + p2[h - 1];
			father[to] = s;
			s = to;
			--h;
		}
		else{
			if(father[s] == -1) continue;
			s = father[s];
			++h;
		}
	}
	return s;
}
void solve(int q){
	p2[0] = 1;
	for(int i=1;i<61;++i) p2[i] = p2[i - 1] * 2;
	root = n + 1 >> 1;
	father[root] = -1;
	for(int i=0;i<61;++i){
		if(p2[i] == n + 1){
			height = i;
			break;
		}
	}
//	printf("root = %lld height = %lld\n",root,height);
	while(q--){
		LL s;
		scanf("%lld %s",&s,str);
		LL h = find_height(s);
//		printf("s = %lld h = %lld\n",s,h);
		printf("%lld\n",query(s,h));
	}
}
int main(){
	int q;
	scanf("%lld %d",&n,&q);
	solve(q);
	return 0;
}
