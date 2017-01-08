                                            
  //File Name: cf364A.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月13日 星期六 15时19分05秒
                                   

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

#define LL long long

using namespace std;

const int MAXN = 4005;

char str[MAXN];
int s[MAXN];
int sum[MAXN];
LL num[40000];

void solve(int a)
{
	int n = strlen(str);
	for(int i=1;i<=n;i++){
		s[i] = str[i-1] - '0';
	}
	sum[0] = 0;
	for(int i=1;i<=n;i++){
		sum[i] = sum[i-1] + s[i];
	}
	memset(num,0,sizeof num);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			num[sum[j]-sum[i-1]]++;
		}
	}
	//cout << num[0] << endl;
	LL ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int cur = sum[j] - sum[i-1];
			if(cur == 0){
				if(a > 0)
					continue;
				else
					ans += n * (n + 1) / 2;
			}
			else{
				if(a % cur)
					continue;
				else{
					cur = a / cur;
					if(cur < 40000)
						ans += num[cur];
				}
			}
		}
	}
	cout << ans << endl;
	return ;
}

int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",str);
	solve(a);
	return 0;
}
