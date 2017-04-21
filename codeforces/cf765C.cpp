                                            
  //File Name: cf765C.cpp
  //Created Time: 2017年04月21日 星期五 16时27分20秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main(){
	int k,a,b,ans(0);
	cin >> k >> a >> b;
	if(a < k && b < k) ans = -1;
	else{
	   	ans = a / k + b / k;
		if(a % k > b / k * (k - 1) || b % k > a / k * (k - 1))
			ans = -1;
	}
	cout << ans << endl;
}
