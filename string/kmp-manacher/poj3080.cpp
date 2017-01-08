                                            
  //File Name: poj3080.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月28日 星期四 00时01分36秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define next Next

using namespace std;

const int MAXN = 60 + 2;

char str[10][MAXN];
char now[MAXN];
int next[MAXN];
char out[MAXN];

void kmp_pre(const char *x,int *next){
	int m = strlen(x);
	int i = 0;
	int j = -1;
	next[0] = -1;
	while(i < m){
		while(j != -1 && x[i] != x[j])
			j = next[j];
		next[++i] = ++j;
	}
}

bool kmp(const char *y,const char *x){
	int n = strlen(y);
	int m = strlen(x);
	int i = 0,j = 0;
	while(i < n){
		while(j != -1 && y[i] != x[j])
			j = next[j];
		i++;
		j++;
		if(j >= m){
			return true;
		}
	}
	return false;
}

void solve(int num){
	int ans = 0;
	for(int i=0;i<59;i++){
		int tot = 0;
		now[tot++] = str[0][i];
		now[tot++] = str[0][i+1];
		for(int j=i+2;j<60;j++){
			now[tot++] = str[0][j];
			now[tot] = '\0';
			kmp_pre(now,next);
			bool flag = true;
			for(int k=1;k<num;k++){
				if(!kmp(str[k],now)){
					flag = false;
					break;
				}
			}
			if(flag){
				int last = ans;
				if(j - i + 1 >= ans){	
					ans = j - i + 1;
					if(ans == last){
						int l = 0;
						while(l < ans && now[l] == out[l])
							l++;
						if(l == ans || now[l] > out[l])
							continue;
					}
					for(int k=0;k<ans;k++){
						out[k] = now[k];
					}
					out[ans] = '\0';
				}
			}
			else
				break;
		}
	}
	if(ans < 3)
		puts("no significant commonalities");
	else{
		for(int i=0;i<ans;i++)
			printf("%c",out[i]);
		puts("");
	}
	return ;
}

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int num;
		scanf("%d",&num);
		for(int i=0;i<num;i++){
			scanf("%s",str[i]);
		}
		solve(num);
	}
	return 0;
}
