                                            
  //File Name: cf757A.cpp
  //Created Time: 2017年01月15日 星期日 16时19分26秒
                                   
#include <bits/stdc++.h>
using namespace std;
char s[100000 + 5];
int a[8];
int change(const char s){
	if(s == 'B') return 0;
	if(s == 'u') return 1;
	if(s == 'l') return 2;
	if(s == 'b') return 3;
	if(s == 'a') return 4;
	if(s == 's') return 5;
	if(s == 'r') return 6;
	return 7;
}
int main(){
	scanf("%s",s);
	int n = strlen(s);
	for(int i=0;i<n;++i){
		int u = change(s[i]);
		++a[u];
	}
	int ans = n;
	a[1] /= 2;
	a[4] /= 2;
	for(int i=0;i<7;++i)
		ans = min(ans,a[i]);
	printf("%d\n",ans);
	return 0;
}
