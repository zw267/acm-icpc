                                            
  //File Name: A.cpp
  //Created Time: 2017年03月22日 星期三 12时07分59秒
                                   
#include <bits/stdc++.h>
using namespace std;
int main(){
	int x,d;
	scanf("%d %d",&x,&d);
	if(d >= 0) printf("%d\n",2 * x + d - 1);
	else printf("%d\n",2 * x - 2);
	return 0;
}
