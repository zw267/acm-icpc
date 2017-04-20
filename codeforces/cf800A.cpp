                                            
  //File Name: cf800A.cpp
  //Created Time: 2017年04月20日 星期四 22时24分42秒
                                   
#include <bits/stdc++.h>
#define LL long long
#define pdd pair<double,double>
#define fir first
#define sec second
using namespace std;
const int MAXN = 100000 + 5;
LL a[MAXN],b[MAXN];
priority_queue<pdd> que;
map<double,double> rem;
double solve(int n,double p){
	double cur = MAXN,sum = 0;
	LL a_sum = 0;
	for(int i=0;i<n;++i){
		a_sum += a[i];
		double u = (double)b[i] / a[i];
		cur = min(u,cur);
		rem[u] += a[i];
	}
	if(p >= a_sum) return -1;
	sum = cur * p;
	for(auto u:rem){
		que.push(pdd(-u.fir,u.sec));
//		printf("%.5f %.5f\n",u.fir,u.sec);
	}
	while(!que.empty()){
		pdd u = que.top();
		que.pop();
		double ut = -u.fir;
		double uw = u.sec;
		if(que.empty()){
			cur += sum / (uw - p);
			break;
		}
		pdd v = que.top();
		que.pop();
		double vt = -v.fir;
		double vw = v.sec;
		sum += (vt - cur) * p;
		double need = (vt - cur) * uw;
		if(sum < need){
			sum -= (vt - cur) * p;
			cur += sum / (uw - p);
			break;
		}
		else{
			cur = vt;
			sum -= need;
			v.sec += uw;
			que.push(v);
		}
	}
	return cur;
}
int main(){
	int n;
	double p;
	scanf("%d %lf",&n,&p);
	for(int i=0;i<n;++i){
		scanf("%lld %lld",a + i,b + i);
	}
	double ans = solve(n,p);
	if(ans == -1) puts("-1");
	else printf("%.14f\n",ans);
	return 0;
}
