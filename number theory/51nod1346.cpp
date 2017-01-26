                                            
  //File Name: nod1346.cpp
  //Created Time: 2017年01月22日 星期日 13时01分06秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N1 = 101;
const int N2 = 131173;
int f[N1][N2],g[N2][N1];
int main(){
	for(int i=2;i<N2;++i)
		scanf("%d",&f[1][i]);
	for(int i=2;i<N2;++i)
		scanf("%d",&g[i][1]);
	for(int i=2;i<N1;++i){
		f[i][1] = g[i][1];
		g[1][i] = f[1][i];
	}
	for(int i=2;i<N1;++i){
		for(int j=2;j<N2;++j){
			f[i][j] = f[i-1][j] ^ f[i][j-1];
			g[j][i] = g[j-1][i] ^ g[j][i-1];
		}
	}
	int q,x,y;
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&x,&y);
		printf("%d\n",f[x][y + 131072] ^ g[x + 131072][y]);
	}
	return 0;
}
