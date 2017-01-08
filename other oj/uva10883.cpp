                                            
  //File Name: uva10883.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2015年12月23日 星期三 23时25分59秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;



const int MAXN = 50000+5;

double lo[MAXN];

void init()
{
	lo[1] = log10(1);
	for(int i=2;i<MAXN;i++){
		lo[i] = lo[i-1] + log10(i);
	}
}

void solve(int n)
{
	double res = 0;
	double tmp;
	
	//lo[0] = log10(1);
	//for(int i=1;i<n;i++){
	//	lo[i] = lo[i-1] + log10(n - i) - log10(i);
	//}

	for(int i=0;i<n;i++){
		scanf("%lf",&tmp);
		bool flag = true;
		if( tmp == 0.0){
			continue;
		}
		if(tmp < 0){
			flag = false;
			tmp *= (-1.0);
		}
		double cur;
		if(i == 0 || i == n - 1)
			cur = log10(1);
		else
			cur = lo[n-1] - lo[i] - lo[n-1-i];
		//cur = lo[i];

		if(flag)
			res += pow(10,log10(tmp) + cur - (n-1) * (log10(2)));
		else
			res -= pow(10,log10(tmp) + cur - (n-1) * (log10(2)));
	}
	printf("%.3lf\n",res);
}

int main()
{
	init();
	int cas = 1;
	int test;
	scanf("%d",&test);
	while(test--){
		printf("Case #%d: ",cas++);
		int n;
		scanf("%d",&n);
		solve(n);
	}
	return 0;
}
