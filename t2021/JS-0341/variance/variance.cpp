#include <bits/stdc++.h>
using namespace std;
int a[110],n,aa,c[110],ans=INT_MAX;
map <string,int> pd;
string zz(int b)
{
	string ss="";
	int d[110],ii=0;
	while (b!=0)
	{
		ii++;
		d[ii]=b%10;
		b=b/10;
	} 
	for (int i=ii;i>=1;i--)
		ss=ss+char(d[i]+'0');
	return ss;
}
string zh(int b[110])
{
	string s="";
	for (int i=1;i<=n;i++)
		s=s+zz(b[i]);
	return s;
}
int cl(int b[110],int p)
{
	c[p]=b[p-1]+b[p+1]-b[p];
	if (pd[zh(c)]==0)
		return 1;
	else
		return 0;
}
int qfc(int b[110])
{
	int s1=0,s2=0;
	for (int i=1;i<=n;i++)
		s1+=b[i];
	for (int i=1;i<=n;i++)
		s2+=(b[i]*n-s1)*(b[i]*n-s1);
	return s2;
}
void dfs(int b[110])
{
	pd[zh(b)]=1;
	ans=min(ans,qfc(b));
	for (int i=n-1;i>1;i--)
	{
		if (cl(b,i))
			dfs(c);
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin >>n;
	for (int i=1;i<=n;i++)
		cin >>a[i],c[i]=a[i];
	dfs(a);
	cout <<ans/n<<endl;
	return 0;
}

