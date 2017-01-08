                                            
  //File Name: la5846.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2015年12月24日 星期四 01时14分30秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>

#define LL long long 

using namespace std;

const int MAXN = 1000 + 5;

int red[MAXN];

LL solve(int n)
{
	LL res = 0;
	for(int i=1;i<=n;i++){
		res += (LL)red[i] * (n - 1 - red[i]);
	}
	res /= 2;

	res = (LL)n * (n - 1) * (n - 2) /6 - res;

	return res;
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		int n;
		scanf("%d",&n);
		memset(red,0,sizeof red);
		for(int i=1;i<n;i++){
			int cur;
			for(int j=i+1;j<=n;j++){
				scanf("%d",&cur);
				if(cur){
					red[i]++;
					red[j]++;
				}
			}
		}

		printf("%lld\n",solve(n));
	}
	return 0;
}
