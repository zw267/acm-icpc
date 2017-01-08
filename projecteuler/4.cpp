                                            
  //File Name: 4.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月02日 星期三 15时23分46秒
                                   
#include <iostream>
#include <algorithm>
using namespace std;
bool ok(int x){
	int a[10],n = 0;
	while(x){
		a[++n] = x % 10;
		x /= 10;
	}
	for(int i=1;i+i<=n;i++)
		if(a[i] != a[n+1-i])
			return false;
	return true;
}
int main(){
	int res = 0;
	for(int i=100;i<1000;i++){
		for(int j=i;j<1000;j++){
			if(ok(i * j))
				res = max(res, i * j);
		}
	}
	cout << res << endl;
	return 0;
}
