                                            
  //File Name: poj3260.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月28日 星期一 18时37分47秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#define fir first
#define sec second
#define mp make_pair

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 10000;

int f[MAXN * 2 + 5];
int deq[MAXN * 2 + 5];
int deqv[MAXN * 2 + 5];
int g[MAXN * 2 + 5];
int c[105];
int v[105];
pair<int,int> input[105];

void solve(int N,int T){
	for(int i=0;i<=T + MAXN;i++)
		f[i] = INF;
	f[0] = 0;
	for(int i=1;i<=N;i++){
		for(int x = 0;x < v[i];x++){
			int s = 0,t = 0;
			for(int j=0;j*v[i]+x <= T + MAXN;j++){
				int val = f[j*v[i]+x] - j;
				while(s < t && deqv[t - 1] >= val)
					t--;
				deqv[t] = val;
				deq[t++] = j;
				f[j*v[i]+x] = deqv[s] + j;
				if(deq[s] + c[i] == j)
					s++;
			}
		}
	}
	//while(1){
	//	int u;
	//	scanf("%d",&u);
	//	cout << f[u] << endl;
	//}
	for(int i=0;i<=T + MAXN;i++)
		g[i] = INF;
	g[0] = 0;
	for(int i=1;i<=N;i++){
		for(int j=v[i];j<=T + MAXN;j++){
			g[j] = min(g[j],g[j-v[i]] + 1);
		}
	}
	
	int ans = INF;
	for(int i=T;i<=T + MAXN;i++){
		ans = min(ans,f[i] + g[i-T]);
	}
	if(ans >= INF)
		puts("-1");
	else
		printf("%d\n",ans);
	return ;
}

int main(){
	int N,T;
	while(~scanf("%d %d",&N,&T)){
		for(int i=1;i<=N;i++){
			scanf("%d",&input[i].fir);
		}
		for(int i=1;i<=N;i++){
			scanf("%d",&input[i].sec);
		}
		sort(input+1,input+N+1);
		for(int i=1;i<=N;i++){
			v[i] = input[i].fir;
			c[i] = input[i].sec;
		}
		solve(N,T);
	}
	return 0;
}
