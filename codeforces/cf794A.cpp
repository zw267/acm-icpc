                                            
  //File Name: cf794A.cpp
  //Created Time: 2017年05月14日 星期日 23时23分41秒
                                   
#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,n,u;
	int res(0);
	cin >> a >> b >> c >> n;
	for(int i(0);i<n;++i){
		cin >> u;
		if(b < u && u < c)
			++res;
	}
	cout << res << endl;
	return 0;
}
