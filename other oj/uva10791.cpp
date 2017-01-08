                                            
  //File Name: uva10791.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2015年12月23日 星期三 16时23分56秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

#define LL long long

using namespace std;

LL a[120];
int tot;

void fact(LL n)
{
	int pre = -1;
	for(LL i=2;i*i <= n;i++){
		while(n % i == 0){
			if(i == pre)
				a[tot] *= i;
			else{
				pre = i;
				a[++tot] = i;
			}
			n /= i;
		}
	}
	if(n != 1)
		a[++tot] = n;
}

void solve(LL n)
{
	tot = 0;
	fact(n);

	if(tot <= 1){
		printf("%lld\n",n+1);
	}
	else{
		LL ret = 0;
		for(int i=1;i<=tot;i++){
			ret += a[i];
		}
		printf("%lld\n",ret);
	}
	return ;
}

int main()
{
	int cas = 1;
	LL n;
	while(~scanf("%lld",&n)){
		if(!n)
			break;
		printf("Case %d: ",cas++);
		solve(n);
	}
	return 0;
}	
