                                            
  //File Name: A.cpp
  //Created Time: 2017年03月22日 星期三 15时42分51秒
                                   
#include <bits/stdc++.h>
using namespace std;
int l[3][2];
bool solve1(int n){
	if(l[0][0] == l[0][1]) return true;
	return false;
}
bool solve2(int l1,int r1,int l2,int r2){
	if(l1 > r1) swap(l1,r1);
	if(l2 > r2) swap(l2,r2);
	if(l2 == r1 && r2 + l1 == r1) return true;
	if(r2 == r1 && l2 + l1 == r1) return true;
	return false;
}
bool solve22(int n){
	return solve2(l[0][0],l[0][1],l[1][0],l[1][1]);
}
bool solve3(int n){
	for(int i=0;i<n;++i){
		int a[2] = {-1,-1};
		for(int j=0;j<n;++j){
			if(j == i) continue;
			if(a[0] == -1) a[0] = j;
			else a[1] = j;
		}
		int L,R;
		for(int j=0;j<2;++j){
			for(int k=0;k<2;++k){
				if(l[a[0]][j] == l[a[1]][k]){
					L = l[a[0]][j];
					R = l[a[0]][!j] + l[a[1]][!k];
					if(solve2(R,L,l[i][0],l[i][1]))
						return true;
				}
			}
		}
	}
	return false;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d %d",&l[i][0],&l[i][1]);
	bool can;
	if(n == 1) can = solve1(1);
	else if(n == 2) can = solve22(2);
	else can = solve3(3);
	if(can) puts("yes");
	else puts("no");
	return 0;
}
