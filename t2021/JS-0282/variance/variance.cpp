#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int a[N];
int b[N],s;
bool vis[N][51];
int n;
unsigned long long s2=0x3f3f3f3f,pf;
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
		s+=a[i];
		pf+=a[i]*a[i];
	}
	for(int i=2;i<n;i++)
	{
		b[i]=b[i-1]+b[i+1]-a[i];
		s+=b[i]-a[i];
		pf+=b[i]*b[i]-a[i]*a[i];
		s2=min(s2,n*pf-s*s);
		pf+=a[i]*a[i]-b[i]*b[i];
		s+=a[i]-b[i];
	}
	cout<<s2<<endl;
	return 0;
}
