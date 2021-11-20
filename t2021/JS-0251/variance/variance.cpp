#include<bits/stdc++.h>
using namespace std;
int rd()
{
	char c=getchar();
	int f=1,ans=0;
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
int a[100010],n,flag,pos;
long long minm;
long long sum;
void judge(int x)
{
	int tmp=a[x-1]+a[x+1]-a[x];
	if (n*(tmp*tmp-a[x]*a[x])+sum*sum-(sum-a[x]+tmp)*(sum-a[x]+tmp)<minm)
	{
		pos=x;
		minm=n*(tmp*tmp-a[x]*a[x])+sum*sum-(sum-a[x]+tmp)*(sum-a[x]+tmp);
//		cout<<tmp<<" "<<sum<<endl;
		flag=1;
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=rd();
	for (int i=1;i<=n;i++)
	{
		a[i]=rd();
		sum+=a[i];
	}
	if (n==3)
	{
		int d;
		flag=0;
		judge(2);
		for (int i=1;i<=n;i++)
		d+=n*a[i]*a[i];
		d-=sum*sum;
		cout<<d<<endl;
		return 0;
	}
	if (n==4)
	{
		int l,r,d=0x3f3f3f;
		int v[101][101],q[100010][2];
		memset(v,0,sizeof(v));
		l=1; r=1; q[1][0]=a[2]; q[1][1]=a[3];
		while (l<=r)
		{
			if (v[a[1]+q[l][1]-q[l][0]][q[l][1]]==0)
			{
				v[a[1]+q[l][1]-q[l][0]][q[l][1]]=1;
				r++;
				q[r][0]=a[1]+q[l][1]-q[l][0];
				q[r][1]=q[l][1];
			}
			if (v[q[l][0]][q[l][0]+a[4]-q[l][1]]==0)
			{
				v[q[l][0]][q[l][0]+a[4]-q[l][1]]=1;
				r++;
				q[r][0]=q[l][0];
				q[r][1]=q[l][0]+a[4]-q[l][1];
			}
//			cout<<q[l][0]<<" "<<q[l][1]<<endl;
			d=min(d,4*(a[1]*a[1]+a[4]*a[4]+q[l][0]*q[l][0]+q[l][1]*q[l][1])
			-(a[1]+q[l][0]+q[l][1]+a[4])*(a[1]+q[l][0]+q[l][1]+a[4]));
			l++;	
		}
		cout<<d<<endl;
	}
	else{
	flag=1;
	long long d=0;
	while (flag==1)
	{
		flag=0;
		for (int i=2;i<n;i++)
			judge(i);
		if (flag==1)
		{
			sum=sum+a[pos-1]+a[pos+1]-2*a[pos];
			a[pos]=a[pos-1]+a[pos+1]-a[pos];
			minm=0;
		}
	}
	for (int i=1;i<=n;i++)
		d+=n*a[i]*a[i];
//	cout<<endl;
//	cout<<sum<<endl;
	d-=sum*sum;
	cout<<d<<endl;
}
	return 0;
}

