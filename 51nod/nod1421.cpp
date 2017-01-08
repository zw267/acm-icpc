                                            
  //File Name: nod1421.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月14日 星期四 17时04分29秒
                                   

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

const int MAXN = 1000000 + 1;

int num[MAXN << 1],pre[MAXN << 1];

int solve(int ma){
	ma <<= 1;  
	int ans = 0;
	pre[1] = 0;
	for(int i=2;i<=ma;i++){
		if(num[i-1])
			pre[i] = i - 1;
		else
			pre[i] = pre[i-1];
	}
	for(int i=2;i<ma;i++){
		if(!num[i]) continue;
		for(int j=i;j<ma;j+=i){
			//if(pre[j+i] > j)
				ans = max(ans,pre[j+i] % i);
		}
	}
	return ans;
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		int ma = 1,u;
		memset(num,0,sizeof num);
		for(int i=1;i<=n;i++){
			scanf("%d",&u);
			num[u]++;
			if(u > ma) ma = u;
		}
		printf("%d\n",solve(ma));
	}
	return 0;
}
