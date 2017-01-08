                                            
  //File Name: bc69B.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月23日 星期六 19时12分50秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

char str[12];
int num[10];

bool get(int year)
{
	if(year % 400 == 0)
		return true;
	if(year % 4 == 0 && year % 100 != 0)
		return true;
	return false;
}

bool solve()
{
	if(str[6] == str[7] && str[6] == str[8] && str[6] == str[9]
			&& str[6] == str[10])
		return true;
	for(int i=6;i<11;i++)
		num[i] = str[i] - '0';
	
	bool flag = true;
	for(int i=6;i<10;i++){
		if(num[i] - num[i+1] != 1)
			flag = false;
	}
	if(flag)
		return true;

	flag = true;
	for(int i=6;i<10;i++){
		if(num[i] - num[i+1] != -1)
			flag = false;
	}

	if(flag)
		return true;

	int year = 0;
	int mon = 0;
	int day = 0;
	for(int i=3;i<7;i++){
		year = year * 10 + (str[i] - '0');
	}
	for(int i=7;i<9;i++){
		mon = mon * 10 + (str[i] - '0');
	}

	for(int i=9;i<11;i++){
		day = day * 10 + (str[i] - '0');
	}

	if(year <1980 || year > 2016)
		return false;
	if(mon < 1 || mon > 12)
		return false;

	if(day < 1 || day > 31)
		return false;
	if(mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8
			|| mon == 10 || mon == 12){
		if(1 <= day && day <= 31)
			return true;
		else
			return false;
	}

	if(mon == 4 || mon == 6 || mon == 9 || mon == 11){
		if(1 <= day && day <= 30)
			return true;
		else
			return false;
	}

	if(get(year)){
		if(day <= 29)
			return true;
		else
			return false;
	}
	else{
		if(day <= 28)
			return true;
		else
			return false;
	}
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		int n;
		LL a,b;
		cin >> n >> a >> b;
		LL res = 0;
		for(int i=0;i<n;i++){
			scanf("%s",str);
			if(solve())
				res += a;
			else
				res += b;
		}
		cout << res << endl;
	}
	return 0;
}
