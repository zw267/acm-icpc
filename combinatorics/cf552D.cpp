                                            
  //File Name: cf552D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月08日 星期五 13时15分13秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 2001;

int x[MAXN],y[MAXN];

LL solve(int n){
	LL ans = 0;
	int i,j,k;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			for(k=j+1;k<n;k++){
				if(x[i] == x[j] && x[i] == x[k])
					continue;
				if((y[i] - y[j]) * (x[i] - x[k]) == (x[i] - x[j]) * (y[i] - y[k]))
					continue;
				ans++;
			}
		}
	}
	return ans;
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++)
			scanf("%d %d",&x[i],&y[i]);
		cout << solve(n) << endl;
	}
	return 0;
}
