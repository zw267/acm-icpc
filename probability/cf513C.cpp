                                            
  //File Name: cf513C.cpp
  //Created Time: 2017年02月27日 星期一 12时21分06秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
int l[5],r[5];
int cal(int L,int R){
	if(R < L) return 0;
	return R - L + 1;
}
double solve(int n,int mi,int ma){
	LL sum1 = 1,sum2 = 1;
	for(int i=0;i<min(3,n);++i)
		sum1 *= (r[i] - l[i] + 1);
	for(int i=3;i<n;++i)
		sum2 *= (r[i] - l[i] + 1);
//	printf("%lld %lld\n",sum1,sum2);
	double res = 0.0;
    for(int x=mi;x<=ma;++x){
		LL now = 0;
		int sec = -1,fir = -1;
		for(int i=0;i<n;++i){
			if(l[i] <= x && x <= r[i]){
				sec = i,fir = -1;
				for(int j=0;j<n;++j){
					if((j < sec && r[j] >= x) || (j > sec && r[j] > x)){
						fir = j;
						now = 1;
						if(j < sec)
							now *= cal(max(x,l[j]),r[j]);
						else
							now *= cal(max(x+1,l[j]),r[j]);
						for(int k=0;k<n;++k){
							if(k == sec || k == fir)
								continue;
							if(k < sec)
								now *= cal(l[k],min(x-1,r[k]));
							else
								now *= cal(l[k],min(x,r[k]));
						}
//						printf("x=%d sec=%d fir=%d now=%lld\n",x,sec,fir,now);
						double tmp = (double)now / sum1 / sum2;
						res += tmp * x;
					}
				}
			}
		}
	}
	return res;
}
int main(){
	int n,mi = 10000,ma = 0;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d %d",&l[i],&r[i]);
		if(l[i] < mi) mi = l[i];
		if(r[i] > ma) ma = r[i];
	}
	printf("%.14f\n",solve(n,mi,ma));
	return 0;
}
