#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 1e5+10;

int a[MAXN];

int solve(int n)
{
	int ans = 0;
	queue<int>que;
	while(!que.empty())
		que.pop();
	for(int i=1;i<=n;i++)
		que.push(a[i]);
	bool flag = true;
	while(flag){
		flag=false;
		int sum=que.size();
		int num = 0;
		int pre=que.front();
		que.pop();
		que.push(pre);
		for(int i=2;i<=sum;i++){
			int cnt=que.front();
			que.pop();
			if(pre>cnt){
				flag=true;
			}
			else
				que.push(cnt);
			pre = cnt;
		}
		if(flag)
			ans++;
	}
	return ans;	
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	printf("%d\n",solve(n));
	return 0;
}
