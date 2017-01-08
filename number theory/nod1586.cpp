                                            
  //File Name: nod1586.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月19日 星期二 21时49分29秒
                                   

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <cctype>

#define LL long long

using namespace std;

const int MAXN = 1000000 + 3;
const int SIZE = 1<<16;

char buffer[SIZE],*head,*tail;

LL scan(){
	LL res = 0,ch,flag = 0;
	if((ch=getchar()) == '-')
		flag = 1;
	else if(ch >= '0' && ch <= '9')
		res = ch - '0';
	while((ch=getchar()) >= '0' && ch <= '9')
		res = res * 10 + ch - '0';
	return flag?-res:res;
}

void print(LL x){
	if(x > 9)
		print(x / 10);
	putchar(x % 10 + '0');
}

LL a[MAXN],c[MAXN],g[MAXN];

void init(){
	memset(g,0,sizeof g);
	for(int i=1;i<MAXN;i++){
		for(int j=i;j<MAXN;j+=i)
			g[j]++;
	}
}

void solve(int n,int q){
	memset(a,0,sizeof a);
	int t,x,y;
	for(int i=1;i<=q;i++){
		t = scan();
		x = scan();
		//scanf("%d %d",&t,&x);
		if(t == 2){
			print(c[x]);
			puts("");
		}
		else{
			y = scan();
			//scanf("%d",&y);
			for(int j=x;j<MAXN;j+=x)
				c[j] += g[j/x] * y;
		}
	}
}

int main(){
	init();
	int n,q;
	n = scan();
	q = scan();
	//scanf("%d %d",&n,&q);
	solve(n,q);
	return 0;
}

