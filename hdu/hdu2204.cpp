//容斥定理
//我们一个数表示为m^k,如果k不是素数，则这个数m^k一定在素数的时候被计算过，所以我们只需要考虑k为素数的情况
//由于n <= 1e18,即 2^60 >= n
//所以我们只需要考虑60以内的素数，先预处理，把60以内的素数放在数组prime中
//设pi表示可以表示成m^prime[i]的性质 ，其中prime[i]表示第i个素数
//设Ai表示具有性质pi的数的集合
//则我们可以用容斥定理解决
//注意到3个素数相乘<=60只有2种情况，2*3*5，2*3*7
//所以在容斥定理枚举的时候，3个素数相乘只有2种情况
//先把1排除在外，最后在把ret + 1,可以避免对1的多算少算


#include <cstdio>
#include <cstring>
#include <cstring>
#include <iostream>
#include <math.h>

#define LL long long

using namespace std;

int prime[60];

int init_prime()
{
	int tot = 1;
	for(int i=2;i<60;i++){
		bool flag = true;
		int e = (int)sqrt(i+0.0);
		for(int j=2;j<=e;j++){
			if(i % j == 0){
				flag = false;
				break;
			}
		}
		if(flag)
			prime[tot++] = i;
	}
	return tot;
}

LL solve(LL n,int tot)
{
	LL ret = 0;
	for(int i=1;i<tot;i++){
		ret +=(LL) (pow(n+0.0,1.0/prime[i]) - 1);
		//cout << pow(n+0.0,1.0/prime[i]) - 1 << endl;
	}

	for(int i = 1;i<tot;i++){
		for(int j=i+1;j<tot;j++){
			ret -=(LL) (pow(n+0.0,1.0/(prime[i] * prime[j])) - 1);
		}
	}

	ret += (LL)(pow(n+0.0,1.0/30) - 1);
	ret += (LL)(pow(n+0.0,1.0/42) - 1);
	return ret + 1;
}

int main()
{
	int tot = init_prime();
	//for(int i=1;i<tot;i++)
	//	cout << prime[i] << endl;

	LL n;
	while(cin >> n){
		cout << solve(n,tot) << endl;
	}
	return 0;
}
