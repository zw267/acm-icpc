                                            
  //File Name: cf653A.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月19日 星期六 16时52分57秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int has[1005];

int main(){
	int n;
	scanf("%d",&n);
	int c;
	memset(has,0,sizeof has);
	for(int i=1;i<=n;i++){
		scanf("%d",&c);
		has[c] = 1;
	}
	bool ans = false;
	for(int i=1;i<1000;i++){
		if(has[i] && has[i+1] && has[i+2])
			ans = true;
	}
	if(ans)
		puts("YES");
	else
		puts("NO");
	return 0;
}
