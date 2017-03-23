                                            
  //File Name: cf777D.cpp
  //Created Time: 2017年03月23日 星期四 18时12分49秒
                                   
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500000 + 5;
vector<string> a;
vector<int> len;
char str[MAXN];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%s",str);
		a.push_back((string)str);
		len.push_back(strlen(str));
	}
//	for(int i=0;i<n;++i){
//		string s = a[i];
//		cout << s << endl;
//	}
//	int ans = 0;
	for(int i=n-2;i>=0;--i){
		string s = a[i];
		string t = a[i + 1];
		for(int j=1;j<=max(len[i],len[i + 1]);++j){
			if(j < len[i] && j == len[i + 1]){
//				ans += (len[i] - j);
				len[i] = j;
				break;
			}
			else if(j < len[i] && j < len[i + 1] && s[j] != t[j]){
				if(s[j] < t[j]) break;
				else if(s[j] > t[j]){
//					ans += (len[i] - j);
					len[i] = j;
				}
			}
		}
	}
//	printf("ans = %d\n",ans);
	for(int i=0;i<n;++i){
		printf("#");
		string s = a[i];
		for(int j=1;j<len[i];++j)
			printf("%c",s[j]);
		puts("");
	}
	return 0;
}
