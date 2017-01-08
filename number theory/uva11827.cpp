                                            
  //File Name: uva11827.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月20日 星期日 19时04分28秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 104;
int a[MAXN];
int gcd(int x,int y){
	return (!y) ? x : gcd(y,x % y);
}
int main(){
	int t,n;
	scanf("%d",&t);
	while(getchar() != '\n') ;
	while(t--){
		char buf;
		int n = 0;
		while((buf = getchar()) != '\n'){
			if(buf >= '0' && buf <= '9'){
				ungetc(buf,stdin);
				scanf("%d",&a[n++]);
			}
		}
		int ans = 0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int tmp = gcd(a[i],a[j]);
				ans = max(ans,tmp);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
