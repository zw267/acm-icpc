#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <math.h>

#define pb push_back

using namespace std;

const int MAXN = 100000+10;

vector< pair<int,int> > ans;
int a[MAXN];
vector<int>dive[MAXN];

void init()
{
	for(int i=1;i<MAXN;i++){
		dive[i].clear();
		int e = sqrt(i+0.0);
		for(int j=1;j<=e;j++){
			if(i%j == 0){
				dive[i].pb(j);
				if(i/j != j)
					dive[i].pb(i/j);
			}
		}		
	}
}

bool judge(int n,int res,int s,int t)
{
	int flag = 0, pos = 0;
	int s_res = 0,s_oth = 0,t_res = 0,t_oth = 0;
	int i = 1;
	while(i<=n){
		if(a[i] == res){
			t_res++;
			if(t_res == t){
				s_res++;
				t_res = t_oth = 0;
				if(s_res == s){
					flag = res;
					pos = i;
					break;
				}
			}
		}
		else{
			t_oth++;
			if(t_oth == t){
				s_oth++;
				t_res = t_oth = 0;
				if(s_oth == s){
					flag = res == 1? 2:1;
					pos = i;
					break;
				}
			}
		}
		i++;
	}

	if(flag == res && pos == n)
		return true;
	return false;
}

void solve(int n)
{
	ans.clear();
	int res = a[n];
	int other = res==1 ? 2 : 1;
	int num_res = 0,num_oth = 0;
	for(int i=1;i<=n;i++){
		if(a[i] == res)
			num_res++;
		else
			num_oth++;
	}

	if(num_res <= num_oth)
		;
	else{
		for(int i=0;i<dive[num_res].size();i++){
			if(judge(n,res,dive[num_res][i],num_res/dive[num_res][i])){
				ans.pb(make_pair(dive[num_res][i],num_res/dive[num_res][i]));
			}
		}
	}

	sort(ans.begin(),ans.end());

	printf("%d\n",(int)ans.size());
	for(int i=0;i<ans.size();i++){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return ;
}

int main()
{
	init();
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	solve(n);

	return 0;
}
