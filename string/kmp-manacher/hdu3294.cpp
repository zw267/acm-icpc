                                            
  //File Name: hdu3294.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月27日 星期三 14时16分56秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 200000 + 2;

char str[MAXN];
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
		mp[i] = mx > i ? min(mx - i,mp[2 * id - i]):1;
		while(ma[i+mp[i]] == ma[i - mp[i]])
			mp[i]++;
		if(i + mp[i] > mx){
			mx = i + mp[i];
			id = i;
		}
	}
}

void update(int l,int r,int &ansl,int &ansr){
	l = (l - 1) / 2;
	r = r / 2 * 2;
	r = (r - 2) / 2;
	if(r - l > ansr - ansl){
		ansl = l;
		ansr = r;
	}
}

void solve(char base){
	int cnt = base - 'a';
	int n = strlen(str);
	for(int i=0;i<n;i++){
		str[i] = str[i] - cnt;
		if(str[i] < 'a')
			str[i] += 26;
	}
	manacher(str);
	int len = n * 2 + 2;
	int ansl = 0,ansr = 0,l,r;
	for(int i=1;i<len;i++){
		l = i - mp[i] + 1;
		r = i + mp[i] - 1;
		update(l,r,ansl,ansr);
	}
	if(ansr - ansl <= 0)
		puts("No solution!");
	else{
		printf("%d %d\n",ansl,ansr);
		for(int i=ansl;i<=ansr;i++)
			printf("%c",str[i]);
		puts("");
	}
	return ;
}

int main(){
	char base[3];
	while(~scanf("%s %s",base,str)){
		solve(base[0]);
	}
	return 0;
}

