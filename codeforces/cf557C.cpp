#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#define hei first
#define d second

using namespace std;

const int MAXN = 100000+5;
const int INF = 0x3f3f3f3f;

pair<int,int> node[MAXN];
int num[MAXN];
int cost[205];
int sum[MAXN];

void solve()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&node[i].hei);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&node[i].d);
	}

	sort(node+1,node+n+1);

	int res = INF;
	memset(num,0,sizeof num);
	memset(cost,0,sizeof cost);

	for(int i=1;i<=n;i++){
		num[node[i].hei]++;
		sum[i] = node[i].d;
	}

	for(int i=n-1;i>0;i--)
		sum[i] += sum[i+1];

	//for(int i=1;i<=n;i++)
	//	printf("%d : %d\n",i,sum[i]);
	
	node[0] = make_pair(0,0);
	for(int i=1;i<=n;i++){
		if(node[i].hei == node[i-1].hei){
			cost[node[i].d]++;
			continue;
		}
		int tmp = sum[i+num[node[i].hei]];
		int cnt = i - num[node[i].hei];
		int pos = 1;
		while(pos <=200 && cnt > 0){
			if(cnt <= cost[pos]){
				tmp += pos * cnt;
				break;
			}
			else{
				cnt -= cost[pos];
				tmp += pos * cost[pos];
				pos++;
			}
		}
		cost[node[i].d]++;
		res = tmp < res ? tmp: res;
	}

	printf("%d\n",res);
	return ;
}

int main()
{
	solve();
	return 0;
}
