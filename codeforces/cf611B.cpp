                                            
  //File Name: cf611B.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月14日 星期四 20时46分36秒
                            

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

int a[100];
LL dp[100][2];

bool is(int pos)
{
	for(int i=pos;i>0;i--){
		if(a[i] == 0)
			return false;
	}
	return true;
}

LL dfs(int pos,int all,bool limit)
{
	if(!limit && dp[pos][all] != -1)
		return dp[pos][all];
	if(pos == 0){
		return all ? 1 : 0;
	}

	int ma = limit?a[pos]:1;
	LL res = 0;
	for(int i=0;i<=ma;i++){
		if(i == 0){
			if(all){
				res += dfs(pos-1,all,i == ma && limit);
			}
			else{
				if(!(limit && i == ma))
					res++;
				else if(limit && is(pos-1))
					res++;
			}
		}
		else{
			res += dfs(pos-1,0,i==ma && limit);
		}
	}

	return limit ? res : dp[pos][all] = res;
}

LL solve(LL n)
{
	if(n == 0)
		return 1;
	int len = 0;
	while(n){
		a[++len] = n % 2;
		n >>= 1;
	}

	return dfs(len,1,true);
}

int main()
{
	memset(dp,-1,sizeof dp);
	LL l,r;
	cin >> l >> r;
	cout << solve(r) - solve(l - 1)<< endl;
	return 0;
}
