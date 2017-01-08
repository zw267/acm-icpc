                                            
  //File Name: uva12299.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月15日 星期五 15时38分11秒
                                   


#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

const int MAXN = 100000+5;
const int INF = 0x3f3f3f3f;

int mi[MAXN << 2];
char str[40];
int arr[40];
int val[MAXN];

void pushup(int rt)
{
	mi[rt] = min(mi[rt<<1],mi[rt<<1|1]);
}

void build(int l,int r,int rt)
{
	if(l == r){
		mi[rt] = val[l];
		return ;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	pushup(rt);
}

int get()
{
	int len = 0;
	int sum  = 0;
	int tot = strlen(str);
	for(int i=6;i<tot;i++){
		int tmp = str[i] - '0';
		//printf("%d\n",tmp);
		if(0 <= tmp && tmp <= 9 ){
			sum = sum * 10 + tmp;
		}
		else{
			arr[++len] = sum;
			sum = 0;
		}
	}
	return len;
}

void update(int p,int add,int l,int r,int rt)
{
	if(l == r){
		mi[rt] = add;
		return ;
	}
	int m = (l+r) >> 1;
	if(p <= m)
		update(p,add,lson);
	else
		update(p,add,rson);
	pushup(rt);
}

int query(int L,int R,int l,int r,int rt)
{
	if(L <= l && R >= r)
		return mi[rt];
	int m = (l + r) >> 1;
	int res = INF;
	if(L <= m)
		res = min(res, query(L,R,lson));
	if(R > m)
		res = min(res,query(L,R,rson));
	return res;
}

void solve(int n,int q)
{
	build(1,n,1);

	for(int i=0;i<q;i++){
		scanf("%s",str);
		int len = get();

		//for(int j=1;j<=len;j++){
		//	printf("%d  ",arr[j]);
		//}
		//puts("");

		if(str[0] == 'q'){
			printf("%d\n",query(arr[1],arr[len],1,n,1));
		}
		else{
			if(len <= 1)
				continue;
			int tmp = val[arr[1]];
			for(int j=1;j<len;j++){
				update(arr[j],val[arr[j+1]],1,n,1);
				val[arr[j]] = val[arr[j+1]];
			}
			update(arr[len],tmp,1,n,1);
			val[arr[len]] = tmp;
		}
	}
	return ;
}

int main()
{
	int n;
	while(~scanf("%d",&n)){
		int q;
		scanf("%d",&q);
		for(int i=1;i<=n;i++)
			scanf("%d",&val[i]);
		solve(n,q);
	}
	return 0;
}
