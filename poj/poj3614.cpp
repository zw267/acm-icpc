                                            
  //File Name: poj3614.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月08日 星期五 14时57分03秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <queue>

#define rat first
#define num second

using namespace std;

const int MAXN = 2505;

pair<int,int> spf[MAXN];
struct Node
{
	int l,r;
	bool operator < (const Node & tmp) const {
		if(tmp.r == r)
			return tmp.l < l;
		return tmp.r < r;
	}
};
Node cow[MAXN];

bool cmp(Node x,Node y)
{
	if(x.l == y.l)
		return x.r < y.r;
	return x.l < y.l;
}

void solve(int C,int L)
{
	int res = 0;
	sort(cow+1,cow+C+1,cmp);
	sort(spf+1,spf+L+1);

	priority_queue<Node> que;
	while(!que.empty())
		que.pop();
	int pos = 1;
	for(int i=1;i<=L;i++){
		while(spf[i].num > 0 ){
			while(pos <= C && cow[pos].l <= spf[i].rat){
				if(cow[pos].r >= spf[i].rat){
					que.push(cow[pos++]);
				}
				else
					pos++;
			}
			//printf("%d\n",(int)que.size());

			while(!que.empty() && que.top().r < spf[i].rat){
				//Node gao = que.top();
				que.pop();
				//printf("%d %d\n",gao.l,gao.r);
			}
			if(que.empty()){
				//printf("%d\n",i);
				break;
			}
			res++;
			//Node he = que.top();
			que.pop();
			//printf("%d %d %d\n",spf[i].rat,he.l,he.r);
			spf[i].num--;
		}
	}

	printf("%d\n",res);
	return ;
}

int main()
{
	int C,L;
	while(~scanf("%d %d",&C,&L)){
		for(int i=1;i<=C;i++){
			scanf("%d %d",&cow[i].l,&cow[i].r);
		}
		for(int i=1;i<=L;i++){
			scanf("%d %d",&spf[i].rat,&spf[i].num);
		}
		solve(C,L);
	}
	return 0;
}
