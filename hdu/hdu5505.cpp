                                            
  //File Name: hdu5505.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月12日 星期二 20时12分24秒
                                   
/*
题意：给出2个数n,m
n每次可以乘上一个自己的因数变成新的n
求最初的n到m至少需要的步数
如果永远到不了输出-1
数据：1<=n<=1000000,1<=m<=2^63

思路：
注意：
1.每次n乘以一个因数之后n就不再是原来的n了，是新的n，
  所以n的因子个数会增加
2.m的数据范围可以到2^63,而long long 最大可以到2^63-1,
  所以需要用到unsigned long long(2^64-1)
  因为没有注意到这一点wa了好久
3.注意了这2个注意的点之后，这道题就是简单的分解因子了

所以我们要做的就是：
1.先特判特殊情况，即输出0或者-1的情况
2.对n进行分解因子
3.tmp = m / n ，对tmp进行分解因子
4.如果tmp里面有n没有的因子，则肯定是输出-1
  否则，每次贪心，n的因子取尽量多个，注意，取后n是新的n了，
  所以每次取后n的该因子的个数翻倍，然后当剩余的小于就一次性取了

*/


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <iostream>

#define ULL unsigned long long
#define LL long long

using namespace std;

//分解因子
map<ULL,ULL> fact(ULL n)
{
	map<ULL,ULL> res;
	for(ULL i=2;i*i<=n;i++){
		while(n % i == 0){
			res[i]++;
			n /= i;
		}
	}
	if(n != 1)
		res[n]++;
	return res;
}

//算出最少需要拿的次数
ULL get(ULL a,ULL b)
{
	LL res = 0;
	while(b > a){
		res++;
		b -= a;
		a *= 2;
	}
	if(b)
		res++;
	return res;
}

LL solve(ULL n,ULL m)
{
	//特判
	if(n > m)
		return -1LL;
	if(n == m)
		return 0LL;
	if(n == 1)
		return -1LL;
	if(m % n > 0)
	return -1LL;	

	ULL tmp = m / n;
	ULL ans = 0;

	map<ULL,ULL> fact_n = fact(n);
	map<ULL,ULL> fact_tmp = fact(tmp);
	map<ULL,ULL> ::iterator it;

	for(it=fact_tmp.begin();it!=fact_tmp.end();it++){
		if(fact_n[it->first] == 0)
			return -1;
		ULL a = fact_n[it->first];
		ULL b = fact_tmp[it->first];
		ULL num = get(a,b);
		ans = num > ans ? num : ans;
	}
	
	return ans;
}

int main()
{
	int test;
	cin >> test;
	while(test--){
		ULL n,m;
		cin >> n >> m;
		cout << solve(n,m) << endl;
	}
	return 0;
}
