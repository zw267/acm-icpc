                                            
  //File Name: cf756A.cpp
  //Created Time: 2017年03月27日 星期一 13时08分29秒
                                   
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000 + 5;
int p[MAXN],b[MAXN];
int fa[MAXN];
int find_fa(int x){
	if(x == fa[x]) return x;
	return fa[x] = find_fa(fa[x]);
}
void Union(int x,int y){
	int fax = find_fa(x);
	int fay = find_fa(y);
	if(fax != fay)
		 fa[fay] = fax;
}
int solve(int n){
	for(int i=1;i<=n;++i)
		fa[i] = i;
	for(int i=1;i<=n;++i)
		Union(i,p[i]);
	int sum = 0;
	for(int i=1;i<=n;++i)
		if(find_fa(i) == i)
			++sum;
//	printf("sum = %d\n",sum);
	if(sum == 1) sum = 0;
	int add = 0;
	for(int i=1;i<=n;++i)
		add ^= b[i];
	return sum + (add == 0);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",p + i);
	for(int i=1;i<=n;++i)
		scanf("%d",b + i);
	printf("%d\n",solve(n));
	return 0;
}
