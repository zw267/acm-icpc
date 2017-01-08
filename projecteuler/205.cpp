                                            
  //File Name: 205.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月04日 星期五 00时41分05秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
LL f[37],g[37];
double solve(){
	for(int i=1;i<=4;i++) f[i] = 1;
	for(int i=2;i<=9;i++){
		for(int j=36;j>0;j--){
			f[j] = 0;
			for(int k=j-1;k>=j-4 && k>=0;k--)
				f[j] += f[k];
		}
	}
	for(int i=1;i<=6;i++) g[i] = 1;
	for(int i=2;i<=6;i++){
		for(int j=36;j>0;j--){
			g[j] = 0;
			for(int k=j-1;k>=j-6 && k>=0;k--)
				g[j] += g[k];
		}
	}
	for(int i=1;i<=36;i++)
		g[i] += g[i-1];
	LL x = 1,y = 1;
	for(int i=1;i<=9;i++) x *= 4;
	for(int i=1;i<=6;i++) y *= 6;
//	cout << g[36] << endl;
//	cout << y << endl;
	x *= y;
	double res = 0;
	for(int i=1;i<=36;i++){
		res += 1.0 * f[i] * g[i-1] / x;
	}
	return res;
}
int main(){
	printf("%.7lf\n",solve());
}
