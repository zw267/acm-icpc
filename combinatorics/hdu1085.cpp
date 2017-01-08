                                            
  //File Name: hdu1085.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月19日 星期六 11时12分38秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

LL ans[8003];
LL c[8003];
int num[3];

void init(int N){
	memset(ans,0,sizeof ans);
	memset(c,0,sizeof c);
	for(int i=0;i<=num[0];i++){
		ans[i] = 1;
	}
	for(int ii=1,i;ii<=2;ii++){
		i = ii == 1 ? 2: 5;
		for(int j=0;j<=N;j++){
			for(int k=0;k*i+j<=N && k<=num[ii];k++){
				c[k*i+j] += ans[j];
			}
		}		
		for(int j=0;j<=N;j++){
			ans[j] = c[j];
			c[j] = 0;
		}
	}
	return ;
}

void solve(){
	int N = num[0] + num[1] * 2 + num[2] * 5;
	init(N);
	int res = 0;
	for(int i=1;i<=N+1;i++){
		if(ans[i] == 0){
			res = i;
			break;
		}
	}
	printf("%d\n",res);
	return ;
}

int main(){
	while(~scanf("%d %d %d",&num[0],&num[1],&num[2])){
		if(!num[0] && !num[1] && !num[2])
			break;
		solve();
	}
	return 0;
}
