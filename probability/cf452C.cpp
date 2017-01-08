                                            
  //File Name: cf452C.cpp
  //Created Time: 2017年01月05日 星期四 23时33分01秒
                                   
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin >> n >> m;
	double ans = 1.0 / n;
	if(n * m > 1)
		ans += (n - 1.0) * (m - 1.0) / n / (n * m - 1.0);
	cout << ans << endl;
	return 0;
}
