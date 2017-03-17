                                            
  //File Name: hdu1237.cpp
  //Created Time: 2017年03月17日 星期五 22时56分53秒
                                   
#include <bits/stdc++.h>
using namespace std;
#define LL long long
stack<double> num;
int main(){
	int n;
	while(~scanf("%d",&n)){
		char c = getchar();
		if(n == 0 && c == '\n')
			break;
		num.push(n);
		c = getchar();
		while(scanf("%d",&n)){
			double m;
			if(c == '*'){
				m = num.top();
				num.pop();
				m = m * n;
				num.push(m);
			}
			else if(c == '/'){
				m = num.top();
				num.pop();
				m = m / n;
				num.push(m);
			}
			else if(c == '+'){
				num.push(n);
			}
			else{
				num.push(-n);
			}
			c = getchar();
			if(c == '\n')
				break;
			c = getchar();
		}
		double ans = 0;
		while(!num.empty()){
			ans += num.top();
//			printf("%.f\n",num.top());
			num.pop();
		}
		printf("%.2f\n",ans);
	}
	return 0;
}
