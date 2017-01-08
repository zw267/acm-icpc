                                            
  //File Name: cf360A.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月26日 星期二 10时23分24秒
                                   

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>

#define LL long long

using namespace std;

const int MAXN = 5005;
const int INF = 0x3f3f3f3f;
struct Node
{
	int op, l,r;
	LL cur;
};
Node node[MAXN];
LL base[MAXN];
LL add[MAXN];

void update1(int l,int r,int d)
{
	for(int i=l;i<=r;i++){
		add[i] += d;
		base[i] += d;
	}
}

void update2(int l,int r,LL ma)
{
	for(int i=l;i<=r;i++)
		base[i] = min(base[i],ma);
	for(int i=l;i<=r;i++)
		add[i] = 0;
}

void solve(int n,int m)
{
	for(int i=1;i<=n;i++){
		add[i] = 0;
		base[i] = INF;
	}
	for(int i=m;i>0;i--){
		if(node[i].op == 1){
			update1(node[i].l,node[i].r,-node[i].cur);
		}
		else{
			update2(node[i].l,node[i].r,node[i].cur);
		}
	}
	for(int i=1;i<=n;i++){
		add[i] = 0;
	}
	bool flag = true;
	for(int i=1;i<=m;i++){
		if(node[i].op == 1){
			for(int j=node[i].l;j<=node[i].r;j++){
				add[j] += node[i].cur;
			}
		}
		else{
			LL ma = -INF;
			for(int j=node[i].l;j<=node[i].r;j++){
				ma = max(ma,base[j] + add[j]);
			}
			//for(int j=1;j<=n;j++)
			//	cout << base[j] + add[j] << " ";
			//cout << endl;
			if(ma != node[i].cur){
				flag = false;
				//break;
			}
		}
	}

	if(!flag)
		puts("NO");
	else{
		puts("YES");
		for(int i=1;i<n;i++)
			cout << base[i] << " ";
		cout << base[n] << endl;
	}
	return ;
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);

	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&node[i].op,&node[i].l,&node[i].r);
		cin >> node[i].cur;
	}

	solve(n,m);
	return 0;
}
