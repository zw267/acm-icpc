                                            
  //File Name: 51nod1653.cpp
  //Created Time: 2017年02月26日 星期日 17时52分22秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int s,w,a;
		double p1,p2;
		scanf("%d %d %d %lf %lf",&s,&w,&a,&p1,&p2);
		double x1 = (1.0 - p1) / p1;
		double x2 = (1.0 - p2) / p2;
		double ans = 1.0 + (1.0 - pow(x1,w)) * (x2 - 1.0) / (pow(x1,w) * (x2 - 1) + pow(x1,-a) * pow(x2,a - s) * (1.0 - x1) + pow(x1,-a) * (x1 - x2));
		printf("%.15f\n",ans);
	}
	return 0;
}
