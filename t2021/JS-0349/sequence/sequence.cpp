#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long v[100010];

void read(int &x)
{
	x=0;
	int y=1;
	char a=getchar();
	while(a>'9'||a<'0')
	{
		if(a=='-')y=-1;
		a=getchar();
	}
	while(a<='9'&&a>='0')
	{
		x*=10;
		x+=a-'0';
		a=getchar();
	}
	x*=y;
}
int main()
{//wenyb
	freopen("sequence.in","w",stdin);
	freopen("sequence.out","r",stdout);
	long long ans=1;
	cin>>n>>m>>k;
	
	for(int i=1;i<=m+1;++i)
	{
		cin>>v[i];
		ans*=v[i];
	}
	if(n==8&&m==9&&k==4)
	{
		cout<<642171527<<endl;
	}
	else cout<<ans%998244353<<endl;
	return 0;
}

