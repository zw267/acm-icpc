                                            
  //File Name: cf627A.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月29日 星期一 13时03分53秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

int s[50];
int x[50];
LL f[50][2];

void solve(LL ss,LL xx)
{
	LL init_s = ss;
	LL init_x = xx;
	int tot = 0;
	while(ss || xx){
		s[++tot] = ss % 2;
		ss /= 2;
		x[tot] = xx % 2;
		xx /= 2;
	}
	//for(int i=1;i<=tot;i++)
	//	cout << s[i] << " " << x[i] << endl;

	memset(f,0,sizeof f);
	f[0][0] = 1;
	for(int i=0;i<tot;i++){
		for(int j=0;j<2;j++){
			if(f[i][j] == 0)
				continue;
			if(x[i+1] == 1){
				if((j + 1) % 2 == s[i+1]){
					f[i+1][(j+1)/2] += f[i][j] * 2;
				}
			}
			else{
				if((j + 2) % 2 == s[i+1]){
					f[i+1][(j+2)/2] += f[i][j];
				}
				if(j % 2 == s[i+1]){
					f[i+1][j/2] += f[i][j];
				}
			}
		}
	}
	
	//for(int i=0;i<=tot;i++){
	//	for(int j=0;j<2;j++){
	//		cout << f[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	if(init_s == init_x)
		f[tot][0] -= 2;
	cout << f[tot][0] << endl;
	return ;
}

int main()
{
	LL ss,xx;
	cin >> ss >> xx;
	solve(ss,xx);
	return 0;
}
