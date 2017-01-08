#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 100000+10;

bool pos[MAXN];
int len[MAXN];

void solve()
{
	int n;
	scanf("%d",&n);
	memset(pos,false,sizeof pos);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		if(pos[a - 1]){
			len[a] = len[a-1] + 1;
		}
		else{
			len[a] = 1;
		}
		pos[a] = true;
	}

	int ma = -1;
	for(int i=1;i<=n;i++){
		if(len[i] > ma)
			ma = len[i];
	}

	printf("%d\n",n - ma);
	return ;
}

int main()
{
	solve();
	return 0;
}
