                                            
  //File Name: cf617B.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月23日 星期六 23时42分02秒
                                   


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

int a[105];

void solve(int n)
{
	int l = 1,r = n;
	while(l <=n && a[l] == 0)
		l++;
	while(r > 0 && a[r] == 0)
		r--;
	if(l > r){
		cout << "0" << endl;
		return ;
	}

	if(l == r){
		cout << "1" << endl;
		return ;
	}

	LL res = 1;
	LL tmp = 0;
	for(int i=l+1;i<=r;i++){
		if(a[i] == 0){
			tmp++;
		}
		else{
			res *= (tmp+1);
			tmp = 0;
		}
	}

	cout << res << endl;
}

int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];

	solve(n);

	return 0;
}
