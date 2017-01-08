                                            
  //File Name: cf616A.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月21日 星期四 16时46分53秒

/*

比较2个大数的大小，有前导0

*/
                                   

#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1e6+10;

char a[MAXN];
char b[MAXN];

void solve()
{
	//puts("eeeeeeeeeee");
	int i=0,j=0;
	while(a[i] == '0')
		i++;
	while(b[j] == '0')
		j++;
	int lena = strlen(a);
	int lenb = strlen(b);

	if(lena - i > lenb - j){
		puts(">");
	}
	else if(lena - i < lenb - j){
		puts("<");
	}
	else{
		//puts("eeeeeeeeeeee");
		while(i < lena && j < lenb && a[i] == b[j]){
			i++;
			j++;
		}
		if(i == lena || j == lenb){
			puts("=");
		}
		else {
			int tmpa = a[i] - '0';
			int tmpb = b[j] - '0';
			if(tmpa > tmpb)
				puts(">");
			else
				puts("<");
		}
	}
	return ;
}

int main()
{
	//puts("eeeeeeeee");
	scanf("%s",a);
	scanf("%s",b);
	solve();

	return 0;
}
