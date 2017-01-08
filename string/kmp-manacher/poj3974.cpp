                                            
  //File Name: poj3974.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月27日 星期三 15时34分11秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 1000000 + 3;

char str[MAXN];
char ma[MAXN << 1];
int mp[MAXN << 1];

int manacher(const char *s){
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
		mp[i] = mx > i ? min(mx - i,mp[2 * id - i]) : 1;
		while(ma[i+mp[i]] == ma[i-mp[i]])
			mp[i]++;
		if(i + mp[i] > mx){
			mx = i + mp[i];
			id = i;
		}
	}
	int ans = 0;
	for(int i=0;i<l;i++){
		ans = max(ans,mp[i] - 1);
	}
	return ans;
}

int main(){
	int cas = 1;
	while(~scanf("%s",str)){
		if(str[0] == 'E')
			break;
		printf("Case %d: %d\n",cas++,manacher(str));
	}
	return 0;
}
