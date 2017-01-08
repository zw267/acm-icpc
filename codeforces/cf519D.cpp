#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <cstdlib>

#define LL long long
#define fir first
#define sec second

using namespace std;

int val[26];
LL sum[100000+5];
char str[100000+5];

map< pair<char,LL>,int > ms;
map< pair<char,LL>,int > :: iterator it;

void solve()
{
	for(int i=0;i<26;i++){
		scanf("%d",&val[i]);
	}
	scanf("%s",str);
	int len = strlen(str);

	ms.clear();
	LL res = 0;
	sum[0] = 0;

	for(int i=1;i<=len;i++){
		sum[i] = sum[i-1] + val[str[i-1] - 'a'];
	}
	
	pair<char,LL> pr;
	LL tmp;
	for(int i=1;i<=len;i++){
		pr = make_pair(str[i-1],sum[i]);
		it = ms.find(make_pair(pr.fir,pr.sec - val[pr.fir-'a']));
		if(it != ms.end())
			res += it->sec;
		ms[pr]++;
	}

	printf("%lld\n",res);
	//printf("%I64d\n",res);
	return ;
}

int main()
{
	solve();
	return 0;
}
