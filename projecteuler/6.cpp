                                            
  //File Name: 6.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月02日 星期三 15时13分44秒
                                   
#include <iostream>
#define LL long long
using namespace std;
int main(){
	LL res = 0;
	for(int i=1;i<=100;i++)
		res += i * i;
	int ma = 101 * 100 / 2;
	res = ma * ma - res;
	cout << res << endl;
	return 0;
}
