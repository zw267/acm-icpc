#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 105;

int maze[MAXN][MAXN];
char str[MAXN];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

bool solve(int n)
{
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int tmp = 0;
			for(int k=0;k<4;k++)
				tmp += maze[i+dx[k]][j+dy[k]];
			if(tmp % 2)
				return false;
		}
	}
	return true;
}

int main()
{
	int n;
	scanf("%d",&n);
	memset(maze,0,sizeof maze);
	for(int i=1;i<=n;i++){
		scanf("%s",str);
		for(int j=1;j<=n;j++)
			if(str[j-1] == 'x')
				maze[i][j] = 0;
			else
				maze[i][j] = 1;
	}
	if(solve(n))
		puts("YES");
	else
		puts("NO");

	return 0;
}
