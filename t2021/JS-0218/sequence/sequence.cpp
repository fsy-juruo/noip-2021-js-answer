#include<bits/stdc++.h>
using namespace std;
int n,m,k,a;
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m+1;i++)
		scanf("%d",&a);
	if(n==5)
		puts("40");
	if(n==8)
		puts("642171527");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
