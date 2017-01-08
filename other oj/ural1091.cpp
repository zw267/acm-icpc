//容斥定理
//题意：给出k，s 2<=k,s<=50,问在[1,s]中选取k个数，这k个数的gcd>1的方案数
//首先，gcd一定是素数的积,由于50/2=25，所以我们只需要25以内的素数
//25内的素数只有9个：2，3，5，7，11，13，17，19，23
//先预处理出dp[i][j]表示i中选j个的方案数
//把9个素数的取不取状态压缩到i中，设Pi表示一个k个数的集合具有k个数的gcd是i表示的prime的乘积的倍数这个性质
//设Ai表示具有性质Pi的集合个数，明显：|Ai| = dp[s/prime[i]][k]
//那么我们要求的就是Ai的并集了
//由于2*3*5=30>25,则9个素数最多同时取2个


#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

#define LL long long

using namespace std;

int prime[9] = {2,3,5,7,11,13,17,19,23};
LL dp[51][51];

void init_dp()
{
	memset(dp,0,sizeof dp);
	dp[0][0] = 1;
	for(int i=1;i<26;i++){
		dp[i][0] = 1;
		for(int j = 1;j<=i;j++)
			dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
	}
}

LL solve(int k,int s)
{
	LL ret = 0;
	int ma = (1 << 9);
	for(int i=1;i<ma;i++){
		int num = 0;
		LL cur = 1;
		for(int j = 0;j<9;j++){
			if(i & (1 << j)){
				num++;
			}
		}
		if(num > 2)
			continue;
		for(int j= 0;j<9;j++){
			if(i & (1 << j))
				cur *=(LL) prime[j];
		}
		if(s / cur < k)
			continue;
		if(num % 2){
			ret = ret + dp[s/cur][k];
			//printf("%lld\n",dp[s/cur][k]);
		}
		else{
			ret = ret - dp[s/cur][k];
			//printf("%lld\n",dp[s/cur][k]);
		}
	}
	return ret;
}

int main()
{
	init_dp();
	int k,s;
	while(~scanf("%d %d",&k,&s)){
		LL ret = solve(k,s);
		ret = ret < 10000 ? ret:10000;
		printf("%lld\n",ret);
	}
	return 0;
}
