                                            
  //File Name: cf331A2.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月10日 星期三 22时13分17秒
                      

/*
题意：
给出一个数组，长度为n，2<=n<=3*1e5
保证这个数组至少有2个数相等
要求：
删除一部分数，使得这个数组满足：
1.这个数组的首尾数相等
2.这个数组的和尽量大
3.这个数组的个数 >= 2

思路：
贪心 + map

用map记录下每一个数的最后出现的位置：O(n)
sum数组记录前缀和:O(n)
sum[i]表示1～i中的>0的数之和

遍历数组，更新答案

*/

#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

#define LL long long

using namespace std;

const int MAXN = 300000+5;
const LL INF = 0x3f3f3f3f3f3f3f3f;

int a[MAXN];
LL sum[MAXN];

void solve(int n)
{
	vector<int> ans;
	map<int,int> chg;
	ans.clear();
	chg.clear();

	sum[0] = 0LL;
	for(int i=1;i<=n;i++){
		sum[i] = sum[i-1] + max(a[i],0);
	}
	for(int i=1;i<=n;i++){
		chg[a[i]] = i;
	}
	LL cur = -INF;
	LL tmp = 0;
	int ans_l = 0,ans_r = 0;
	for(int i=1;i<=n;i++){
		int r = chg[a[i]];
		if(r <= i)
			continue;
		//cout << i << endl << r << endl;
		tmp = sum[r-1] - sum[i] + a[i] + a[r];
		//cout << tmp << endl;
		if(tmp > cur){
			cur = tmp;
			ans_l = i;
			ans_r = r;
		}
	}
	for(int i=1;i<ans_l;i++)
		ans.push_back(i);
	for(int i=ans_l+1;i<ans_r;i++){
		if(a[i] < 0)
			ans.push_back(i);
	}
	for(int i=ans_r+1;i<=n;i++)
		ans.push_back(i);

	cout << cur << " " << ans.size() << endl;
	if(ans.size() > 0){
		for(int i=0;i<ans.size()-1;i++)
			printf("%d ",ans[i]);
		printf("%d\n",ans[ans.size()-1]);
	}
	return ;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	solve(n);

	return 0;
}
