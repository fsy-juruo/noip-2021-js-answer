#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
long long rd()
{
	char c=getchar();
	long long f=1,ans=0;
	while (!isdigit(c))
	{
		if (c=='-') f=-1;
		c=getchar();
	}
	while (isdigit(c))
	{
		ans=(ans<<3)+(ans<<1)+(c-'0');
		c=getchar();
	}
	return f*ans;
}
long long s[110],n,a[110],v[110],m,k;
long long fin;
long long power(int x,int y,int z)
{
	long long yy=y,xx=x;
	long long ans=1;
	while (yy>0)
	{
		if (yy%2==1){
			yy--;
			ans*=xx;
			ans%=z;
		}
		else{
			yy/=2;
			xx*=xx;
			xx%=z;
		}
	}
	return ans;
}
bool check()
{
	memset(s,0,sizeof(s));
	int flag=0;
	for (int i=1;i<=n;i++)
		s[a[i]]++;
	for (int i=0;i<=m+ceil(log(n)/log(2));i++)
	{
		if (s[i]&1) flag++;
		s[i+1]+=s[i]/2;
	}
	if (flag<=k)
		return true;
	return false;
}
long long c(int x,int y)
{
	long long ans=1;
	if (y-x<x) x=y-x;
	for (int i=y-x+1;i<=y;i++)
		ans=ans*i%mod;
	for (int i=2;i<=x;i++)
		ans=ans*power(i,mod-2,mod)%mod;
	return ans;
}
void renew()
{
	long long ans=1;
	int num=1;
	for (int i=1;i<=n;i++)
	{
		ans=ans*v[a[i]]%mod;
		if (a[i]==a[i+1])
			num++;
		else{
//			cout<<num<<" "<<n-i+1<<endl;
			ans=ans*c(num,num+n-i)%mod;
			num=1;
		}
	}
//	cout<<ans<<endl;
	fin=(fin+ans)%mod;	
//	cout<<fin<<endl;	
}
void form(int x)
{
	if (x==n+1)
	{
//		for (int i=1;i<=n;i++)
//			cout<<a[i]<<" ";
//		cout<<endl;
		if (check()==true)
		{
			renew();
//			cout<<"yes"<<endl;
		}
	}
	else
	{
		for (int i=a[x-1];i<=m;i++)
		{
			a[x]=i;
			form(x+1);
		}
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=rd(); m=rd(); k=rd();
	fin=0;
//	for (int i=1;i<=10;i++)
//		cout<<c(i,10)<<endl;
	for (int i=0;i<=m;i++)
		v[i]=rd();
//	if (k!=1)
//	{
		form(1);
		cout<<fin<<endl;
//	}
//	else {
//		for (int i=ceil(log(n)/log(2));i<=m+ceil(log(n)/log(2));i++)
//		{
//			
//		}
//	}
	return 0;
}

