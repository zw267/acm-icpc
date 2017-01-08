                                            
  //File Name: 76.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月04日 星期五 23时14分34秒
                                   
#include <iostream>
#define LL long long
const int MAXN = 101;
LL f[MAXN][MAXN];
int solve(int n){
	f[0][0] = 1;
	for(int i=0;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j <= i) f[i][j] = f[i-j][j] + f[i][j-1];
			else f[i][j] = f[i][i];
		}
	}
	return f[n][n-1];
}
int main(){
	std::cout << solve(100) << std::endl;
	return 0;
}
