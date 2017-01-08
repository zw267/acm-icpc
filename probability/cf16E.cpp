                                            
  //File Name: cf16E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月23日 星期六 16时53分31秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>

#define LL long long

using namespace std;

const int MAXN = 18;

double f[MAXN][(1<<MAXN)];
double a[MAXN][MAXN];
vector<int> vt[MAXN];

void init_vt(const int n){
	int ma = 1 << n;
	for(int i=0;i<n;i++)
		vt[i].clear();
	for(int i=0,u,s;i<ma;i++){
		u = i,s = 0;
		while(u){
			if(u & 1) s++;
			u >>= 1;
		}
		vt[n-s].push_back(i);
	}
}

double solve(const int n){
	init_vt(n);
	memset(f,0,sizeof(f));
	f[0][(1<<n)-1] = 1.0;
	vector<int> tmp1,tmp2;
	for(int i=1;i<n;i++){
		int w = (n - i + 1) * (n - i) / 2;
		for(int jj=0,j;jj<vt[i].size();jj++){
			j = vt[i][jj];
			tmp1.clear(),tmp2.clear();
			for(int k=0;k<n;k++){
				if((j & (1 << k)))
					tmp1.push_back(k);
				else
					tmp2.push_back(k);
			}
			//printf("j = %d  1 = %d  0 = %d\n",j,tmp1.size(),tmp2.size());
			int u,v,ma1 = tmp1.size(),ma2 = tmp2.size();
			for(int kk=0,k;kk<ma1;kk++){
				k = tmp1[kk];
				for(int ll=0,l;ll<ma2;ll++){
					l = tmp2[ll];
					f[i][j] += f[i-1][j|(1<<l)] * a[k][l] / w;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		printf("%.8f",f[n-1][1<<i]);
		if(i < n - 1) printf(" ");
		else puts("");
	}
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%lf",&a[i][j]);
		solve(n);
	}
	return 0;
}
