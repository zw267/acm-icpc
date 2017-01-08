                                            
  //File Name: cf618B.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月04日 星期四 21时59分07秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int a[51][51];
int p[51];
int cnt[51];
bool vis[51];

int get(int n)
{
	int pos = n - 1;	
	while(true){
		if(cnt[pos] == n - pos && cnt[pos+1] == 0)
			break;
		else
			pos--;
	}
	if(vis[pos])
		return pos+1;
	//printf("%d\n",pos);
	return pos;
}

void solve(int n)
{
	memset(vis,false,sizeof vis);
	memset(p,-1,sizeof p);
	for(int i=1;i<=n;i++){
		memset(cnt,0,sizeof cnt);
		for(int j=1;j<=n;j++){
			cnt[a[i][j]]++;
		}
		p[i] = get(n);
		vis[p[i]] = true;
	}
	for(int i=1;i<n;i++)
		printf("%d ",p[i]);
	printf("%d\n",p[n]);
	return ;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	}
	solve(n);

	return 0;
}
