                                            
  //File Name: cf296B.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月16日 星期二 16时43分29秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>

#define LL long long

using namespace std;

const int MAXN = 1e5+5;
const int MOD = 1e9+7;

LL f[MAXN][4];
char s[MAXN];
char t[MAXN];

bool is(char ch)
{
	if(ch != '?')
		return true;
	return false;
}

void solve(int n)
{
	memset(f,0,sizeof f);
	f[0][3] = 1LL;
	for(int i=0;i<n;i++){
		char a = s[i+1], b = t[i+1];
		if(is(a) && is(b)){
			if(a == b){
				f[i+1][3] = f[i][3];
				f[i+1][0] = f[i][0];
				f[i+1][1] = f[i][1];
				f[i+1][2] = f[i][2];
			}
			else if(a < b){
				f[i+1][1] = (f[i][1] + f[i][3]) % MOD;
				f[i+1][2] = 0;
				f[i+1][3] = 0;
				f[i+1][0] = (f[i][0] + f[i][2]) % MOD;
			}
			else{
				f[i+1][1] = 0;
				f[i+1][2] = (f[i][2] + f[i][3]) % MOD;
				f[i+1][3] = 0;
				f[i+1][0] = (f[i][0] + f[i][1]) % MOD;
			}
		}
		else if(is(a) && !is(b)){
			int u = a - '0';
			f[i+1][3] = f[i][3];
			f[i+1][1] = (f[i][1] * (10 - u) % MOD + f[i][3] * (9 - u) % MOD) % MOD;
			f[i+1][2] = (f[i][2] * (u + 1) % MOD + f[i][3] * u % MOD) % MOD;
			f[i+1][0] = (f[i][0] * 10 % MOD  + f[i][1] * u % MOD + f[i][2] * (9 - u) % MOD) % MOD;
		}
		else if(!is(a) && is(b)){
			int u = b - '0';
			f[i+1][3] = f[i][3];
			f[i+1][1] = (f[i][1] * (u + 1) %  MOD + f[i][3] * u % MOD) % MOD;
			f[i+1][2] = (f[i][2] * (10 - u) + f[i][3] * (9 - u) % MOD) % MOD;
			f[i+1][0] = (f[i][0] * 10 % MOD + f[i][1] * (9 - u) % MOD + f[i][2] * u % MOD) % MOD;
		}
		else{
			f[i+1][3] = (f[i][3] * 10) % MOD;
			f[i+1][1] = (f[i][1] * 55 % MOD + f[i][3] * 45 % MOD) % MOD;
			f[i+1][2] = (f[i][2] * 55 % MOD + f[i][3] * 45 % MOD) % MOD;
			f[i+1][0] =(f[i][0] * 100 % MOD + f[i][1] * 45 % MOD + f[i][2] * 45 % MOD) % MOD;
		}
	}
	//printf("%d %d %d %d\n",(int)f[n][0],(int)f[n][1],(int)f[n][2],(int)f[n][3]);
	printf("%d\n",(int)f[n][0]);
	return ;
}

int main()
{
	int n;
	while(~scanf("%d",&n)){
		scanf("%s",s+1);
		scanf("%s",t+1);
		solve(n);
	}
	return 0;
}
