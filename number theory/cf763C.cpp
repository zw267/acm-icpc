                                            
  //File Name: cf763C.cpp
  //Created Time: 2017年02月22日 星期三 16时18分45秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 100000 + 5;
LL a[MAXN],b[MAXN];
LL qp(LL x,LL y,LL p){
	LL res = 1;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % p;
		x = x * x % p;
	}
	return res;
}
void solve(LL p,int n,LL sum,LL square_sum){
	if(n == p)
		puts("0 1");
	else if(n == 1)
		printf("%d 0\n",a[1]);
	else{
		sort(a + 1,a + n + 1);
		bool flag;
		for(int i=2;i<=n;++i){
			LL d = a[i] - a[1];
			LL b1 = (sum - (n - 1LL) * n / 2 % p * d % p + p) % p * qp(n,p-2,p) % p;
			LL ss = b1 * b1 % p * n % p + (n-1LL) * n * (2 * n - 1) / 6 % p * d % p * d % p + (n - 1LL) * n % p * b1 % p * d % p;
			ss %= p;
			if(ss != square_sum)
				continue;
			b[1] = b1;
			for(int i=2;i<=n;++i)
				b[i] = (b[i - 1] + d) % p;
			sort(b + 1,b + n + 1);
			flag = true;
			for(int i=1;i<=n;++i){
				if(b[i] != a[i]){
					flag = false;
					break;
				}
			}
			if(flag){
				cout << b1 << " " << d << endl;
				break;
			}
		}
		if(!flag)
			puts("-1");
	}
}
int main(){
	LL p;
	int n;
	cin >> p >> n;
	LL sum = 0,square_sum = 0;
	for(int i=1;i<=n;++i){
		cin >> a[i];
		(sum += a[i]) %= p;
		(square_sum += a[i] * a[i]) %= p;
	}
	solve(p,n,sum,square_sum);
	return 0;
}
