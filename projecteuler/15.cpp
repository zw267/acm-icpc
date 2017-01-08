                                            
  //File Name: 15.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月03日 星期四 00时49分27秒
                                   
#include <iostream>
#define LL long long
using namespace std;
const int MAXN = 45;
LL f[MAXN][MAXN];
void init(){
	for(int i=0;i<MAXN;i++){
		f[i][0] = 1;
		for(int j=1;j<=i;j++)
			f[i][j] = f[i-1][j] + f[i-1][j-1];
	}
}
int main(){
	init();
	cout << f[40][20] << endl;
	return 0;
}
