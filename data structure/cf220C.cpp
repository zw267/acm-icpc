                                            
  //File Name: cf220C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年06月03日 星期五 10时11分44秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <set>
#include <math.h>

using namespace std;

#define fir first
#define sec second
#define mp make_pair
#define pii pair<int,int>

const int MAXN = 100000 + 3;

set< pii > s1,s2;
set< pii >::iterator it,it2;

int p[MAXN],b[MAXN],ans[MAXN];

void solve(int n){
	s1.clear();
	s2.clear();
	int tot = 0;
	for(int i=1;i<=n;i++){
		s1.insert(mp(i-p[b[i]],b[i]));
		s2.insert(mp(b[i],i-p[b[i]]));
	}
	for(int i=0,j;i<n;i++){
		it = s1.lower_bound(mp(tot,-n));
		ans[i] = abs(it->fir - tot);
		if(it != s1.begin()){
			it--;
			ans[i] = min(ans[i],abs(it->fir - tot));
		}	
		j = i + 1;
		it2 = s2.lower_bound(mp(b[j],-n));
		if(it2 == s2.end())
			puts("eeeeeeeeeeeeeeeee");
		it = s1.lower_bound(mp(it2->sec,b[j]));
		s1.erase(it);
		s2.erase(it2);
		s1.insert(mp(n-p[b[j]]+tot+1,b[j]));
		tot++;
	}
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=1,u;i<=n;i++){
			scanf("%d",&u);
			p[u] = i;
		}
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		solve(n);
		for(int i=0;i<n;i++){
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}
