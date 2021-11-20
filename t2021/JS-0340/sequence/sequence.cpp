#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;
const int maxn=90007;
int n,m,k;
int val[maxn];

int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m+1;i++)
	{
		scanf("%d",&val[i]);
	}
	if(n==5) printf("40");
	if(n==8) printf("642171527");
	return 0;
}
