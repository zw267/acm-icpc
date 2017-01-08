                                            
  //File Name: 8.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月02日 星期三 22时31分25秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
char str[55];
int s[1010];
LL solve(int n){
	LL res = 0,tmp = s[0];
	int l = 0,r = 0;
	while(r < n){
		while(r < n - 1 && r - l + 1 < 13){
			r++;
			tmp *= s[r];
			if(tmp == 0)
				r += 1,l = r,tmp = s[l];
		}
		if(r - l + 1 == 13) res = max(res,tmp);
		r++;
		if(r == n) break;
		tmp *= s[r];
		if(tmp == 0) 
			l = r,tmp = s[l];
		else
			tmp /= s[l],l+=1;
	}
	return res;
}
int main(){
	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	int tot = 0;
	for(int i=0;i<20;i++){
		scanf("%s",str);
		for(int j=0;j<50;j++)
			s[tot++] = str[j] - '0';
	}
	printf("%lld\n",solve(tot));
	fclose(stdin);
//	fclose(stdout);
	return 0;
}
