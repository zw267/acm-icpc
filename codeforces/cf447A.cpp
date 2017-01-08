#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 310;

int mod[MAXN];

int main()
{
	int p,n;
	int res = -1;
	cin >> p >> n;
	memset(mod,0,sizeof mod);
	for(int i=1;i<=n;i++){
		int tmp;
		cin >> tmp;
		tmp %= p;
		if(mod[tmp] == 1 && res == -1)
			res =i;
		else
			mod[tmp]++;
	}

	cout << res << endl;
	return 0;
}
