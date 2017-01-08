                                            
  //File Name: nod1351.cpp
  //Created Time: 2017年01月02日 星期一 14时59分21秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 50;
int low[MAXN],high[MAXN];
bool big(int x,int y){
	return x > y;
}
int solve(int n,int c,int x){
	int res1 = n,res2 = n,now = 0;
	sort(low,low+n,big);
	for(int i=0;i<n;++i){
		now += low[i];
		if(now >= x){
			res1 = i + 1;
			break;
		}
	}
	now = 0;
	sort(high,high+n);
	for(int i=0;i<n;++i){
		now += high[i];
		if(now > c - x){
			res2 = n - i;
			break;
		}
	}
	return min(res1,res2);
}
int main(){
	int t,n,c,x;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&n,&c,&x);
		for(int i=0;i<n;++i){
			scanf("%d %d",low + i,high + i);
		}
		printf("%d\n",solve(n,c,x));
	}
	return 0;
}
