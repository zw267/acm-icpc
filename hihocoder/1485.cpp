                                            
  //File Name: 1485.cpp
  //Created Time: 2017年04月01日 星期六 19时04分28秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 100000 + 5;
char str[MAXN];
int a[MAXN];
int num[3][3];
vector<int> pos[3];
void cal(int x,int l){
	int p = lower_bound(pos[x].begin(),pos[x].end(),l) - pos[x].begin();
	for(int i=0;i<3;++i)
		num[x][i] = pos[x][p - 1 + i];
//	printf("l = %d p = %d\n",l,p);
//	for(int i=0;i<3;++i)
//		printf("%d %d %d\n",num[x][0],num[x][1],num[x][2]);
}
void update(int &ansl,int &ansr,int l,int r,int n){
	if(l < 1 || r > n) return ;
	if(ansl == -1 || r - l < ansr - ansl)
		ansl = l,ansr = r;
}
int solve(){
	int ansl = -1,ansr = -1;
	int n = strlen(str + 1);
	for(int i=1;i<=n;++i){
		if(str[i] == 'h')
			a[i] = 0;
		else if(str[i] == 'i')
			a[i] = 1;
		else if(str[i] == 'o')
			a[i] = 2;
		else
			a[i] = 3;
	}
	for(int i=0;i<3;++i)
		pos[i].push_back(0);
	for(int i=1;i<=n;++i){
		if(a[i] < 3)
			pos[a[i]].push_back(i);
	}
	for(int i=0;i<3;++i){
		pos[i].push_back(n + 1);
		pos[i].push_back(n + 2);
	}
	if(pos[0].size() < 5) return -1;
	for(int i=2;i<pos[0].size();++i){
		int r = pos[0][i],l = pos[0][i - 1];
		if(r > n) break;
		cal(1,l);
		cal(2,l);
		if(r > num[1][2] || r > num[2][2]) 
			continue;
		if(r > num[1][1] && r > num[2][1]){
			update(ansl,ansr,l,r,n);
		}
		else if(r > num[1][1]){
			if(num[2][0] > num[1][0]) 
				update(ansl,ansr,num[2][0],r,n);
			if(num[2][2] < num[1][2])
				update(ansl,ansr,l,num[2][2],n);
		}
		else if(r > num[2][1]){
			if(num[1][0] > num[2][0])
				update(ansl,ansr,num[1][0],r,n);
			if(num[1][2] < num[2][2])
				update(ansl,ansr,l,num[1][2],n);
		}
		else{
			update(ansl,ansr,min(num[1][0],num[2][0]),r,n);
			update(ansl,ansr,l,max(num[1][1],num[2][1]),n);
			update(ansl,ansr,num[1][0],num[2][1],n);
			update(ansl,ansr,num[2][0],num[1][1],n);
		}
	}
	if(ansl == -1) return -1;
	return ansr - ansl + 1;
}
int main(){
	scanf("%s",str + 1);
	printf("%d\n",solve());
	return 0;
}
