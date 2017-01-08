//容斥原理
//水题
//注意输入的m的集合有可能有0元素，要先去掉




#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

int s[11];

LL gcd(LL x,LL y)
{
	if(y == 0)
		return x;
	return gcd(y,x% y);
}

void solve(LL n,int m)
{
	LL res = 0;
	int ma = (1 << m);
	for(int i=1;i<ma;i++){
		LL tmp = 1;
		int num = 0;
		for(int j=0;j<m;j++){
			if(i & (1 << j)){
				tmp = tmp / gcd(tmp,s[j]) * s[j];
				num++;
			}
		}
		if(num % 2)
			res = res + (n-1)/tmp;
		else
			res = res - (n-1)/tmp;
	}
	cout << res << endl;
}

int main()



{
	LL n;
	int m;
	while(cin >> n >> m){
		int num = 0;

		for(int i=0;i<m;i++){
			int tmp;
			cin >> tmp;
			if(tmp){
				s[num++] = tmp;
			}
		}
		solve(n,num);
	}
	return 0;
}
