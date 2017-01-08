                                            
  //File Name: cf590A.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2015年12月24日 星期四 15时41分43秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 500000+5;

int a[MAXN];
int b[MAXN];

int get(int c,int d,int e)
{
	if(c > d)
		swap(c,d);
	if(e < d){
		swap(e,d);
		if(c > d)
			swap(c,d);
	}
	return d;
}

bool judge(int * x,int* y,int n)
{
	y[1] = x[1];
	y[n] = x[n];
	for(int i=2;i<n;i++){
		y[i] = get(x[i-1],x[i],x[i+1]);
	}

	for(int i=2;i<n;i++){
		if(x[i] != y[i])
			return false;
	}
	return true;
}

void solve(int n)
{
	int res = 0;
	int * x = a;
	int * y = b;
	while(res < 2300){
		if(judge(x,y,n))
			break;
		else{
			res++;
			int * tmp = x;
			x = y;
			y = tmp;
		}
	}
	if(res >= 2300)
		puts("-1");
	else{
		printf("%d\n",res);
		for(int i=1;i<n;i++)
			printf("%d ",x[i]);
		printf("%d\n",x[n]);
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
