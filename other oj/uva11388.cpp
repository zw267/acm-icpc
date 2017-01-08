#include <cstring>
#include <cstdio>

#define LL long long 

using namespace std;

int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		LL g,l;
		scanf("%lld %lld",&g,&l);
		if(g > l || l % g != 0)
			puts("-1");
		else{
			printf("%lld %lld\n",g,l);
		}
	}
	return 0;
}
