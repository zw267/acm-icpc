                                            
  //File Name: cf118C.cpp
  //Created Time: 2017年01月16日 星期一 22时13分30秒
                                   
#include <bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;
const int MAXN = 10000 + 5;
int a[MAXN],tmp[MAXN];
pii b[MAXN];
char str[MAXN];
int num[10][10],sum[10];
int ans[MAXN];
void cal(const int n,int k,const int x){
	for(int i=1;i<=n;++i)
		b[i] = pii(abs(a[i] - x),-a[i]);
	sort(b+1,b+n+1);
	int p = 1;
	while(k--){
		sum[x] += b[p].fir;
		++num[x][-b[p].sec];
		++p;
	}
}
void update(const int n,const int x){
	for(int i=9;i>=0;--i){
		if(i == x)
			continue;
		int p = i > x ? 1 : n;
		while(num[x][i]){
			while(tmp[p] != i)
				p = i > x ? p + 1 : p - 1;
			tmp[p] = x;
			--num[x][i];
		}
	}
	bool flag = false;
	if(ans[1] == -1)
		flag = true;
	else{
		for(int i=1;i<=n;++i){
			if(ans[i] < tmp[i]){
				flag = false;
				break;
			}
			else if(ans[i] > tmp[i]){
				flag = true;
				break;
			}
		}
	}
	if(flag){
		for(int i=1;i<=n;++i)
			ans[i] = tmp[i];
	}
}
int solve(const int n,const int k){
	for(int i=1;i<=n;++i)
		a[i] = str[i] - '0';
	for(int i=0;i<10;++i)
		cal(n,k,i);
	ans[1] = -1;
	int res = (int)1e9;
	for(int i=0;i<10;++i)
		res = min(res,sum[i]);
	for(int i=0;i<10;++i){
		if(sum[i] == res){
			for(int j=1;j<=n;++j)
				tmp[j] = a[j];
			update(n,i);
		}
	}
	return res;
}
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	scanf("%s",str + 1);
	int res = solve(n,k);
	printf("%d\n",res);
	for(int i=1;i<=n;i++)
		printf("%d",ans[i]);
	puts("");
	return 0;
}
