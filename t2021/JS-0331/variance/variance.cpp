#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int n=0;
int ans=0;
double k=0;
double fc(int q[],int n)//���㷽��ĺ��� 
{
	double pjz=0,f=0;//pjz����ƽ��ֵ��f������ 
	int zh=0;
	for(int i=1;i<=n;i++)
	{
		zh+=q[i];
	}
	pjz=double(zh)/double(n);
	for(int i=1;i<=n;i++)
	{
		f+=double(double(q[i])-pjz)*double(double(q[i])-pjz);
	}
	return f;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	memset(a,0,sizeof(a));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	k=fc(a,n);
	for(int i=2;i<=n-1;i++)
	{
		a[i]=a[i-1]+a[i+1]-a[i];
		double p=fc(a,n);
		//cout<<endl<<i<<"   "<<p<<endl;
		//for(int i=1;i<=n;i++)
		//{
		//	cout<<a[i]<<" ";
		//}
		if(p<k)
		{
			k=p;
		}
		a[i]=b[i];
	} 
	for(int i=2;i<=n-1;i++)
	{
		a[i]=a[i-1]+a[i+1]-a[i];
		double p=fc(a,n);
		//cout<<endl<<i<<"   "<<p<<endl;
		//for(int i=1;i<=n;i++)
		//{
		//	cout<<a[i]<<" ";
		//}
		if(p<k)
		{
			k=p;
		}
	}
	ans=k*double(n);
	//cout<<endl;
	cout<<ans;
	//cout<<endl;
	//cout<<k;
	return 0;
 } 
