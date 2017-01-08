                                            
  //File Name: cf109B.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月24日 星期日 09时08分45秒
                                   

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>

#define LL long long

using namespace std;

vector<int> lucky;

void init(){
	lucky.clear();
	lucky.push_back(0);
	for(int i=0,l,r;i<9;i++){
		r = lucky.size() - 1;
		l = r + 1 - (1 << i);
		for(int j=l;j<=r;j++){
			lucky.push_back(lucky[j] * 10 + 4);
			lucky.push_back(lucky[j] * 10 + 7);
		}
	}
	lucky.push_back(1000000001);
	//for(int i=0;i<10;i++)
	//	printf("%d\n",lucky[i]);
	//printf("tot = %d\n",lucky.size());
	sort(lucky.begin(),lucky.end());
}

int get(int l1,int r1,int l2,int r2){
	if(r1 < l2 || l1 > r2) return 0;
	int l = max(l1,l2);
	int r = min(r1,r2);
	return r - l + 1;
}

double solve(int pl,int pr,int vl,int vr,int k){
	LL ans = 0;
	int L,R,ma = lucky.size() - k;
	for(int l=1,r;l<=ma;l++){
		r = l + k - 1;
		L = get(pl,pr,lucky[l-1]+1,lucky[l]);
		R = get(vl,vr,lucky[r],lucky[r+1]-1);
		ans += (LL)L * R;
		L = get(vl,vr,lucky[l-1]+1,lucky[l]);
		R = get(pl,pr,lucky[r],lucky[r+1]-1);
		ans += (LL)L * R;
	}
	if(k == 1){
		for(int i=1;i<lucky.size()-1;i++){
			if(lucky[i] <= pr && lucky[i] >= pl && lucky[i] <= vr 
					&& lucky[i] >= vl)
				ans--;
		}
	}
	LL ans1 = (pr - pl + 1LL) * (vr - vl + 1LL);
	return (ans + 0.0) / ans1;
}

int main(){
	init();
	int pl,pr,vl,vr,k;
	while(~scanf("%d %d %d %d %d",&pl,&pr,&vl,&vr,&k)){
		printf("%.12f\n",solve(pl,pr,vl,vr,k));
	}
	return 0;
}

