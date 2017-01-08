                                            
  //File Name: zoj5504.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月05日 星期六 12时37分31秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	int test;
	cin >> test;
	while(test--){
		int n;
		cin >> n;
		int ans = 0;
		int u;
		for(int i=0;i<n;i++){
			cin >> u;
			if(u > 6000)
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
