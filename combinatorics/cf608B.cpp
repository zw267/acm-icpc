                                            
  //File Name: cf608B.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月12日 星期五 20时43分21秒
                                   

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define LL long long

using namespace std;

const int MAXN = 200000+5;

char a[MAXN];
char b[MAXN];
int len_a,len_b;

int num[2][MAXN];

void solve()
{
	len_a = strlen(a);
	len_b = strlen(b);
	num[0][0] = num[1][0] = 0;
	for(int i=1;i<=len_a;i++){
		num[0][i] = num[0][i-1];
		num[1][i] = num[1][i-1];
		int cur = a[i-1] - '0';
		num[cur][i]++;
	}
	//for(int i=0;i<=len_a;i++){
	//	printf("%d %d\n",num[0][i],num[1][i]);
	//}
	LL ans = 0;
	int l,r,cur;
	for(int i=1;i<=len_b;i++){
		if(len_b-i+1 >= len_a)
			l = 1;
		else
			l = len_a+i-len_b;
		r = min(i,len_a);
		if(b[i-1] == '1')
			cur = 0;
		else
			cur = 1;
		ans += (LL)num[cur][r] - num[cur][l-1];
		//printf("%d %d %d\n",l,r,ans);
	}
	cout << ans << endl;
	return ;
}

int main()
{
	scanf("%s",a);
	scanf("%s",b);
	solve();
	return 0;
}
