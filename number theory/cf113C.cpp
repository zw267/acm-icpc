                                            
  //File Name: cf113c.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月08日 星期二 19时55分30秒
                                   
#include <iostream>
using namespace std;
const int MAXN = (int)3e8 + 10;
bool is[MAXN];
int main(){
	int l,r;
	cin >> l >> r;
	int j;
	for(int i=3;(j=i*i)<=r;i+=2){
		if(!is[i]){
			for(;j<=r;j+=i+i)
				is[j] = 1;
		}
	}
	int ans = 0;
	for(int i=5;i<=r;i+=4){
		if(i >= l && !is[i])
			ans++;
	}
	if(l <= 2 && r >= 2)
		ans++;
	cout << ans << endl;
	return 0;
}

