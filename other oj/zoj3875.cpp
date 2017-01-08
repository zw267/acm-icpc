                                            
  //File Name: zoj3875.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月05日 星期六 12时56分59秒
                                   

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

#define fir first
#define sec second
#define pb push_back
#define mp make_pair

using namespace std;

const int MAXN = 105;

vector< pair<int,string> > s;
int a[3];
string ans[3];

int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		int sum = 0;
		scanf("%d %d %d",&a[0],&a[1],&a[2]);
		for(int j=0;j<3;j++){
			s.clear();
			string cur;
			int cnt;
			for(int i=0;i<a[j];i++){
				cin >> cur;
				scanf("%d",&cnt);
				s.pb(mp(cnt,cur));
			}
			sort(s.begin(),s.end());
			ans[j] = s[a[j]/2].sec;
			sum += s[a[j]/2].fir;
		}
		cout << sum << " " << ans[0] << " " << ans[1] << " " << ans[2] << endl;
	}
	return 0;
}
