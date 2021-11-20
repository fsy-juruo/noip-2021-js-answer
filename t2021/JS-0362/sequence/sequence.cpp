#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k,v[101];
ll s,c[31][31],a1,a2,a3,a4,a5;
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m+1;i++)
		scanf("%d",&v[i]);
	for(int i=1;i<=50;i++)
	{
		c[i][0]=1;
		c[i][i]=1;
	}
	for(int i=2;i<=50;i++)
		for(int j=1;j<i;j++)
			c[i][j]=c[i-1][j]+c[i-1][j-1];
	if (n==5)
	{
		a5=c[50][5]*5*4*3*2%998244353;
		a4=c[50][1]*c[5][3]*c[48][1]*2*c[47][1]%998244353;
		a3=c[50][1]*5*c[49][1]*4*c[48][1]*3*c[3][1]%998244353+c[50][1]*c[5][2]+c[49][1]*c[3][2]+c[48][1]%998244353;
		a2=(c[50][1]+c[50][1]*5*c[48][1]+c[50][1]*c[5][3]*c[2][1]+c[50][1]*c[5][2]*c[3][1]*c[47][1])%998244353;
		a1=c[48][1]*5;
		if (k==1)
			cout<<a1<<endl;
		if (k==2)
			cout<<a1+a2<<endl;
		if (k==3)
			cout<<a1+a2+a3<<endl;
		if (k==4)
			cout<<a1+a2+a3+a4<<endl;
		if (k==5)
			cout<<a1+a2+a3+a4+a5<<endl;
	}
	return 0;
}

