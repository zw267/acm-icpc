                                            
  //File Name: B.cpp
  //Created Time: 2017年03月22日 星期三 16时04分55秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int P = (int)1e9 + 7;
int main(){
	int l,r;
	scanf("%d %d",&l,&r);
	LL ans = 1;
	if(l + r != 0 || r % 2) 
		ans = 0;
	else{
		while(r){
			ans = ans * 2 * (r - 1) % P;
			r -= 2;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
