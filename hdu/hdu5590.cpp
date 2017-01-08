                                            
  //File Name: hdu5590.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月11日 星期一 21时11分20秒
                                   


#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 105;

char s[MAXN];
char t[MAXN];

char get(char ch)
{
	if(ch == 'A')
		return 'U';
	if(ch == 'T')
		return 'A';
	if(ch == 'C')
		return 'G';
	if(ch == 'G')
		return 'C';
	return '#';
}

bool solve(int n)
{
	for(int i=0;i<n;i++){
		if(get(s[i]) == '#')
			return false;
		if(get(s[i]) != t[i])
			return false;
	}
	return true;
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		int n;
		scanf("%d",&n);
		scanf("%s",s);
		scanf("%s",t);
		if(solve(n))
			puts("YES");
		else
			puts("NO");
	}

	return 0;
}


