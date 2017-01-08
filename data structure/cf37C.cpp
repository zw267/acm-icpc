                                            
  //File Name: cf37C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月29日 星期二 21时01分46秒
                                   
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fir first
#define sec second
const int MAXN = 1003;
pii len[MAXN];
string ans[MAXN],tmp;
int tot,n,sum;
void dfs(int dep){
	if(tot == n || dep > len[tot].fir) return ;
	if(dep == len[tot].fir){
		ans[len[tot].sec] = tmp;
		sum++;
		tot++;
		return ;		
	}
	tmp += '0';
	dfs(dep + 1);
	int x = tmp.length();
	tmp[x-1] = '1';
	dfs(dep + 1);
	tmp.erase(--tmp.end());
}
int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> len[i].fir;
		len[i].sec = i;
	}
	sort(len,len+n);
	tot = sum = 0;
	tmp = "";
	dfs(0);
	if(sum < n)
		puts("NO");
	else{
		puts("YES");
		for(int i=0;i<n;i++)
			cout << ans[i] << endl;
	}
	return 0;
}
