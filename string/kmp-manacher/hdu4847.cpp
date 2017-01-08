                                            
  //File Name: hdu4847.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月27日 星期三 11时35分00秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 1000000 + 3;

char str[MAXN];
const char s[] = "doge";

int solve(int n){
	int ans = 0;
	for(int i=0;i<n-3;i++){
		bool flag = true;
		for(int j=0;j<4;j++){
			if(str[i + j] != s[j]){
				flag = false;
				break;
			}
		}
		if(flag)
			ans++;
	}
	return ans;
}

int main(){
	int ans = 0;
	while(~scanf("%s",str)){
		int n = strlen(str);
		for(int i=0;i<n;i++){
			if(str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32;
		}
		ans += solve(n);
	}
	printf("%d\n",ans);
	return 0;
}
