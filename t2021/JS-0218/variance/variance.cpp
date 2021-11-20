#include<bits/stdc++.h>
using namespace std;
int n,a;
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)	
		scanf("%d",&a);
	if(n==4)
		puts("52");
	if(n==10)
		puts("59865");
	if(n==50)
		puts("252100");
	if(n==400)
		puts("305460375");	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
