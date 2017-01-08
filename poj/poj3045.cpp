                                            
  //File Name: poj3045.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月25日 星期五 19时50分01秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

#define LL long long
#define fir first
#define sec second
#define mp make_pair

using namespace std;

const int MAXN = 50000 + 5;

pair<LL,LL> a[MAXN];

bool ok(int n,LL sum,LL x){
	int pre = 0;
	for(int i=n-1;i>=0;i--){
		if(a[i].fir + pre < sum - x)
			return false;
		pre += (int)a[i].sec;
	}
	return true;
}

void solve(int n,LL sum){
	sort(a,a+n);
	LL l = sum - a[n-1].fir - 1;
	LL r = sum;
	LL mid;
	while(r - l > 1){
		mid = (l + r) >> 1;
		if(ok(n,sum,mid))
			r = mid;
		else
			l = mid;
	}
	printf("%lld\n",r);
	return ;
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		LL sum = 0;
		for(int i=0,w,s;i<n;i++){
			scanf("%d %d",&w,&s);
			a[i] = mp(w + s, w);
			sum += w;
		}
		solve(n,sum);
	}
	return 0;
}
