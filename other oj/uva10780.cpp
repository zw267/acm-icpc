#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int INF = 0x3f3f3f3f;

void fact(map<int,int> & res,int n)
{
	for(int i=2;i * i <= n;i++){
		while(n % i == 0){
			res[i]++;
			n /= i;
		}
	}
	if(n != 1)
		res[n]++;
}

void solve(int m,int n)
{
	map<int,int> mn;
	for(int i=2;i<=n;i++){
		fact(mn,i);
	}
	map<int,int> mm;
	map<int,int>::iterator it;
	fact(mm,m);

	int res = INF;
	for(it=mm.begin();it != mm.end();it++){
		int tmp = mn[it->first] / it->second;
		//printf("%d %d\n",it->first,tmp);
		res = tmp < res ? tmp: res;
	}
	if(!res)
		puts("Impossible to divide");
	else
		printf("%d\n",res);
}

int main()
{
	int test;
	int cas = 1;
	scanf("%d",&test);
	while(test--){
		printf("Case %d:\n",cas++);
		int m,n;
		scanf("%d %d",&m,&n);
		solve(m,n);
	}
	return 0;
}
