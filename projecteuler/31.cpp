                                            
  //File Name: 31.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月03日 星期四 19时19分23秒
                                   
#include <iostream>
using namespace std;
int a[8] = {1,2,5,10,20,50,100,200};
int f[201];
int solve(int n){
	f[0] = 1;
	for(int i=0;i<8;i++){
		for(int j=a[i];j<=n;j++)
			f[j] += f[j - a[i]];
	}
	return f[n];
}
int main(){
	cout << solve(200) << endl;
}
