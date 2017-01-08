                                            
  //File Name: hdu3613.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月27日 星期三 16时40分16秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 500000 + 3;
const int INF = 0x3f3f3f3f;

char str[MAXN];
int val[26];
int pre[MAXN];
int suf[MAXN];
char ma[MAXN << 1];
int mp[MAXN << 1];

void manacher(const char *s){
	int len = strlen(s);
	int l = 0;
	ma[l++] = '$';
	ma[l++] = '#';
	for(int i=0;i<len;i++){
		ma[l++] = s[i];
		ma[l++] = '#';
	}
	ma[l] = 0;
	int mx = 0, id = 0;
	for(int i=0;i<l;i++){
		mp[i] = mx > i ? min(mx - i,mp[2 *id - i]) :1;
		while(ma[i+mp[i]] == ma[i-mp[i]])
			mp[i]++;
		if(i + mp[i] > mx){
			mx = i + mp[i];
			id = i;
		}
	}
}

void solve(){
	int n = strlen(str);
	pre[0] = val[str[0] - 'a'];
	for(int i=1;i<n;i++){
		pre[i] = pre[i - 1] + val[str[i] - 'a'];
	}
	suf[n] = 0;
	for(int i=n-1;i>=0;i--){
		suf[i] = suf[i + 1] + val[str[i] - 'a'];
	}
	manacher(str);
	int ans = -INF;
	for(int i=0,mid,l,r,now;i<n-1;i++){
		mid = (i + 1) * 2 + 1;
		l = (1 + mid) / 2;
		r = (mid + 2 * n + 1) / 2;
		now = 0;
		if(l + mp[l] - 1 == mid)
			now += pre[i];
		if(r - mp[r] + 1 == mid)
			now += suf[i + 1];
		if(now > ans)
			ans = now;
	}
	printf("%d\n",ans);
	return ;
}

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		for(int i=0;i<26;i++){
			scanf("%d",&val[i]);
		}
		scanf("%s",str);
		solve();
	}
	return 0;
}
