                                            
  //File Name: cf268E.cpp
  //Created Time: 2017年02月28日 星期二 17时18分49秒
                                   
#include <bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;
const int MAXN = 50000 + 5;
double f[MAXN];
pii song[MAXN];
bool cmp(pii a,pii b){
	return a.fir * a.sec * (100 - b.sec) > b.fir * b.sec * (100 - a.sec);
}
double solve(int n){
	sort(song + 1,song + n + 1,cmp);
	f[0] = 0.0;
	double res = 0.0;
	for(int i=1;i<=n;++i){
		int l = song[i].fir;
		double p = song[i].sec * 1.0 / 100.0;
		res += l + (1.0 - p) * f[i - 1];
		f[i] = p * l + f[i - 1];
	}
	return res;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d %d",&song[i].fir,&song[i].sec);
	}
	printf("%.15f\n",solve(n));
	return 0;
}
