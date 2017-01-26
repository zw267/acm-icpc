                                            
  //File Name: cf113B.cpp
  //Created Time: 2017年01月17日 星期二 16时54分33秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 2005;
const LL P = (LL)1e9 + 7;
char s[MAXN],b[MAXN],e[MAXN];
LL hs[MAXN],p[MAXN];
vector<LL> ans;
vector<int> pos;
LL cal_h(int l,int r){
	return hs[r] - hs[l - 1] * p[r - l + 1];
}
int solve(){
	int ls = strlen(s + 1);
	int lb = strlen(b + 1);
	int le = strlen(e + 1);
	LL hb = 0,he = 0;
	for(int i=1;i<=lb;++i)
		hb = hb * P + b[i];
	for(int i=1;i<=le;++i)
		he = he * P + e[i];
	hs[0] = 0;
	for(int i=1;i<=ls;++i)
		hs[i] = hs[i - 1] * P + s[i];
	p[0] = 1;
	for(int i=1;i<=ls;++i)
		p[i] = p[i - 1] * P;
	for(int i=1,j;i<=ls;++i){
		j = i + lb - 1;
		if(j > ls) break;
		LL tmp = cal_h(i,j);
		if(tmp == hb)
			pos.push_back(i);
	}
//	for(int k=0;k<pos.size();++k)
//		printf("%d %d\n",pos[k],pos[k] + lb - 1);
	for(int i=1,j;i<=ls;++i){
		j = i + le - 1;
		if(j > ls) break;
		LL tmp = cal_h(i,j);
		if(tmp == he){
//			printf("%d %d\n",i,j);
			for(int k=0;k<pos.size();++k){
				int u = pos[k],v = pos[k] + lb - 1;
				if(u <= i && v <= j)
//					printf("%d %d %lld\n",u,j,cal_h(u,j)),
					ans.push_back(cal_h(u,j));
				else
					break;
			}
		}
	}
	if(ans.size() == 0)
		return 0;
	int res = 1;
	sort(ans.begin(),ans.end());
	for(int i=1;i<ans.size();++i)
		if(ans[i] != ans[i - 1])
			++res;
	return res;
}
int main(){
	scanf("%s %s %s",s + 1,b + 1,e + 1);
	printf("%d\n",solve());
	return 0;
}
