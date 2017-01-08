                                            
  //File Name: cf621A.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月01日 星期一 19时56分58秒
                                   
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>

#define LL long long 

using namespace std;

const int MAXN = 100000+5;

int main()
{
	LL ans = 0LL;
	int n;
	cin >> n;
	LL tmp;
	vector<LL> odd1;
	vector<LL> odd2;
	for(int i=0;i<n;i++){
		cin >> tmp;
		if(tmp % 2 == 0 && tmp > 0)
			ans += tmp;
		else if(tmp % 2 == 1 && tmp > 0)
			odd1.push_back(tmp);
		else if(tmp % 2 == 1 && tmp < 0)
			odd2.push_back(tmp);
	}
	sort(odd1.begin(),odd1.end());
	sort(odd2.begin(),odd2.end());
		
	int i;
	for(i=odd1.size()-1;i>0;i-=2){
		ans += (odd1[i] + odd1[i-1]);
	}
	if(i == 0 && odd2.size() >= 1){
		LL cnt = odd1[0] + odd2[odd2.size()-1];
		if(cnt > 0)
			ans += cnt;
	}

	cout << max(ans,0LL) << endl;
	return 0;
}
