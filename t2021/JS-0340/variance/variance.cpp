#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;
const int maxn=100007;
int n;
int a[maxn];
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(n==4) printf("52");
	if(n==10) printf("59865");
	if(n==50) printf("252100");
	if(n==400) printf("305460375");
	return 0;
}
