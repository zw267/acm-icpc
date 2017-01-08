                                            
  //File Name: 2.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月02日 星期三 15时03分11秒
                                   
#include <iostream>
#define LL long long
using namespace std;
int main(){
	int ma = 4000000;
	int pre = 1,now = 1,tmp;
	LL res = 0;
	while(1){
		tmp = now;
		now = pre + now;
		pre = tmp;
		if(now > ma) break;
		if(!(now & 1))
		   res += now;	
	}
	cout << res << endl;
	return 0;
}
