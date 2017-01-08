                                            
  //File Name: nod1435.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年06月13日 星期一 17时11分48秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

int ans[70],tot;
char str[15];

void get(int x){
	if(x == 2)
		ans[tot++] = 2;
	else if(x == 3)
		ans[tot++] = 3;
	else if(x == 4){
		get(2),get(2),get(3);
	}
	else if(x == 5){
		ans[tot++] = 5;
	}
	else if(x == 6){
		get(3),get(5);
	}
	else if(x == 7){
		ans[tot++] = 7;
	}
	else if(x == 8){
		get(7),get(2),get(2),get(2);
	}
	else if(x == 9){
		get(7),get(3),get(3),get(2);
	}
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		scanf("%s",str);
		tot = 0;
		for(int i=0,u;i<n;i++){
			u = str[i] - '0';
			get(u);
		}
		sort(ans,ans+tot);
		for(int i=tot-1;i>0;i--)
			printf("%d",ans[i]);
		printf("%d\n",ans[0]);
	}
	return 0;
}
