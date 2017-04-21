                                            
  //File Name: cf765B.cpp
  //Created Time: 2017年04月21日 星期五 16时12分42秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
char str[510];
bool use[26];
int main(){
	memset(use,false,sizeof use);
	bool flag = true;
	scanf("%s",str);
	int n = strlen(str);
	for(int i=0;i<n;++i){
		int cur = str[i] - 'a';
		for(int j=0;j<cur;++j){
			if(!use[j]){
				flag = false;
				break;
			}
		}
		use[cur] = true;
	}
	if(flag) puts("YES");
	else puts("NO");
	return 0;
}
