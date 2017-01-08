                                            
  //File Name: hdu5504.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月12日 星期二 19时55分14秒
                                   


#include <cstdio>
#include <cstring>
#include <algorithm>

#define LL long long

using namespace std;

LL a[62];
int num[3];

LL solve(int n)
{
	if(n == 1)
		return a[0];
	LL res = 1;
	bool flag = false;
	sort(a,a+n);
	num[0] = num[1] = num[2] = 0;
	for(int i=0;i<n;i++){
		if(a[i] < 0)
			num[0]++;
		else if(a[i] == 0)
			num[1]++;
		else
			num[2]++;
	}
	
	int tmp = num[0] / 2 * 2;
	for(int i=0;i<tmp;i++){
		res = res * a[i];
		flag = true;
	}

	for(int i=num[0]+num[1];i<n;i++){
		res = res * a[i];
		flag = true;
	}

	if(!flag)
		res = 0;
	return res;
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%I64d",&a[i]);
		printf("%I64d\n",solve(n));
	}
	return 0;
}
