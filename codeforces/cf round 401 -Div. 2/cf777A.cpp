                                            
  //File Name: cf777A.cpp
  //Created Time: 2017年03月23日 星期四 19时27分46秒
                                   
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,x;
	scanf("%d %d",&n,&x);
	n %= 6;
	int a[3] = {0,1,2};
	for(int i=1;i<=n;++i){
		if(i & 1) swap(a[0],a[1]);
		else swap(a[1],a[2]);
	}
//	printf("%d %d %d\n",a[0],a[1],a[2]);
	printf("%d\n",a[x]);
	return 0;
}
