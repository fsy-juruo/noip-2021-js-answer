#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int sum=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f*=-1;ch=getchar();}
	while(isdigit(ch)){sum=sum*10+ch-48;ch=getchar();}
	return sum*f;
}
int a[10005];
int p[10005];
bool can[605];
int zy[605];
int gs[605];
int cal[605];
int n;
long long ans=0;
inline int  calc()
{
//	for(int i=0;i<n;i++)cout<<cal[i]<<" ";
//	cout<<endl;
//	system("pause");
	for(int i=1;i<n;i++) cal[i]=cal[i-1]+cal[i];
	int zh=0;
	int pfh=0;
	for(int i=0;i<n;i++) zh+=cal[i],pfh+=cal[i]*cal[i];
	return n*pfh-zh*zh;
}
inline void yc()
{
	for(int j=0;j<n;j++)p[j]=cal[j];
	long long nw=calc();
	for(int i=0;i<n;i++)cal[i]=p[i];
	for(int i=1;i<n;i++)
	{
//		int i=rand()%(n-1)+1;
		for(int j=0;j<n;j++)p[j]=cal[j];
		sort(cal+1,cal+i+1);
		reverse(cal+1,cal+i+1);
		sort(cal+i+1,cal+n);
		nw=min(calc(),nw);
		for(int j=0;j<n;j++)cal[j]=p[j];
	}
	ans=min(ans,nw);
}
signed main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	srand(time(0));
	n=read();
	for(int i=0;i<n;i++)a[i]=read();
	for(int i=1;i<n;i++)cal[i]=a[i]-a[i-1];
	sort(cal+1,cal+n);
	int T=(7000000/n/n);
	ans=INT_MAX;
	while(T--)
	{
		random_shuffle(cal+1,cal+n);
		yc();
	}
	cout<<ans<<endl;
	return 0;
}
/*
4
1 2 4 6
*/
