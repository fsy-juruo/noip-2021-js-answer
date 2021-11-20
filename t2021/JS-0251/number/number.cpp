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
int o[9]={0,1,10,100,1000,10000,100000,1000000,10000000};
int    p[10000010],pos[10000010];
int maxm=0;
void form(int x)
{
	for (int i=1;i<=x;i++)
		for (int j=0;j<o[i];j++)
			for (int k=0;k<o[x-i+1];k++)	
				if (p[7*o[i]+j+k*o[i+1]]!=1)
				{
					int tmp=7*o[i]+j+k*o[i+1],t=tmp;
//					cout<<tmp<<endl;
//					if (tmp==170) cout<<"oooo"<<endl;
					while (tmp<=o[x+1])
					{
						p[tmp]=1;
//						if (tmp==170) cout<<p[tmp]<<"oooo"<<endl;
//						cout<<tmp<<endl;
						tmp+=t;
					}
				}
}
int t,a[200010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	memset(p,0,sizeof(p));
	p[10000001]=0;
	t=rd();
	for (int i=1;i<=t;i++)
	{
		a[i]=rd();
		maxm=max(maxm,a[i]);
	}
	int k=1;
	while (o[k]<maxm)
		k++;
//	cout<<k<<endl;
	form(k-1);
//	int k=10000000;
//	while (p[k+1]==1)
//		k++;
//	cout<<k<<endl;
//	cout<<p[10000001]<<endl;
//	int flag=
//	for (int i=1;i<=100;i++)
//	{
//		cout<<i<<" "<<p[i]<<endl;
//	}
	k=maxm;
	while (p[k+1]==1)
		k++;
	int flag=k+1;
	for (int i=maxm;i>=1;i--)
	{
		pos[i]=flag;
		if (p[i]==0) flag=i;
	}
//	cout<<p[170]<<endl;
	for (int i=1;i<=t;i++)
	{
		if (p[a[i]]==1) printf("-1\n");
		else printf("%d\n",pos[a[i]]);
	}
//	cout<<"end"<<endl;
	return 0;
}

