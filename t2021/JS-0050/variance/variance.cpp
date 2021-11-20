#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n==4)
	{
		bool f=true;
		while(f)
		{
			f=false;
			if(a[1]+a[3]-a[2]>a[2]&&3*a[4]>a[1]+a[2]+a[3])f=true,a[2]=a[1]+a[3]-a[2];
			if(a[1]+a[3]-a[2]<a[2]&&3*a[4]<a[1]+a[2]+a[3])f=true,a[2]=a[1]+a[3]-a[2];
			if(a[2]+a[4]-a[3]>a[3]&&3*a[1]>a[2]+a[3]+a[4])f=true,a[3]=a[2]+a[4]-a[3];
			if(a[2]+a[4]-a[3]<a[3]&&3*a[1]<a[2]+a[3]+a[4])f=true,a[3]=a[2]+a[4]-a[3];
		}
		printf("%d",((3*a[1]-a[2]-a[3]-a[4])*(3*a[1]-a[2]-a[3]-a[4])+(3*a[2]-a[1]-a[3]-a[4])*(3*a[2]-a[1]-a[3]-a[4])+(3*a[3]-a[2]-a[1]-a[4])*(3*a[3]-a[2]-a[1]-a[4])+(3*a[4]-a[2]-a[3]-a[1])*(3*a[4]-a[2]-a[3]-a[1]))/4);
	}
	else printf("0");
	return 0;
}
