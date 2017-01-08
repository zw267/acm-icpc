                                            
  //File Name: 1.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月02日 星期三 14时56分05秒
                                   
#include <iostream>
using namespace std;
int main(){
	int res = 0;
	for(int i=3;i<1000;i++){
		if(i % 3 ==0 || i % 5 == 0)
			res += i;
	}
	cout << res << endl;
	return 0;
}
