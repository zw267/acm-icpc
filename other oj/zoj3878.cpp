                                            
  //File Name: zoj3878.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月05日 星期六 15时12分02秒


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

char s[] = {"-=_+qwertyuiop[]QWERTYUIOP{}asdfghjkl;'ASDFGHJKL:\"zxcvbnm,./ZXCVBNM<>?"};  
char t[] = {"[]{}',.pyfgcrl/=\"<>PYFGCRL?+aoeuidhtns-AOEUIDHTNS_;qjkxbmwvz:QJKXBMWVZ"}; 

char str[3];

char solve()
{
	int len = strlen(s);
	for(int i=0;i<len;i++){
		if(str[0] == s[i])
			return t[i];
	}
	return str[0];
}

int main()
{
	while(~scanf("%c",&str[0])){
		printf("%c",solve());
	}
	return 0;
}

