                                            
  //File Name: cf765A.cpp
  //Created Time: 2017年04月21日 星期五 15时53分52秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
char s[10],home[5];
bool check(const char *s){
	if(s[0] == home[0] && s[1] == home[1] && s[2] == home[2])
		return true;
	return false;
}
int main(){
	int n,a(0),b(0);
	scanf("%d",&n);
	scanf("%s",home);
	for(int i=0;i<n;++i){
		scanf("%s",s);
		if(check(s)) ++a;
		if(check(s + 5)) ++b;
	}
	if(a == b) puts("home");
	else puts("contest");
	return 0;
}
