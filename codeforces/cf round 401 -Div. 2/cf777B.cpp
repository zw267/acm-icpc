                                            
  //File Name: cf777B.cpp
  //Created Time: 2017年03月23日 星期四 19时07分05秒
                                   
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 5;
multiset<int> rem;
int a[MAXN],b[MAXN];
char str[MAXN];
int solve(int n,int f){
	rem.clear();
	for(int i=0;i<n;++i)
		rem.insert(b[i]);
	for(int i=0;i<n;++i){
		auto it = rem.lower_bound(a[i]);
		if(f)
			it = rem.lower_bound(a[i] + 1);
		if(it == rem.end())
			break;
		else
			rem.erase(it);
	}
	if(f == 0) return rem.size();
	else return n - rem.size();
}
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",str);
	for(int i=0;i<n;++i)
		a[i] = str[i] - '0';
	scanf("%s",str);
	for(int i=0;i<n;++i)
		b[i] = str[i] - '0';
	sort(a,a + n);
	int mi = solve(n,0);
	int ma = solve(n,1);
	printf("%d\n%d\n",mi,ma);
	return 0;
}
