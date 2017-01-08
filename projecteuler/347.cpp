                                            
  //File Name: 347.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月04日 星期五 02时10分17秒
                                   
#include <stdio.h>
#include <algorithm>
#include <iostream>
#define LL long long
const int MAXN = 10000000 + 1;
int num[MAXN],f[MAXN];
LL mul[MAXN];
LL solve(int n){
	for(int i=1;i<=n;i++) mul[i] = 1;
	for(int i=2;i<=n;i++){
		if(!num[i]){
			for(int j=2*i;j<=n;j+=i){
				num[j]++;
//				if(num[j] == 2)
//					std::cout << j << std::endl;
				mul[j] *= i;
			}
		}
	}
	for(int i=2;i<=n;i++){
		if(num[i] == 2){
			f[mul[i]] = std::max(f[mul[i]],i);
		}
	}
	LL res = 0;
	for(int i=2;i<=n;i++)
		res += f[i];
	return res;
}
int main(){
	std::cout << solve(10000000) << std::endl;
	return 0;
}
